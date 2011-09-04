/********************************************************************************
** Form generated from reading UI file 'asthostform.ui'
**
** Created: Tue Oct 5 14:50:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTHOSTFORM_H
#define UI_ASTHOSTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AstHostForm
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *channelsTab;
    QHBoxLayout *horizontalLayout;
    QScrollArea *channelsArea;
    QWidget *channelsAreaWidgetContents;
    QScrollArea *dahdiArea;
    QWidget *dahdiAreaWidgetContents;
    QWidget *cdrTab;
    QVBoxLayout *verticalLayout_2;
    QTableView *cdrTableView;

    void setupUi(QWidget *AstHostForm)
    {
        if (AstHostForm->objectName().isEmpty())
            AstHostForm->setObjectName(QString::fromUtf8("AstHostForm"));
        AstHostForm->resize(566, 416);
        verticalLayout = new QVBoxLayout(AstHostForm);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(AstHostForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        channelsTab = new QWidget();
        channelsTab->setObjectName(QString::fromUtf8("channelsTab"));
        horizontalLayout = new QHBoxLayout(channelsTab);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        channelsArea = new QScrollArea(channelsTab);
        channelsArea->setObjectName(QString::fromUtf8("channelsArea"));
        channelsArea->setWidgetResizable(true);
        channelsAreaWidgetContents = new QWidget();
        channelsAreaWidgetContents->setObjectName(QString::fromUtf8("channelsAreaWidgetContents"));
        channelsAreaWidgetContents->setGeometry(QRect(0, 0, 272, 371));
        channelsAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        channelsArea->setWidget(channelsAreaWidgetContents);

        horizontalLayout->addWidget(channelsArea);

        dahdiArea = new QScrollArea(channelsTab);
        dahdiArea->setObjectName(QString::fromUtf8("dahdiArea"));
        dahdiArea->setWidgetResizable(true);
        dahdiAreaWidgetContents = new QWidget();
        dahdiAreaWidgetContents->setObjectName(QString::fromUtf8("dahdiAreaWidgetContents"));
        dahdiAreaWidgetContents->setGeometry(QRect(0, 0, 272, 371));
        dahdiAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        dahdiArea->setWidget(dahdiAreaWidgetContents);

        horizontalLayout->addWidget(dahdiArea);

        tabWidget->addTab(channelsTab, QString());
        cdrTab = new QWidget();
        cdrTab->setObjectName(QString::fromUtf8("cdrTab"));
        verticalLayout_2 = new QVBoxLayout(cdrTab);
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cdrTableView = new QTableView(cdrTab);
        cdrTableView->setObjectName(QString::fromUtf8("cdrTableView"));
        cdrTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        cdrTableView->setAlternatingRowColors(true);
        cdrTableView->setSelectionMode(QAbstractItemView::NoSelection);
        cdrTableView->setShowGrid(false);
        cdrTableView->setWordWrap(false);
        cdrTableView->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(cdrTableView);

        tabWidget->addTab(cdrTab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(AstHostForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AstHostForm);
    } // setupUi

    void retranslateUi(QWidget *AstHostForm)
    {
        tabWidget->setTabText(tabWidget->indexOf(channelsTab), QApplication::translate("AstHostForm", "Channels", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(cdrTab), QApplication::translate("AstHostForm", "Call Data Records", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AstHostForm);
    } // retranslateUi

};

namespace Ui {
    class AstHostForm: public Ui_AstHostForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTHOSTFORM_H
