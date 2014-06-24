#ifndef ASTMANIFACE_H
#define ASTMANIFACE_H

#include <QTcpSocket>
#include <QStringList>

class AstManIface : public QTcpSocket
{
    Q_OBJECT
public:
    explicit AstManIface();

signals:
    void SocketConnected();
    void SocketDisconnected();
    void SocketError();

//    void ResponseEvent(QString subject, QHash<QString, QString> parameters);
    void ReceiveEvent(QString event, QHash<QString, QString> parameters);
    void ReceiveResponse(QString response, QHash<QString, QString> parameters);

/* implemented & unimplemented events
//    Agent status events
//    void AgentcallbackloginEvent();
//    void AgentcallbacklogoffEvent();
//    void AgentCalledEvent();
//    void AgentCompleteEvent();
//    void AgentConnectEvent();
//    void AgentDumpEvent();
//    void AgentloginEvent();
//    void AgentlogoffEvent();
//    void QueueMemberAddedEvent();
//    void QueueMemberPausedEvent();
//    void QueueMemberStatusEvent();

//    Call status events
    void CdrEvent(QStringList callDataRecord);
    void DialEvent(QString source, QString destination, QString callerID, QString callerIDName,
                   QString srcUniqueID, QString destUniqueID);
//    void ExtensionStatusEvent();
    void HangupEvent(QString channel, QString uniqueID, int cause);
    void MusicOnHoldEvent(QString channel, bool state, QString uniqueID);
//    void JoinEvent();
//    void LeaveEvent();
    void LinkEvent(QString channel1, QString channel2, QString uniqueID1, QString uniqueID2);
//    void MeetmeJoinEvent();
//    void MeetmeLeaveEvent();
//    void MeetmeStopTalkingEvent();
//    void MeetmeTalkingEvent();
//    void MessageWaitingEvent();
    void NewcalleridEvent(QString channel, QString callerID, QString uniqueID);
    void NewchannelEvent(QString channel, QString state, QString callerID, QString uniqueID);
    void NewextenEvent(QString channel, QString context, QString extension, int priority,
                       QString application, QString appData, QString uniqueID);
//    void ParkedCallEvent();
//    void RenameEvent();
//    void SetCDRUserFieldEvent();
    void UnlinkEvent(QString channel1, QString channel2, QString uniqueID1, QString uniqueID2);
//    void UnParkedCallEvent();

//    System status events
    void AlarmEvent(QString alarm, QString channel);
    void AlarmClearEvent(QString channel);
    void DNDStateEvent(QString channel);
//    void LogChannelEvent();
    void PeerStatusEvent(QString peer, QString peerStatus, QString cause, long time);
    void RegistryEvent(QString channel, QString domain, QString status);
    void ReloadEvent(QString message);
    void ShutdownEvent(bool shutdown, bool restart);

//    User status events
//    void UserEventEvent();

//    Unformatted and Undocumented
    void NewstateEvent(QString channel, QString state, QString callerID, QString uniqueID);
//    void ParkedCallsCompleteEvent();
//    void QueueParamsEvent();
//    void QueueMemberEvent();
//    void QueueStatusEnd();
    void Status(QString channel, QString callerID, QString account, QString state, QString context,
                QString extension, int priority, long seconds, QString link, QString uniqueID);
    void StatusCompleteEvent();
//    void ZapShowChannelsEvent();
//    void ZapShowChannelsCompleteEvent();

//    Command responses
    void ActionResponse(QString response, QString actionID, QString message);
*/

public slots:
    void ActionLogin(QString server, quint16 port, QString username, QString secret);

//    void ActionAbsoluteTimeout();
//    void ActionChangeMonitor();
    void ActionCommand(QString command, QString actionID);
    void ActionEvents(QString eventMask, QString actionID);
//    void ActionExtensionState();
//    void ActionGetVar();
    void ActionHangup(QString channel, QString actionID);
    void ActionIAXpeers();
//    void ActionListCommands();
    void ActionLogoff();
//    void ActionMailboxCount();
//    void ActionMailboxStatus();
//    void ActionMonitor();
//    void ActionOriginate();
//    void ActionParkedCalls();
//    void ActionPing();
//    void ActionQueueAdd();
//    void ActionQueueRemove();
//    void ActionQueues();
//    void ActionQueueStatus();
//    void ActionRedirect();
//    void ActionSetCDRUserField();
//    void ActionSetVar();
    void ActionSIPpeers();
    void ActionStatus(QString channel, QString actionID);
//    void ActionStopMonitor();
//    void ActionZapDialOffhook();
//    void ActionZapDNDoff();
//    void ActionZapDNDon();
//    void ActionZapHangup();
//    void ActionZapTransfer();
    void ActionZapShowChannels(QString actionID);

//    void ActionAgentCallbackLogin();
//    void ActionAgentLogoff();
//    void ActionAgents();
//    void ActionDBGet();
//    void ActionDBPut();
//    void ActionQueuePause();
//    void ActionSIPshowPeer();
//    void ActionGetConfig();
//    void ActionPlayDTMF();
//    void ActionUpdateConfig();

private slots:
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError);
    void onReadyRead();

private:
    QString username;
    QString secret;

    void ReadEvent(QString event, QStringList parameters);
    void ReadResponse(QString response, QStringList parameters);
    void SendAction(QString action, QStringList parameters);
};

#endif // ASTMANIFACE_H
