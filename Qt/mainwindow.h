#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QString>

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
    void _initialsListItemHasBeenClicked(QListWidgetItem *);

private:
    Ui::MainWindow *ui;

    /*****USERS*******/
    QListWidget * _initialsListView;
    void _setupInitials();
    QString _currentUser;
};

#endif // MAINWINDOW_H
