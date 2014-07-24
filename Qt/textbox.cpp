#ifndef TEXTBOX_CPP
#define TEXTBOX_CPP

void MainWindow::_setupTextbox()
{
    _textbox = new QTextEdit("Report is generated here. Start customizing!",this);
    _textbox->setGeometry(_initialsListView->width()+3,_initialsListView->geometry().y(),width()-_initialsListView->width()-5,_initialsListView->height());
    connect(_textbox, SIGNAL(textChanged()),this,SLOT(_textInTextboxHasChanged()));
    _textbox->show();
}

void MainWindow::_textInTextboxHasChanged()
{
    _clipboard->setText(_textbox->toPlainText());
}

#endif
