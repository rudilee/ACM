#include "astchanform.h"
#include "ui_astchanform.h"

AstChanForm::AstChanForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AstChanForm)
{
    ui->setupUi(this);
}

AstChanForm::~AstChanForm()
{
    delete ui;
}

void AstChanForm::changeEvent(QEvent *e)
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

void AstChanForm::setLabel(int label, QString value)
{
    switch (label) {
    case 0: // Channel
        ui->channelLabel->setText(value);
        break;
    case 1: // CallerID
        ui->callerIdLabel->setText(value);
        break;
    case 2: // Context
        ui->contextLabel->setText(value);
        break;
    case 3: // Exten
        ui->extenLabel->setText(value);
        break;
    case 4: // Parameters
        ui->paramsLabel->setText(value);
        break;
    case 5: // State
        ui->stateLabel->setPixmap(QPixmap(QString(value).prepend(":/state/")));

        if (value == "Clear") {
            ui->frame->setStyleSheet("background-color: #d2d2d2; border-radius: 6;");
        } else if (value == "Dialing") {
            ui->frame->setStyleSheet("background-color: #edb667; border-radius: 6;");
        } else if (value == "Ring") {
            ui->frame->setStyleSheet("background-color: #ece67c; border-radius: 6;");
        } else if (value == "Ringing") {
            ui->frame->setStyleSheet("background-color: #b7b5f9; border-radius: 6;");
        } else if (value == "Up") {
            ui->frame->setStyleSheet("background-color: #a8d69c; border-radius: 6;");
        } else if (value == "Down") {
            ui->frame->setStyleSheet("background-color: #ec9a9a; border-radius: 6;");
        }
        break;
    case 6:  // Unique ID
        ui->uniqueIdLabel->setText(value);
        break;
    }
}
