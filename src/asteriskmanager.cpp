#include <QUuid>

#include "asteriskmanager.h"

AsteriskManager::AsteriskManager(QObject *parent) :
	QTcpSocket(parent),
	responseEnum(AsteriskManager::staticMetaObject.enumerator(AsteriskManager::staticMetaObject.indexOfEnumerator("Response"))),
	eventEnum(AsteriskManager::staticMetaObject.enumerator(AsteriskManager::staticMetaObject.indexOfEnumerator("Event")))
{
	connect(this, SIGNAL(readyRead()), SLOT(onReadyRead()));
}

QString AsteriskManager::eventValue(AsteriskManager::Event event)
{
    return eventEnum.valueToKey(event);
}

QString AsteriskManager::version()
{
    return version_;
}

QString AsteriskManager::action(QString action, QVariantMap headers)
{
    QString actionID = QString();

//    qDebug("<action>");

    if (state() == QAbstractSocket::ConnectedState) {
        actionID = QUuid::createUuid().toString();

        headers["ActionID"] = actionID;
        headers["Action"] = action;

        QMapIterator<QString, QVariant> header(headers);
        while (header.hasNext()) {
            header.next();

//            qDebug() << QString(header.key()).append(":") << header.value();

            write(QString("%1: %2\r\n").arg(header.key(), valueToString(header.value())).toLatin1());
        }

        write("\r\n");
    }

//    qDebug("</action>");

    return actionID;
}

QString AsteriskManager::actionHangup(QString channel, uint cause)
{
	QVariantMap headers;
	headers["Channel"] = channel;

	insertNotEmpty(&headers, "Cause", cause);

    return action("Hangup", headers);
}

QString AsteriskManager::actionLogin(QString username, QString secret)
{
	QVariantMap headers;
	headers["Username"] = username;

	insertNotEmpty(&headers, "Secret", secret);

    return action("Login", headers);
}

QString AsteriskManager::actionLogoff()
{
    return action("Logoff");
}

QString AsteriskManager::actionOriginate(QString channel,
										 QString exten,
										 QString context,
										 uint priority,
										 QString application,
										 QString data,
										 uint timeout,
										 QString callerID,
										 QVariantMap variables,
										 QString account,
										 boolean earlyMedia,
										 boolean async,
										 QStringList codecs)
{
	QVariantMap headers;
	headers["Channel"] = channel;

	insertNotEmpty(&headers, "Exten", exten);
	insertNotEmpty(&headers, "Context", context);
	insertNotEmpty(&headers, "Priority", priority);
	insertNotEmpty(&headers, "Application", application);
	insertNotEmpty(&headers, "Data", data);
	insertNotEmpty(&headers, "Timeout", timeout);
	insertNotEmpty(&headers, "CallerID", callerID);
	insertNotEmpty(&headers, "Account", account);
	insertNotEmpty(&headers, "EarlyMedia", earlyMedia);
	insertNotEmpty(&headers, "Async", async);
	insertNotEmpty(&headers, "Codecs", codecs.join(','));

	qDebug() << "Headers:" << headers;

	if (!variables.isEmpty()) {
		QMapIterator<QString, QVariant> variable(variables);
		while (variable.hasNext()) {
			variable.next();

			headers.insertMulti("Variable", QString("%1=%2").arg(variable.key(), valueToString(variable.value())));
		}
	}

    return action("Originate", headers);
}

QString AsteriskManager::actionPark(QString channel, QString channel2, uint timeout, QString parkinglot)
{
	QVariantMap headers;
	headers["Channel"] = channel;
	headers["Channel2"] = channel2;

	insertNotEmpty(&headers, "Timeout", timeout);
	insertNotEmpty(&headers, "Parkinglot", parkinglot);

    return action("Park", headers);
}

QString AsteriskManager::actionPlayDTMF(QString channel, QString digit)
{
	QVariantMap headers;
	headers["Channel"] = channel;
	headers["Digit"] = digit;

    return action("PlayDTMF", headers);
}

QString AsteriskManager::actionQueueAdd(QString queue,
										QString interface,
										uint penalty,
										boolean paused,
										QString memberName,
										QString stateInterface)
{
	QVariantMap headers;
	headers["Queue"] = queue;
	headers["Interface"] = interface;

	insertNotEmpty(&headers, "Penalty", penalty);
	insertNotEmpty(&headers, "Paused", paused);
	insertNotEmpty(&headers, "MemberName", memberName);
	insertNotEmpty(&headers, "StateInterface", stateInterface);

    return action("QueueAdd", headers);
}

