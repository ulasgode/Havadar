#include <QtGui/QApplication>
#include "controlmodule.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlModule w;
    w.show();

    return a.exec();
}
