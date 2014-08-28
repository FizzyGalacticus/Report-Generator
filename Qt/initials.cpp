#ifndef INITIALS_CPP
#define INITIALS_CPP
#include "mainwindow.h"

void MainWindow::_initialsListItemHasBeenClicked(QListWidgetItem * item)
{
    if(item != _initialsListView->item(_initialsListView->count()-1))
    {
            _currentUser = item->text();
            qDebug() << _currentUser.toStdString().c_str() << tr("Clicked!") << '\n';
    }
    else
    {
        QString userInitials = getUserInputString(this,tr("Initials"),tr("Initials:"));
        if(userInitials.size())
        {
            addTextToDatabase(userInitials,"initials");
            _initialsListView->item(_initialsListView->count()-1)->setText(userInitials);

            _initialsListView->sortItems();
            _initialsListView->show();

            for(int i = 0; i < _initialsListView->count(); i++)
                if(_initialsListView->item(i)->text() == userInitials)
                    _initialsListView->setItemSelected(_initialsListView->item(i), true);
            _currentUser = userInitials;

            _initialsListView->addItem(QString(tr("Add New...")));
            _initialsListView->item(_initialsListView->count()-1)->setTextColor("Black");

            qDebug() << _currentUser << QString(tr("Clicked!")) << '\n';
        }
    }

    if(_addInitials->isChecked()) _generateReport();
}

void MainWindow::_setupInitials()
{
    _initials->setGeometry(0,menuBar()->height(),146,11);
    _initials->setAlignment(Qt::AlignCenter);
    _initials->show();

    _initialsListView = new QListWidget(this);
    _initialsListView->setParent(this);

    connect
                (
                    _initialsListView,
                    SIGNAL(itemClicked(QListWidgetItem*)),
                    this,
                    SLOT(_initialsListItemHasBeenClicked(QListWidgetItem*))
                );

    QVector<QString> * myList = getTextFromDatabase("initials");

    if( myList->empty())
    {
        QString userInitials = getUserInputString(this,tr("Initials"),tr("Initials:"));
        myList->push_back(userInitials);
        addTextToDatabase(userInitials,"initials");
    }

    for(int i = 0; i < myList->size(); i++)
    {
        _initialsListView->addItem(myList->at(i));
        _initialsListView->item(i)->setTextColor("Black");
    }
    _initialsListView->addItem(tr("Add new..."));
    _initialsListView->setGeometry(0,_initials->geometry().y()+_initials->geometry().height()+3,146,100);
    _initialsListView->show();
}

#endif
