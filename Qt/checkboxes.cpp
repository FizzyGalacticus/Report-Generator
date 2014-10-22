#ifndef CHECKBOXES_CPP
#define CHECKBOXES_CPP
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

/**************     SETUP   ************************/

void MainWindow::_setupCheckboxes()
{
    QVBoxLayout * initialsDateTimeLayout = new QVBoxLayout;
    QVBoxLayout * mainServicesLayout = new QVBoxLayout;
    QVBoxLayout * installedUpdatedAndCompleted = new QVBoxLayout;
    QHBoxLayout * checkboxesLayout = new QHBoxLayout;

    /****************INITIALS, TIME, AND DATE CHECKBOXES*********************/
    _addInitials->setText(tr("Add Initials"));
    _addDate->setText(tr("Add Date"));
    _addTime->setText(tr("Add Time"));

    connect(_addInitials, SIGNAL(stateChanged(int)),this,SLOT(_addInitialsStateHasChanged(int)));
    connect(_addDate, SIGNAL(stateChanged(int)),this,SLOT(_addDateStateHasChanged(int)));
    connect(_addTime, SIGNAL(stateChanged(int)),this,SLOT(_addTimeStateHasChanged(int)));

    initialsDateTimeLayout->addWidget(_addInitials);
    initialsDateTimeLayout->addWidget(_addDate);
    initialsDateTimeLayout->addWidget(_addTime);

    for(int i = 0; i < initialsDateTimeLayout->count(); i++)
        initialsDateTimeLayout->itemAt(i)->widget()->setMaximumHeight(15);

    initialsDateTimeLayout->addStretch();

    /****************MAIN SERVICE CHECKBOXES********************************/
    QHBoxLayout * hddpassSpacer = new QHBoxLayout;
    QHBoxLayout * hddfailSpacer = new QHBoxLayout;
    QHBoxLayout * sfcpassSpacer = new QHBoxLayout;
    QHBoxLayout * sfcFailSpacer = new QHBoxLayout;

    _checkout->setText(tr("Just Checked Out"));
    _hddscan->setText(tr("HDD Scan"));
    _hddpass->setText(tr("Passed"));
    _hddfail->setText(tr("Failed"));
    _sfcscan->setText(tr("SFC Scan"));
    _sfcpass->setText(tr("Passed"));
    _sfcfail->setText(tr("Failed"));
    _upgradeInPlace->setText(tr("Upgrade-In-Place"));
    _resetBrowsers->setText(tr("Reset Browsers"));
    _windowsUpdates->setText(tr("Windows Updates"));
    _restorePoints->setText(tr("Reset Restore Points"));

    _checkout->setMaximumHeight(14);
    _hddscan->setMaximumHeight(14);
    _hddpass->setMaximumHeight(14);
    _hddfail->setMaximumHeight(14);
    _sfcscan->setMaximumHeight(14);
    _sfcpass->setMaximumHeight(14);
    _sfcfail->setMaximumHeight(14);
    _upgradeInPlace->setMaximumHeight(14);
    _resetBrowsers->setMaximumHeight(14);
    _windowsUpdates->setMaximumHeight(14);
    _restorePoints->setMaximumHeight(14);

    _hddpass->setCheckable(false);
    _hddpass->setVisible(false);
    _hddfail->setCheckable(false);
    _hddfail->setVisible(false);
    _sfcpass->setCheckable(false);
    _sfcpass->setVisible(false);
    _sfcfail->setCheckable(false);
    _sfcfail->setVisible(false);

    hddpassSpacer->addSpacerItem(new QSpacerItem(15,14,QSizePolicy::Fixed));
    hddpassSpacer->addWidget(_hddpass);
    hddfailSpacer->addSpacerItem(new QSpacerItem(15,14,QSizePolicy::Fixed));
    hddfailSpacer->addWidget(_hddfail);
    sfcpassSpacer->addSpacerItem(new QSpacerItem(15,14,QSizePolicy::Fixed));
    sfcpassSpacer->addWidget(_sfcpass);
    sfcFailSpacer->addSpacerItem(new QSpacerItem(15,14,QSizePolicy::Fixed));
    sfcFailSpacer->addWidget(_sfcfail);

    connect(_checkout, SIGNAL(stateChanged(int)),this,SLOT(_checkoutStateHasChanged(int)));
    connect(_hddscan,SIGNAL(stateChanged(int)),this,SLOT(_hddscanStateHasChanged(int)));
    connect(_hddpass,SIGNAL(stateChanged(int)),this,SLOT(_hddpassStateHasChanged(int)));
    connect(_hddfail,SIGNAL(stateChanged(int)),this,SLOT(_hddfailStateHasChanged(int)));
    connect(_sfcscan,SIGNAL(stateChanged(int)),this,SLOT(_sfcscanStateHasChanged(int)));
    connect(_sfcpass,SIGNAL(stateChanged(int)),this,SLOT(_sfcpassStateHasChanged(int)));
    connect(_sfcfail,SIGNAL(stateChanged(int)),this,SLOT(_sfcfailStateHasChanged(int)));
    connect(_upgradeInPlace, SIGNAL(stateChanged(int)),this,SLOT(_upgradeInPlaceStateHasChanged(int)));
    connect(_resetBrowsers, SIGNAL(stateChanged(int)),this,SLOT(_resetBrowsersStateHasChanged(int)));
    connect(_windowsUpdates, SIGNAL(stateChanged(int)),this,SLOT(_windowsUpdatesStateHasChanged(int)));
    connect(_restorePoints, SIGNAL(stateChanged(int)),this,SLOT(_restorePointsStateHasChanged(int)));

    mainServicesLayout->addWidget(_checkout);
    mainServicesLayout->addWidget(_hddscan);
    mainServicesLayout->addLayout(hddpassSpacer);
    mainServicesLayout->addLayout(hddfailSpacer);
    mainServicesLayout->addWidget(_sfcscan);
    mainServicesLayout->addLayout(sfcpassSpacer);
    mainServicesLayout->addLayout(sfcFailSpacer);
    mainServicesLayout->addWidget(_upgradeInPlace);
    mainServicesLayout->addWidget(_resetBrowsers);
    mainServicesLayout->addWidget(_windowsUpdates);
    mainServicesLayout->addWidget(_restorePoints);
    mainServicesLayout->addStretch();

    /*******************INSTALLED AND UPDATED PROGRAMS CHECKBOXES***********/
    QHBoxLayout * avSpacerLayout = new QHBoxLayout;
    QHBoxLayout * win8SpacerLayout = new QHBoxLayout;

    avSpacerLayout->addSpacerItem(new QSpacerItem(15,14,QSizePolicy::Fixed));
    avSpacerLayout->addWidget(_installedAV);
    win8SpacerLayout->addSpacerItem(new QSpacerItem(15,14,QSizePolicy::Fixed));
    win8SpacerLayout->addWidget(_win8);

    _installedPrograms->setText(tr("Installed Programs"));
    _installedAV->setText(tr("Installed AV"));
    _win8->setText(tr("Windows 8"));
    _workCompleted->setText(tr("Wrapped Up"));

    _installedPrograms->setMaximumHeight(15);
    _installedAV->setMaximumHeight(15);
    _win8->setMaximumHeight(15);
    _workCompleted->setMaximumHeight(15);

    _installedAV->setVisible(false);
    _win8->setVisible(false);

    connect(_installedPrograms, SIGNAL(stateChanged(int)),this,SLOT(_installedProgramsStateHasChanged(int)));
    connect(_installedAV, SIGNAL(stateChanged(int)),this,SLOT(_installedAVStateHasChanged(int)));
    connect(_win8, SIGNAL(stateChanged(int)),this,SLOT(_win8StateHasChanged(int)));
    connect(_workCompleted, SIGNAL(stateChanged(int)), this, SLOT(_completedStateHasChanged(int)));

    installedUpdatedAndCompleted->addWidget(_installedPrograms);
    installedUpdatedAndCompleted->addLayout(avSpacerLayout);
    installedUpdatedAndCompleted->addLayout(win8SpacerLayout);
    installedUpdatedAndCompleted->addStretch();
    installedUpdatedAndCompleted->addWidget(_workCompleted);

    checkboxesLayout->addLayout(initialsDateTimeLayout);
    checkboxesLayout->addLayout(mainServicesLayout);
    checkboxesLayout->addLayout(installedUpdatedAndCompleted);

    _centralWidgetLayout->addLayout(checkboxesLayout);
}

