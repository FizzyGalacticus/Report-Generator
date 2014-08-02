#ifndef CHECKBOXES_CPP
#define CHECKBOXES_CPP

/**************     SETUP   ************************/

void MainWindow::_setupCheckboxes()
{
    _setupAddInitialsCheckbox();
    _setupDateAndTimeCheckboxes();
    _setupCheckoutCheckbox();
    _setupHDDCheckboxes();
    _setupSFCCheckboxes();
    _setupUpgradeInPlaceCheckbox();
    _setupResetBrowsersCheckbox();
    _setupWindowsUpdatesCheckbox();
    _setupRestorePointsCheckbox();
    _setupInstalledProgramsCheckbox();
}

void MainWindow::_setupAddInitialsCheckbox()
{
    _addInitials = new QCheckBox(this);
    _addInitials->setText(tr("Add Initials"));
    const int addinitialsY = _initialsListView->geometry().y()+_initialsListView->height()+3;
    _addInitials->setGeometry(0,addinitialsY,width()/3,_initials->height()+3);
    connect(_addInitials, SIGNAL(stateChanged(int)),this,SLOT(_addInitialsStateHasChanged(int)));
}

void MainWindow::_setupDateAndTimeCheckboxes()
{
    _addDate = new QCheckBox(this);
    _addDate->setText(tr("Add Date"));
    _addDate->setGeometry(_addInitials->geometry().x(),_addInitials->geometry().y()+_addInitials->height()+3,_addInitials->width(),_addInitials->height());
    connect(_addDate, SIGNAL(stateChanged(int)),this,SLOT(_addDateStateHasChanged(int)));

    _addTime = new QCheckBox(this);
    _addTime->setText(tr("Add Time"));
    _addTime->setGeometry(_addInitials->geometry().x(),_addDate->geometry().y()+_addDate->height()+3,_addInitials->width(),_addInitials->height());
    connect(_addTime, SIGNAL(stateChanged(int)),this,SLOT(_addTimeStateHasChanged(int)));
}

void MainWindow::_setupCheckoutCheckbox()
{
    _checkout = new QCheckBox(this);
    _checkout->setText(tr("Just Checked Out"));
    _checkout->setGeometry(_addInitials->width(),_addInitials->geometry().y(),_addInitials->width(),_addInitials->height());
    connect(_checkout, SIGNAL(stateChanged(int)),this,SLOT(_checkoutStateHasChanged(int)));
}

void MainWindow::_setupHDDCheckboxes()
{
    //     Main HDD Scan Checkbox
    _hddscan = new QCheckBox(this);
    _hddscan->setText(tr("HDD Scan"));
    const int hddscanY = _checkout->geometry().y() + _checkout->height() + 3;
    _hddscan->setGeometry(_checkout->geometry().x(),hddscanY,_checkout->width(),_checkout->height());
    connect(_hddscan,SIGNAL(stateChanged(int)),this,SLOT(_hddscanStateHasChanged(int)));

    //     HDD Scan Pass Checkbox
    _hddpass = new QCheckBox(this);
    _hddpass->setText(tr("Passed"));
    const int hddpassY = _hddscan->geometry().y() + _hddscan->height() + 3;
    _hddpass->setGeometry(_hddscan->geometry().x()+15,hddpassY,_hddscan->width()-15,_hddscan->height());
    _hddpass->setCheckable(false);
    _hddpass->setVisible(false);
    connect(_hddpass,SIGNAL(stateChanged(int)),this,SLOT(_hddpassStateHasChanged(int)));

    //     HDD Scan Fail Checkbox
    _hddfail = new QCheckBox(this);
    _hddfail->setText(tr("Failed"));
    const int hddfailY = _hddpass->geometry().y() + _hddscan->height() + 3;
    _hddfail->setGeometry(_hddscan->geometry().x()+15,hddfailY,_hddpass->width()-15,_hddscan->height());
    _hddfail->setCheckable(false);
    _hddfail->setVisible(false);
    connect(_hddfail,SIGNAL(stateChanged(int)),this,SLOT(_hddfailStateHasChanged(int)));
}

