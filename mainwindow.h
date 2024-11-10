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
    void searchInputInv();
    void searchInputShop();
    void statsButtonClicked();
    void invButtonClicked();
    void drinkButtonClicked();
    void equipButtonClicked();
    void unequipAllButtonClicked();

    void menuButtonClicked();

    void shopButtonClicked();
    void shopBuyButtonClicked();
    void shopSellButtonClicked();
    void shopComboBoxChanged();

    void hostelButtonClicked();
    void yesHostelButtonClicked();
    void noHostelButtonClicked();
    void hostelComboBoxChanged();

    void mineButtonClicked();
    void enterMineButtonClicked();
    void quitMineButtonClicked();
    void fightMineButtonClicked();
    void mineComboBoxChanged();
    void potionButtonClicked();
    void attackButtonClicked();
    void goBackButtonClicked();
    void drinkMineButtonClicked();
    void monsterAttack(QString info);


private:
    Ui::MainWindow *ui;
    Hero* m_hero;
    int m_currentVillage;
    int m_lastIndex;
    vector<Village*> m_villages;
    vector<Merchant*> m_shops;
    vector<Hostel*> m_hostels;
    vector<Mine*> m_mines;

    int getUiStackedWidgetIndex(string widget);
    void connectAll();
    void stackedWidgetIndexSetup();
    void genVillages();
    void getAllBuildings();
};
#endif // MAINWINDOW_H
