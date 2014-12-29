#include "channelframe.h"
#include "ui_channelframe.h"

#include <QMetaEnum>
#include <QMenu>

ChannelFrame::ChannelFrame(QWidget *parent, QString channel, int duration) :
    QFrame(parent),
    ui(new Ui::ChannelFrame),
    channel(channel)
{
    ui->setupUi(this);
    ui->channel->setText(QString("[%1]").arg(parseChannelId(channel)));
    ui->duration->setTime(QTime::fromString("00:00:00", "HH:mm:ss").addSecs(duration));

    setupCommand();
    startTimer(1000);
}

ChannelFrame::~ChannelFrame()
{
    delete ui;
}

QString ChannelFrame::parseChannelId(QString channel)
{
    QRegExp channelPattern("^.+\\-(.+$)");
    QString channelId;

    if (channelPattern.indexIn(channel) > -1)
        channelId = channelPattern.cap(1);

    return channelId;
}

void ChannelFrame::setState(QString stateText)
{
    QString color = "200, 200, 200";

    const QMetaObject *metaObj = metaObject();
    State state = (State) metaObj->enumerator(metaObj->indexOfEnumerator("State")).keysToValue(stateText.toLatin1().data());

    switch (state) {
    case Down:
        color = "200, 150, 150";
        break;
    case Rsrvd:
        color = "150, 150, 200";
        break;
    case Dialing:
    case Ringing:
    case Ring:
        color = "200, 200, 150";
        break;
    case Up:
        color = "150, 200, 150";
        break;
    default:
        break;
    };

    setStyleSheet(QString("QFrame#ChannelFrame { border-radius: 4px; background-color: rgb(%1) }").arg(color));
}

void ChannelFrame::setExtension(QString extension)
{
    ui->channel->setText(extension);
}

void ChannelFrame::setupCommand()
{
    QMenu *commands = new QMenu(ui->command);
    commands->addAction(QIcon(":/menu/listen"), "Listen");
    commands->addAction(QIcon(":/menu/whisper"), "Whisper");
    commands->addAction(QIcon(":/menu/hangup"), "Hangup");

    ui->command->setMenu(commands);

    connect(commands, SIGNAL(triggered(QAction*)), SLOT(onCommandMenuTriggered(QAction*)));
}

void ChannelFrame::timerEvent(QTimerEvent *event)
{
    QObject::timerEvent(event);

    ui->duration->setTime(ui->duration->time().addSecs(1));
}

void ChannelFrame::onCommandMenuTriggered(QAction *action)
{
    emit commandTriggered(action->text());
}
