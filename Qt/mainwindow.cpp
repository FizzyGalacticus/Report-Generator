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
    _initials(new QLabel("Initials",this))
    //_hddscan(new QCheckBox(this)),
    //_hddpass(new QCheckBox(this)),
    //_hddfail(new QCheckBox(this))
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

void MainWindow::_setup()
{
    _setupInitials();
    _setupHDDCheckboxes();
}

#endif
