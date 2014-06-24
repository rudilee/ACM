#include "channelframe.h"
#include "ui_channelframe.h"

ChannelFrame::ChannelFrame(QWidget *parent, QString channel, QString duration) :
    QFrame(parent),
    ui(new Ui::ChannelFrame),
    channel(channel)
{
    ui->setupUi(this);
    ui->channel->setText(channel);
    ui->duration->setTime(QTime::fromString(duration, "HH:mm:ss"));

    startTimer(1000);
}

ChannelFrame::~ChannelFrame()
{
    delete ui;
}

void ChannelFrame::setState(int state, QString description)
{
    QString color = "200, 200, 200";

    switch (state) {
    case 0: // Down
        color = "200, 150, 150";
        break;
    case 1: // Rsrvd
        color = "150, 150, 200";
        break;
    case 3: // Dialing
    case 4: // Ring
        color = "200, 200, 150";
        break;
    case 6: // Up
        color = "150, 200, 150";
        break;
    default:
        break;
    };

    setStyleSheet(QString("QFrame { border-radius: 10px; background-color: rgb(%1) }").arg(color));
}

void ChannelFrame::timerEvent(QTimerEvent *event)
{
    QObject::timerEvent(event);

    ui->duration->setTime(ui->duration->time().addSecs(1));
}
