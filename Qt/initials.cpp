#ifndef INITIALS_CPP
#define INITIALS_CPP
#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

void MainWindow::_initialsListItemHasBeenClicked(QListWidgetItem * item)
{
    if(item != _initialsListView->item(_initialsListView->count()-1))
    {
            _currentUser = item->text();
            qDebug() << _currentUser << tr("Clicked!") << '\n';
    }
    else
    {
        QString userInitials = getUserInputString(this,tr("Initials"),tr("Initials:"));
        if(userInitials.size())
        {
            userInitials = userInitials.toUpper();
            _addTextToDatabase(userInitials,"initials");
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
    QHBoxLayout * labelLayout = new QHBoxLayout;
    QHBoxLayout * initialListAndTextBox = new QHBoxLayout;
    QVector<QString> * myList = _getTextFromDatabase("initials");

    connect
                (
                    _initialsListView,
                    SIGNAL(itemClicked(QListWidgetItem*)),
                    this,
                    SLOT(_initialsListItemHasBeenClicked(QListWidgetItem*))
                );
    connect(_textbox, SIGNAL(textChanged()),this,SLOT(_textInTextboxHasChanged()));

    if( myList->empty())
    {
        QString userInitials;

        while(true)
        {
            userInitials = getUserInputString(this,tr("Initials"),tr("Initials:"));
            if(userInitials.size()) break;
        }
        userInitials = userInitials.toUpper();
        myList->push_back(userInitials);
        _addTextToDatabase(userInitials,"initials");
    }

    for(int i = 0; i < myList->size(); i++)
    {
        _initialsListView->addItem(myList->at(i));
        _initialsListView->item(i)->setTextColor("Black");
    }
    _initialsListView->addItem(tr("Add new..."));

    _initialsListView->setMaximumWidth(72);
    _initials->setMaximumWidth(_initialsListView->width());

    initialListAndTextBox->addWidget(_initialsListView);
    initialListAndTextBox->addWidget(_textbox);
    labelLayout->setAlignment(Qt::AlignCenter);
    labelLayout->addWidget(_initials);
    labelLayout->addStretch();

    _centralWidgetLayout->addLayout(labelLayout);
    _centralWidgetLayout->addLayout(initialListAndTextBox);
}

#endif
