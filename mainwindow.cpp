#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Game->setCurrentIndex(0);
    connect(ui->btn_quit,SIGNAL(clicked(bool)),this,SLOT(quitButtonClicked()));
    connect(ui->btn_start,SIGNAL(clicked(bool)),this,SLOT(startButtonClicked()));
    connect(ui->btn_back,SIGNAL(clicked(bool)),this,SLOT(backButtonClicked()));
    connect(ui->btn_createHero,SIGNAL(clicked(bool)),this,SLOT(createHeroButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
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

