#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QMdiArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QToolButton *sessionManagerButton;
    QMenu *sessionManagerMenu;
    QMdiArea *sessionArea;

    void setup();
    void populateSession();
    void openSessionWindow(QString name, QString hostname = "", quint16 port = 0, QString username = "", QString password = "");

private slots:
    void showSessionManager();

    void onSubWindowActivated(QMdiSubWindow *window);
    void onSessionMenuTriggered(QAction *action);

    void on_actionCloseSession_triggered();
};

#endif // MAINWINDOW_H
