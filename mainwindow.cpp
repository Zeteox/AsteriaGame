#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;
using namespace std::this_thread;

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
    m_villages.push_back(new Village("Burratta"));
    ui->lbl_nameVillage1->setText(QString::fromStdString(m_villages[0]->getName()));
    ui->lbl_nameVillage2->setText(QString::fromStdString(m_villages[1]->getName()));
}

void MainWindow::stackedWidgetIndexSetup() {
    ui->Main->setCurrentIndex(0);
    ui->stk_Warrior->setCurrentIndex(0);
    ui->stk_Mage->setCurrentIndex(0);
    ui->stk_Paladin->setCurrentIndex(0);
    ui->stk_invStats->setCurrentIndex(0);
    ui->tab_inventory->setCurrentIndex(0);
    ui->tab_shop->setCurrentIndex(0);
    ui->stk_hostelheal->setCurrentIndex(0);
    ui->stk_mine->setCurrentIndex(0);
    ui->stk_mineFight->setCurrentIndex(0);
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
    connect(ui->btn_backInv,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));
    connect(ui->btn_drink,SIGNAL(clicked(bool)),this,SLOT(drinkButtonClicked()));
    connect(ui->btn_equip,SIGNAL(clicked(bool)),this,SLOT(equipButtonClicked()));
    connect(ui->btn_unequipAll,SIGNAL(clicked(bool)),this,SLOT(unequipAllButtonClicked()));

    connect(ui->btn_village1,SIGNAL(clicked(bool)),this,SLOT(btnVillageOneClicked()));
    connect(ui->btn_village2,SIGNAL(clicked(bool)),this,SLOT(btnVillageTwoClicked()));

    connect(ui->btn_shop,SIGNAL(clicked(bool)),this,SLOT(shopButtonClicked()));
    connect(ui->btn_buy,SIGNAL(clicked(bool)),this,SLOT(shopBuyButtonClicked()));
    connect(ui->btn_sell,SIGNAL(clicked(bool)),this,SLOT(shopSellButtonClicked()));
    connect(ui->txt_searchShop,SIGNAL(textChanged()),this,SLOT(searchInputShop()));
    connect(ui->cbox_shops,SIGNAL(currentTextChanged(QString)),this,SLOT(shopComboBoxChanged()));

    connect(ui->btn_hostel,SIGNAL(clicked(bool)),this,SLOT(hostelButtonClicked()));
    connect(ui->btn_yes,SIGNAL(clicked(bool)),this,SLOT(yesHostelButtonClicked()));
    connect(ui->btn_no,SIGNAL(clicked(bool)),this,SLOT(noHostelButtonClicked()));
    connect(ui->cbox_hostel,SIGNAL(currentTextChanged(QString)),this,SLOT(hostelComboBoxChanged()));

    connect(ui->btn_mine,SIGNAL(clicked(bool)),this,SLOT(mineButtonClicked()));
    connect(ui->btn_Enter,SIGNAL(clicked(bool)),this,SLOT(enterMineButtonClicked()));
    connect(ui->cbox_mines,SIGNAL(currentTextChanged(QString)),this,SLOT(mineComboBoxChanged()));
    connect(ui->btn_quitMine,SIGNAL(clicked(bool)),this,SLOT(quitMineButtonClicked()));
    connect(ui->btn_fight,SIGNAL(clicked(bool)),this,SLOT(fightMineButtonClicked()));
    connect(ui->btn_attack,SIGNAL(clicked(bool)),this,SLOT(attackButtonClicked()));
    connect(ui->btn_potion,SIGNAL(clicked(bool)),this,SLOT(potionButtonClicked()));
    connect(ui->btn_drinkMine,SIGNAL(clicked(bool)),this,SLOT(drinkMineButtonClicked()));
    connect(ui->btn_goBack,SIGNAL(clicked(bool)),this,SLOT(goBackButtonClicked()));
    connect(ui->btn_continue,SIGNAL(clicked(bool)),this,SLOT(enterMineButtonClicked()));

    connect(ui->btn_quitEnd,SIGNAL(clicked(bool)),this,SLOT(quitButtonClicked()));
}

