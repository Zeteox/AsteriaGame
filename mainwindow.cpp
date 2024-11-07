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

void MainWindow::stackedWidgetIndexSetup() {
    ui->Main->setCurrentIndex(0);
    ui->stk_Warrior->setCurrentIndex(0);
    ui->stk_Mage->setCurrentIndex(0);
    ui->stk_Paladin->setCurrentIndex(0);
    ui->stk_invStats->setCurrentIndex(0);
}

void MainWindow::connectAll() {
    connect(ui->btn_quit,SIGNAL(clicked(bool)),this,SLOT(quitButtonClicked()));
    connect(ui->btn_quitMenu,SIGNAL(clicked(bool)),this,SLOT(quitButtonClicked()));
    connect(ui->btn_start,SIGNAL(clicked(bool)),this,SLOT(startButtonClicked()));
    connect(ui->btn_back,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));
    connect(ui->btn_back2,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));
    connect(ui->btn_resume,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));
    connect(ui->btn_worldMap,SIGNAL(clicked(bool)),this,SLOT(worldButtonClicked()));
    connect(ui->btn_hero,SIGNAL(clicked(bool)),this,SLOT(heroButtonClicked()));
    connect(ui->txt_search,SIGNAL(textChanged()),this,SLOT(searchInput()));
    connect(ui->btn_stats,SIGNAL(clicked(bool)),this,SLOT(statsButtonClicked()));
    connect(ui->btn_inv,SIGNAL(clicked(bool)),this,SLOT(invButtonClicked()));
    connect(ui->btn_Menu,SIGNAL(clicked(bool)),this,SLOT(menuButtonClicked()));

    connect(ui->btn_createHero,SIGNAL(clicked(bool)),this,SLOT(createHeroButtonClicked()));

    connect(ui->btn_warrior,SIGNAL(clicked(bool)),this,SLOT(btnWarriorClicked()));
    connect(ui->btn_statsWarrior,SIGNAL(clicked(bool)),this,SLOT(btnWarriorStatsClicked()));

    connect(ui->btn_mage,SIGNAL(clicked(bool)),this,SLOT(btnMageClicked()));
    connect(ui->btn_statsMage,SIGNAL(clicked(bool)),this,SLOT(btnMageStatsClicked()));

    connect(ui->btn_paladin,SIGNAL(clicked(bool)),this,SLOT(btnPaladinClicked()));
    connect(ui->btn_statsPaladin,SIGNAL(clicked(bool)),this,SLOT(btnPaladinStatsClicked()));

    connect(ui->btn_village1,SIGNAL(clicked(bool)),this,SLOT(btnVillageOneClicked()));
    connect(ui->btn_village2,SIGNAL(clicked(bool)),this,SLOT(btnVillageTwoClicked()));
}

void MainWindow::quitButtonClicked()
{
    this->close();
}

void MainWindow::startButtonClicked()
{
    m_lastIndex = ui->Main->currentIndex();
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
    m_lastIndex = ui->Game->currentIndex();
    ui->Game->setCurrentIndex(3);
    ui->btn_village2->setEnabled(true);
}

void MainWindow::btnVillageTwoClicked() {
    m_lastIndex = ui->Game->currentIndex();
    ui->Game->setCurrentIndex(3);
}

void MainWindow::worldButtonClicked() {
    m_lastIndex = ui->Game->currentIndex();
    ui->Game->setCurrentIndex(0);
}

void MainWindow::heroButtonClicked() {
    m_lastIndex = ui->Game->currentIndex();
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
    if (ui->Game->currentIndex() != 2) {
        m_lastIndex = ui->Game->currentIndex();
    }
    ui->Game->setCurrentIndex(2);
}

void MainWindow::searchInput()
{
    if (m_hero != nullptr) {
        vector<Potion*> inv = m_hero->getInventory()->showPotions();

        ui->list_inventory->clear();

        for (size_t x=0;x<inv.size();x++) {
            if (inv[x]->getName().find(ui->txt_search->toPlainText().QString::toStdString()) != string::npos) {
                ui->list_inventory->addItem(QString::fromStdString(inv[x]->getName()));
            }
        }
    }
}

