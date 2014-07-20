#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QString>
#include <QLabel>
#include <QCheckBox>

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

private:
    Ui::MainWindow *ui;

    /*****SETUP**********/
    void _setup();

    /*****INITIALS*******/
    QListWidget * _initialsListView;
    QLabel * _initials;
    void _setupInitials();
    QString _currentUser;

    /*****HDD SCAN*******/
    QCheckBox * _hddscan;
    QCheckBox * _hddpass;
    QCheckBox * _hddfail;
    void _setupHDDCheckboxes();
};

#endif // MAINWINDOW_H
