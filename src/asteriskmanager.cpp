#include "asteriskmanager.h"

#include <QStringList>
#include <QRegExp>
#include <QDateTime>

#include <QDebug>

AsteriskManager::AsteriskManager() :
    QTcpSocket()
{
    asteriskResponse << "Success"
                     << "Error";

    asteriskEvent << "FullyBooted"
                  << "CoreShowChannel"
                  << "DAHDIShowChannels"
                  << "PeerEntry"
                  << "ExtensionStatus"
                  << "QueueParams"
                  << "QueueMember"
                  << "QueueMemberStatus"
                  << "QueueMemberAdded"
                  << "QueueMemberRemoved"
                  << "QueueMemberPaused"
                  << "Newchannel"
                  << "Newstate"
                  << "Dial"
                  << "Hangup"
                  << "Bridge"
                  << "Unlink"
                  << "Cdr";

    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(onError(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(readyRead()), SLOT(onReadyRead()));
}

void AsteriskManager::connectToHost(const QString &hostName, quint16 port)
{
    QTcpSocket::connectToHost(hostName, port);
}

QString AsteriskManager::actionLogin(QString username, QString secret)
{
    QHash<QString, QString> headers;
    headers["Username"] = username;
    headers["Secret"] = secret;

    return sendAction("Login", headers);
}

QString AsteriskManager::actionLogoff()
{
    return sendAction("Logoff");
}

QString AsteriskManager::actionStatus(QString channel, QStringList variables)
{
    QHash<QString, QString> headers;
    headers["Channel"] = channel;

    if (!variables.isEmpty())
        headers["Variables"] = variables.join(',');

    return sendAction("Status", headers);
}

QString AsteriskManager::actionCoreStatus()
{
    return sendAction("CoreStatus");
}

QString AsteriskManager::actionCoreSettings()
{
    return sendAction("CoreSettings");
}

QString AsteriskManager::actionCoreShowChannels()
{
    return sendAction("CoreShowChannels");
}

QString AsteriskManager::actionWaitEvent(int timeout)
{
    QHash<QString, QString> headers;
    headers["Timeout"] = timeout;

    return sendAction("WaitEvent", headers);
}

QString AsteriskManager::actionOriginate(QString channel,
                                      QString exten,
                                      QString context,
                                      uint priority,
                                      QString application,
                                      QString data,
                                      int timeout,
                                      QString callerId,
                                      QStringList variables,
                                      QString account,
                                      bool async,
                                      QStringList codecs)
{
    QHash<QString, QString> headers;
    headers["Channel"] = channel;

    if (!exten.isEmpty() && !context.isEmpty() && priority > 0) {
        headers["Exten"] = exten;
        headers["Context"] = context;
        headers["Priority"] = QString::number(priority);
    }

    if (!application.isEmpty()) {
        headers["Application"] = application;

        if (!data.isEmpty())
            headers["Data"] = data;
    }

    if (timeout > 0)
        headers["Timeout"] = QString::number(timeout);

    if (!callerId.isEmpty())
        headers["CallerID"] = callerId;

    if (!variables.isEmpty()) {
        foreach (QString variable, variables) {
            headers.insertMulti("Variable", variable);
        }
    }

    if (!account.isEmpty())
        headers["Account"] = account;

    headers["Async"] = (async ? "true" : "false");

    if (!codecs.isEmpty())
        headers["Codecs"] = codecs.join(',');

    qDebug() << "Asterisk Originate.." << "Channel:" << channel << "Exten:" << exten;

    return sendAction("Originate", headers);
}

QString AsteriskManager::actionHangup(QString channel, uint cause)
{
    QHash<QString, QString> headers;
    headers["Channel"] = channel;

    if (cause > 0)
        headers["Cause"] = QString::number(cause);

    qDebug("Asterisk Hangup..");

    return sendAction("Hangup", headers);
}

QString AsteriskManager::actionDAHDIShowChannels()
{
    return sendAction("DAHDIShowChannels");
}

QString AsteriskManager::actionSIPpeers()
{
    return sendAction("SIPpeers");
}

QString AsteriskManager::actionSIPshowpeer(QString peer)
{
    QHash<QString, QString> headers;
    headers["Peer"] = peer;

    return sendAction("SIPshowpeer", headers);
}

QString AsteriskManager::actionQueueStatus(QString queue, QString member)
{
    QHash<QString, QString> headers;

    if (!queue.isEmpty())
        headers["Queue"] = queue;

    if (!member.isEmpty())
        headers["Member"] = member;

    return sendAction("QueueStatus", headers);
}

QString AsteriskManager::actionQueueAdd(QString queue, QString interface, bool paused)
{
    QHash<QString, QString> headers;
    headers["Queue"] = queue;
    headers["Interface"] = interface;

    if (paused)
        headers["Paused"] = "true";

    return sendAction("QueueAdd", headers);
}

QString AsteriskManager::actionQueueRemove(QString queue, QString interface)
{
    QHash<QString, QString> headers;
    headers["Queue"] = queue;
    headers["Interface"] = interface;

    return sendAction("QueueRemove", headers);
}

QString AsteriskManager::actionQueuePause(QString interface,
                                       bool paused,
                                       QString queue,
                                       QString reason)
{
    QHash<QString, QString> headers;
    headers["Interface"] = interface;
    headers["Paused"] = paused ? "True" : "False";

    if (!queue.isEmpty())
        headers["Queue"] = queue;

    if (!reason.isEmpty())
        headers["Reason"] = reason;

    return sendAction("QueuePause", headers);
}

QString AsteriskManager::sendAction(QString action, QHash<QString, QString> headers)
{
    // TODO: pastiin kalo login berhasil baru jalanin action
    if (state() != ConnectedState)
        return "";

    QByteArray message = QString("Action: ").append(action).toLatin1();
    QString actionId = QDateTime::currentDateTime().toString("yyyyMMddHHmmsszzz");

    headers["ActionID"] = actionId;

    QHashIterator<QString, QString> header(headers);
    while (header.hasNext()) {
        header.next();

        message.append(QString("\n%1: %2").arg(header.key(), header.value()));
    }

    write(message.append("\n\n"));

    return actionId;
}

void AsteriskManager::parseMessageBuffer()
{
    qDebug("Try to Parse Asterisk Message buffer");

    QRegExp keyValue("([A-Za-z0-9\\-]+):\\s(.*)\r\n");
    QHash<QString, QString> headers;

    while (!messageQueue.isEmpty()) {
        if (keyValue.indexIn(messageQueue.dequeue()) > -1)
            headers[keyValue.cap(1)] = keyValue.cap(2);
    }

    if (headers.contains("Response"))
        emit receiveResponse((Asterisk::Response) asteriskResponse.indexOf(headers["Response"]), headers);
    else if (headers.contains("Event"))
        emit receiveEvent((Asterisk::Event) asteriskEvent.indexOf(headers["Event"]), headers);

    messageBuffer.clear();
}

void AsteriskManager::onError(QAbstractSocket::SocketError socketError)
{
    QString message;

    switch (socketError) {
    case QAbstractSocket::ConnectionRefusedError:
        message = "The connection was refused (or timed out)";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        message = "The remote host closed the connection";
        break;
    case QAbstractSocket::HostNotFoundError:
        message = "The host address was not found";
        break;
    case QAbstractSocket::NetworkError:
        message = "An error occurred with the network\n (e.g., the network cable was accidentally plugged out).";
        break;
    default:
        message = "Misc. connection error";
    }

    emit connectionError(message);

    qDebug() << "Asterisk Connection Error:" << socketError;
}

void AsteriskManager::onReadyRead()
{
    QByteArray line;

    qDebug("\n[AMI_START]");
    QString debugLines;

    while (canReadLine()) {
        line = readLine();
        debugLines += QString(line).trimmed().append("\n");

        if (line != "\r\n")
            messageQueue.enqueue(line);
        else
            parseMessageBuffer();
    }

    qDebug() << debugLines;
    qDebug("[AMI_END]\n");
}
