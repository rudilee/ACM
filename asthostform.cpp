#include "asthostform.h"
#include "ui_asthostform.h"

AstHostForm::AstHostForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AstHostForm)
{
    QStringList header;

    channelsFormsLayout = new FlowLayout();
    dahdiFormsLayout = new FlowLayout();

    ui->setupUi(this);
    ui->cdrTableView->setModel(&cdrModel);
    ui->channelsAreaWidgetContents->setLayout(channelsFormsLayout);
    ui->dahdiAreaWidgetContents->setLayout(dahdiFormsLayout);

    header /*<< "Privilege" << "Fullname" << "Account Code"*/ << "Source" /*<< "Status"*/ << "Destination" << "Destination Context"
            << "Caller ID" << "Channel" << "Destination Channel" << "Last Application" << "Last Data" << "Start Time"
            << "Answer Time" << "End Time" << "Duration" << "Billable Seconds" << "Disposition" /*<< "AMA Flags"*/
            << "Unique ID" /*<< "User Field"*/;

    cdrModel.setHorizontalHeaderLabels(header);

    setupDahdi();

    connect(&amiSocket, SIGNAL(ReceiveEvent(QString,QHash<QString,QString>)), this, SLOT(onEventReceived(QString,QHash<QString,QString>)));
    connect(&amiSocket, SIGNAL(ReceiveResponse(QString,QHash<QString,QString>)), this, SLOT(onResponseReceived(QString,QHash<QString,QString>)));
}

AstHostForm::~AstHostForm()
{
    delete ui;
}

void AstHostForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void AstHostForm::onConnectionTriggered(bool checked)
{
    if (checked) {
        amiSocket.ActionLogin("192.168.11.8", 5038, "test", "kampret");
    } else {
        amiSocket.ActionLogoff();
    }
}

