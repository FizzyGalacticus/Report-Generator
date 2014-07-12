#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QRect>
#include <QDesktopWidget>
#include <QInputDialog>
#include <QString>
#include <string>
using std::string;

const QString getUserInput(QWidget *parent, const QString windowName, const QString prompt)
{
    return QInputDialog::getText(parent, windowName,prompt, QLineEdit::Normal,"", 0);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Report Generator");

    const QString initials = getUserInput(this, "Initials", "Initials:");

    QDesktopWidget desktop;
    QWidget *wdg = new QWidget;
    wdg->setWindowTitle("Pop-up");
    wdg->setFixedSize(50,40);

    QPushButton *myButton = new QPushButton(wdg);
    myButton->setText("Push me!");
    myButton->show();
    wdg->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
