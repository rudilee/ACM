/********************************************************************************
** Form generated from reading UI file 'astchanform.ui'
**
** Created: Wed Oct 6 16:11:39 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTCHANFORM_H
#define UI_ASTCHANFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AstChanForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *stateLabel;
    QLabel *channelLabel;
    QFormLayout *formLayout;
    QLabel *paramsLabel;
    QLabel *extenLabel;
    QLabel *contextLabel;
    QLabel *uniqueIdLabel;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *callerIdLabel;
    QLabel *label;

    void setupUi(QWidget *AstChanForm)
    {
        if (AstChanForm->objectName().isEmpty())
            AstChanForm->setObjectName(QString::fromUtf8("AstChanForm"));
        AstChanForm->resize(144, 73);
        AstChanForm->setMinimumSize(QSize(144, 0));
        AstChanForm->setMaximumSize(QSize(144, 16777215));
        AstChanForm->setStyleSheet(QString::fromUtf8("* * QLabel {\n"
"border-width: 0;\n"
"border-radius: 0;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(AstChanForm);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(AstChanForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: #d2d2d2;\n"
"border-radius: 6;"));
        frame->setFrameShape(QFrame::Box);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, -1);
        stateLabel = new QLabel(frame);
        stateLabel->setObjectName(QString::fromUtf8("stateLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stateLabel->sizePolicy().hasHeightForWidth());
        stateLabel->setSizePolicy(sizePolicy);
        stateLabel->setMinimumSize(QSize(16, 16));
        stateLabel->setMaximumSize(QSize(16, 16));
        stateLabel->setStyleSheet(QString::fromUtf8("border-radius:0;"));
        stateLabel->setPixmap(QPixmap(QString::fromUtf8(":/state/Clear")));

        horizontalLayout->addWidget(stateLabel);

        channelLabel = new QLabel(frame);
        channelLabel->setObjectName(QString::fromUtf8("channelLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(channelLabel->sizePolicy().hasHeightForWidth());
        channelLabel->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        channelLabel->setFont(font);
        channelLabel->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        horizontalLayout->addWidget(channelLabel);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setContentsMargins(2, 2, 2, 2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(2);
        formLayout->setVerticalSpacing(0);
        paramsLabel = new QLabel(frame);
        paramsLabel->setObjectName(QString::fromUtf8("paramsLabel"));
        QFont font1;
        font1.setPointSize(6);
        font1.setBold(true);
        font1.setWeight(75);
        paramsLabel->setFont(font1);
        paramsLabel->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(4, QFormLayout::FieldRole, paramsLabel);

        extenLabel = new QLabel(frame);
        extenLabel->setObjectName(QString::fromUtf8("extenLabel"));
        extenLabel->setFont(font1);
        extenLabel->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(3, QFormLayout::FieldRole, extenLabel);

        contextLabel = new QLabel(frame);
        contextLabel->setObjectName(QString::fromUtf8("contextLabel"));
        contextLabel->setFont(font1);
        contextLabel->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(2, QFormLayout::FieldRole, contextLabel);

        uniqueIdLabel = new QLabel(frame);
        uniqueIdLabel->setObjectName(QString::fromUtf8("uniqueIdLabel"));
        uniqueIdLabel->setFont(font1);
        uniqueIdLabel->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(1, QFormLayout::FieldRole, uniqueIdLabel);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Andale Mono"));
        font2.setPointSize(6);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        callerIdLabel = new QLabel(frame);
        callerIdLabel->setObjectName(QString::fromUtf8("callerIdLabel"));
        callerIdLabel->setFont(font1);
        callerIdLabel->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(0, QFormLayout::FieldRole, callerIdLabel);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("border-radius:0;"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addWidget(frame);


        retranslateUi(AstChanForm);

        QMetaObject::connectSlotsByName(AstChanForm);
    } // setupUi

    void retranslateUi(QWidget *AstChanForm)
    {
        AstChanForm->setWindowTitle(QApplication::translate("AstChanForm", "Form", 0, QApplication::UnicodeUTF8));
        stateLabel->setText(QString());
        channelLabel->setText(QApplication::translate("AstChanForm", "...", 0, QApplication::UnicodeUTF8));
        paramsLabel->setText(QApplication::translate("AstChanForm", "...", 0, QApplication::UnicodeUTF8));
        extenLabel->setText(QApplication::translate("AstChanForm", "...", 0, QApplication::UnicodeUTF8));
        contextLabel->setText(QApplication::translate("AstChanForm", "...", 0, QApplication::UnicodeUTF8));
        uniqueIdLabel->setText(QApplication::translate("AstChanForm", "...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AstChanForm", "PAR:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AstChanForm", "EXT:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AstChanForm", "CTX:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AstChanForm", "UID:", 0, QApplication::UnicodeUTF8));
        callerIdLabel->setText(QApplication::translate("AstChanForm", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AstChanForm", "CID:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AstChanForm: public Ui_AstChanForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTCHANFORM_H
