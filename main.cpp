#include <QApplication>
#include "mainwindow.h"
#include "potion.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // ----------test
    vector<Potion*> inv;
    for (int x=0;x<4;x++) {
        inv.push_back(new Potion(1));
    }
    qDebug()<<inv.size();
    qDebug()<<inv[2];
    auto nx= next(inv.begin()+1);
    inv.erase(nx);
    qDebug()<<inv.size();
    qDebug()<<inv[2];
    nx= next(inv.begin()+1);
    inv.erase(nx);
    qDebug()<<inv.size();
    qDebug()<<inv[2];
    // -----------

    return a.exec();
}
