#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QString>
#include <QLabel>
#include <QCheckBox>
#include <QIcon>
#include <QTextEdit>

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
    void _hddscanStateHasChanged(int);                          //HDDScan
    void _hddpassStateHasChanged(int);                          //HDDScan Passed
    void _hddfailStateHasChanged(int);                          //HDDScan Failed
    void _sfcscanStateHasChanged(int);                          //SFCScan
    void _sfcpassStateHasChanged(int);                          //SFCScan Passed
    void _sfcfailStateHasChanged(int);                          //SFCScan Failed

private:
    Ui::MainWindow *ui;

    /*****MAIN ICON******/
    QIcon _mainWindowIcon;

    /*****SETUP**********/
    void _setup();

    /*****INITIALS*******/
    QListWidget * _initialsListView;
    QLabel * _initials;
    void _setupInitials();
    QString _currentUser;

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

    /*****TEXT BOX*******/
    QTextEdit * _textbox;
    void _setupTextbox();
};

#endif // MAINWINDOW_H
