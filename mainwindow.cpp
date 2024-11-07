#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_hero = nullptr;

    stackedWidgetIndexSetup();
    connectAll();
}

MainWindow::~MainWindow()
{
    delete m_hero;

    delete ui;
}

void MainWindow::genVillages() {
    m_currentVillage = 0;
    m_villages.push_back(new Village("Vendetta"));
}

void MainWindow::stackedWidgetIndexSetup() {
    ui->Main->setCurrentIndex(0);
    ui->stk_Warrior->setCurrentIndex(0);
    ui->stk_Mage->setCurrentIndex(0);
    ui->stk_Paladin->setCurrentIndex(0);
    ui->stk_invStats->setCurrentIndex(0);
    ui->tab_inventory->setCurrentIndex(0);
    ui->tab_shop->setCurrentIndex(0);
}

void MainWindow::connectAll() {
    // ------------ Main
    connect(ui->btn_quit,SIGNAL(clicked(bool)),this,SLOT(quitButtonClicked()));
    connect(ui->btn_start,SIGNAL(clicked(bool)),this,SLOT(startButtonClicked()));
    connect(ui->btn_back,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));

    connect(ui->btn_createHero,SIGNAL(clicked(bool)),this,SLOT(createHeroButtonClicked()));

    connect(ui->btn_warrior,SIGNAL(clicked(bool)),this,SLOT(btnWarriorClicked()));
    connect(ui->btn_statsWarrior,SIGNAL(clicked(bool)),this,SLOT(btnWarriorStatsClicked()));

    connect(ui->btn_mage,SIGNAL(clicked(bool)),this,SLOT(btnMageClicked()));
    connect(ui->btn_statsMage,SIGNAL(clicked(bool)),this,SLOT(btnMageStatsClicked()));

    connect(ui->btn_paladin,SIGNAL(clicked(bool)),this,SLOT(btnPaladinClicked()));
    connect(ui->btn_statsPaladin,SIGNAL(clicked(bool)),this,SLOT(btnPaladinStatsClicked()));

    // ------------ Game

    connect(ui->btn_Menu,SIGNAL(clicked(bool)),this,SLOT(menuButtonClicked()));
    connect(ui->btn_quitMenu,SIGNAL(clicked(bool)),this,SLOT(quitButtonClicked()));
    connect(ui->btn_resume,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));

    connect(ui->btn_back2,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));
    connect(ui->btn_worldMap,SIGNAL(clicked(bool)),this,SLOT(worldButtonClicked()));
    connect(ui->btn_hero,SIGNAL(clicked(bool)),this,SLOT(heroButtonClicked()));

    connect(ui->txt_search,SIGNAL(textChanged()),this,SLOT(searchInputInv()));
    connect(ui->btn_stats,SIGNAL(clicked(bool)),this,SLOT(statsButtonClicked()));
    connect(ui->btn_inv,SIGNAL(clicked(bool)),this,SLOT(invButtonClicked()));

    connect(ui->btn_village1,SIGNAL(clicked(bool)),this,SLOT(btnVillageOneClicked()));
    connect(ui->btn_village2,SIGNAL(clicked(bool)),this,SLOT(btnVillageTwoClicked()));

    connect(ui->btn_shop,SIGNAL(clicked(bool)),this,SLOT(shopButtonClicked()));
    connect(ui->txt_searchShop,SIGNAL(textChanged()),this,SLOT(searchInputShop()));
    connect(ui->cbox_shops,SIGNAL(currentTextChanged(QString)),this,SLOT(shopComboBoxChanged()));

    connect(ui->btn_hostel,SIGNAL(clicked(bool)),this,SLOT(hostelButtonClicked()));
    connect(ui->btn_mine,SIGNAL(clicked(bool)),this,SLOT(mineButtonClicked()));
}

int MainWindow::getUiStackedWidgetIndex(string widget) {
    if (widget == "Main") {
        return ui->Main->currentIndex();
    } else if (widget == "Game") {
        return ui->Game->currentIndex();
    } else {
        return 0;
    }
}

