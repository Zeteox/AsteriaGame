#include "mainwindow.h"

#include <QApplication>
#include "potion.h"
#include "inventory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Potion* popo = new Potion(2);
    Inventory* Inv = new Inventory();
    string lala = Inv->addPotion(popo);
    qDebug()<<lala;
    return a.exec();
}
