#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "io.cpp"
#include <QDebug>
#include <QPushButton>
#include <QRect>
#include <QDesktopWidget>
#include <QStringList>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Report Generator");

    /*const QString initials = getUserInputString(this, "Initials", "Initials:");

    QDesktopWidget desktop;
    QWidget *wdg = new QWidget;
    wdg->setWindowTitle("Pop-up");
    wdg->setFixedSize(50,40);

    QPushButton *myButton = new QPushButton(wdg);
    myButton->setText("Push me!");
    myButton->show();
    wdg->show();*/

    vector<string> myList = getStringListFromFile("users");

    if( myList.empty())
    {
        string userInitials = getUserInputString(this,"Initials","Initials:").toStdString();
        myList.push_back(userInitials);
        appendLineToFile(tr("users"),tr(userInitials.c_str()));
    }

    QListWidget * initials = new QListWidget(this);
    for(unsigned int i = 0; i < myList.size(); i++)
    {
        initials->addItem(QString(myList[i].c_str()));
        initials->item(i)->setTextColor("Black");
    }
    initials->addItem("Add new...");
    initials->setGeometry(0,0,width(),height());
    initials->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

#endif
