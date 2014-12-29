#ifndef ASTERISKMANAGER_H
#define ASTERISKMANAGER_H

#include <QTcpSocket>
#include <QMetaEnum>
#include <QStringList>

#define yes "yes"
#define no "no"

typedef int boolean;
typedef QString answer;

class AsteriskManager : public QTcpSocket
{
	Q_OBJECT

	Q_ENUMS(Response)
	Q_ENUMS(Event)

public:
	enum Response {
		Success,
		Error,
		Follows
	};

	enum Event {
		AgentCalled,
		AgentComplete,
		AgentConnect,
		AgentDump,
		AgentRingNoAnswer,
		Agentlogin,
		Agentlogoff,
		Alarm,
		AlarmClear,
		Bridge,
		BridgeAction,
		BridgeExec,
		ChanSpyStart,
		ChanSpyStop,
		ConfbridgeEnd,
		ConfbridgeJoin,
		ConfbridgeLeave,
		ConfbridgeStart,
		ConfbridgeTalking,
		DAHDIChannel,
		DNDState,
		DTMF,
		Dial,
		ExtensionStatus,
		FullyBooted,
		Hangup,
		HangupHandlerPop,
		HangupHandlerPush,
		HangupHandlerRun,
		HangupRequest,
		Hold,
		Join,
		Leave,
		LocalBridge,
		LogChannel,
		Masquerade,
		MeetmeEnd,
		MeetmeJoin,
		MeetmeLeave,
		MeetmeMute,
		MeetmeTalkRequest,
		MeetmeTalking,
		MessageWaiting,
		ModuleLoadReport,
		NewAccountCode,
		NewCallerid,
		NewPeerAccount,
		Newchannel,
		Newexten,
		Newstate,
		OriginateResponse,
		ParkedCall,
		ParkedCallGiveUp,
		ParkedCallTimeOut,
		Pickup,
		PresenceStatus,
		QueueCallerAbandon,
		QueueMemberAdded,
		QueueMemberPaused,
		QueueMemberPenalty,
		QueueMemberRemoved,
		QueueMemberRinginuse,
		QueueMemberStatus,
		Rename,
		Shutdown,
		SoftHangupRequest,
		SpanAlarm,
		SpanAlarmClear,
		UnParkedCall,
		VarSet,
		// Event yg gak ke dokumentasi di 'make full' asterisk
		CoreShowChannel,
		CoreShowChannelsComplete,
		MusicOnHold,
		PeerEntry,
		PeerlistComplete,
		PeerStatus,
		QueueEntry,
		QueueMember,
		QueueParams,
		QueueStatusComplete,
		RTCPReceived,
        RTCPSent,
        Status,
        StatusComplete
	};

	explicit AsteriskManager(QObject *parent = 0);

    QString eventValue(AsteriskManager::Event event);
    QString version();

    QString action(QString action, QVariantMap headers = QVariantMap());
    QString actionHangup(QString channel, uint cause = 0);
	QString actionLogin(QString username, QString secret = QString());
    QString actionLogoff();
	QString actionOriginate(QString channel,
							QString exten = QString(),
							QString context = QString(),
							uint priority = 0,
							QString application = QString(),
							QString data = QString(),
							uint timeout = 0,
							QString callerID = QString(),
							QVariantMap variables = QVariantMap(),
							QString account = QString(),
							boolean earlyMedia = -1,
							boolean async = -1,
							QStringList codecs = QStringList());
    QString actionPark(QString channel, QString channel2, uint timeout = 0, QString parkinglot = QString());
    QString actionPlayDTMF(QString channel, QString digit);
	QString actionQueueAdd(QString queue,
						   QString interface,
						   uint penalty = 0,
						   boolean paused = -1,
						   QString memberName = QString(),
                           QString stateInterface = QString());
    QString actionQueuePause(QString interface, boolean paused, QString queue = QString(), QString reason = QString());
    QString actionQueueRemove(QString queue, QString interface);
    QString actionQueueStatus(QString queue = QString(), QString member = QString());
	QString actionRedirect(QString channel,
						   QString exten,
						   QString context,
						   uint priority,
						   QString extraChannel = QString(),
						   QString extraExten = QString(),
						   QString extraContext = QString(),
                           uint extraPriority = 0);
    QString actionSIPshowpeer(QString peer);

private:
	QMetaEnum responseEnum, eventEnum;
    QVariantMap packetBuffer;
    QString version_;

	QString valueToString(QVariant value);
	QVariant stringValue(QString string);
	void insertNotEmpty(QVariantMap *headers, QString key, QVariant value);
    void dispatchPacket();

private slots:
	void onReadyRead();

signals:
	void connected(QString version);
	void responseSent(AsteriskManager::Response response, QVariantMap headers, QString actionID);
	void eventGenerated(AsteriskManager::Event event, QVariantMap headers);
};

#endif // ASTERISKMANAGER_H
