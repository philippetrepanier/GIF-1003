#include "employegui.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EmployeGUI w;
    w.show();
    return a.exec();
}
