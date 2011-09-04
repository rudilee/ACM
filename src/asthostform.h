#ifndef ASTHOSTFORM_H
#define ASTHOSTFORM_H

#include <QWidget>
#include <QStandardItemModel>

#include "astmaniface.h"
#include "astchanform.h"
#include "flowlayout.h"

namespace Ui {
    class AstHostForm;
}

class AstHostForm : public QWidget {
    Q_OBJECT

public slots:
    void onConnectionTriggered(bool checked = false);

private slots:
    void onEventReceived(QString subject, QHash<QString, QString> parameters);
    void onResponseReceived(QString subject, QHash<QString, QString> parameters);

public:
    AstHostForm(QWidget *parent = 0);
    ~AstHostForm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AstHostForm *ui;

    QStandardItemModel cdrModel;
    AstManIface amiSocket;
    QHash<QString, AstChanForm *> astChanForms;
    FlowLayout *channelsFormsLayout;
    FlowLayout *dahdiFormsLayout;

    void setupDahdi();
    void newAstChanForm(QString channel);
    void deleteAstChanForm(QString channel);
};

#endif // ASTHOSTFORM_H
