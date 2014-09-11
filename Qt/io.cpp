#ifndef IO_CPP
#define IO_CPP
#include "mainwindow.h"
#include <QInputDialog>
#include <QString>
#include <QStringList>
#include <QDebug>

inline const QString getUserInputString(QWidget *parent, const QString windowName, const QString prompt)
{
    bool ok = false;
    const QString input = QInputDialog::getText(parent, windowName,prompt, QLineEdit::Normal,"", &ok);

    if(ok) return input;
    else return "";
}

#endif
