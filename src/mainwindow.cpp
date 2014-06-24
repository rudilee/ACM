#include <QMessageBox>

#include "astchanmon.h"
#include "ui_astchanmon.h"

AstChanMon::AstChanMon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AstChanMon)
{
    astHostForm = new AstHostForm(this);

    ui->setupUi(this);
    ui->actionMainToolbar->setChecked(true);
    ui->actionStatusbar->setChecked(true);
    ui->mainToolBar->insertWidget(ui->actionConnection, &hostLabel);
    ui->mainToolBar->insertWidget(ui->actionConnection, new QLabel(" "));
    ui->mainToolBar->insertWidget(ui->actionConnection, &hostEntry);
    ui->mainToolBar->insertWidget(ui->actionConnection, new QLabel(" : "));
    ui->mainToolBar->insertWidget(ui->actionConnection, &portEntry);
    ui->mainToolBar->insertWidget(ui->actionConnection, new QLabel(" "));
    ui->mainToolBar->insertWidget(ui->actionConnection, &usernameLabel);
    ui->mainToolBar->insertWidget(ui->actionConnection, new QLabel(" "));
    ui->mainToolBar->insertWidget(ui->actionConnection, &usernameEntry);
    ui->mainToolBar->insertWidget(ui->actionConnection, new QLabel(" "));
    ui->mainToolBar->insertWidget(ui->actionConnection, &secretLabel);
    ui->mainToolBar->insertWidget(ui->actionConnection, new QLabel(" "));
    ui->mainToolBar->insertWidget(ui->actionConnection, &secretEntry);
    ui->mainToolBar->insertWidget(ui->actionConnection, new QLabel(" "));

    ui->statusBar->insertWidget(0, &channelsLabel);
    ui->statusBar->insertWidget(1, &channelsCount);
    ui->statusBar->insertWidget(2, &callsLabel);
    ui->statusBar->insertWidget(3, &callsCount);

    hostLabel.setPixmap(QPixmap(":/toolbar/host"));
    hostEntry.setFixedWidth(150);
    portEntry.setFixedWidth(60);
    portEntry.setMinimum(2000);
    portEntry.setMaximum(20000);
    portEntry.setValue(5038);
    usernameLabel.setPixmap(QPixmap(":/toolbar/username"));
    usernameEntry.setFixedWidth(100);
    secretLabel.setPixmap(QPixmap(":/toolbar/secret"));
    secretEntry.setFixedWidth(100);
    secretEntry.setEchoMode(QLineEdit::Password);

    channelsLabel.setPixmap(QPixmap(":/statusbar/active_channels"));
    channelsCount.setText("0 Channels");
    callsLabel.setPixmap(QPixmap(":/statusbar/active_calls"));
    callsCount.setText("0 Calls");

    setCentralWidget(astHostForm);

    connect(astHostForm, SIGNAL(changeActiveCounts(int,int)), this, SLOT(onActiveCountsChanged(int,int)));
}

AstChanMon::~AstChanMon()
{
    delete ui;
}

void AstChanMon::on_actionFullscreen_triggered(bool checked)
{
    if (checked) {
        lastWindowState = windowState();

        showFullScreen();
    } else {
        setWindowState(lastWindowState);
    }
}

void AstChanMon::on_actionMainToolbar_triggered(bool checked)
{
    if (checked) {
        ui->mainToolBar->show();
    } else {
        ui->mainToolBar->hide();
    }
}

void AstChanMon::on_actionStatusbar_triggered(bool checked)
{
    if (checked)  {
        ui->statusBar->show();
    } else {
        ui->statusBar->hide();
    }
}

void AstChanMon::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "<b>Asterisk Channel Monitor</b><br>"
                       "Asterisk&trade; IPPBX channels activities & Call Data Record(CDR) live monitor tool.<br>"
                       "<br>Developed by <i>KAMPRETAN Labs</i>.<br>"
                       "website: <a href=\"http://it.dnn.co.id\">http://it.dnn.co.id</a><br>"
                       "email: <a href=\"mailto:it@dnn.co.id\">it@dnn.co.id</a><br>"
                       "Copyright &copy; 2010 PT. Delta Nuansa Nirwana.");
}

void AstChanMon::on_actionConnection_triggered(bool checked)
{
    if (checked) {
        astHostForm->connectServer(hostEntry.text(), portEntry.value(), usernameEntry.text(), secretEntry.text());
    } else {
        astHostForm->disconnectServer();
    }

    ui->actionConnection->setText(checked ? "Disconnect" : "Connect");
}

void AstChanMon::onActiveCountsChanged(int activeChannels, int activeCalls)
{
    channelsCount.setText(QVariant(activeChannels).toString().append(" Channels"));
    callsCount.setText(QVariant(activeCalls).toString().append(" Calls"));
}
