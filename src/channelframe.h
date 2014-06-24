#ifndef CHANNELFRAME_H
#define CHANNELFRAME_H

#include <QFrame>

namespace Ui {
class ChannelFrame;
}

class ChannelFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ChannelFrame(QWidget *parent = 0, QString channel = "", QString duration = "");
    ~ChannelFrame();

    void setState(int state, QString description);

private:
    Ui::ChannelFrame *ui;
    QString channel;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // CHANNELFRAME_H
