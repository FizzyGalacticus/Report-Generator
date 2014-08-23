#ifndef TEXTBOX_CPP
#define TEXTBOX_CPP
#include "mainwindow.h"
#include <QString>

void MainWindow::_setupTextbox()
{
    _textbox = new QTextEdit("Report is generated here. Start customizing!",this);
    _textbox->setGeometry(_initialsListView->width()+3,_initialsListView->geometry().y(),width()-_initialsListView->width()-5,_initialsListView->height());
    connect(_textbox, SIGNAL(textChanged()),this,SLOT(_textInTextboxHasChanged()));
    _textbox->show();
}

void MainWindow::_textInTextboxHasChanged()
{
    QString text = _textbox->toPlainText();

    if(text.length())
        _clipboard->setText(text);
    else _textbox->setText("No text =(");
}

#endif
