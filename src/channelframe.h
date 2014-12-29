#ifndef CHANNELFRAME_H
#define CHANNELFRAME_H

#include <QFrame>

namespace Ui {
class ChannelFrame;
}

class ChannelFrame : public QFrame
{
    Q_OBJECT

    Q_ENUMS(State)

public:
    enum State {
        Down,
        Rsrvd,
        Dialing = 3,
        Ring = 4,
        Ringing = 5,
        Up = 6
    };

    explicit ChannelFrame(QWidget *parent = 0, QString channel = QString(), int duration = 0);
    ~ChannelFrame();

    QString parseChannelId(QString channel);

    void setState(QString stateText);
    void setExtension(QString extension);

private:
    Ui::ChannelFrame *ui;
    QString channel;

    void setupCommand();

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void onCommandMenuTriggered(QAction *action);

signals:
    void commandTriggered(QString command);
};

#endif // CHANNELFRAME_H
