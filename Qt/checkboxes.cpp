#ifndef CHECKBOXES_CPP
#define CHECKBOXES_CPP

/**************     SETUP   ************************/

void MainWindow::_setupCheckboxes()
{
    _setupCheckoutCheckbox();
    _setupHDDCheckboxes();
    _setupSFCCheckboxes();
    _setupAddInitialsCheckbox();
    _setupDateAndTimeCheckboxes();
}

void MainWindow::_setupCheckoutCheckbox()
{
    _checkout = new QCheckBox(this);
    _checkout->setText("Just Checked Out");
    const int checkoutY = _initialsListView->geometry().y()+_initialsListView->height()+3;
    _checkout->setGeometry(0,checkoutY,width()/3,_initials->height()+3);
    connect(_checkout, SIGNAL(stateChanged(int)),this,SLOT(_checkoutStateHasChanged(int)));
}

void MainWindow::_setupHDDCheckboxes()
{
    //     Main HDD Scan Checkbox
    _hddscan = new QCheckBox(this);
    _hddscan->setText("HDD Scan");
    const int hddscanY = _checkout->geometry().y() + _checkout->height() + 3;
    _hddscan->setGeometry(0,hddscanY,_checkout->width(),_checkout->height());
    connect(_hddscan,SIGNAL(stateChanged(int)),this,SLOT(_hddscanStateHasChanged(int)));

    //     HDD Scan Pass Checkbox
    _hddpass = new QCheckBox(this);
    _hddpass->setText("Passed");
    const int hddpassY = _hddscan->geometry().y() + _hddscan->height() + 3;
    _hddpass->setGeometry(15,hddpassY,_hddscan->width()-15,_hddscan->height());
    _hddpass->setCheckable(false);
    _hddpass->setVisible(false);
    connect(_hddpass,SIGNAL(stateChanged(int)),this,SLOT(_hddpassStateHasChanged(int)));

    //     HDD Scan Fail Checkbox
    _hddfail = new QCheckBox(this);
    _hddfail->setText("Failed");
    const int hddfailY = _hddpass->geometry().y() + _hddscan->height() + 3;
    _hddfail->setGeometry(15,hddfailY,_hddpass->width(),_hddscan->height());
    _hddfail->setCheckable(false);
    _hddfail->setVisible(false);
    connect(_hddfail,SIGNAL(stateChanged(int)),this,SLOT(_hddfailStateHasChanged(int)));
}

void MainWindow::_setupSFCCheckboxes()
{
    //     Main SFC Scan Checkbox
    _sfcscan = new QCheckBox(this);
    _sfcscan->setText("SFC Scan");
    const int sfcscanY = _hddfail->geometry().y() + _hddfail->height() + 3;
    _sfcscan->setGeometry(0,sfcscanY,_hddfail->width(),_checkout->height());
    connect(_sfcscan,SIGNAL(stateChanged(int)),this,SLOT(_sfcscanStateHasChanged(int)));

    //     SFC Scan Pass Checkbox
    _sfcpass = new QCheckBox(this);
    _sfcpass->setText("Passed");
    const int sfcpassY = _sfcscan->geometry().y() + _sfcscan->height() + 3;
    _sfcpass->setGeometry(15,sfcpassY,_hddpass->width(),_sfcscan->height());
    _sfcpass->setCheckable(false);
    _sfcpass->setVisible(false);
    connect(_sfcpass,SIGNAL(stateChanged(int)),this,SLOT(_sfcpassStateHasChanged(int)));

    //     SFC Scan Fail Checkbox
    _sfcfail = new QCheckBox(this);
    _sfcfail->setText("Failed");
    const int sfcfailY = _sfcpass->geometry().y() + _sfcscan->height() + 3;
    _sfcfail->setGeometry(15,sfcfailY,_hddpass->width(),_sfcscan->height());
    _sfcfail->setCheckable(false);
    _sfcfail->setVisible(false);
    connect(_sfcfail,SIGNAL(stateChanged(int)),this,SLOT(_sfcfailStateHasChanged(int)));
}

void MainWindow::_setupAddInitialsCheckbox()
{
    _addInitials = new QCheckBox(this);
    _addInitials->setText("Add Initials");
    _addInitials->setGeometry(_checkout->width()+3,_checkout->geometry().y(),_checkout->width(),_checkout->height());
    connect(_addInitials, SIGNAL(stateChanged(int)),this,SLOT(_addInitialsStateHasChanged(int)));
}

void MainWindow::_setupDateAndTimeCheckboxes()
{
    _addDate = new QCheckBox(this);
    _addDate->setText("Add Date");
    _addDate->setGeometry(_addInitials->geometry().x(),_hddscan->geometry().y(),_checkout->width(),_checkout->height());
    connect(_addDate, SIGNAL(stateChanged(int)),this,SLOT(_addDateStateHasChanged(int)));

    _addTime = new QCheckBox(this);
    _addTime->setText("Add Time");
    _addTime->setGeometry(_addInitials->geometry().x(),_hddpass->geometry().y(),_checkout->width(),_checkout->height());
    connect(_addTime, SIGNAL(stateChanged(int)),this,SLOT(_addTimeStateHasChanged(int)));
}

/**************     SLOTS   ************************/

void MainWindow::_checkoutStateHasChanged(int state)
{
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

void MainWindow::_addInitialsStateHasChanged(int state)
{
    if(_currentUser.length()) _generateReport();
}

void MainWindow::_addDateStateHasChanged(int state)
{
    _generateReport();
}

void MainWindow::_addTimeStateHasChanged(int state)
{
    _generateReport();
}

#endif
