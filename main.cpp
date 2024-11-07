#include <QApplication>

#include "mainwindow.h"
//#include "village.h"
#include "mine.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Mine* mine = new Mine(0);
    qDebug() << mine->getMonster();
    qDebug() << mine->levelUp();
    qDebug() << mine->getMonster();
    qDebug() << mine->levelUp();
    //Village* vi = new Village("vi");
    //qDebug() << vi->getAllBuildings();

    return a.exec();
}
