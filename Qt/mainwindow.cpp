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
    ui(new Ui::MainWindow),
    _initialsListView(new QListWidget(this))
{
    ui->setupUi(this);
    this->setWindowTitle("Report Generator");

    connect
                (
                    _initialsListView,
                    SIGNAL(itemClicked(QListWidgetItem*)),
                    this,
                    SLOT(_initialsListItemHasBeenClicked(QListWidgetItem*))
                );

    /*const QString initials = getUserInputString(this, "Initials", "Initials:");

    QDesktopWidget desktop;
    QWidget *wdg = new QWidget;
    wdg->setWindowTitle("Pop-up");
    wdg->setFixedSize(50,40);

    QPushButton *myButton = new QPushButton(wdg);
    myButton->setText("Push me!");
    myButton->show();
    wdg->show();*/

    _setupUsers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_initialsListItemHasBeenClicked(QListWidgetItem * item)
{
    if(item != _initialsListView->item(_initialsListView->count()-1))
    {
            _currentUser = item->text();
    }
    else
    {
        string userInitials = getUserInputString(this,"Initials","Initials:").toStdString();
        appendLineToFile(tr("users"),tr(userInitials.c_str()));
    }
    qDebug() << item->text().toStdString().c_str() << "Clicked!" << '\n';
}

void MainWindow::_setupUsers()
{
    vector<string> myList = getStringListFromFile("users");

    if( myList.empty())
    {
        string userInitials = getUserInputString(this,"Initials","Initials:").toStdString();
        myList.push_back(userInitials);
        appendLineToFile(tr("users"),tr(userInitials.c_str()));
    }

    for(unsigned int i = 0; i < myList.size(); i++)
    {
        _initialsListView->addItem(QString(myList[i].c_str()));
        _initialsListView->item(i)->setTextColor("Black");
    }
    _initialsListView->addItem("Add new...");
    _initialsListView->setGeometry(20,11,100,50);
    _initialsListView->show();
}

#endif
