#ifndef TEXTBOX_CPP
#define TEXTBOX_CPP
#include "mainwindow.h"
#include <QString>

void MainWindow::_textInTextboxHasChanged()
{
    QString text = _textbox->toPlainText();

    if(text.length())
        _clipboard->setText(text);
    else _textbox->setText("No text =(");
}

void MainWindow::_generateReport()
{
    QString report = "";

    if(_addInitials->isChecked() && _currentUser.length())
        report += _currentUser + " - ";

    if(_addDate->isChecked() && _addTime->isChecked())
        report += _date + " " +
                QTime::currentTime().toString("hh:mm AP") + " - ";
    else if(_addDate->isChecked())
        report += _date + " - ";
    else if(_addTime->isChecked())
        report += QTime::currentTime().toString("hh:mm AP") + " - ";

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
            if(i == _currentlySelectedMalware->count()-1 && _currentlySelectedMalware->count() != 1) report += ("and " + _currentlySelectedMalware->at(i) + ".\n");
            else if(_currentlySelectedMalware->count() == 1) report += (_currentlySelectedMalware->at(0) + '\n');
            else report += _currentlySelectedMalware->at(i) + ", ";
        }
    }

    if(_removedWithMalwarebytes >= 0)
        report += "Ran a scan with Malwarebytes' Anti-Malware and removed " +
                QString::number(_removedWithMalwarebytes) +
                " found infected object(s).\n";

    if(_removedWithAvast >= 0)
        report += "Ran a boot-time scan with Avast! Free Anti-Virus and removed " +
                QString::number(_removedWithAvast) +
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

    if(_workCompleted->isChecked())
        report += ("\nSystem is fully functional and operating optimally.\nThank you for your business!\n-" + (_currentUser.length()?_currentUser:""));

    if(_textbox) _textbox->setText(report);

    if(_niniteProcess) qDebug() << _niniteProcess->isOpen();
}

#endif
