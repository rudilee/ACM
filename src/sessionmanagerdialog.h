#ifndef SESSIONMANAGERDIALOG_H
#define SESSIONMANAGERDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class SessionManagerDialog;
}

class SessionManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SessionManagerDialog(QWidget *parent = 0);
    ~SessionManagerDialog();

    QString getName();
    QString getHostname();
    quint16 getPort();
    QString getUsername();
    QString getPassword();

private:
    Ui::SessionManagerDialog *ui;
    QSettings settings;

    struct Session {
        QString hostname;
        quint16 port;
        QString username;
        QString password;
    };
    QHash<QString, Session> sessions;

    void loadSessions();
    void saveSessions();

private slots:
    void on_newSession_clicked();
    void on_editSession_clicked();
    void on_deleteSession_clicked();
    void on_saveSession_clicked();
    void on_cancel_clicked();
};

#endif // SESSIONMANAGERDIALOG_H
