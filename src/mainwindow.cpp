#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStringList header;

    ui->setupUi(this);
    ui->cdrTableView->setModel(&cdrModel);

    header << "Privilege" << "Fullname" << "Account Code" << "Source" << "Status" << "Destination" << "Destination Context"
            << "Caller ID" << "Channel" << "Destination Channel" << "Last Application" << "Last Data" << "Start Time"
            << "Answer Time" << "End Time" << "Duration" << "Billable Seconds" << "Disposition" << "AMA Flags"
            << "Unique ID" << "User Field";

    cdrModel.setHorizontalHeaderLabels(header);

    connect(&amiSocket, SIGNAL(ResponseEvent(QString,QHash<QString,QString>)), this, SLOT(onResponseEvent(QString,QHash<QString,QString>)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnection_triggered()
{
    if (ui->actionConnection->isChecked()) {
        amiSocket.ActionLogin("192.168.10.2", 5038, "umbrus", "kampret");
    } else {
        amiSocket.ActionLogoff();
    }
}

void MainWindow::onResponseEvent(QString subject, QHash<QString, QString> parameters)
{
    if (subject == "Cdr") {
        QHashIterator<QString, QString> iter(parameters);
        QList<QStandardItem *> cdrList;

        while (iter.hasNext()) {
            iter.next();

            cdrList << new QStandardItem(iter.value());
        }

        cdrModel.appendRow(cdrList);
    }
}
