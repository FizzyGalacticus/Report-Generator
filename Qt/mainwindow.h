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
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QMenu>
#include <QtSql/QSqlDatabase>
#include <QVector>
#include <QWidget>
#include <QVBoxLayout>

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
    void _addInitialsStateHasChanged(int);                      //Add Initials
    void _addDateStateHasChanged(int);                          //Add Date
    void _addTimeStateHasChanged(int);                          //Add Time
    void _checkoutStateHasChanged(int);                         //Checkout
    void _hddscanStateHasChanged(int);                          //HDDScan
    void _hddpassStateHasChanged(int);                          //HDDScan Passed
    void _hddfailStateHasChanged(int);                          //HDDScan Failed
    void _sfcscanStateHasChanged(int);                          //SFCScan
    void _sfcpassStateHasChanged(int);                          //SFCScan Passed
    void _sfcfailStateHasChanged(int);                          //SFCScan Failed
    void _upgradeInPlaceStateHasChanged(int);                   //Upgrade-In-Place
    void _resetBrowsersStateHasChanged(int);                    //Reset Browsers
    void _windowsUpdatesStateHasChanged(int);                   //Windows Updates
    void _restorePointsStateHasChanged(int);                    //Restore Points
    void _installedProgramsStateHasChanged(int);                //Installed Programs
    void _installedAVStateHasChanged(int);                      //Installed AV
    void _win8StateHasChanged(int);                             //Windows 8 Machine
    void _textInTextboxHasChanged();                            //Text change
    void _resetButtonHasBeenClicked();                          //Reset button
    void _malwareButtonHasBeenClicked();                        //Malware Button
    void _malwareListViewItemHasBeenDoubleClicked(QListWidgetItem *);//Malware List Item
    void _malwareWindowAcceptButtonHasBeenClicked();            //Malware Accept
    void _saveReportButtonHasBeenClicked();                     //Save Report
    void _about();                                              //About Menu
    void _aboutQt();                                            //About Qt Menu
    void _aboutAuthor();                                        //About Author Menu

private:
    Ui::MainWindow *ui;

    //Central Widget & Layout
    QWidget * _centralWidget;
    QVBoxLayout * _centralWidgetLayout;

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

    /***************************CHECKBOXES***************************/
    void _setupCheckboxes();

    /*****INITIALS*******/
    QCheckBox * _addInitials;

    /****DATE AND TIME***/
    QString _date;
    QCheckBox * _addDate;
    QCheckBox * _addTime;

    /*****CHECKOUT*******/
    QCheckBox * _checkout;

    /*****HDD SCAN*******/
    QCheckBox * _hddscan;
    QCheckBox * _hddpass;
    QCheckBox * _hddfail;

    /*****SFC SCAN*******/
    QCheckBox * _sfcscan;
    QCheckBox * _sfcpass;
    QCheckBox * _sfcfail;

    /**UPGRADE-IN-PLACE**/
    QCheckBox * _upgradeInPlace;

    /***RESET BROWSERS***/
    QCheckBox * _resetBrowsers;

    /***WINDOWS UPDATES**/
    QCheckBox * _windowsUpdates;

    /***RESTORE POINTS**/
    QCheckBox * _restorePoints;

    /*INSTALLED PROGRAMS*/
    QCheckBox * _installedPrograms;
    QCheckBox * _installedAV;
    QCheckBox * _win8;

    /***************************************************************/

    /*****TEXT BOX*******/
    QTextEdit * _textbox;
    void _generateReport();

    /****RESET BUTTON****/
    QPushButton * _resetButton;

    /**********************MALWARE WINDOW***************************/
    QDialog * _malwareWindow;
    QListWidget * _malwareListView;
    QPushButton * _malwareButton;
    QPushButton * _malwareWindowAcceptButton;
    QStringList * _currentlySelectedMalware;
    int _removedWithMalwarebytes;
    QLineEdit * _removedWithMalwarebytesInput;
    int _removedWithAvast;
    QLineEdit * _removedWithAvastInput;
    void _setupMalwareWindow();
    void _setupMalwareListView();

    /*************************BUTTONS*******************************/
    void _setupButtons();

    /***************************MENUES******************************/
    QMenu * _fileMenu;
    QMenu * _helpMenu;
    QAction *_openAct;
    QAction *_exitAct;
    QAction *_aboutAct;
    QAction *_aboutQtAct;
    QAction *_aboutAuthorAct;
    void _createMenus();
    void _createActions();
    void _setupMenus();

    /*************************SQL DATABASE**************************/
    QSqlDatabase * _db;
    QSqlQuery * _dbquery;
    QVector<QString> * _getTextFromDatabase(const QString &);
    void _addTextToDatabase(const QString &, const QString &);
    bool _openDatabase();

    /**************************SAVE REPORT**************************/
    QPushButton * _saveReportButton;
    bool _saveReport(const QString &);
};

#endif // MAINWINDOW_H
