#include "astchanmon.h"
#include "ui_astchanmon.h"

AstChanMon::AstChanMon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AstChanMon)
{
    astHostForm = new AstHostForm(this);

    ui->setupUi(this);
    ui->mdiArea->addSubWindow(astHostForm);
}

AstChanMon::~AstChanMon()
{
    delete ui;
}

void AstChanMon::on_actionConnection_triggered(bool checked)
{
    astHostForm->onConnectionTriggered(checked);
}