void AstHostForm::onEventReceived(QString event, QHash<QString, QString> parameters)
{
    if (event == "Cdr") {
        QList<QStandardItem *> cdrList;

        cdrList /*<< new QStandardItem(parameters["Privilege"]) << new QStandardItem(parameters["Fullname"]) << new QStandardItem(parameters["AccountCode"])*/
                 << new QStandardItem(parameters["Source"]) /*<< new QStandardItem(parameters["Status"])*/ << new QStandardItem(parameters["Destination"])
                 << new QStandardItem(parameters["DestinationContext"]) << new QStandardItem(parameters["CallerID"]) << new QStandardItem(parameters["Channel"])
                 << new QStandardItem(parameters["DestinationChannel"]) << new QStandardItem(parameters["LastApplication"]) << new QStandardItem(parameters["LastData"])
                 << new QStandardItem(parameters["StartTime"]) << new QStandardItem(parameters["AnswerTime"]) << new QStandardItem(parameters["EndTime"])
                 << new QStandardItem(parameters["Duration"]) << new QStandardItem(parameters["BillableSeconds"]) << new QStandardItem(parameters["Disposition"])
                 /*<< new QStandardItem(parameters["AMAFlags"])*/ << new QStandardItem(parameters["UniqueID"]) /*<< new QStandardItem(parameters["UserField"])*/;

        if (cdrModel.rowCount() == 25) {
            cdrModel.takeRow(24);
        }

        cdrModel.insertRow(0, cdrList);
    } else if (event == "Status") {
        newAstChanForm(parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(0, parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForms[parameters["Channel"]]->setLabel(2, parameters["Context"].isEmpty() ? "..." : parameters["Context"]);
        astChanForms[parameters["Channel"]]->setLabel(3, parameters["Extension"].isEmpty() ? "..." : parameters["Extension"].append(",").append(parameters["Priority"]));
        astChanForms[parameters["Channel"]]->setLabel(5, parameters["State"]);
        astChanForms[parameters["Channel"]]->setLabel(6, parameters["Uniqueid"]);
    } else if (event == "Newcallerid") {
        newAstChanForm(parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(0, parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForms[parameters["Channel"]]->setLabel(6, parameters["Uniqueid"]);
    } else if (event == "Newchannel") {
        newAstChanForm(parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(0, parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForms[parameters["Channel"]]->setLabel(5, parameters["State"]);
        astChanForms[parameters["Channel"]]->setLabel(6, parameters["Uniqueid"]);
    } else if (event == "Newexten") {
        newAstChanForm(parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(0, parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(2, parameters["Context"]);
        astChanForms[parameters["Channel"]]->setLabel(3, parameters["Extension"].append(",").append(parameters["Priority"]).append(",").append(parameters["Application"]).append("()"));
        astChanForms[parameters["Channel"]]->setLabel(4, parameters["AppData"]);
        astChanForms[parameters["Channel"]]->setLabel(6, parameters["Uniqueid"]);
    } else if (event == "Newstate") {
        newAstChanForm(parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(0, parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForms[parameters["Channel"]]->setLabel(5, parameters["State"]);
        astChanForms[parameters["Channel"]]->setLabel(6, parameters["Uniqueid"]);
    } else if (event == "Rename") {
        //
    } else if (event == "Dial") {
        newAstChanForm(parameters["Channel"]);
        astChanForms[parameters["Channel"]]->setLabel(0, parameters["Source"]);
        astChanForms[parameters["Channel"]]->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForms[parameters["Channel"]]->setLabel(6, parameters["Uniqueid"]);

        if (parameters["Uniqueid"].isEmpty()) {
            deleteAstChanForm(parameters["Channel"]);
        }
    } else if (event == "Link") {
        // Nothing To Do.. (Yet :P)
    } else if (event == "Unlink") {
        // Nothing To Do too.. (Yet :P)
    } else if (event == "Hangup") {
        deleteAstChanForm(parameters["Channel"]);
    }
}

void AstHostForm::onResponseReceived(QString response, QHash<QString, QString> parameters)
{
    if (response == "Success") {
        if (parameters["Message"] == "Authentication accepted") {
            amiSocket.ActionStatus("", "ListChannels");
        }
    } else if (response == "Error") {
        if (parameters["Message"] == "Authentication failed") {
            amiSocket.disconnectFromHost();
        }
    } else if (response == "Goodbye") {
        QHashIterator<QString, AstChanForm *> astChanForm(astChanForms);

        while (astChanForm.hasNext()) {
            astChanForm.next();

            if (astChanForm.key().startsWith("Zap")) {
                astChanForm.value()->setLabel(1, "...");
                astChanForm.value()->setLabel(2, "...");
                astChanForm.value()->setLabel(3, "...");
                astChanForm.value()->setLabel(5, "Clear");
                astChanForm.value()->setLabel(6, "...");
            } else {
                channelsFormsLayout->removeWidget(astChanForm.value());

                delete astChanForm.value();
                astChanForms.remove(astChanForm.key());
            }
        }
    }
}

void AstHostForm::setupDahdi()
{
    QString channel;

    for (int i = 1; i < 16; i++) {
        channel = QString("Zap/").append(QVariant(i).toString().append("-1"));
        astChanForms[channel] = new AstChanForm(this);
        astChanForms[channel]->setLabel(0, channel);

        dahdiFormsLayout->addWidget(astChanForms[channel]);
    }

    for (int i = 17; i < 32; i++) {
        channel = QString("Zap/").append(QVariant(i).toString().append("-1"));
        astChanForms[channel] = new AstChanForm(this);
        astChanForms[channel]->setLabel(0, channel);

        dahdiFormsLayout->addWidget(astChanForms[channel]);
    }

    for (int i = 32; i < 47; i++) {
        channel = QString("Zap/").append(QVariant(i).toString().append("-1"));
        astChanForms[channel] = new AstChanForm(this);
        astChanForms[channel]->setLabel(0, channel);

        dahdiFormsLayout->addWidget(astChanForms[channel]);
    }

    for (int i = 48; i < 63; i++) {
        channel = QString("Zap/").append(QVariant(i).toString().append("-1"));
        astChanForms[channel] = new AstChanForm(this);
        astChanForms[channel]->setLabel(0, channel);

        dahdiFormsLayout->addWidget(astChanForms[channel]);
    }
}

void AstHostForm::newAstChanForm(QString channel)
{
    if (channel.startsWith("Zap")) {
        return;
    }

    if (!astChanForms.contains(channel)) {
        astChanForms[channel] = new AstChanForm(this);

        channelsFormsLayout->addWidget(astChanForms[channel]);
    }
}

void AstHostForm::deleteAstChanForm(QString channel)
{
    if (astChanForms.contains(channel)) {
        if (channel.startsWith("Zap")) {
            astChanForms[channel]->setLabel(1, "...");
            astChanForms[channel]->setLabel(2, "...");
            astChanForms[channel]->setLabel(3, "...");
            astChanForms[channel]->setLabel(5, "Clear");
            astChanForms[channel]->setLabel(6, "...");
            return;
        }

        channelsFormsLayout->removeWidget(astChanForms[channel]);

        delete astChanForms[channel];
        astChanForms.remove(channel);
    }
}
