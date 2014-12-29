#include "sessionmanagerdialog.h"
#include "ui_sessionmanagerdialog.h"

#include <QDebug>

SessionManagerDialog::SessionManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SessionManagerDialog)
{
    ui->setupUi(this);
    ui->pages->setCurrentIndex(0);

    connect(ui->sessions, SIGNAL(doubleClicked(QModelIndex)), SLOT(accept()));

    loadSessions();
}

SessionManagerDialog::~SessionManagerDialog()
{
    delete ui;
}

QString SessionManagerDialog::getName()
{
    return ui->sessions->currentItem()->text();
}

QString SessionManagerDialog::getHostname()
{
    return sessions.value(ui->sessions->currentItem()->text()).hostname;
}

quint16 SessionManagerDialog::getPort()
{
    return sessions.value(ui->sessions->currentItem()->text()).port;
}

QString SessionManagerDialog::getUsername()
{
    return sessions.value(ui->sessions->currentItem()->text()).username;
}

QString SessionManagerDialog::getPassword()
{
    return sessions.value(ui->sessions->currentItem()->text()).password;
}

void SessionManagerDialog::loadSessions()
{
    int size = settings.beginReadArray("sessions");

    ui->sessions->clear();

    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);

        QString name = settings.value("name").toString();
        Session session = {
            settings.value("hostname").toString(),
            settings.value("port").toUInt(),
            settings.value("username").toString(),
            settings.value("password").toString() // TODO: decrypt password
        };

        sessions[name] = session;

        ui->sessions->addItem(name);
    }

    settings.endArray();
}

void SessionManagerDialog::saveSessions()
{
    settings.remove("sessions");
    settings.beginWriteArray("sessions");

    int i = 0;

    QHashIterator<QString, Session> session(sessions);
    while (session.hasNext()) {
        session.next();

        settings.setArrayIndex(i++);
        settings.setValue("name", session.key());
        settings.setValue("hostname", session.value().hostname);
        settings.setValue("port", session.value().port);
        settings.setValue("username", session.value().username);
        settings.setValue("password", session.value().password); // TODO: encrypt password
    }

    settings.endArray();
}

void SessionManagerDialog::on_newSession_clicked()
{
    ui->name->clear();
    ui->hostname->clear();
    ui->port->setValue(5038);
    ui->username->clear();
    ui->password->clear();

    ui->pages->setCurrentIndex(1);
}

void SessionManagerDialog::on_editSession_clicked()
{
    QString name = ui->sessions->currentItem()->text();
    if (!name.isEmpty()) {
        Session session = sessions.value(name);

        ui->name->setText(name);
        ui->hostname->setText(session.hostname);
        ui->port->setValue(session.port);
        ui->username->setText(session.username);
        ui->password->setText(session.password);

        ui->pages->setCurrentIndex(1);
    }
}

void SessionManagerDialog::on_deleteSession_clicked()
{
    if (sessions.remove(ui->sessions->currentItem()->text()) > 0) {
        ui->sessions->takeItem(ui->sessions->currentRow());

        saveSessions();
    }
}

void SessionManagerDialog::on_saveSession_clicked()
{
    sessions[ui->name->text()] = {
        ui->hostname->text(),
        ui->port->value(),
        ui->username->text(),
        ui->password->text()
    };

    saveSessions();
    loadSessions();

    ui->pages->setCurrentIndex(0);
}

void SessionManagerDialog::on_cancel_clicked()
{
    ui->pages->setCurrentIndex(0);
}
