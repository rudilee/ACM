#ifndef ASTCHANMON_H
#define ASTCHANMON_H

#include <QMainWindow>

#include "asthostform.h"

namespace Ui {
    class AstChanMon;
}

class AstChanMon : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_actionConnection_triggered(bool checked = false);

public:
    explicit AstChanMon(QWidget *parent = 0);
    ~AstChanMon();

private:
    Ui::AstChanMon *ui;

    AstHostForm *astHostForm;
};

#endif // ASTCHANMON_H
