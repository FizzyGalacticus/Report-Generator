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

    /*
    QDesktopWidget desktop;
    QWidget *wdg = new QWidget;
    wdg->setWindowTitle("Pop-up");
    wdg->setFixedSize(50,40);

    QPushButton *myButton = new QPushButton(wdg);
    myButton->setText("Push me!");
    myButton->show();
    wdg->show();*/

    _setup();

//    QFile::copy("://Resources/Ninite/Ninite-NoAV.exe", "Ninite-NoAV.exe");
//    QProcess::startDetached("Ninite-NoAV.exe",QStringList("/silent"));

    if(QSysInfo::windowsVersion()==QSysInfo::WV_WINDOWS7) qDebug() << "Windows 7!" << '\n';

//    _initialsListView->setItemSelected(_initialsListView->item(0),1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_hddscanStateHasChanged(int state)
{
    if(state)
    {
        _hddpass->setCheckable(true);
        _hddpass->setVisible(true);
        _hddfail->setCheckable(true);
        _hddfail->setVisible(true);
    }
    else
    {
        _hddpass->setCheckable(false);
        _hddpass->setChecked(false);
        _hddpass->setVisible(false);
        _hddfail->setCheckable(false);
        _hddfail->setChecked(false);
        _hddfail->setVisible(false);
    }
}

void MainWindow::_hddpassStateHasChanged(int state)
{
  if(state) _hddfail->setChecked(false);
}

void MainWindow::_hddfailStateHasChanged(int state)
{
    if(state) _hddpass->setChecked(false);
}

void MainWindow::_setupHDDCheckboxes()
{
    //     Main HDD Scan Checkbox
    _hddscan = new QCheckBox(this);
    _hddscan->setText("HDD Scan");
    const int hddscanY = _initialsListView->geometry().y()+_initialsListView->height()+3;
    _hddscan->setGeometry(0,hddscanY,_initialsListView->width(),_initials->height()+2);
    connect(_hddscan,SIGNAL(stateChanged(int)),this,SLOT(_hddscanStateHasChanged(int)));

    //     HDD Scan Pass Checkbox
    _hddpass = new QCheckBox(this);
    _hddpass->setText("Passed");
    const int hddpassY = _hddscan->geometry().y() + _hddscan->height() + 3;
    _hddpass->setGeometry(15,hddpassY,_hddscan->width(),_hddscan->height());
    _hddpass->setCheckable(false);
    _hddpass->setVisible(false);
    connect(_hddpass,SIGNAL(stateChanged(int)),this,SLOT(_hddpassStateHasChanged(int)));

    //     HDD Scan Fail Checkbox
    _hddfail = new QCheckBox(this);
    _hddfail->setText("Failed");
    const int hddfailY = _hddpass->geometry().y() + _hddscan->height() + 3;
    _hddfail->setGeometry(15,hddfailY,_hddscan->width(),_hddscan->height());
    _hddfail->setCheckable(false);
    _hddfail->setVisible(false);
    connect(_hddfail,SIGNAL(stateChanged(int)),this,SLOT(_hddfailStateHasChanged(int)));
}

void MainWindow::_sfcscanStateHasChanged(int state)
{
    if(state)
    {
        _sfcpass->setCheckable(true);
        _sfcpass->setVisible(true);
        _sfcfail->setCheckable(true);
        _sfcfail->setVisible(true);
    }
    else
    {
        _sfcpass->setCheckable(false);
        _sfcpass->setChecked(false);
        _sfcpass->setVisible(false);
        _sfcfail->setCheckable(false);
        _sfcfail->setChecked(false);
        _sfcfail->setVisible(false);
    }
}

void MainWindow::_sfcpassStateHasChanged(int state)
{
  if(state) _sfcfail->setChecked(false);
}

void MainWindow::_sfcfailStateHasChanged(int state)
{
    if(state) _sfcpass->setChecked(false);
}

void MainWindow::_setupSFCCheckboxes()
{
    //     Main SFC Scan Checkbox
    _sfcscan = new QCheckBox(this);
    _sfcscan->setText("SFC Scan");
    const int sfcscanY = _hddfail->geometry().y() + _hddfail->height() + 3;
    _sfcscan->setGeometry(0,sfcscanY,_initialsListView->width(),_initials->height()+2);
    connect(_sfcscan,SIGNAL(stateChanged(int)),this,SLOT(_sfcscanStateHasChanged(int)));

    //     SFC Scan Pass Checkbox
    _sfcpass = new QCheckBox(this);
    _sfcpass->setText("Passed");
    const int sfcpassY = _sfcscan->geometry().y() + _sfcscan->height() + 3;
    _sfcpass->setGeometry(15,sfcpassY,_sfcscan->width(),_sfcscan->height());
    _sfcpass->setCheckable(false);
    _sfcpass->setVisible(false);
    connect(_sfcpass,SIGNAL(stateChanged(int)),this,SLOT(_sfcpassStateHasChanged(int)));

    //     SFC Scan Fail Checkbox
    _sfcfail = new QCheckBox(this);
    _sfcfail->setText("Failed");
    const int sfcfailY = _sfcpass->geometry().y() + _sfcscan->height() + 3;
    _sfcfail->setGeometry(15,sfcfailY,_sfcscan->width(),_sfcscan->height());
    _sfcfail->setCheckable(false);
    _sfcfail->setVisible(false);
    connect(_sfcfail,SIGNAL(stateChanged(int)),this,SLOT(_sfcfailStateHasChanged(int)));
}

void MainWindow::_setup()
{
    _setupInitials();
    _setupHDDCheckboxes();
    _setupSFCCheckboxes();
}

#endif
