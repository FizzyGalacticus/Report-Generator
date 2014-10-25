#ifndef _MENUES_CPP
#define _MENUES_CPP
#include "mainwindow.h"
#include <QMessageBox>
#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>

void MainWindow::_createMenus()
{
    _fileMenu = menuBar()->addMenu(tr("&File"));
    _fileMenu->addAction(_exitAct);

    _helpMenu = menuBar()->addMenu(tr("&Help"));
    _helpMenu->addAction(_aboutAct);
    _helpMenu->addAction(_aboutQtAct);
    _helpMenu->addAction(_aboutAuthorAct);

    _installMenu = menuBar()->addMenu(tr("&Install"));
    _installMenu->addAction(_niniteAct);
}

void MainWindow::_createActions()
{
    _exitAct = new QAction(tr("&Exit"), this);
    _exitAct->setStatusTip(tr("Exit the application"));
    connect(_exitAct, SIGNAL(triggered()), this, SLOT(close()));

    _aboutAct = new QAction(tr("&About"), this);
    _aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(_aboutAct, SIGNAL(triggered()), this, SLOT(_about()));

    _aboutQtAct = new QAction(tr("About &Qt"), this);
    _aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(_aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(_aboutQtAct, SIGNAL(triggered()), this, SLOT(_aboutQt()));

    _aboutAuthorAct = new QAction(tr("About &Author"), this);
    _aboutAuthorAct->setStatusTip(tr("Show information about Report-Generator's author"));
    connect(_aboutAuthorAct, SIGNAL(triggered()),this, SLOT(_aboutAuthor()));

    _niniteAct = new QAction(tr("&Ninite"),this);
    _niniteAct->setIcon(QIcon(QPixmap::fromImage(*_niniteIcon)));
    _niniteAct->setStatusTip(tr("Install applications using Ninite installer"));
    connect(_niniteAct, SIGNAL(triggered()), this, SLOT(_installNinite()));
}

void MainWindow::_about()
{
    QMessageBox::about(this, tr("About Menu"),
        tr("ComputerWerks, Inc. Report Generator."
           "<p>This program is to assist technicians "
           "at CWI in logging work done to client systems."));
}

void MainWindow::_aboutQt()
{
}

void MainWindow::_aboutAuthor()
{
    QMessageBox::about
            (
                this,
                tr("Authors Menu"),
                tr("<b>Author: </b> Dustin Dodson")
            );
}

void MainWindow::_installNinite()
{
    qDebug() << "Opening Ninite installer dialog!";

    QDialog * niniteInstallerDialog = new QDialog(this);
    QHBoxLayout * installerLayout = new QHBoxLayout;

    QLabel * niniteIconLabel = new QLabel();
    QPushButton * runNiniteButton = new QPushButton("Run Ninite!");

    niniteIconLabel->setPixmap(QPixmap::fromImage(_niniteIcon->scaled(64,64)));
    connect(runNiniteButton, SIGNAL(clicked()), this, SLOT(_runNiniteInstallerButtonHasBeenClicked()));

    installerLayout->addWidget(niniteIconLabel);
    installerLayout->addWidget(runNiniteButton);
    installerLayout->addWidget(_installAV);

    niniteInstallerDialog->setLayout(installerLayout);
    niniteInstallerDialog->exec();
}

void MainWindow::_runNiniteInstallerButtonHasBeenClicked()
{
#ifdef __WIN32 || defined __WIN32__ || defined __WINNT || defined __WINNT__
    const QSysInfo::WinVersion windowsVersion = QSysInfo::windowsVersion();
    delete _niniteProcess;
    _niniteProcess = new QProcess(this);

    connect(_niniteProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(_niniteInstallerIsFinished(int,QProcess::ExitStatus)));

    if(windowsVersion == QSysInfo::WV_WINDOWS7 || windowsVersion == QSysInfo::WV_VISTA || windowsVersion == QSysInfo::WV_XP)
    {
        qDebug() << "Running Windows 7, Vista, or XP!";
        QString niniteInstallerLocation = QDir::tempPath();
        _niniteInstallerFile->setAutoRemove(true);

        if(_installAV->isChecked())
        {
            qDebug() << "Running Ninite and installing AV!";
            niniteInstallerLocation += "Ninite-AV.exe";
            QFile::copy("://Resources/Ninite/Ninite-AV.exe",niniteInstallerLocation);
            _niniteInstallerFile->setFileName(niniteInstallerLocation);
            _niniteProcess->startDetached(_niniteInstallerFile->fileName());
        }
        else
        {
            qDebug() << "Running Ninite without installing AV!";
            niniteInstallerLocation += "Ninite-NoAV.exe";
            QFile::copy("://Resources/Ninite/Ninite-NoAV.exe", niniteInstallerLocation);
            _niniteInstallerFile->setFileName(niniteInstallerLocation);
            _niniteProcess->startDetached(_niniteInstallerFile->fileName());
        }
        qDebug() << "Filename:" << niniteInstallerLocation;
    }
    else if(windowsVersion == QSysInfo::WV_WINDOWS8 || windowsVersion == QSysInfo::WV_WINDOWS8_1)
    {
        qDebug() << "Running Windows 8!";

        if(_installAV->isChecked())
        {
            qDebug() << "Running Ninite and installing AV!";
            QFile::copy("://Resources/Ninite/Ninite-Win8-AV.exe", "Ninite-Win8-AV.exe");
            _niniteInstallerFile->setFileName("Ninite-Win8-AV.exe");
            //_niniteProcess->startDetached("Ninite-Win8-AV.exe"/*,QStringList("/silent")*/);
            _niniteProcess->startDetached(_niniteInstallerFile->fileName());
            //QDesktopServices::openUrl(QUrl("://Resources/Ninite/Ninite-Win8-AV.exe"));
        }
        else
        {
            qDebug() << "Running Ninite without installing AV!";
            QFile::copy("://Resources/Ninite/Ninite-Win8-NoAV.exe", "Ninite-Win8-NoAV.exe");
            //_niniteProcess->startDetached("Ninite-Win8-NoAV.exe"/*,QStringList("/silent")*/);
            _niniteProcess->startDetached(_niniteInstallerFile->fileName());
            //QDesktopServices::openUrl(QUrl("://Resources/Ninite/Ninite-Win8-NoAV.exe"));
        }
    }

#else
    qDebug() << "Not running on Windows platform!";
#endif
}

void MainWindow::_niniteInstallerIsFinished(int exitCode,QProcess::ExitStatus exitStatus)
{
    qDebug() << "Exit Code:" << exitCode;

    if(_niniteInstallerFile->exists())
    {
        qDebug() << _niniteInstallerFile->fileName() << "exists!";
        if(_niniteProcess->isOpen()) _niniteProcess->close();
        if(!_niniteInstallerFile->remove())
        {
            qDebug() << "...but couldn't be removed for some stupid reason!";
            qDebug() << "Error:" << _niniteInstallerFile->errorString();
        }
    }
}

void MainWindow::_setupMenus()
{
    _createActions();
    _createMenus();
}

#endif
