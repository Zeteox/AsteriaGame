#include <QApplication>
#include "mainwindow.h"
#include "hero.h"
#include "potion.h"
#include "sword.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // ----------test
    Sword* ss = new Sword("sa",10,10);
    Hero* toto = new Hero("hg",10,10,10,10,"mage noir");
    Potion* popo = new Potion(5);
    qDebug() << popo->getHp();
    ss->showStats();
    toto->talk();
    toto->showStats();
    // -----------

    return a.exec();
}
