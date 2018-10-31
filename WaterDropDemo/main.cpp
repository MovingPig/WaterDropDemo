#include "WaterDropDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WaterDropDemo w;
    w.show();
    return a.exec();
}