/**************     SLOTS   ************************/

void MainWindow::_addInitialsStateHasChanged(int state)
{
    if(state)
        qDebug() << tr("I want to add initials!");
    else qDebug() << tr("Actually, I don't want to add my initials!");

    if(_currentUser.length()) _generateReport();
}

void MainWindow::_addDateStateHasChanged(int state)
{
    if(state)
        qDebug() << tr("I want to add the date!");
    else qDebug() << tr("Actually, I don't want to add the date!");

    _generateReport();
}

void MainWindow::_addTimeStateHasChanged(int state)
{
    if(state)
        qDebug() << tr("I want to add the time!");
    else qDebug() << tr("Actually, I don't want to add the time!");

    _generateReport();
}

void MainWindow::_checkoutStateHasChanged(int state)
{
    if(state)
        qDebug() << tr("Just checked out!");
    else qDebug() << tr("Actually, I didn't just check out!");

    _generateReport();
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

    _generateReport();
}

void MainWindow::_hddpassStateHasChanged(int state)
{
  if(state) _hddfail->setChecked(false);
  _generateReport();
}

void MainWindow::_hddfailStateHasChanged(int state)
{
    if(state) _hddpass->setChecked(false);
    _generateReport();
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
    _generateReport();
}

void MainWindow::_sfcpassStateHasChanged(int state)
{
  if(state) _sfcfail->setChecked(false);
  _generateReport();
}

