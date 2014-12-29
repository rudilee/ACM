#include "sessionwindow.h"
#include "ui_sessionwindow.h"

#include <QNetworkInterface>
#include <QMessageBox>
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
    ui->scrollAreaWidgetContents->setLayout(&layout);

    populateLocalAddress();
    setupAsterisk(hostname, port);
}

SessionWindow::~SessionWindow()
{
    asterisk.actionLogoff();

    delete ui;
}

QString SessionWindow::parsePeer(QString channel)
{
    QRegExp channelPattern("^(.+)\\-.+$");
    QString peer;

    if (channelPattern.indexIn(channel) > -1)
        peer = channelPattern.cap(1);

    return peer;
}

QString SessionWindow::takeAction(QString action, QString actionId)
{
    if (actions.value(action) == actionId)
        return actions.take(actionId);

    return QString();
}

void SessionWindow::populateLocalAddress()
{
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol /*&& address != QHostAddress(QHostAddress::LocalHost)*/)
             localAddress << address.toString();
    }
}

void SessionWindow::setupAsterisk(QString hostname, quint16 port)
{
    connect(&asterisk, SIGNAL(connected(QString)), SLOT(onAsteriskConnected(QString)));
    connect(&asterisk, SIGNAL(responseSent(AsteriskManager::Response,QVariantMap,QString)),
            SLOT(onAsteriskResponseSent(AsteriskManager::Response,QVariantMap, QString)));
    connect(&asterisk, SIGNAL(eventGenerated(AsteriskManager::Event,QVariantMap)),
            SLOT(onAsteriskEventGenerated(AsteriskManager::Event,QVariantMap)));

    asterisk.connectToHost(hostname, port);
}

void SessionWindow::addPeer(QString peer)
{
    if (!peers.contains(peer)) {
        PeerFrame *frame = new PeerFrame(this, peer);

        peers[peer] = frame;
        layout.addWidget(frame);

        connect(frame, SIGNAL(commandTriggered(QString, QString)), SLOT(onPeerCommandTriggered(QString, QString)));
    }
}

void SessionWindow::setPeerStatus(QString peer, QString registered)
{
    addPeer(peer);

    peers[peer]->setStatus(registered == "Registered");
}

void SessionWindow::setPeerAddress(QString peer, QString ipAddress)
{
    addPeer(peer);

    peers[peer]->setAddress(ipAddress);
}

void SessionWindow::addChannel(QString channel, int duration)
{
    QString peer = parsePeer(channel);

    addPeer(peer);

    peers[peer]->addChannel(channel, duration);
}

void SessionWindow::setChannelState(QString channel, QString state)
{
    addChannel(channel);

    peers[parsePeer(channel)]->setChannelState(channel, state);
}

void SessionWindow::setChannelExtension(QString channel, QString extension)
{
    addChannel(channel);

    peers[parsePeer(channel)]->setChannelExtension(channel, extension);
}

void SessionWindow::removeChannel(QString channel)
{
    QString peer = parsePeer(channel);

    if (peer.contains(peer))
        peers[peer]->removeChannel(channel);
}

void SessionWindow::onAsteriskConnected(QString version)
{
    actions["Login"] = asterisk.actionLogin(username, password);
}

void SessionWindow::onAsteriskResponseSent(AsteriskManager::Response response, QVariantMap headers, QString actionId)
{
    if (actionId == actions.value("Login")) {
        switch (response) {
        case AsteriskManager::Success:
            actions.remove("Login");
            actions["Status"] = asterisk.action("Status");
            actions["SIPpeers"] = asterisk.action("SIPpeers");

            break;
        case AsteriskManager::Error:
            QMessageBox::warning(this, "Asterisk Manager", headers["Message"].toString());

            ((QWidget *) parent())->close();

            break;
        }
    }
}

void SessionWindow::onAsteriskEventGenerated(AsteriskManager::Event event, QVariantMap headers)
{
    QString actionId = headers["ActionID"].toString(),
            channel = headers["Channel"].toString(),
            peer = headers["Peer"].toString(),
            state = headers[headers.contains("State") ? "State" : "ChannelStateDesc"].toString(),
            address = headers["Address"].toString(),
            extension = headers["Extension"].toString();

    if (address.isEmpty()) {
        if (headers.contains("IPaddress"))
            address = QString("%1:%2").arg(headers["IPaddress"].toString(), headers["IPport"].toString());
    }

    if (extension.isEmpty()) {
        if (headers.contains("ConnectedLineNum")) {
            extension = headers["ConnectedLineNum"].toString();

            if (extension.isEmpty())
                extension = headers["ConnectedLineName"].toString();
        }
    }

    switch (event) {
    case AsteriskManager::PeerEntry:
        if (actionId == actions.value("SIPpeers"))
            peer = QString("%1/%2").arg(headers["Channeltype"].toString(), headers["ObjectName"].toString());

        if (!address.isEmpty()) {
            if (localAddress.contains(address))
                selfPeer = peer;

            if (!address.startsWith("-none-")) {
                setPeerStatus(peer, "Registered");
                setPeerAddress(peer, address);
            }
        }

        addPeer(peer);

        break;
    case AsteriskManager::PeerStatus:
        if (headers.contains("PeerStatus")) {
            QString peerStatus = headers["PeerStatus"].toString();

            if (peerStatus == "Unregistered")
                peers[peer]->setAddress(QString());

            setPeerStatus(peer, peerStatus);
            setPeerAddress(peer, peerStatus == "Unregistered" ? QString() : address);
        }

        break;
    case AsteriskManager::Status:
        addChannel(channel, headers["Seconds"].toInt());
        setChannelState(channel, state);

        if (!extension.isEmpty())
            setChannelExtension(channel, extension);

        break;
    case AsteriskManager::Newchannel:
        addChannel(channel);
        break;
    case AsteriskManager::Newstate:
        setChannelState(channel, state);

        if (!extension.isEmpty())
            setChannelExtension(channel, extension);

        break;
    case AsteriskManager::Newexten:
        setChannelExtension(channel, extension);
        break;
    case AsteriskManager::Hangup:
        removeChannel(channel);
        break;
    case AsteriskManager::StatusComplete:
        takeAction("Status", actionId);
        break;
    case AsteriskManager::PeerlistComplete:
        takeAction("SIPpeers", actionId);
        break;
    }
}

void SessionWindow::onPeerCommandTriggered(QString channel, QString command)
{
    if (command == "Listen" || command == "Whisper") {
        QString data = QString("%1,bq%2").arg(channel, command == "Whisper" ? "w" : QString());

        qDebug() << "Self Peer:" << selfPeer;

        asterisk.actionOriginate("SIP/1002", QString(), "default", 0, "ExtenSpy", data, 0, command);
    } else if (command == "Hangup") {
        asterisk.actionHangup(channel);
    }
}
