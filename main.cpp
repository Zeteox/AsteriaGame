#include "mainwindow.h"
#include "hero.h"

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
    Hero* toto = new Hero("hg",10,10,10,10,"mage noir");
    toto->talk();
    toto->showStats();
    return a.exec();
}