void MainWindow::_setupSFCCheckboxes()
{
    //     Main SFC Scan Checkbox
    _sfcscan = new QCheckBox(this);
    _sfcscan->setText(tr("SFC Scan"));
    const int sfcscanY = _hddfail->geometry().y() + _hddfail->height() + 3;
    _sfcscan->setGeometry(_hddscan->geometry().x(),sfcscanY,_hddfail->width(),_checkout->height());
    connect(_sfcscan,SIGNAL(stateChanged(int)),this,SLOT(_sfcscanStateHasChanged(int)));

    //     SFC Scan Pass Checkbox
    _sfcpass = new QCheckBox(this);
    _sfcpass->setText(tr("Passed"));
    const int sfcpassY = _sfcscan->geometry().y() + _sfcscan->height() + 3;
    _sfcpass->setGeometry(_hddscan->geometry().x()+15,sfcpassY,_hddpass->width()-15,_sfcscan->height());
    _sfcpass->setCheckable(false);
    _sfcpass->setVisible(false);
    connect(_sfcpass,SIGNAL(stateChanged(int)),this,SLOT(_sfcpassStateHasChanged(int)));

    //     SFC Scan Fail Checkbox
    _sfcfail = new QCheckBox(this);
    _sfcfail->setText(tr("Failed"));
    const int sfcfailY = _sfcpass->geometry().y() + _sfcscan->height() + 3;
    _sfcfail->setGeometry(_hddscan->geometry().x()+15,sfcfailY,_hddpass->width()-15,_sfcscan->height());
    _sfcfail->setCheckable(false);
    _sfcfail->setVisible(false);
    connect(_sfcfail,SIGNAL(stateChanged(int)),this,SLOT(_sfcfailStateHasChanged(int)));
}

void MainWindow::_setupUpgradeInPlaceCheckbox()
{
    _upgradeInPlace = new QCheckBox(this);
    _upgradeInPlace->setText(tr("Upgrade-In-Place"));
    const int UIPY = _sfcfail->geometry().y()+_sfcscan->height()+3;
    _upgradeInPlace->setGeometry(_sfcscan->geometry().x(),UIPY,_addInitials->width(),_addInitials->height());
    connect(_upgradeInPlace, SIGNAL(stateChanged(int)),this,SLOT(_upgradeInPlaceStateHasChanged(int)));
}

void MainWindow::_setupResetBrowsersCheckbox()
{
    _resetBrowsers = new QCheckBox(this);
    _resetBrowsers->setText(tr("Reset Browsers"));
    const int resetBrowsersY = _upgradeInPlace->geometry().y()+_addInitials->height()+3;
    _resetBrowsers->setGeometry(_checkout->geometry().x(),resetBrowsersY,_addInitials->width(),_addInitials->height());
    connect(_resetBrowsers, SIGNAL(stateChanged(int)),this,SLOT(_resetBrowsersStateHasChanged(int)));
}

void MainWindow::_setupWindowsUpdatesCheckbox()
{
    _windowsUpdates = new QCheckBox(this);
    _windowsUpdates->setText(tr("Windows Updates"));
    const int windowsUpdateY = _resetBrowsers->geometry().y()+_addInitials->height()+3;
    _windowsUpdates->setGeometry(_checkout->geometry().x(),windowsUpdateY,_addInitials->width(),_addInitials->height());
    connect(_windowsUpdates, SIGNAL(stateChanged(int)),this,SLOT(_windowsUpdatesStateHasChanged(int)));
}

void MainWindow::_setupRestorePointsCheckbox()
{
    _restorePoints = new QCheckBox(this);
    _restorePoints->setText(tr("Reset Restore Points"));
    const int restorePointsY = _windowsUpdates->geometry().y()+_addInitials->height()+3;
    _restorePoints->setGeometry(_checkout->geometry().x(),restorePointsY,_addInitials->width(),_addInitials->height());
    connect(_restorePoints, SIGNAL(stateChanged(int)),this,SLOT(_restorePointsStateHasChanged(int)));
}

void MainWindow::_setupInstalledProgramsCheckbox()
{
    _installedPrograms = new QCheckBox(this);
    _installedPrograms->setText(tr("Installed Programs"));
    _installedPrograms->setGeometry(_checkout->geometry().x()+_checkout->width(),_checkout->geometry().y(),_addInitials->width(),_addInitials->height());
    connect(_installedPrograms, SIGNAL(stateChanged(int)),this,SLOT(_installedProgramsStateHasChanged(int)));

    _installedAV = new QCheckBox(this);
    _installedAV->setText(tr("Installed AV"));
    _installedAV->setGeometry(_installedPrograms->geometry().x()+15,_hddscan->geometry().y(),_addInitials->width()-15,_addInitials->height());
    connect(_installedAV, SIGNAL(stateChanged(int)),this,SLOT(_installedAVStateHasChanged(int)));
    _installedAV->setVisible(false);

    _win8 = new QCheckBox(this);
    _win8->setText(tr("Windows 8"));
    _win8->setGeometry(_installedPrograms->geometry().x()+15,_hddpass->geometry().y(),_addInitials->width()-15,_addInitials->height());
    connect(_win8, SIGNAL(stateChanged(int)),this,SLOT(_win8StateHasChanged(int)));
    _win8->setVisible(false);
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

#endif
