#include "mainwindow.h"
#include <QApplication>
#include "io.cpp"
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
