#include "peerframe.h"
#include "ui_peerframe.h"

PeerFrame::PeerFrame(QWidget *parent, QString peer) :
    QFrame(parent),
    ui(new Ui::PeerFrame)
{
    ui->setupUi(this);
    ui->peer->setText(peer);
}

PeerFrame::~PeerFrame()
{
    delete ui;
}

void PeerFrame::setStatus(bool registered)
{
    QString color = registered ? "150, 200, 150, 150" : "200, 200, 200, 150";

    setStyleSheet(QString("QFrame#PeerFrame { border-radius: 10px; background-color: rgb(%1) }").arg(color));
}

void PeerFrame::setAddress(QString address)
{
    ui->address->setText(address);
}

void PeerFrame::addChannel(QString channel, int duration)
{
    if (!channels.contains(channel)) {
        ChannelFrame *frame = new ChannelFrame(this, channel, duration);

        channels[channel] = frame;
        ui->channels->addWidget(frame);

        connect(frame, SIGNAL(commandTriggered(QString)), SLOT(onChannelCommandTriggered(QString)));
    }
}

void PeerFrame::setChannelState(QString channel, QString state)
{
    if (channels.contains(channel))
        channels[channel]->setState(state);
}

void PeerFrame::setChannelExtension(QString channel, QString extension)
{
    if (channels.contains(channel))
        channels[channel]->setExtension(extension);
}

void PeerFrame::removeChannel(QString channel)
{
    if (channels.contains(channel)) {
        ChannelFrame *frame = channels.take(channel);

        ui->channels->removeWidget(frame);
        frame->deleteLater();
    }
}

void PeerFrame::onChannelCommandTriggered(QString command)
{
    ChannelFrame *channel = (ChannelFrame *) sender();

    emit commandTriggered(channels.key(channel), command);
}
