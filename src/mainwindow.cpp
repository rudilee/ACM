#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sessionmanagerdialog.h"
#include "sessionwindow.h"

#include <QSettings>
#include <QMdiSubWindow>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sessionManagerButton(new QToolButton),
    sessionManagerMenu(new QMenu),
    sessionArea(new QMdiArea(this))
{
    ui->setupUi(this);

    setup();

    connect(sessionManagerButton, SIGNAL(clicked()), SLOT(showSessionManager()));
    connect(sessionArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), SLOT(onSubWindowActivated(QMdiSubWindow*)));
    connect(sessionManagerMenu, SIGNAL(triggered(QAction*)), SLOT(onSessionMenuTriggered(QAction*)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sessionManagerMenu;
}

void MainWindow::setup()
{
    setWindowTitle(QApplication::applicationName());

    sessionManagerButton->setParent(ui->mainToolBar);
    sessionManagerButton->setIcon(QIcon(":/dialog/session manager"));
    sessionManagerButton->setPopupMode(QToolButton::MenuButtonPopup);
    sessionManagerButton->setMenu(sessionManagerMenu);

    ui->mainToolBar->addWidget(sessionManagerButton);
    ui->mainToolBar->addAction(ui->actionCloseSession);

    setCentralWidget(sessionArea);
    populateSession();
    showSessionManager();
}

void MainWindow::populateSession()
{
    QSettings settings;
    int size = settings.beginReadArray("sessions");

    QMdiSubWindow *window = sessionArea->currentSubWindow();
    QString name = (window != 0 ? window->windowTitle() : "");

    sessionManagerMenu->clear();

    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);

        QAction *action = sessionManagerMenu->addAction(settings.value("name").toString());
        action->setCheckable(true);
        action->setChecked(action->text() == name);
    }

    settings.endArray();
}

void MainWindow::openSessionWindow(QString name, QString hostname, quint16 port, QString username, QString password)
{
    foreach (QMdiSubWindow *subWindow, sessionArea->subWindowList()) {
        if (subWindow->windowTitle() == name) {
            subWindow->showMaximized();
            subWindow->raise();

            return;
        }
    }

    SessionWindow *sessionWindow = new SessionWindow(this, hostname, port, username, password);
    sessionArea->addSubWindow(sessionWindow);

    sessionWindow->setWindowTitle(name);
    sessionWindow->showMaximized();
}

void MainWindow::showSessionManager()
{
    SessionManagerDialog sessionManager(this);
    if (sessionManager.exec() == QDialog::Accepted) {
        openSessionWindow(sessionManager.getName(),
                          sessionManager.getHostname(),
                          sessionManager.getPort(),
                          sessionManager.getUsername(),
                          sessionManager.getPassword());
    }

    populateSession();
}

void MainWindow::onSubWindowActivated(QMdiSubWindow *window)
{
    QString name = (window != 0 ? window->windowTitle() : "");

    foreach (QAction *action, sessionManagerMenu->actions()) {
        action->setChecked(action->text() == name);
    }
}

void MainWindow::onSessionMenuTriggered(QAction *action)
{
    QSettings settings;
    QString name = action->text();

    int size = settings.beginReadArray("sessions");
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);

        if (settings.value("name").toString() == name) {
            openSessionWindow(name,
                              settings.value("hostname").toString(),
                              settings.value("port").toUInt(),
                              settings.value("username").toString(),
                              settings.value("password").toString());

            break;
        }
    }

    settings.endArray();
}

void MainWindow::on_actionCloseSession_triggered()
{
    QMdiSubWindow *window = sessionArea->currentSubWindow();
    if (window != 0)
        window->close();
}
