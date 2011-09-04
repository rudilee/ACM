#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "astmaniface.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_actionConnection_triggered();

    void onResponseEvent(QString subject, QHash<QString, QString> parameters);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QStandardItemModel cdrModel;
    AstManIface amiSocket;
};

#endif // MAINWINDOW_H
