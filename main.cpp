#include "mainwindow.h"

#include <QApplication>
#include "potion.h"
#include "sword.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Sword* ss = new Sword("sa",10,10);
    ss->showStats();
    return a.exec();
}
