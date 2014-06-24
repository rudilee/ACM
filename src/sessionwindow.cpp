#include "asthostform.h"
#include "ui_asthostform.h"

AstHostForm::AstHostForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AstHostForm)
{
    activeChannels = 0;
    activeCalls = 0;

    setupWidget();
    setupSocket();
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

void AstHostForm::connectServer(QString host, int port, QString username, QString password)
{
    amiSocket.ActionLogin(host, port, username, password);
}

void AstHostForm::disconnectServer()
{
    amiSocket.ActionLogoff();

    activeChannels = 0;
    activeCalls = 0;

    refreshCounts();
}

void AstHostForm::onEventReceived(QString event, QHash<QString, QString> parameters)
{
    AstChanForm *astChanForm;

    if (event == "Cdr") {
        QList<QStandardItem *> cdrList;

        cdrList /*<< new QStandardItem(parameters["Privilege"]) << new QStandardItem(parameters["Fullname"]) << new QStandardItem(parameters["AccountCode"])*/
                 << new QStandardItem(parameters["Source"]) /*<< new QStandardItem(parameters["Status"])*/ << new QStandardItem(parameters["Destination"])
                 << new QStandardItem(parameters["DestinationContext"]) << new QStandardItem(parameters["CallerID"]) << new QStandardItem(parameters["Channel"])
                 << new QStandardItem(parameters["DestinationChannel"]) << new QStandardItem(parameters["LastApplication"]) << new QStandardItem(parameters["LastData"])
                 << new QStandardItem(parameters["StartTime"]) << new QStandardItem(parameters["AnswerTime"]) << new QStandardItem(parameters["EndTime"])
                 << new QStandardItem(parameters["Duration"]) << new QStandardItem(parameters["BillableSeconds"]) << new QStandardItem(parameters["Disposition"])
                 /*<< new QStandardItem(parameters["AMAFlags"])*/ << new QStandardItem(parameters["UniqueID"]) /*<< new QStandardItem(parameters["UserField"])*/;

        if (cdrModel.rowCount() == 30) {
            cdrModel.takeRow(29);
        }

        cdrModel.insertRow(0, cdrList);
    } else if (event == "Status") {
        astChanForm = newAstChanForm(parameters["Uniqueid"]);

        astChanForm->setLabel(0, parameters["Channel"]);
        astChanForm->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForm->setLabel(2, parameters["Context"].isEmpty() ? "..." : parameters["Context"]);
        astChanForm->setLabel(3, parameters["Extension"].isEmpty() ? "..." : parameters["Extension"].append(",").append(parameters["Priority"]));
        astChanForm->setLabel(5, parameters["State"]);
        astChanForm->setLabel(6, parameters["Uniqueid"]);
    } else if (event == "Newcallerid") {
        astChanForm = newAstChanForm(parameters["Uniqueid"]);

        astChanForm->setLabel(0, parameters["Channel"]);
        astChanForm->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForm->setLabel(6, parameters["Uniqueid"]);
    } else if (event == "Newchannel") {
        astChanForm = newAstChanForm(parameters["Uniqueid"]);

        astChanForm->setLabel(0, parameters["Channel"]);
        astChanForm->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForm->setLabel(5, parameters["State"]);
        astChanForm->setLabel(6, parameters["Uniqueid"]);

        activeChannels++;
        refreshCounts();
    } else if (event == "Newexten") {
        astChanForm = newAstChanForm(parameters["Uniqueid"]);

        astChanForm->setLabel(0, parameters["Channel"]);
        astChanForm->setLabel(2, parameters["Context"]);
        astChanForm->setLabel(3, parameters["Extension"].append(",").append(parameters["Priority"]).append(",").append(parameters["Application"]).append("()"));
        astChanForm->setLabel(4, parameters["AppData"]);
        astChanForm->setLabel(6, parameters["Uniqueid"]);
    } else if (event == "Newstate") {
        astChanForm = newAstChanForm(parameters["Uniqueid"]);

        astChanForm->setLabel(0, parameters["Channel"]);
        astChanForm->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForm->setLabel(5, parameters["State"]);
        astChanForm->setLabel(6, parameters["Uniqueid"]);
    } else if (event == "Dial") {
        astChanForm = newAstChanForm(parameters["Uniqueid"]);

        astChanForm->setLabel(0, parameters["Source"]);
        astChanForm->setLabel(1, parameters["CallerID"].append(" ").append(parameters["CallerIDName"]));
        astChanForm->setLabel(5, parameters["State"]);
        astChanForm->setLabel(6, parameters["Uniqueid"]);

        if (parameters["Uniqueid"].isEmpty()) {
            deleteAstChanForm(parameters["Uniqueid"]);
        }
    } else if (event == "Link") {
        activeCalls++;
        refreshCounts();
    } else if (event == "Unlink") {
        if (activeCalls > 0) {
            activeCalls--;
            refreshCounts();
        }
    } else if (event == "Hangup") {
        deleteAstChanForm(parameters["Uniqueid"]);

        if (activeChannels > 0) {
            activeChannels--;
            refreshCounts();
        }
    }/* else {
        qDebug("<++");
        qDebug(event.toLatin1().data());
        qDebug(parameters["Uniqueid"].toLatin1().data());
        qDebug("++>");
    }*/

    astChanForm = NULL;
}

void AstHostForm::onResponseReceived(QString response, QHash<QString, QString> parameters)
{
    if (response == "Success") {
        if (parameters["Message"] == "Authentication accepted") {
            amiSocket.ActionStatus("", "ListChannels");
            amiSocket.ActionCommand("show channels", "ShowChannels");
        }
    } else if (response == "Error") {
        if (parameters["Message"] == "Authentication failed") {
            amiSocket.disconnectFromHost();
        }
    } else if (response == "Follows") {
        activeChannels = parameters["ActiveChannels"].toInt();
        activeCalls = parameters["ActiveCalls"].toInt();

        refreshCounts();
    } else if (response == "Goodbye") {
        QHashIterator<QString, AstChanForm *> astChanForm(astChanForms);

        while (astChanForm.hasNext()) {
            astChanForm.next();

            channelsFormsLayout->removeWidget(astChanForm.value());

            delete astChanForm.value();
            astChanForms.remove(astChanForm.key());
        }
    }
}

void AstHostForm::setupWidget()
{
    QStringList header;

    channelsFormsLayout = new FlowLayout();

    ui->setupUi(this);
    ui->cdrTableView->setModel(&cdrModel);
    ui->channelsAreaWidgetContents->setLayout(channelsFormsLayout);

    header /*<< "Privilege" << "Fullname" << "Account Code"*/ << "Source" /*<< "Status"*/ << "Destination" << "Destination Context"
            << "Caller ID" << "Channel" << "Destination Channel" << "Last Application" << "Last Data" << "Start Time"
            << "Answer Time" << "End Time" << "Duration" << "Billable Seconds" << "Disposition" /*<< "AMA Flags"*/
            << "Unique ID" /*<< "User Field"*/;

    cdrModel.setHorizontalHeaderLabels(header);
}

void AstHostForm::setupSocket()
{
    connect(&amiSocket, SIGNAL(ReceiveEvent(QString,QHash<QString,QString>)), this, SLOT(onEventReceived(QString,QHash<QString,QString>)));
    connect(&amiSocket, SIGNAL(ReceiveResponse(QString,QHash<QString,QString>)), this, SLOT(onResponseReceived(QString,QHash<QString,QString>)));
}

AstChanForm *AstHostForm::newAstChanForm(QString uniqueid)
{
    if (!astChanForms.contains(uniqueid)) {
        astChanForms[uniqueid] = new AstChanForm(this);

        channelsFormsLayout->addWidget(astChanForms[uniqueid]);
    }

    if (astChanForms.contains(uniqueid)) {
        return astChanForms[uniqueid];
    } else {
        return NULL;
    }
}

void AstHostForm::deleteAstChanForm(QString uniqueid)
{
    if (astChanForms.contains(uniqueid)) {
        channelsFormsLayout->removeWidget(astChanForms[uniqueid]);

        delete astChanForms[uniqueid];
        astChanForms.remove(uniqueid);
    }
}

void AstHostForm::refreshCounts()
{
    emit changeActiveCounts(activeChannels, activeCalls);
}
