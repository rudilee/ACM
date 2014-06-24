#include "astmaniface.h"

AstManIface::AstManIface()
{
    connect(this, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(this, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void AstManIface::ActionLogin(QString server, quint16 port, QString username, QString secret)
{
    if (state() == ConnectedState) {
        return;
    }

    this->username = username;
    this->secret = secret;

    connectToHost(server, port);
}

void AstManIface::ActionCommand(QString command, QString actionID)
{
    QStringList parameters;
    parameters << QString(command).prepend("Command: ")
            << QString(actionID).prepend("ActionID: ");

    SendAction("Command", parameters);
}

void AstManIface::ActionEvents(QString eventMask, QString actionID)
{
    QStringList parameters;
    parameters << QString(eventMask).prepend("EventMask: ")
            << QString(actionID).prepend("ActionID");

    SendAction("Events", parameters);
}

void AstManIface::ActionHangup(QString channel, QString actionID)
{
    QStringList parameters;
    parameters << QString(channel).prepend("Channel: ")
            << QString(actionID).prepend("ActionID");

    SendAction("Hangup", parameters);
}

void AstManIface::ActionIAXpeers()
{
    SendAction("IAXpeers", QStringList());
}

void AstManIface::ActionLogoff()
{
    SendAction("Logoff", QStringList());
}

void AstManIface::ActionSIPpeers()
{
    SendAction("SIPpeers", QStringList());
}

void AstManIface::ActionStatus(QString channel, QString actionID)
{
    QStringList parameters;

    if (channel.isEmpty()) {
        parameters << QString(channel).prepend("Channel: ");
    }

    parameters << QString(actionID).prepend("ActionID");

    SendAction("Status", parameters);
}

void AstManIface::ActionZapShowChannels(QString actionID)
{
    QStringList parameters;
    parameters << QString(actionID).prepend("ActionID");

    SendAction("ZapShowChannels", parameters);
}

void AstManIface::onConnected()
{
    QStringList parameters;
    parameters << QString(username).prepend("Username: ")
            << QString(secret).prepend("Secret: ")
            << "Events: on";

    SendAction("Login", parameters);

    emit SocketConnected();
}

void AstManIface::onDisconnected()
{
    QHash<QString, QString> parameters;
    parameters["ActionID"] = "ami_logoff";
    parameters["Message"] = "Thanks for all the fish.";

    emit ReceiveResponse("Goodbye", parameters);
    emit SocketDisconnected();
}

void AstManIface::onError(QAbstractSocket::SocketError)
{
    emit SocketError();
}

void AstManIface::onReadyRead()
{
    QByteArray line;
    QStringList field;
    QStringList parameters;
    QHash<QString, QString> paramsHash;
    QStringList paramsField;
    QRegExp keyValue("^([A-Za-z]+):\\s(.+)");
    int foundPos = 0;

    while (canReadLine()) {
        line = readLine().trimmed();

        if (line.isEmpty()) {
            field = QString(parameters.first()).split(": ");

            if (!parameters.isEmpty()) {
                parameters.removeFirst();

                for (int i = 0; i < parameters.size(); ++i) {
                    foundPos = keyValue.indexIn(parameters.at(i));

                    if (foundPos == -1) {
                        continue;
                    }

                    paramsField = keyValue.capturedTexts();
                    paramsHash[paramsField.at(1)] = paramsField.last();
                }
            }

            if (field.first() == "Event") {
                emit ReceiveEvent(field.last(), paramsHash);

//                ReadEvent(field.last(), parameters);
            } else if (field.first() == "Response") {
                if (field.last() == "Follows") {
                    QStringList totals;
                    QRegExp totalActive("([0-9]+)\\s[A-Za-z].+");
                    int paramsCount = parameters.count();

                    totalActive.indexIn(parameters.at(paramsCount - 3));
                    totals = totalActive.capturedTexts();
                    paramsHash["ActiveChannels"] = totals.at(1);

                    totalActive.indexIn(parameters.at(paramsCount - 2));
                    totals = totalActive.capturedTexts();
                    paramsHash["ActiveCalls"] = totals.at(1);
                }

                emit ReceiveResponse(field.last(), paramsHash);

                ReadResponse(field.last(), parameters);
            }

//            emit ResponseEvent(field.last(), paramsHash);

            parameters.clear();
        } else {
            parameters << line;
        }
    }
}

void AstManIface::ReadEvent(QString event, QStringList parameters)
{
    qDebug("<==");
    qDebug(event.toLatin1().data());

    for (int i = 0; i < parameters.size(); ++i)
         qDebug(QString(parameters.at(i)).toLatin1().data());

    qDebug("==>");
}

void AstManIface::ReadResponse(QString response, QStringList parameters)
{
    qDebug("<--");
    qDebug(response.toLatin1().data());

    for (int i = 0; i < parameters.size(); ++i)
         qDebug(QString(parameters.at(i)).toLatin1().data());

    qDebug("-->");
}

void AstManIface::SendAction(QString action, QStringList parameters)
{
    QByteArray actionPacket;
    actionPacket.append(action.prepend("Action: ").append("\r\n"));

    if (!parameters.isEmpty()) {
        actionPacket.append(parameters.join("\r\n"));
    }

    write(actionPacket.append("\r\n\r\n"));
}