void MainWindow::getAllBuildings() {
    ui->cbox_hostel->clear();
    ui->cbox_hostel->addItem("No hostel");
    ui->cbox_shops->clear();
    ui->cbox_shops->addItem("No shop");
    ui->cbox_mines->clear();
    ui->cbox_mines->addItem("    No Mine");

    m_shops.clear();
    for (size_t x=0;x<m_villages[m_currentVillage-1]->getAllBuildings().size();x++) {
        if (m_villages[m_currentVillage-1]->getAllBuildings()[x]->getType() == "Merchant") {
            m_shops.push_back(m_villages[m_currentVillage-1]->getAllBuildings()[x]->getMerchant());
            ui->cbox_shops->addItem(QString::fromStdString("Merchant " + to_string(m_shops.size())));
        }
    }
    m_hostels.clear();
    for (size_t x=0;x<m_villages[m_currentVillage-1]->getAllBuildings().size();x++) {
        if (m_villages[m_currentVillage-1]->getAllBuildings()[x]->getType() == "Hostel") {
            m_hostels.push_back(m_villages[m_currentVillage-1]->getAllBuildings()[x]->getHostel());
            ui->cbox_hostel->addItem(QString::fromStdString("Hostel " + to_string(m_hostels.size())));
        }
    }
    m_mines.clear();
    for (size_t x=0;x<m_villages[m_currentVillage-1]->getAllBuildings().size();x++) {
        if (m_villages[m_currentVillage-1]->getAllBuildings()[x]->getType() == "Mine") {
            m_mines.push_back(m_villages[m_currentVillage-1]->getAllBuildings()[x]->getMine());
            if (m_mines[m_mines.size()-1]->getMineLevel()>6) {
                ui->cbox_mines->addItem(QString::fromStdString("Mine " + to_string(m_mines.size()) + " (finished)"));
            } else {
                ui->cbox_mines->addItem(QString::fromStdString("Mine " + to_string(m_mines.size()) +
                                                               "(lvl "+ to_string(m_mines[m_mines.size()-1]->getMineLevel())+")"));
            }
        }
    }
    if (m_currentVillage==1) {
        if (m_mines.empty()) {
            ui->btn_village2->setEnabled(true);
        } else {
            bool isVillageCleared = true;
            for (size_t i =0;i<m_mines.size();i++) {
                if (!m_mines[i]->getMonster().empty()) {
                    isVillageCleared = false;
                    break;
                }
            }
            if (isVillageCleared) {
                ui->btn_village2->setEnabled(true);
            }
        }
    } else if (m_currentVillage==2) {
        if (m_mines.empty()) {
            ui->Game->setCurrentIndex(8);
        } else {
            bool isVillageCleared = true;
            for (size_t i =0;i<m_mines.size();i++) {
                if (!m_mines[i]->getMonster().empty()) {
                    isVillageCleared = false;
                    break;
                }
            }
            if (isVillageCleared) {
                ui->Game->setCurrentIndex(8);
            }
        }
        ui->lbl_end->setText("You won");
    }
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
        ui->cbox_hostel->setCurrentIndex(0);
        ui->cbox_shops->setCurrentIndex(0);
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
    getAllBuildings();
}

void MainWindow::btnVillageTwoClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(3);
    m_currentVillage = 2;
    getAllBuildings();
}

void MainWindow::worldButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(0);
    m_currentVillage = 0;
    ui->cbox_hostel->setCurrentIndex(0);
    ui->cbox_shops->setCurrentIndex(0);
}

void MainWindow::heroButtonClicked() {
    m_hero->updDamage();
    m_hero->updDefence();
    ui->Game->setCurrentIndex(1);
    statsButtonClicked();
    searchInputInv();
}

void MainWindow::statsButtonClicked() {
    ui->stk_invStats->setCurrentIndex(0);
    ui->lbl_statsHero->setText(QString::fromStdString(m_hero->getStats()));
}