void MainWindow::_sfcfailStateHasChanged(int state)
{
    if(state) _sfcpass->setChecked(false);
    _generateReport();
}

void MainWindow::_upgradeInPlaceStateHasChanged(int state)
{
    if(state)
        qDebug() << tr("Performed Windows Upgrade-In-Place!");
    else qDebug() << tr("Actually I didn't perform the Upgrade-In-Place...");

    _generateReport();
}

void MainWindow::_resetBrowsersStateHasChanged(int state)
{
    if(state)
        qDebug() << tr("Reset browsers!");
    else qDebug() << tr("I didn't actually reset the browsers");

    _generateReport();
}

void MainWindow::_windowsUpdatesStateHasChanged(int state)
{
    if(state) qDebug() << tr("Installed updates!");
    else qDebug() << tr("Actually, updates weren't installed.");

    _generateReport();
}

void MainWindow::_restorePointsStateHasChanged(int state)
{
    if(state) qDebug() << tr("Reset restore points!");
    else qDebug() << tr("Didn't actually reset restore points.");

    _generateReport();
}

void MainWindow::_installedProgramsStateHasChanged(int state)
{
    if(state)
    {
        _installedAV->setVisible(true);
        _win8->setVisible(true);
        qDebug() << tr("Installed Programs!");
    }
    else
    {
        qDebug() << tr("Didn't actually install programs!");
        _installedAV->setChecked(false);
        _installedAV->setVisible(false);
        _win8->setChecked(false);
        _win8->setVisible(false);
    }

    _generateReport();
}

void MainWindow::_installedAVStateHasChanged(int state)
{
    if(state) qDebug() << tr("Installed Anti-Virus software!");
    else qDebug() << tr("Didn't actually install AV!");

    _generateReport();
}

void MainWindow::_win8StateHasChanged(int state)
{
    if(state) qDebug() << tr("System is running Windows 8!");
    else qDebug() << tr("System is not actually running Windows 8!");

    _generateReport();
}

void MainWindow::_completedStateHasChanged(int state)
{
    if(state) qDebug() << tr("Finally done!");
    else qDebug() << tr("Not done yet! Hehehe.");

    _generateReport();
}

#endif
