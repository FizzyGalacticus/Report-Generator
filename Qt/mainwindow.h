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
    void _about();                                               //About Menu
    void _aboutQt();                                             //About Qt Menu
    void _aboutAuthor();                                         //About Author Menu

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
    void _setupAddInitialsCheckbox();

    /****DATE AND TIME***/
    QString _date;
    QCheckBox * _addDate;
    QCheckBox * _addTime;
    void _setupDateAndTimeCheckboxes();

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

    /**UPGRADE-IN-PLACE**/
    QCheckBox * _upgradeInPlace;
    void _setupUpgradeInPlaceCheckbox();

    /***RESET BROWSERS***/
    QCheckBox * _resetBrowsers;
    void _setupResetBrowsersCheckbox();

    /***WINDOWS UPDATES**/
    QCheckBox * _windowsUpdates;
    void _setupWindowsUpdatesCheckbox();

    /***RESTORE POINTS**/
    QCheckBox * _restorePoints;
    void _setupRestorePointsCheckbox();

    /*INSTALLED PROGRAMS*/
    QCheckBox * _installedPrograms;
    QCheckBox * _win8;
    QCheckBox * _installedAV;
    void _setupInstalledProgramsCheckbox();

    /***************************************************************/

    /*****TEXT BOX*******/
    QTextEdit * _textbox;
    void _setupTextbox();
    void _generateReport();

    /****RESET BUTTON****/
    QPushButton * _resetButton;
    void _setupResetButton();

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
    void _setupMalwareButton();

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
    void _setupSQLiteDatabase();
    QVector<QString> * getTextFromDatabase(const QString &);
    void addTextToDatabase(const QString &, const QString &);
};

#endif // MAINWINDOW_H
