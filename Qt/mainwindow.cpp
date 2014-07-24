#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "io.cpp"
#include "initials.cpp"
#include "checkboxes.cpp"
#include <QPushButton>
#include <QDesktopWidget>
#include <QProcess>
#include <QFile>
#include <QSysInfo>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _mainWindowIcon(":/Resources/Icons/CWILogo.bmp"),
    _initials(new QLabel("Initials",this))
    //_hddscan(new QCheckBox(this)),
    //_hddpass(new QCheckBox(this)),
    //_hddfail(new QCheckBox(this))
{
    ui->setupUi(this);
    this->setWindowTitle("ComputerWerks Inc. - Report Generator");
    this->setWindowIcon(_mainWindowIcon);
    this->setFixedSize(600,400);

//    QDesktopWidget desktop;
//    QWidget *wdg = new QWidget;
//    wdg->setWindowTitle("Pop-up");
//    wdg->setFixedSize(200,40);

//    QPushButton *myButton = new QPushButton(wdg);
//    myButton->setText("Push me!");
//    wdg->show();

    _setup();

//    QFile::copy("://Resources/Ninite/Ninite-NoAV.exe", "Ninite-NoAV.exe");
//    QProcess::startDetached("Ninite-NoAV.exe",QStringList("/silent"));

#ifdef __WINDOWS__
    if(QSysInfo::windowsVersion()==QSysInfo::WV_WINDOWS7) qDebug() << "Windows 7!" << '\n';
#endif

//    _initialsListView->setItemSelected(_initialsListView->item(0),1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_setupTextbox()
{
    _textbox = new QTextEdit("Default Text",this);
    _textbox->setGeometry(_initialsListView->width()+3,_initialsListView->geometry().y(),width()-_initialsListView->width()-3,_initialsListView->height());
    _textbox->show();
}

void MainWindow::_setup()
{
    _setupInitials();
    _setupCheckoutCheckbox();
    _setupHDDCheckboxes();
    _setupSFCCheckboxes();
    _setupTextbox();
}

#endif
