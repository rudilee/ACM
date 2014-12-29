#ifndef SESSIONWINDOW_H
#define SESSIONWINDOW_H

#include "asteriskmanager.h"
#include "channelframe.h"
#include "peerframe.h"
#include "flowlayout.h"

#include <QWidget>

namespace Ui {
class SessionWindow;
}

class SessionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SessionWindow(QWidget *parent,
                           QString hostname,
                           quint16 port,
                           QString username,
                           QString password);
    ~SessionWindow();

private:
    Ui::SessionWindow *ui;
    AsteriskManager asterisk;
    QString username, password;
    QHash<QString, PeerFrame *> peers; // Peer, Frame
    FlowLayout layout;
    QHash<QString, QString> actions; // Action, Action ID
    QStringList localAddress;
    QString selfPeer;

    QString parsePeer(QString channel);
    QString takeAction(QString action, QString actionId);

    void populateLocalAddress();
    void setupAsterisk(QString hostname, quint16 port);
    void addPeer(QString peer);
    void setPeerStatus(QString peer, QString registered);
    void setPeerAddress(QString peer, QString ipAddress);
    void addChannel(QString channel, int duration = 0);
    void setChannelState(QString channel, QString state);
    void setChannelExtension(QString channel, QString extension);
    void removeChannel(QString channel);

private slots:
    void onAsteriskConnected(QString version);
    void onAsteriskResponseSent(AsteriskManager::Response response, QVariantMap headers, QString actionId);
    void onAsteriskEventGenerated(AsteriskManager::Event event, QVariantMap headers);

    void onPeerCommandTriggered(QString channel, QString command);
};

#endif // SESSIONWINDOW_H
