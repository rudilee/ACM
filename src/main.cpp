#include <QtGui/QApplication>
#include "astchanmon.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AstChanMon astChanMon;
    astChanMon.show();

    return a.exec();
}
