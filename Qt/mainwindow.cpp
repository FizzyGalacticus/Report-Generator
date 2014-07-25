#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "io.cpp"
#include "initials.cpp"
#include "checkboxes.cpp"
#include "textbox.cpp"
#include <QPushButton>
#include <QDesktopWidget>
#include <QProcess>
#include <QFile>
#include <QSysInfo>
#include <QTextEdit>
#include <string>
using std::string;
#include <exception>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _mainWindowIcon(":/Resources/Icons/CWILogo.bmp"),
    _clipboard(QApplication::clipboard()),
    _initials(new QLabel("Initials",this)),
    _date(QDate::currentDate().toString("MM/dd/yy"))
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

    qDebug() << _date.toStdString().c_str() << QTime::currentTime().toString("hh:mm:ss").toStdString().c_str() << '\n';

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_generateReport()
{
    string report = "";

    if(_addInitials->isChecked() && _currentUser.length())
        report += _currentUser.toStdString() + " - ";

    if(_addDate->isChecked() && _addTime->isChecked())
        report += _date.toStdString() + " " +
                QTime::currentTime().toString("hh:mm:ss").toStdString() + " - ";
    else if(_addDate->isChecked())
        report += _date.toStdString() + " - ";
    else if(_addTime->isChecked())
        report += QTime::currentTime().toString("hh:mm AP").toStdString() + " - ";

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

    if(_upgradeInPlace->isChecked())
        report += "Performed Windows Upgrade-In-Place to repair operating system.\n";

    if(_resetBrowsers->isChecked())
        report += "Reset all web browser settings to default and disabled all add-on/extensions.\n";

    if(_textbox) _textbox->setText(report.c_str());
}

void MainWindow::_resetButtonHasBeenClicked()
{
    _addInitials->setChecked(false);
    _addDate->setChecked(false);
    _addTime->setChecked(false);
    _checkout->setChecked(false);
    _hddscan->setChecked(false);
    _sfcscan->setChecked(false);
    _upgradeInPlace->setChecked(false);
    _resetBrowsers->setChecked(false);
    _textbox->setText("Report has been reset!");

    qDebug() << "Report has been reset!";
}

void MainWindow::_setupResetButton()
{
    _resetButton = new QPushButton("Reset",this);
    _resetButton->setGeometry(0,height()-30,50,30);
    connect(_resetButton,SIGNAL(clicked()),this,SLOT(_resetButtonHasBeenClicked()));
    _resetButton->show();
}

void MainWindow::_setup()
{
    _setupInitials();
    _setupCheckboxes();
    _setupTextbox();
    _setupResetButton();
}

#endif
