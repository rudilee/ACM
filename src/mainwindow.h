#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
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
    QLineEdit *hostname, *username, *password;
    QSpinBox *port;
    QPushButton *quickConnect;
    QMdiArea *sessionArea;

    void setupToolbar();
    void populateSession();
    void openSessionWindow(QString name, QString hostname = "", quint16 port = 0, QString username = "", QString password = "");

private slots:
    void showSessionManager();

    void onSubWindowActivated(QMdiSubWindow *window);
    void onSessionMenuTriggered(QAction *action);
    void onQuickConnectClicked();

    void on_actionCloseSession_triggered();
};

#endif // MAINWINDOW_H
