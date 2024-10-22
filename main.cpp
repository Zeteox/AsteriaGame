#include "mainwindow.h"
#include "hero.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Hero* toto = new Hero("hg",10,10,10,10,"mage noir");
    toto->talk();
    toto->showStats();
    return a.exec();
}
