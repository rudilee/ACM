#include "sessionwindow.h"
#include "ui_sessionwindow.h"

#include <QDebug>

SessionWindow::SessionWindow(QWidget *parent,
                             QString hostname,
                             quint16 port,
                             QString username,
                             QString password) :
    QWidget(parent),
    ui(new Ui::SessionWindow),
    username(username),
    password(password)
{
    ui->setupUi(this);

    setup(hostname, port);
}

SessionWindow::~SessionWindow()
{
    asterisk.disconnectFromHost();

    delete ui;
}

void SessionWindow::setup(QString hostname, quint16 port)
{
    connect(&asterisk, SIGNAL(connected()), SLOT(onAsteriskConnected()));
    connect(&asterisk, SIGNAL(receiveResponse(Asterisk::Response,QHash<QString,QString>)), SLOT(onAsteriskReceiveResponse(Asterisk::Response,QHash<QString,QString>)));
    connect(&asterisk, SIGNAL(receiveEvent(Asterisk::Event,QHash<QString,QString>)), SLOT(onAsteriskReceiveEvent(Asterisk::Event,QHash<QString,QString>)));

    asterisk.connectToHost(hostname, port);

    ui->scrollAreaWidgetContents->setLayout(&layout);
}

void SessionWindow::addChannel(QString channel, QString duration)
{
    ChannelFrame *frame = new ChannelFrame(this, channel, duration);

    channels[channel] = frame;
    layout.addWidget(frame);
}

void SessionWindow::removeChannel(QString channel)
{
    layout.removeWidget(channels[channel]);

    delete channels.take(channel);
}

void SessionWindow::onAsteriskConnected()
{
    asterisk.actionLogin(username, password);
}

void SessionWindow::onAsteriskReceiveResponse(Asterisk::Response response, QHash<QString, QString> headers)
{
    switch (response) {
    case Asterisk::Success:
        break;
    default:
        break;
    }
}

void SessionWindow::onAsteriskReceiveEvent(Asterisk::Event event, QHash<QString, QString> headers)
{
    QString channel = headers["Channel"];

    switch (event) {
    case Asterisk::FullyBooted:
        asterisk.actionCoreShowChannels();
        asterisk.actionDAHDIShowChannels();
        asterisk.actionSIPpeers();

        break;
    case Asterisk::CoreShowChannel:
    case Asterisk::Newchannel:
        addChannel(channel, headers["Duration"]);
    case Asterisk::Newstate:
        if (channels.contains(channel))
            channels[channel]->setState(headers["ChannelState"].toUInt(), headers["ChannelStateDesc"]);

        break;
    case Asterisk::DAHDIShowChannels:
        break;
    case Asterisk::PeerEntry:
        break;
    case Asterisk::Hangup:
        removeChannel(headers["Channel"]);
        break;
    default:
        break;
    }
}
