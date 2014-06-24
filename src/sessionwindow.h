#ifndef SESSIONWINDOW_H
#define SESSIONWINDOW_H

#include "asteriskmanager.h"
#include "channelframe.h"
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
    QHash<QString, ChannelFrame *> channels;
    FlowLayout layout;

    void setup(QString hostname, quint16 port);
    void addChannel(QString channel, QString duration);
    void removeChannel(QString channel);

private slots:
    void onAsteriskConnected();
    void onAsteriskReceiveResponse(Asterisk::Response response, QHash<QString, QString> headers);
    void onAsteriskReceiveEvent(Asterisk::Event event, QHash<QString, QString> headers);
};

#endif // SESSIONWINDOW_H
