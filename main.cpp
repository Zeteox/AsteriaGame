#include <QApplication>

#include "mainwindow.h"
#include "village.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Village* bourg = new Village("bourg");
    qDebug() << "village : " << bourg->getAllBuildings();
    return a.exec();
}
