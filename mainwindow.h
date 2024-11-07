#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "warrior.h"
#include "mage.h"
#include "paladin.h"
#include "village.h"
#include "mine.h"
#include "hostel.h"
#include "merchant.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void quitButtonClicked();
    void startButtonClicked();
    void backButtonClicked();
    void createHeroButtonClicked();
    void btnWarriorClicked();
    void btnWarriorStatsClicked();
    void btnMageClicked();
    void btnMageStatsClicked();
    void btnPaladinClicked();
    void btnPaladinStatsClicked();
    void btnVillageOneClicked();
    void btnVillageTwoClicked();
    void worldButtonClicked();
    void heroButtonClicked();
    void searchInput();
    void statsButtonClicked();
    void invButtonClicked();
    void menuButtonClicked();

private:
    Ui::MainWindow *ui;
    Hero* m_hero;
    int m_lastIndex;



    void connectAll();
    void stackedWidgetIndexSetup();
};
#endif // MAINWINDOW_H
