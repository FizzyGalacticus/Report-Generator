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
#include <QDateTime>
#include <QTextEdit>
#include <string>
using std::string;
#include <exception>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _mainWindowIcon(":/Resources/Icons/CWILogo.bmp"),
    _initials(new QLabel("Initials",this))
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

    qDebug() << QDate::currentDate().toString("MM/dd/yy").toStdString().c_str() << QTime::currentTime().toString("hh:mm:ss").toStdString().c_str() << '\n';

//    _initialsListView->setItemSelected(_initialsListView->item(0),1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_setupTextbox()
{
    _textbox = new QTextEdit("Report is generated here. Start customizing!",this);
    _textbox->setGeometry(_initialsListView->width()+3,_initialsListView->geometry().y(),width()-_initialsListView->width()-3,_initialsListView->height());
    _textbox->show();
}

void MainWindow::_generateReport()
{
    string report = "";
    if(_checkout->isChecked())
        report += "Pulled system from shelf.\n";

    if(_hddscan && _hddscan->isChecked())
    {
        report += "Ran a surface scan on HDD - ";
        if(_hddpass && _hddpass->isChecked())
            report += "passed.\n";
        else if(_hddfail && _hddfail->isChecked())
            report += "failed.\n";
    }

    if(_sfcscan && _sfcscan->isChecked())
    {
        report += "Ran System File Checker - ";
        if(_sfcpass && _sfcpass->isChecked())
            report += "passed.\n";
        else if(_sfcfail && _sfcfail->isChecked())
            report += "failed.\n";
    }

    if(_textbox) _textbox->setText(report.c_str());
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
