#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "io.cpp"
#include <QDebug>
#include <QPushButton>
#include <QRect>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Report Generator");

    const QString initials = getUserInput(this, "Initials", "Initials:");

    QDesktopWidget desktop;
    QWidget *wdg = new QWidget;
    wdg->setWindowTitle("Pop-up");
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

#endif
