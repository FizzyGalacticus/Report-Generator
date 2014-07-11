#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QRect>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Report Generator");

    QDesktopWidget desktop;
    QWidget *wdg = new QWidget;
    wdg->setWindowTitle("Pop-up");
    //wdg->geometry().setHeight(200);
    //wdg->geometry().setWidth(200);
    wdg->setFixedSize(50,40);

    QPushButton *myButton = new QPushButton(wdg);
    myButton->setText("Push me!");
    myButton->show();
    wdg->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