void MainWindow::invButtonClicked() {
    ui->stk_invStats->setCurrentIndex(1);
    ui->txt_search->clear();
}

void MainWindow::drinkButtonClicked() {
    if (ui->list_potionInv->currentRow()>=0) {
        m_hero->drink(m_hero->getInventory()->getPotions()[ui->list_potionInv->currentRow()]);
        ui->txt_search->clear();
    }
}

//--------------------------------------------------------------------------------

void MainWindow::equipButtonClicked() {
    if (ui->list_weaponInv->currentRow()>=0) {
        Weapon* weapon = m_hero->getInventory()->getWeapons()[ui->list_weaponInv->currentRow()];
        if (weapon->getType()=="Sword") {
            if (m_hero->getClass()=="Warrior" || m_hero->getClass()=="Paladin") {
                m_hero->setWeapon(weapon);
                QIcon icon = ui->list_weaponInv->item(ui->list_weaponInv->currentRow())->icon();
                ui->lbl_swordStaffPic->setPixmap(icon.pixmap(icon.actualSize(QSize(100,100))));
            }
        } else if (weapon->getType()=="Shield") {
            if (m_hero->getClass()=="Paladin") {
                m_hero->setWeapon(weapon);
                QIcon icon = ui->list_weaponInv->item(ui->list_weaponInv->currentRow())->icon();
                ui->lbl_shieldPic->setPixmap(icon.pixmap(icon.actualSize(QSize(100,100))));
            }
        } else if (weapon->getType()=="Staff") {
            if (m_hero->getClass()=="Mage") {
                m_hero->setWeapon(weapon);
                QIcon icon = ui->list_weaponInv->item(ui->list_weaponInv->currentRow())->icon();
                ui->lbl_swordStaffPic->setPixmap(icon.pixmap(icon.actualSize(QSize(100,100))));
            }
        }
    }
}

void MainWindow::unequipAllButtonClicked() {
    m_hero->setWeapon(nullptr);
    ui->lbl_swordStaffPic->setPixmap(QPixmap());
    ui->lbl_shieldPic->setPixmap(QPixmap());
}

//--------------------------------------------------------------------------------



void MainWindow::menuButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(2);
}

