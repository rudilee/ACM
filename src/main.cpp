#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setOrganizationDomain("Kanaya Hijab");
    QApplication::setApplicationName("Asterisk Channel Monitor");

    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
