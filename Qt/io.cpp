#ifndef IO_CPP
#define IO_CPP

#include <QInputDialog>
#include <QString>

inline const QString getUserInput(QWidget *parent, const QString windowName, const QString prompt)
{
    return QInputDialog::getText(parent, windowName,prompt, QLineEdit::Normal,"", 0);
}

#endif