void MainWindow::searchInputInv() {
    if (m_hero != nullptr) {
        vector<Potion*> inv = m_hero->getInventory()->getPotions();
        vector<Weapon*> invWeapon = m_hero->getInventory()->getWeapons();

        ui->list_potionInv->clear();
        ui->list_weaponInv->clear();

        for (size_t x=0;x<inv.size();x++) {
            if (inv[x]->getName().find(ui->txt_search->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_potionInv->addItem(QString::fromStdString(inv[x]->getName()));
                QListWidgetItem* item = ui->list_potionInv->item(x);
                if (item->text()=="Small Potion") {
                    item->setIcon(QIcon(":/Images/Images/Button/potion/potion1.png"));
                } else if (item->text()=="Medium Potion") {
                    item->setIcon(QIcon(":/Images/Images/Button/potion/potion2.png"));
                } else if (item->text()=="Big Potion") {
                    item->setIcon(QIcon(":/Images/Images/Button/potion/potion3.png"));
                } else if (item->text()=="Divine Potion") {
                    item->setIcon(QIcon(":/Images/Images/Button/potion/potion4.png"));
                } else if (item->text()=="Divine Potiom") {
                    item->setIcon(QIcon(":/Images/Images/Button/potion/potion5.png"));
                }
            }
        }

        for (size_t x=0;x<invWeapon.size();x++) {
            if (invWeapon[x]->getName().find(ui->txt_search->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_weaponInv->addItem(QString::fromStdString(invWeapon[x]->getName()));
                QListWidgetItem* item = ui->list_weaponInv->item(x);
                if (item->text()=="Starter Sword") {
                    item->setIcon(QIcon(":/Images/Images/Button/sword/sword1.png"));
                } else if (item->text()=="Standard Sword") {
                    item->setIcon(QIcon(":/Images/Images/Button/sword/sword2.png"));
                } else if (item->text()=="Rare Sword") {
                    item->setIcon(QIcon(":/Images/Images/Button/sword/sword3.png"));
                } else if (item->text()=="Magical Sword") {
                    item->setIcon(QIcon(":/Images/Images/Button/sword/sword4.png"));
                } else if (item->text()=="Legendary Sword") {
                    item->setIcon(QIcon(":/Images/Images/Button/sword/sword5.png"));
                } else if (item->text()=="Mythic Sword") {
                    item->setIcon(QIcon(":/Images/Images/Button/sword/sword6.png"));

                }else if (item->text()=="Starter Staff") {
                    item->setIcon(QIcon(":/Images/Images/Button/staff/staff1.png"));
                } else if (item->text()=="Standard Staff") {
                    item->setIcon(QIcon(":/Images/Images/Button/staff/staff2.png"));
                } else if (item->text()=="Rare Staff") {
                    item->setIcon(QIcon(":/Images/Images/Button/staff/staff3.png"));
                } else if (item->text()=="Magical Staff") {
                    item->setIcon(QIcon(":/Images/Images/Button/staff/staff4.png"));
                } else if (item->text()=="Legendary Staff") {
                    item->setIcon(QIcon(":/Images/Images/Button/staff/staff5.png"));
                } else if (item->text()=="Mythic Staff") {
                    item->setIcon(QIcon(":/Images/Images/Button/staff/staff5.png"));

                } else if (item->text()=="Standard Shield") {
                    item->setIcon(QIcon(":/Images/Images/Button/shields/shield1.png"));
                } else if (item->text()=="Rare Shield") {
                    item->setIcon(QIcon(":/Images/Images/Button/shields/shield2.png"));
                } else if (item->text()=="Magical Shield") {
                    item->setIcon(QIcon(":/Images/Images/Button/shields/shield3.png"));
                } else if (item->text()=="Legendary Shield") {
                    item->setIcon(QIcon(":/Images/Images/Button/shields/shield4.png"));
                } else if (item->text()=="Mythic Shield") {
                    item->setIcon(QIcon(":/Images/Images/Button/shields/shield5.png"));
                }
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
        vector<Weapon*> invW = m_hero->getInventory()->getWeapons();

        ui->list_potions->clear();
        ui->list_weapons->clear();
        ui->list_invSell->clear();

        for (size_t x=0;x<potionStock.size();x++) {
            if (potionStock[x]->getName().find(ui->txt_searchShop->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_potions->addItem(QString::fromStdString(potionStock[x]->getName()+" ("+to_string(potionStock[x]->getPrice())+"G)"));
            }
        }
        for (size_t i=0;i<weaponStock.size();i++) {
            if (weaponStock[i]->getName().find(ui->txt_searchShop->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_weapons->addItem(QString::fromStdString(weaponStock[i]->getName()+" ("+to_string(weaponStock[i]->getPrice())+"G)"));
            }
        }
        for (size_t x=0;x<invP.size();x++) {
            if (invP[x]->getName().find(ui->txt_searchShop->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_invSell->addItem(QString::fromStdString(invP[x]->getName()+" ("+to_string(invP[x]->getPrice())+"G)"));
            }
        }
        for (size_t x=0;x<invW.size();x++) {
            if (invW[x]->getName().find(ui->txt_searchShop->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_invSell->addItem(QString::fromStdString(invW[x]->getName()+" ("+to_string(invW[x]->getPrice())+"G)"));
            }
        }
    }
}

void MainWindow::shopButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->lbl_merchantSpeak->setText("Here's my stock, have a look!");
    ui->lbl_golds->setText("Golds: " + QString::fromStdString(to_string(m_hero->getGolds())));
    ui->Game->setCurrentIndex(5);
}

void MainWindow::hostelButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    ui->Game->setCurrentIndex(6);
    ui->btn_no->setHidden(true);
    ui->btn_yes->setHidden(true);
    ui->stk_hostelheal->setCurrentIndex(0);
    ui->lbl_heroPic->setStyleSheet(ui->lbl_heroPicture->styleSheet());
    ui->lbl_goldsHostel->setText("Golds: " + QString::fromStdString(to_string(m_hero->getGolds())));
    if (m_hostels.size()==0) {
        ui->lbl_hostelSpeak->setText("The Hostel is empty maybe it's closed");
        ui->lbl_hostelPic->setStyleSheet("");
    } else {
        ui->lbl_hostelSpeak->setText("Select an Hostel");
    }
}

void MainWindow::hostelComboBoxChanged() {
    if (ui->cbox_hostel->currentIndex()-1>=0) {
        Hostel* hostel = m_hostels[ui->cbox_hostel->currentIndex()-1];
        ui->lbl_hostelSpeak->setText("Hello adventurer! do you want some \n"
                                     "sleep and good food?"
                                     "\nIt will cost you "
                                     + QString::fromStdString(to_string(hostel->getPrice())) + " Golds");
        ui->btn_no->setHidden(false);
        ui->btn_yes->setHidden(false);
        ui->stk_hostelheal->setCurrentIndex(0);
    }
}

void MainWindow::yesHostelButtonClicked() {
    Hostel* hostel = m_hostels[ui->cbox_hostel->currentIndex()-1];
    if (hostel->getPrice()<=m_hero->getGolds()) {
        ui->lbl_hostelSpeak->setText("I knew you would say that! Come, follow me");
        ui->lbl_heal->setText("You have recovered all your life");
        m_hero->healHp(m_hero->getMaxHp());
        m_hero->setGolds(m_hero->getGolds() - hostel->getPrice());
        ui->stk_hostelheal->setCurrentIndex(1);
        ui->lbl_goldsHostel->setText("Golds: " + QString::fromStdString(to_string(m_hero->getGolds())));
    } else {
        ui->lbl_hostelSpeak->setText("Get out if you can't\n invest a little bit of gold");
    }
    ui->btn_no->setHidden(true);
    ui->btn_yes->setHidden(true);
}

void MainWindow::noHostelButtonClicked() {
    ui->lbl_hostelSpeak->setText("I hoped that you were a great men");
    ui->btn_no->setHidden(true);
    ui->btn_yes->setHidden(true);
}


void MainWindow::shopBuyButtonClicked() {
    Merchant* merchant = m_shops[ui->cbox_shops->currentIndex()-1];
    if (ui->list_potions->currentItem()!=nullptr) {
        Potion* popo = nullptr;
        for (int i =0;i<ui->list_potions->count();i++) {
            if (ui->list_potions->currentItem()->text().QString::toStdString().find(merchant->getPotionStock()[i]->getName()) != string::npos) {
                popo = merchant->getPotionStock()[i];
                if (m_hero->getGolds()>=popo->getPrice()) {
                    m_hero->trade(merchant, popo);
                    ui->lbl_golds->setText("Golds: " + QString::fromStdString(to_string(m_hero->getGolds())));
                    ui->lbl_merchantSpeak->setText("Thanks i'll remember it!");
                    searchInputShop();
                } else {
                    ui->lbl_merchantSpeak->setText("Go somewhere else you poor little guy");
                }
                break;
            }
        }
    } else if (ui->list_weapons->currentItem()!=nullptr) {
        Weapon* weapon = nullptr;
        for (int i =0;i<ui->list_weapons->count();i++) {
            if (ui->list_weapons->currentItem()->text().QString::toStdString().find(merchant->getWeaponStock()[i]->getName()) != string::npos) {
                weapon = merchant->getWeaponStock()[i];
                if (m_hero->getGolds()>=weapon->getPrice()) {
                    m_hero->trade(merchant, weapon);
                    ui->lbl_golds->setText("Golds: " + QString::fromStdString(to_string(m_hero->getGolds())));
                    ui->lbl_merchantSpeak->setText("Thanks i'll remember it!");
                    searchInputShop();
                } else {
                    ui->lbl_merchantSpeak->setText("Go somewhere else you poor little guy");
                }
                break;
            }
        }
    } else {
        ui->lbl_merchantSpeak->setText("Select an Item to buy");
    }
}

void MainWindow::shopSellButtonClicked() {
    Merchant* merchant = m_shops[ui->cbox_shops->currentIndex()-1];
    if (ui->list_invSell->currentItem()!=nullptr) {
        int allPotionSize = m_hero->getInventory()->getPotions().size();
        int index = ui->list_invSell->currentRow();
        if (index>=allPotionSize) {
            m_hero->sell(merchant, m_hero->getInventory()->getWeapons()[index-allPotionSize]);
            ui->lbl_merchantSpeak->setText("what a trash piece, but i'll take it");
        } else {
            m_hero->sell(merchant, m_hero->getInventory()->getPotions()[index]);
            ui->lbl_merchantSpeak->setText("I wonder why you sold me this potion");
        }
        searchInputShop();
        ui->lbl_golds->setText("Golds: " + QString::fromStdString(to_string(m_hero->getGolds())));
    } else {
        ui->lbl_merchantSpeak->setText("Select an Item to sell");
    }
}

void MainWindow::mineButtonClicked() {
    if (ui->Game->currentIndex() != m_lastIndex) {
        m_lastIndex = getUiStackedWidgetIndex("Game");
    }
    if (ui->cbox_mines->currentIndex()==0) {
        ui->btn_Enter->setEnabled(false);
    }
    ui->Game->setCurrentIndex(7);
}

void MainWindow::mineComboBoxChanged() {
    if (ui->cbox_mines->currentIndex()>0) {
        ui->btn_Enter->setEnabled(true);
    } else {
        ui->btn_Enter->setEnabled(false);
    }
}

void MainWindow::enterMineButtonClicked() {
    ui->frm_menu->setHidden(false);
    Mine* mine = m_mines[ui->cbox_mines->currentIndex()-1];
    ui->stk_mine->setCurrentIndex(1);
    ui->nb_lastIndex->setValue(m_lastIndex);
    ui->btn_back2->setEnabled(false);
    ui->btn_worldMap->setEnabled(false);
    ui->lbl_remainingMonster->setText(QString::fromStdString(to_string(mine->getMonsterNumber()))
                                      +" Remaining monsters");
    if (!mine->getMonster().empty()) {
        ui->btn_fight->setEnabled(true);
        ui->btn_quitMine->setEnabled(false);
    } else {
        ui->btn_quitMine->setEnabled(true);
        ui->btn_fight->setEnabled(false);
    }
}

void MainWindow::quitMineButtonClicked() {
    ui->stk_mine->setCurrentIndex(0);
    m_lastIndex = ui->nb_lastIndex->value();
    ui->btn_back2->setEnabled(true);
    ui->btn_worldMap->setEnabled(true);
    backButtonClicked();
    m_mines[ui->cbox_mines->currentIndex()-1]->levelUp();
    getAllBuildings();
}

void MainWindow::fightMineButtonClicked() {
    Mine* mine = m_mines[ui->cbox_mines->currentIndex()-1];
    ui->stk_mineFight->setCurrentIndex(0);
    ui->btn_potion->setEnabled(true);
    ui->btn_attack->setEnabled(true);
    ui->lbl_heroPictureMine->setStyleSheet(ui->lbl_heroPicture->styleSheet());
    ui->lbl_monsterPictureMine->setStyleSheet("image :url("+QString::fromStdString(mine->getMonster()[0]->getImagePath())+")");
    ui->lbl_heroHp->setText(QString::number(m_hero->getHp())+"/"+QString::number(m_hero->getMaxHp()));
    ui->lbl_monsterHp->setText(QString::number(mine->getMonster()[0]->getHp())+"/"+QString::number(mine->getMonster()[0]->getMaxHp()));
    ui->lbl_fightTextMine->setText("You've encountered a " +
                                   QString::fromStdString(mine->getMonster()[0]->getName()));
    ui->stk_mine->setCurrentIndex(2);
    ui->frm_menu->setHidden(true);
}

void MainWindow::goBackButtonClicked() {
    ui->stk_mineFight->setCurrentIndex(0);
}

void MainWindow::drinkMineButtonClicked() {
    if (ui->list_potionsMine->currentRow()>=0) {
        if (m_hero->getHp() < m_hero->getMaxHp()) {
            goBackButtonClicked();
            Potion* popo = m_hero->getInventory()->getPotions()[ui->list_potionsMine->currentRow()];
            m_hero->drink(popo);
            ui->lbl_fightTextMine->setText("You healed " + QString::number(popo->getHp()) + " Hp");
            ui->lbl_heroHp->setText(QString::number(m_hero->getHp())+"/"+QString::number(m_hero->getMaxHp()));
        } else {
            ui->lbl_fightTextMine->setText("You don't need to drink that");
        }
    } else {
        ui->lbl_fightTextMine->setText("Select a potion before drinking the void");
    }
}

void MainWindow::potionButtonClicked() {
    ui->stk_mineFight->setCurrentIndex(1);
    vector<Potion*> inv = m_hero->getInventory()->getPotions();

    ui->list_potionsMine->clear();

    for (size_t x=0;x<inv.size();x++) {
        if (inv[x]->getName().find(ui->txt_search->toPlainText().QString::toStdString()) != string::npos) {
            ui->list_potionsMine->addItem(QString::fromStdString(inv[x]->getName()));
        }
    }
}

void MainWindow::attackButtonClicked() {
    ui->stk_mineFight->setCurrentIndex(0);
    QString monsterInfo = "";
    int damage = 0;
    Mine* mine = m_mines[ui->cbox_mines->currentIndex()-1];
    if (m_hero->getClass()=="Warrior") {
        damage =m_hero->getDamage()*1.5;
        mine->getMonster()[0]->removeHp(damage);
    } else {
        damage = m_hero->getDamage();
        mine->getMonster()[0]->removeHp(m_hero->getDamage());
    }
    monsterInfo="You've dealt "+QString::number(damage-mine->getMonster()[0]->getDefence())+" Damage";
    ui->lbl_monsterHp->setText(QString::number(mine->getMonster()[0]->getHp())+"/"+QString::number(mine->getMonster()[0]->getMaxHp()));
    if (mine->getMonster()[0]->getHp()==0) {
        ui->stk_mineFight->setCurrentIndex(2);
        if (mine->getMineLevel()>=6) {
            switch (getRandNumber(0,1)) {
            case 0:
                m_hero->addToInventory(new Potion(4));
                break;
            case 1:
                m_hero->addToInventory(new Potion(4));
                break;
            }
        }
        m_hero->setGolds(m_hero->getGolds()+mine->getMonster()[0]->getGolds());
        ui->btn_attack->setEnabled(false);
        ui->btn_potion->setEnabled(false);
        mine->removeMonster(mine->getMonster()[0]);
        ui->lbl_fightTextMine->setText(monsterInfo);
    } else {
        monsterAttack(monsterInfo);
    }
}

void MainWindow::monsterAttack(QString info) {
    Mine* mine = m_mines[ui->cbox_mines->currentIndex()-1];
    QString infoPlayer = "";
    bool takeDmg = true;
    if (m_hero->getClass()=="Mage") {
        int dodgeNumber=getRandNumber(1,100);
        if (dodgeNumber<m_hero->getBonuses()) {
            takeDmg = false;
            infoPlayer= "\nand you dodged the ennemy attack";
        }
    }
    if (takeDmg) {
        m_hero->removeHp(mine->getMonster()[0]->getDamage());
        ui->lbl_heroHp->setText(QString::number(m_hero->getHp())+"/"+QString::number(m_hero->getMaxHp()));
        infoPlayer = "\nand taken "+QString::number(mine->getMonster()[0]->getDamage()-m_hero->getDefence())+ " Damage";
    }
    ui->lbl_fightTextMine->setText(info + infoPlayer);
    if (m_hero->getHp()==0) {
        ui->Game->setCurrentIndex(8);
        ui->lbl_end->setText("You died");
    }
}