void MainWindow::quitButtonClicked()
{
    this->close();
}

void MainWindow::startButtonClicked()
{
    m_lastIndex = getUiStackedWidgetIndex("Main");
    ui->Main->setCurrentIndex(1);
}

void MainWindow::backButtonClicked()
{
    if (m_hero == nullptr) {
        ui->Main->setCurrentIndex(m_lastIndex);
    } else {
        ui->Game->setCurrentIndex(m_lastIndex);
    }
}

void MainWindow::createHeroButtonClicked()
{
    string name = ui->txt_name->text().QString::toStdString();
    if (name != "") {
        bool next = false;
        if (ui->btn_paladin->isChecked()) {
            m_hero = new Paladin(name,15,10,1,2,"Paladin");
            ui->lbl_heroPicture->setStyleSheet("image: url(:/Images/Images/LivingCreature/Hero/paladin.jpeg)");
            next = !next;
        } else if (ui->btn_warrior->isChecked()) {
            m_hero = new Warrior(name,10,10,2,1,"Warrior");
            ui->lbl_heroPicture->setStyleSheet("image: url(:/Images/Images/LivingCreature/Hero/warrior.jpeg)");
            next = !next;
        } else if (ui->btn_mage->isChecked()) {
            m_hero = new Mage(name,10,15,2,0,"Mage");
            ui->lbl_heroPicture->setStyleSheet("image: url(:/Images/Images/LivingCreature/Hero/sorcer.jpeg)");
            next = !next;
        }
        if (next) {
            ui->Main->setCurrentIndex(2);
            m_lastIndex = 0;
            ui->btn_mage->setChecked(false);
            ui->btn_paladin->setChecked(false);
            ui->btn_warrior->setChecked(false);
            m_hero->addToInventory(new Potion(1));
            m_hero->addToInventory(new Potion(2));
            m_hero->addToInventory(new Potion(1));
            m_hero->addToInventory(new Potion(3));
            m_hero->addToInventory(new Potion(5));
            m_hero->addToInventory(new Potion(4));
            genVillages();
        }
    }
}


void MainWindow::btnWarriorClicked()
{
    if (!ui->btn_warrior->isChecked()) {
        ui->btn_warrior->setChecked(true);
    }
    ui->btn_createHero->setEnabled(true);
    ui->btn_mage->setChecked(false);
    ui->btn_paladin->setChecked(false);
}


void MainWindow::btnMageClicked()
{
    if (!ui->btn_mage->isChecked()) {
        ui->btn_mage->setChecked(true);
    }
    ui->btn_createHero->setEnabled(true);
    ui->btn_warrior->setChecked(false);
    ui->btn_paladin->setChecked(false);
}


void MainWindow::btnPaladinClicked()
{
    if (!ui->btn_paladin->isChecked()) {
        ui->btn_paladin->setChecked(true);
    }
    ui->btn_createHero->setEnabled(true);
    ui->btn_warrior->setChecked(false);
    ui->btn_mage->setChecked(false);
}

void MainWindow::btnWarriorStatsClicked() {
    if (ui->btn_statsWarrior->text() == "⇓") {
        ui->btn_statsWarrior->setText("⇑");
        ui->stk_Warrior->setCurrentIndex(1);
    } else {
        ui->btn_statsWarrior->setText("⇓");
        ui->stk_Warrior->setCurrentIndex(0);
    }
}

void MainWindow::btnMageStatsClicked() {
    if (ui->btn_statsMage->text() == "⇓") {
        ui->btn_statsMage->setText("⇑");
        ui->stk_Mage->setCurrentIndex(1);
    } else {
        ui->btn_statsMage->setText("⇓");
        ui->stk_Mage->setCurrentIndex(0);
    }
}

