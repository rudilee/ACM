/********************************************************************************
** Form generated from reading UI file 'astchanmon.ui'
**
** Created: Tue Oct 5 14:50:23 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTCHANMON_H
#define UI_ASTCHANMON_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AstChanMon
{
public:
    QAction *actionConnection;
    QAction *actionPreferences;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *AstChanMon)
    {
        if (AstChanMon->objectName().isEmpty())
            AstChanMon->setObjectName(QString::fromUtf8("AstChanMon"));
        AstChanMon->resize(590, 489);
        actionConnection = new QAction(AstChanMon);
        actionConnection->setObjectName(QString::fromUtf8("actionConnection"));
        actionConnection->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/toolbar/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/toolbar/connect.png"), QSize(), QIcon::Active, QIcon::On);
        actionConnection->setIcon(icon);
        actionPreferences = new QAction(AstChanMon);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/toolbar/wrench_orange.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreferences->setIcon(icon1);
        centralWidget = new QWidget(AstChanMon);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        verticalLayout->addWidget(mdiArea);

        AstChanMon->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(AstChanMon);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(32, 32));
        AstChanMon->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AstChanMon);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AstChanMon->setStatusBar(statusBar);
        menuBar = new QMenuBar(AstChanMon);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 590, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        AstChanMon->setMenuBar(menuBar);

        mainToolBar->addAction(actionConnection);
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        retranslateUi(AstChanMon);

        QMetaObject::connectSlotsByName(AstChanMon);
    } // setupUi

    void retranslateUi(QMainWindow *AstChanMon)
    {
        AstChanMon->setWindowTitle(QApplication::translate("AstChanMon", "Asterisk Channel Monitor", 0, QApplication::UnicodeUTF8));
        actionConnection->setText(QApplication::translate("AstChanMon", "Connect/Disconnect", 0, QApplication::UnicodeUTF8));
        actionPreferences->setText(QApplication::translate("AstChanMon", "Preferences", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("AstChanMon", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("AstChanMon", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AstChanMon: public Ui_AstChanMon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTCHANMON_H
