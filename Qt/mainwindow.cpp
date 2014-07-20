#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "io.cpp"
#include "initials.cpp"
#include <QPushButton>
#include <QDesktopWidget>
#include <QProcess>
#include <QFile>
#include <QSysInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _initials(new QLabel("Initials",this))
{
    ui->setupUi(this);
    this->setWindowTitle("Report Generator");

    /*
    QDesktopWidget desktop;
    QWidget *wdg = new QWidget;
    wdg->setWindowTitle("Pop-up");
    wdg->setFixedSize(50,40);

    QPushButton *myButton = new QPushButton(wdg);
    myButton->setText("Push me!");
    myButton->show();
    wdg->show();*/

    _setupInitials();

//    QFile::copy("://Resources/Ninite/Ninite-NoAV.exe", "Ninite-NoAV.exe");
//    QProcess::startDetached("Ninite-NoAV.exe",QStringList("/silent"));

    if(QSysInfo::windowsVersion()==QSysInfo::WV_WINDOWS7) qDebug() << "Windows 7!" << '\n';
}

MainWindow::~MainWindow()
{
    delete ui;
}

#endif
