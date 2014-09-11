#ifndef SAVE_REPORT_CPP
#define SAVE_REPORT_CPP
#include "mainwindow.h"
#include "io.cpp"
#include <QFile>
#include <QTextStream>
#include <QDebug>

void MainWindow::_saveReportButtonHasBeenClicked()
{
    if(_saveReport(getUserInputString(this,"File Name","Please enter a name for the file:")))
        qDebug() << "File saved!";
    else qDebug() << "Could not save file!";
}

bool MainWindow::_saveReport(const QString & filename)
{
    if(!filename.size()) return false;

    QFile * outputFile = new QFile((filename + ".txt"));

    if(outputFile->exists())
        outputFile->open(QIODevice::Append | QIODevice::Text);
    else
        outputFile->open(QIODevice::WriteOnly);

    if(!outputFile->isOpen())
        return false;

    QTextStream * outputStream = new QTextStream(outputFile);

    *outputStream << _textbox->toPlainText() << '\n';
    outputFile->close();
    return true;
}

#endif
