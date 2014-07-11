#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Report Generator");

    QWidget *wdg = new QWidget;
    wdg->setWindowTitle("Pop-up");

    QPushButton *myButton = new QPushButton(wdg);
    myButton->setText("Push me!");
    myButton->show();
    wdg->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
