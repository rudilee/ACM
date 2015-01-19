#ifndef PEERFRAME_H
#define PEERFRAME_H

#include <QFrame>
#include <QHash>

#include "channelframe.h"

namespace Ui {
class PeerFrame;
}

class PeerFrame : public QFrame
{
    Q_OBJECT

public:
    explicit PeerFrame(QWidget *parent = 0, QString peer = QString());
    ~PeerFrame();

    void setStatus(bool registered);
    void setAddress(QString address);
    void addChannel(QString channel, int duration = 0);
    void setChannelState(QString channel, QString state);
    void setChannelExtension(QString channel, QString extension);
    void removeChannel(QString channel);

private:
    Ui::PeerFrame *ui;
    QHash<QString, ChannelFrame *> channels;

private slots:
    void onChannelCommandTriggered(QString command);

signals:
    void commandTriggered(QString channel, QString command);
};

#endif // PEERFRAME_H
