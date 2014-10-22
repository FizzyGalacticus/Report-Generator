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
#include <exception>
#include <QWindow>
#include <QDialog>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _centralWidget(new QWidget),
    _centralWidgetLayout(new QVBoxLayout),
    _mainWindowIcon(":/Resources/Icons/CWILogo.ico"),
    _clipboard(QApplication::clipboard()),
    _initialsListView(new QListWidget),
    _initials(new QLabel(tr("Initials"),this)),
    _addInitials(new QCheckBox),
    _date(QDate::currentDate().toString("MM/dd/yy")),
    _addDate(new QCheckBox),
    _addTime(new QCheckBox),
    _checkout(new QCheckBox),
    _hddscan(new QCheckBox),
    _hddpass(new QCheckBox),
    _hddfail(new QCheckBox),
    _sfcscan(new QCheckBox),
    _sfcpass(new QCheckBox),
    _sfcfail(new QCheckBox),
    _upgradeInPlace(new QCheckBox),
    _resetBrowsers(new QCheckBox),
    _windowsUpdates(new QCheckBox),
    _restorePoints(new QCheckBox),
    _installedPrograms(new QCheckBox),
    _installedAV(new QCheckBox),
    _win8(new QCheckBox),
    _workCompleted(new QCheckBox),
    _textbox(new QTextEdit("Report is generated here. Start customizing!",this)),
    _currentlySelectedMalware(new QStringList),
    _removedWithMalwarebytes(-1),
    _removedWithAvast(-1),
    _db(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", "CWI"))),
    _dbquery(NULL),
    _saveReportButton(new QPushButton("Save Report")),
    _niniteIcon(new QImage(":/Resources/Icons/ninite.png")),
    _installAV(new QCheckBox("Install AV?")),
    _niniteProcess(NULL),
    _niniteInstallerFile(new QFile("Ninite-NoAV.exe"))
{
    ui->setupUi(this);
    this->setWindowTitle("ComputerWerks Inc. - Report Generator");
    this->setWindowIcon(_mainWindowIcon);
    this->setCentralWidget(_centralWidget);

    _setup();

    qDebug() << _date << QTime::currentTime().toString("hh:mm:ss") << '\n';
}

MainWindow::~MainWindow()
{
    delete ui;
    _db->close();


    if(_niniteInstallerFile->exists())
    {
        qDebug() << _niniteInstallerFile->fileName() << "exists!";
        _niniteInstallerFile->close();
        if(!_niniteInstallerFile->remove())
        {
            qDebug() << "...but couldn't be removed for some stupid reason!";
            qDebug() << "Error:" << _niniteInstallerFile->errorString();
        }
    }
}

void MainWindow::_refreshButtonHasBeenClicked()
{
    _generateReport();
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

void MainWindow::_setup()
{
    _setupMenus();
    _setupInitials();
    _setupCheckboxes();
    _setupButtons();

    _centralWidget->setLayout(_centralWidgetLayout);
}

void MainWindow::_setupButtons()
{
    QHBoxLayout * buttons = new QHBoxLayout;

    _refreshButton = new QPushButton(tr("Refresh"),this);
    _resetButton = new QPushButton(tr("Reset"),this);
    _malwareButton = new QPushButton(tr("Malware"),this);

    _refreshButton->setMaximumSize(50,30);
    _resetButton->setMaximumSize(50,30);
    _malwareButton->setMaximumSize(50,30);
    _saveReportButton->setMaximumSize(80,30);

    connect(_refreshButton, SIGNAL(clicked()),this,SLOT(_refreshButtonHasBeenClicked()));
    connect(_resetButton,SIGNAL(clicked()),this,SLOT(_resetButtonHasBeenClicked()));
    connect(_malwareButton,SIGNAL(clicked()),this,SLOT(_malwareButtonHasBeenClicked()));
    connect(_saveReportButton,SIGNAL(clicked()),this,SLOT(_saveReportButtonHasBeenClicked()));

    buttons->addWidget(_refreshButton);
    buttons->addWidget(_resetButton);
    buttons->addStretch();
    buttons->addWidget(_saveReportButton);
    buttons->addStretch();
    buttons->addWidget(_malwareButton);

    _centralWidgetLayout->addLayout(buttons);
}

#endif