QString AsteriskManager::actionQueuePause(QString interface, boolean paused, QString queue, QString reason)
{
	QVariantMap headers;
	headers["Interface"] = interface;
	headers["Paused"] = paused;

    insertNotEmpty(&headers, "Queue", queue);
	insertNotEmpty(&headers, "Reason", reason);

    return action("QueuePause", headers);
}

QString AsteriskManager::actionQueueRemove(QString queue, QString interface)
{
	QVariantMap headers;
	headers["Queue"] = queue;
	headers["Interface"] = interface;

    return action("QueueRemove");
}

QString AsteriskManager::actionQueueStatus(QString queue, QString member)
{
	QVariantMap headers;

	insertNotEmpty(&headers, "Queue", queue);
	insertNotEmpty(&headers, "Member", member);

    return action("QueueStatus", headers);
}

QString AsteriskManager::actionRedirect(QString channel,
										QString exten,
										QString context,
										uint priority,
										QString extraChannel,
										QString extraExten,
										QString extraContext,
										uint extraPriority)
{
	QVariantMap headers;
	headers["Channel"] = channel;
	headers["Exten"] = exten;
	headers["Context"] = context;
	headers["Priority"] = priority;

	insertNotEmpty(&headers, "ExtraChannel", extraChannel);
	insertNotEmpty(&headers, "ExtraExten", extraExten);
	insertNotEmpty(&headers, "ExtraContext", extraContext);
	insertNotEmpty(&headers, "ExtraPriority", extraPriority);

    return action("Redirect", headers);
}

QString AsteriskManager::actionSIPshowpeer(QString peer)
{
	QVariantMap headers;
	headers["Peer"] = peer;

    return action("SIPshowpeer", headers);
}

QString AsteriskManager::valueToString(QVariant value)
{
	switch (value.type()) {
	case QMetaType::Char:
		return value.toChar() == 1 ? "true" : "false";
	default:
		return value.toString();
	}
}

QVariant AsteriskManager::stringValue(QString string)
{
	QVariant value(string);

	if (string == "true" || string == "false")
		value.setValue(string == "true");
	else if (QVariant(value).convert(QMetaType::UInt))
		value.setValue(string.toUInt());

	return value;
}

void AsteriskManager::insertNotEmpty(QVariantMap *headers, QString key, QVariant value)
{
	bool isEmpty = false;

	switch (value.type()) {
	case QMetaType::Int:
		isEmpty = value.toChar() == -1;
		break;
	case QMetaType::UInt:
		isEmpty = value.toUInt() == 0;
		break;
	default:
		isEmpty = value.isNull();
		break;
	}

	if (!isEmpty)
		headers->insert(key, value);
}

void AsteriskManager::dispatchPacket()
{
	if (packetBuffer.contains("Response")) {
		QString actionID = packetBuffer["ActionID"].toString();
		Response response = (Response) responseEnum.keyToValue(packetBuffer["Response"].toByteArray().data());

		emit responseSent(response, packetBuffer, actionID);
	} else if (packetBuffer.contains("Event")) {
		Event event = (Event) eventEnum.keyToValue(packetBuffer["Event"].toByteArray().data());

		emit eventGenerated(event, packetBuffer);
	}

	packetBuffer.clear();
}

void AsteriskManager::onReadyRead()
{
	QRegExp keyValue("^([A-Za-z0-9\\-]+):\\s(.+)$");
	QByteArray line;

    qDebug("<ami>");

	while (canReadLine()) {
		line = readLine();

        qDebug() << line.trimmed();

		if (line != "\r\n") {
            if (keyValue.indexIn(line) > -1) {
				packetBuffer[keyValue.cap(1)] = stringValue(keyValue.cap(2).trimmed());
            } else if (line.startsWith("Asterisk Call Manager")) {
                version_ = line.replace("Asterisk Call Manager/", QByteArray()).trimmed();

                emit connected(version_);
            }
		} else if (!packetBuffer.isEmpty()) {
			dispatchPacket();
		}
	}

    qDebug("</ami>");
}

