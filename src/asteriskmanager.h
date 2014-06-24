#ifndef ASTERISKMANAGER_H
#define ASTERISKMANAGER_H

#include <QTcpSocket>
#include <QStringList>
#include <QQueue>

namespace Asterisk {
typedef enum {
    Success,
    Error
} Response;

typedef enum {
    FullyBooted,
    CoreShowChannel,
    DAHDIShowChannels,
    PeerEntry,
    ExtensionStatus,
    QueueParams,
    QueueMember,
    QueueMemberStatus,
    QueueMemberAdded,
    QueueMemberRemoved,
    QueueMemberPaused,
    Newchannel,
    Newstate,
    Dial,
    Hangup,
    Bridge,
    Unlink,
    Cdr
} Event;
}

class AsteriskManager : public QTcpSocket
{
    Q_OBJECT
public:
    explicit AsteriskManager();

    void connectToHost(const QString &hostName, quint16 port = 5038);

    // Action commands
    QString actionLogin(QString username, QString secret);
    QString actionLogoff();
    QString actionStatus(QString channel, QStringList variables = QStringList());
    QString actionCoreStatus();
    QString actionCoreSettings();
    QString actionCoreShowChannels();
    QString actionWaitEvent(int timeout = -1);
    QString actionOriginate(QString channel,
                            QString exten = "",
                            QString context = "",
                            uint priority = 0,
                            QString application = "",
                            QString data = "",
                            int timeout = 0,
                            QString callerId = "",
                            QStringList variables = QStringList(),
                            QString account = "",
                            bool async = true,
                            QStringList codecs = QStringList());
    QString actionHangup(QString channel, uint cause = 0);
    QString actionDAHDIShowChannels();
    QString actionSIPpeers();
    QString actionSIPshowpeer(QString peer);
    QString actionQueueStatus(QString queue = "", QString member = "");
    // Queue, Interface, Penalty, Paused, MemberName, StateInterface
    QString actionQueueAdd(QString queue, QString interface, bool paused = false);
    QString actionQueueRemove(QString queue, QString interface);
    QString actionQueuePause(QString interface,
                             bool paused,
                             QString queue = "",
                             QString reason = "");

private:
    QStringList asteriskResponse, asteriskEvent;
    QString username, secret;
    QList<QByteArray> messageBuffer;
    QQueue<QByteArray> messageQueue;

    QString sendAction(QString action, QHash<QString, QString> headers = QHash<QString, QString>());
    void parseMessageBuffer();

private slots:
    void onError(QAbstractSocket::SocketError socketError);
    void onReadyRead();

signals:
    void connectionError(QString message);
    void receiveResponse(Asterisk::Response response, QHash<QString, QString> headers);
    void receiveEvent(Asterisk::Event event, QHash<QString, QString> headers);
};

#endif // ASTERISKMANAGER_H
