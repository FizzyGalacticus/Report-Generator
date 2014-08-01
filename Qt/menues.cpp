
#ifndef _MENUES_CPP
#define _MENUES_CPP

#include <QMessageBox>

void MainWindow::_createMenus()
{
    _fileMenu = menuBar()->addMenu(tr("&File"));
    _fileMenu->addAction(_exitAct);

    _helpMenu = menuBar()->addMenu(tr("&Help"));
    _helpMenu->addAction(_aboutAct);
    _helpMenu->addAction(_aboutQtAct);
    _helpMenu->addAction(_aboutAuthorAct);
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
    connect(_aboutQtAct, SIGNAL(triggered()), qApp, SLOT(_aboutQt()));
    connect(_aboutQtAct, SIGNAL(triggered()), this, SLOT(_aboutQt()));

    _aboutAuthorAct = new QAction(tr("About &Author"), this);
    _aboutAuthorAct->setStatusTip(tr("Show information about Report-Generator's author"));
    connect(_aboutAuthorAct, SIGNAL(triggered()),this, SLOT(_aboutAuthor()));
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

void MainWindow::_setupMenus()
{
    _createActions();
    _createMenus();
}

#endif
