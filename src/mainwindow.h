#ifndef ASTCHANMON_H
#define ASTCHANMON_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>

#include "asthostform.h"

namespace Ui {
    class AstChanMon;
}

class AstChanMon : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_actionFullscreen_triggered(bool checked = false);
    void on_actionMainToolbar_triggered(bool checked = false);
    void on_actionStatusbar_triggered(bool checked = false);
    void on_actionAbout_triggered();
    void on_actionConnection_triggered(bool checked = false);
    void onActiveCountsChanged(int activeChannels, int activeCalls);

public:
    explicit AstChanMon(QWidget *parent = 0);
    ~AstChanMon();

private:
    Ui::AstChanMon *ui;

    QFlags<Qt::WindowState> lastWindowState;
    QLabel hostLabel, usernameLabel, secretLabel, channelsLabel, callsLabel, channelsCount, callsCount;
    QLineEdit hostEntry, usernameEntry, secretEntry;
    QSpinBox portEntry;
    AstHostForm *astHostForm;
};

#endif // ASTCHANMON_H
