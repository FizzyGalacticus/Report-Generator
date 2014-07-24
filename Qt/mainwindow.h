#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QString>
#include <QLabel>
#include <QCheckBox>
#include <QIcon>
#include <QTextEdit>
#include <QDateTime>
#include <QClipboard>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void _initialsListItemHasBeenClicked(QListWidgetItem *);    //Initials
    void _checkoutStateHasChanged(int);                         //Checkout
    void _hddscanStateHasChanged(int);                          //HDDScan
    void _hddpassStateHasChanged(int);                          //HDDScan Passed
    void _hddfailStateHasChanged(int);                          //HDDScan Failed
    void _sfcscanStateHasChanged(int);                          //SFCScan
    void _sfcpassStateHasChanged(int);                          //SFCScan Passed
    void _sfcfailStateHasChanged(int);                          //SFCScan Failed
    void _addInitialsStateHasChanged(int);                      //Add Initials
    void _addDateStateHasChanged(int);                          //Add Date
    void _addTimeStateHasChanged(int);                          //Add Time
    void _textInTextboxHasChanged();                            //Text change

private:
    Ui::MainWindow *ui;

    /*****MAIN ICON******/
    QIcon _mainWindowIcon;

    /*****SETUP**********/
    void _setup();

    /*****CLIPBOARD******/
    QClipboard * _clipboard;

    /*****INITIALS*******/
    QListWidget * _initialsListView;
    QLabel * _initials;
    void _setupInitials();
    QString _currentUser;
    QCheckBox * _addInitials;
    void _setupAddInitialsCheckbox();

    /*****CHECKBOXES*****/
    void _setupCheckboxes();

    /*****CHECKOUT*******/
    QCheckBox * _checkout;
    void _setupCheckoutCheckbox();

    /*****HDD SCAN*******/
    QCheckBox * _hddscan;
    QCheckBox * _hddpass;
    QCheckBox * _hddfail;
    void _setupHDDCheckboxes();

    /*****SFC SCAN*******/
    QCheckBox * _sfcscan;
    QCheckBox * _sfcpass;
    QCheckBox * _sfcfail;
    void _setupSFCCheckboxes();

    /****DATE AND TIME***/
    QString _date;
    QCheckBox * _addDate;
    QCheckBox * _addTime;
    void _setupDateAndTimeCheckboxes();

    /*****TEXT BOX*******/
    QTextEdit * _textbox;
    void _setupTextbox();
    void _generateReport();
};

#endif // MAINWINDOW_H
