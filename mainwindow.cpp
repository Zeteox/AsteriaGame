#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidgetIndexSetup();

    connectAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::stackedWidgetIndexSetup() {
    ui->Game->setCurrentIndex(0);
    ui->stk_Warrior->setCurrentIndex(0);
    ui->stk_Mage->setCurrentIndex(0);
    ui->stk_Paladin->setCurrentIndex(0);
}

void MainWindow::connectAll() {
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
}

void MainWindow::quitButtonClicked()
{
    this->close();
}

void MainWindow::startButtonClicked()
{
    ui->Game->setCurrentIndex(1);
}

void MainWindow::backButtonClicked()
{
    QStackedWidget* Game = ui->Game;
    Game->setCurrentIndex(Game->currentIndex()-1);
}

void MainWindow::createHeroButtonClicked()
{
    ui->Game->setCurrentIndex(0);
}


void MainWindow::btnWarriorClicked()
{
    if (!ui->btn_warrior->isChecked()) {
        ui->btn_warrior->setChecked(true);
    }
    ui->btn_mage->setChecked(false);
    ui->btn_paladin->setChecked(false);
}


void MainWindow::btnMageClicked()
{
    if (!ui->btn_mage->isChecked()) {
        ui->btn_mage->setChecked(true);
    }
    ui->btn_warrior->setChecked(false);
    ui->btn_paladin->setChecked(false);
}


void MainWindow::btnPaladinClicked()
{
    if (!ui->btn_paladin->isChecked()) {
        ui->btn_paladin->setChecked(true);
    }
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

