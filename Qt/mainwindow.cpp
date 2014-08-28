#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "io.cpp"
#include "initials.cpp"
#include "checkboxes.cpp"
#include "textbox.cpp"
#include "malwarewindow.cpp"
#include "menues.cpp"
#include <QPushButton>
#include <QDesktopWidget>
#include <QProcess>
#include <QFile>
#include <QSysInfo>
#include <QTextEdit>
#include <string>
using std::string;
#include <exception>
#include <QWindow>
#include <QDialog>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _mainWindowIcon(":/Resources/Icons/CWILogo.bmp"),
    _clipboard(QApplication::clipboard()),
    _initials(new QLabel(tr("Initials"),this)),
    _date(QDate::currentDate().toString("MM/dd/yy")),
    _currentlySelectedMalware(new QStringList),
    _removedWithMalwarebytes(-1),
    _removedWithAvast(-1),
    _db(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
{
    ui->setupUi(this);
    this->setWindowTitle("ComputerWerks Inc. - Report Generator");
    this->setWindowIcon(_mainWindowIcon);
    this->setFixedSize(600,400);

    _setup();

    //QFile::copy("://Resources/Ninite/Ninite-NoAV.exe", "Ninite-NoAV.exe");
    //QProcess::startDetached("Ninite-NoAV.exe",QStringList("/silent"));

#ifdef __WINDOWS__
    if(QSysInfo::windowsVersion()==QSysInfo::WV_WINDOWS7) qDebug() << tr("Windows 7!") << '\n';
#endif

    qDebug() << _date.toStdString().c_str() << QTime::currentTime().toString("hh:mm:ss").toStdString().c_str() << '\n';

    _db->setHostName("CWI");
    _db->setDatabaseName("CWIDB");
    bool ok = _db->open();

    if(ok)
    {
        qDebug() << "Database opened!";

        QSqlQuery * query = new QSqlQuery(*_db);
        query->exec("CREATE TABLE removedprograms(TITLE TEXT)");
        query->exec("INSERT INTO removedprograms VALUES (\"Search Protect\")");
        query->exec("SELECT * FROM removedprograms");

        while(query->next()) qDebug() << query->value(0).toString();
    }
    else qDebug() << "Database failed to open.";
}

MainWindow::~MainWindow()
{
    delete ui;
    _db->close();
}

void MainWindow::_generateReport()
{
    string report = "";

    if(_addInitials->isChecked() && _currentUser.length())
        report += _currentUser.toStdString() + " - ";

    if(_addDate->isChecked() && _addTime->isChecked())
        report += _date.toStdString() + " " +
                QTime::currentTime().toString("hh:mm AP").toStdString() + " - ";
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

    if(_currentlySelectedMalware->count())
    {
        report += "Removed the following program(s): ";
        for(int i = 0; i < _currentlySelectedMalware->count(); i++)
        {
            if(i == _currentlySelectedMalware->count()-1 && _currentlySelectedMalware->count() != 1) report += ("and " + _currentlySelectedMalware->at(i).toStdString() + ".\n");
            else if(_currentlySelectedMalware->count() == 1) report += (_currentlySelectedMalware->at(0).toStdString() + '\n');
            else report += _currentlySelectedMalware->at(i).toStdString() + ", ";
        }
    }

    if(_removedWithMalwarebytes >= 0)
        report += "Ran a scan with Malwarebytes' Anti-Malware and removed " +
                QString::number(_removedWithMalwarebytes).toStdString() +
                " found infected object(s).\n";

    if(_removedWithAvast >= 0)
        report += "Ran a boot-time scan with Avast! Free Anti-Virus and removed " +
                QString::number(_removedWithAvast).toStdString() +
                " found infected object(s).\n";

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

    if(_installedPrograms->isChecked())
    {
        report += "Installed/updated the following program(s): ";

        if(!_win8->isChecked()) report += "Adobe Flash Player, ";
        report += "Adobe Shockwave, Adobe Reader, Java, Microsoft Silverlight, CCleaner";
        if(_win8->isChecked()) report += ", Classic Shell";

        if(_installedAV->isChecked()) report += ", Malwarebytes' Anti-Malware, and Avast! Free Anti-Virus.\n";
        else report += ", and Malwarebytes' Anti-Malware.\n";
    }

    if(_windowsUpdates->isChecked())
        report += "Installed the latest Windows updates from Microsoft.\n";

    if(_restorePoints->isChecked())
        report += "Deleted old restore points potentially harboring infections and created a new 'CWI' restore point.\n";

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
    _windowsUpdates->setChecked(false);
    _restorePoints->setChecked(false);
    _installedPrograms->setChecked(false);
    _currentlySelectedMalware->clear();
    _removedWithMalwarebytes = -1;
    _removedWithAvast = -1;
    _textbox->setText(tr("Report has been reset!"));

    qDebug() << tr("Report has been reset!");
}

void MainWindow::_setupResetButton()
{
    _resetButton = new QPushButton(tr("Reset"),this);
    _resetButton->setGeometry(0,height()-30,50,30);
    connect(_resetButton,SIGNAL(clicked()),this,SLOT(_resetButtonHasBeenClicked()));
    _resetButton->show();
}

void MainWindow::_setup()
{
    _setupMenus();
    _setupInitials();
    _setupCheckboxes();
    _setupTextbox();
    _setupResetButton();
    _setupMalwareButton();
}

void MainWindow::_setupMalwareButton()
{
    _malwareButton = new QPushButton(tr("Malware"),this);
    _malwareButton->setGeometry(width()-100,height()-30,100,30);
    connect(_malwareButton,SIGNAL(clicked()),this,SLOT(_malwareButtonHasBeenClicked()));
    _malwareButton->show();
}

#endif
