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
    return a.exec();
}