void MainWindow::btnPaladinStatsClicked() {
    if (ui->btn_statsPaladin->text() == "⇓") {
        ui->btn_statsPaladin->setText("⇑");
        ui->stk_Paladin->setCurrentIndex(1);
    } else {
        ui->btn_statsPaladin->setText("⇓");
        ui->stk_Paladin->setCurrentIndex(0);
    }
}

void MainWindow::btnVillageOneClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(3);
    m_currentVillage = 1;
}

void MainWindow::btnVillageTwoClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(3);
    m_currentVillage = 2;
}

void MainWindow::worldButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(0);
    m_currentVillage = 0;
}

void MainWindow::heroButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    m_hero->updDamage();
    m_hero->updDefence();
    ui->lbl_statsHero->setText(QString::fromStdString(m_hero->getStats()));
    ui->Game->setCurrentIndex(1);
}

void MainWindow::statsButtonClicked() {
    ui->stk_invStats->setCurrentIndex(0);
}

void MainWindow::invButtonClicked() {
    ui->stk_invStats->setCurrentIndex(1);
    ui->txt_search->clear();
}

void MainWindow::menuButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(2);
}

void MainWindow::searchInputInv() {
    if (m_hero != nullptr) {
        vector<Potion*> inv = m_hero->getInventory()->getPotions();

        ui->list_potionInv->clear();

        for (size_t x=0;x<inv.size();x++) {
            if (inv[x]->getName().find(ui->txt_search->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_potionInv->addItem(QString::fromStdString(inv[x]->getName()));
            }
        }
    }
}

void MainWindow::shopComboBoxChanged() {
    ui->list_potions->clear();
    ui->list_weapons->clear();
    ui->list_invSell->clear();
    ui->txt_searchShop->clear();
}

void MainWindow::searchInputShop() {
    if (ui->cbox_shops->currentIndex()-1 >=0) {
        Merchant* merchant = m_shops[ui->cbox_shops->currentIndex()-1];
        vector<Potion*> potionStock = merchant->getPotionStock();
        vector<Weapon*> weaponStock = merchant->getWeaponStock();
        vector<Potion*> invP = m_hero->getInventory()->getPotions();

        ui->list_potions->clear();
        ui->list_weapons->clear();
        ui->list_invSell->clear();

        for (size_t x=0;x<potionStock.size();x++) {
            if (potionStock[x]->getName().find(ui->txt_searchShop->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_potions->addItem(QString::fromStdString(potionStock[x]->getName()+" ("+to_string(potionStock[x]->getPrice())+"G)"));
            }
        }
        for (size_t x=0;x<weaponStock.size();x++) {
            if (weaponStock[x]->getName().find(ui->txt_searchShop->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_weapons->addItem(QString::fromStdString(weaponStock[x]->getName()+" ("+to_string(weaponStock[x]->getPrice())+"G)"));
            }
        }
        for (size_t x=0;x<invP.size();x++) {
            if (invP[x]->getName().find(ui->txt_searchShop->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_invSell->addItem(QString::fromStdString(invP[x]->getName()+" ("+to_string(invP[x]->getPrice())+"G)"));
            }
        }
    }
}

void MainWindow::shopButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->lbl_golds->setText("Golds: " + QString::fromStdString(to_string(m_hero->getGolds())));
    ui->Game->setCurrentIndex(5);
    for (int i=1;i<ui->cbox_shops->count();i++) {
        ui->cbox_shops->removeItem(i);
    }
    m_shops.clear();
    for (size_t x=0;x<m_villages[m_currentVillage-1]->getAllBuildings().size();x++) {
        if (m_villages[m_currentVillage-1]->getAllBuildings()[x]->getType() == "Merchant") {
            m_shops.push_back(m_villages[m_currentVillage-1]->getAllBuildings()[x]->getMerchant());
            ui->cbox_shops->addItem(QString::fromStdString("Merchant " + to_string(m_shops.size())));
        }
    }
}

void MainWindow::hostelButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(6);
}

void MainWindow::mineButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(7);
}
