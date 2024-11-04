#include <QApplication>
#include "mainwindow.h"
#include "monster.h"
#include "mine.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Mine* mimi = new Mine(2);
    Monster* mons = new Monster("lolo", 25, 25, 25, 25, true, "big sword", 25, 25);
    qDebug() << "level : " << mimi->getMineLevel() << "\n";
    mimi->setMineLevel(1);
    qDebug() << "level : " << mimi->getMineLevel() << "\n";
    return a.exec();
}
