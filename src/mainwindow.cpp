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
    hostname(new QLineEdit),
    username(new QLineEdit),
    password(new QLineEdit),
    port(new QSpinBox),
    quickConnect(new QPushButton("Quick Connect")),
    sessionArea(new QMdiArea(this))
{
    ui->setupUi(this);

    setWindowTitle(QApplication::applicationName());
    setCentralWidget(sessionArea);
    setupToolbar();
    populateSession();

    connect(sessionManagerButton, SIGNAL(clicked()), SLOT(showSessionManager()));
    connect(sessionArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), SLOT(onSubWindowActivated(QMdiSubWindow*)));
    connect(sessionManagerMenu, SIGNAL(triggered(QAction*)), SLOT(onSessionMenuTriggered(QAction*)));
    connect(quickConnect, SIGNAL(clicked()), SLOT(onQuickConnectClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupToolbar()
{
    sessionManagerButton->setParent(ui->mainToolBar);
    sessionManagerButton->setIcon(QIcon(":/dialog/session manager"));
    sessionManagerButton->setPopupMode(QToolButton::MenuButtonPopup);
    sessionManagerButton->setMenu(sessionManagerMenu);
    sessionManagerButton->setToolTip("Session Manager");

    hostname->setParent(ui->mainToolBar);
    hostname->setPlaceholderText("Asterisk hostname");
    hostname->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    port->setParent(ui->mainToolBar);
    port->setMaximum(65000);
    port->setValue(5038);
    port->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    username->setParent(ui->mainToolBar);
    username->setPlaceholderText("AMI username");
    username->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    password->setParent(ui->mainToolBar);
    password->setPlaceholderText("AMI secret");
    password->setEchoMode(QLineEdit::Password);
    password->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    quickConnect->setParent(ui->mainToolBar);
    quickConnect->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    ui->mainToolBar->addWidget(sessionManagerButton);
    ui->mainToolBar->addAction(ui->actionCloseSession);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(hostname);
    ui->mainToolBar->addWidget(port);
    ui->mainToolBar->addWidget(username);
    ui->mainToolBar->addWidget(password);
    ui->mainToolBar->addWidget(quickConnect);

    QWidget *spacer = new QWidget(ui->mainToolBar);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    ui->mainToolBar->addWidget(spacer);
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

void MainWindow::onQuickConnectClicked()
{
    openSessionWindow(hostname->text().prepend("Quick Connect: "), hostname->text(), port->value(), username->text(), password->text());
}

void MainWindow::on_actionCloseSession_triggered()
{
    QMdiSubWindow *window = sessionArea->currentSubWindow();
    if (window != 0)
        window->close();
}
