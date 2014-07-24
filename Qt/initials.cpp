#ifndef INITIALS_CPP
#define INITIALS_CPP

void MainWindow::_initialsListItemHasBeenClicked(QListWidgetItem * item)
{
    if(item != _initialsListView->item(_initialsListView->count()-1))
    {
            _currentUser = item->text();
            qDebug() << _currentUser.toStdString().c_str() << "Clicked!" << '\n';
            if(_addInitials->isChecked()) _generateReport();
    }
    else
    {
        string userInitials = getUserInputString(this,"Initials","Initials:").toStdString();
        if(userInitials.size())
        {
            appendLineToFile(tr("users"),tr(userInitials.c_str()));
            _initialsListView->item(_initialsListView->count()-1)->setText(QString(userInitials.c_str()));

            _initialsListView->sortItems();
            _initialsListView->show();

            for(int i = 0; i < _initialsListView->count(); i++)
                if(_initialsListView->item(i)->text() == QString(userInitials.c_str()))
                    _initialsListView->setItemSelected(_initialsListView->item(i), true);
            _currentUser = userInitials.c_str();

            _initialsListView->addItem(QString("Add New..."));
            _initialsListView->item(_initialsListView->count()-1)->setTextColor("Black");

            qDebug() << _currentUser.toStdString().c_str() << "Clicked!" << '\n';
        }
    }
}

void MainWindow::_setupInitials()
{
    _initials->setGeometry(25,3,73,11);
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

    vector<string> myList = getStringListFromFile("users");

    if( myList.empty())
    {
        string userInitials = getUserInputString(this,"Initials","Initials:").toStdString();
        myList.push_back(userInitials);
        appendLineToFile(tr("users"),tr(userInitials.c_str()));
    }

    for(unsigned int i = 0; i < myList.size(); i++)
    {
        _initialsListView->addItem(QString(myList[i].c_str()));
        _initialsListView->item(i)->setTextColor("Black");
    }
    _initialsListView->addItem("Add new...");
    _initialsListView->setGeometry(0,_initials->geometry().y()+_initials->geometry().height()+3,146,100);
    _initialsListView->show();
}

#endif
