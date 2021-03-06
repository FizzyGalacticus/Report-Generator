#ifndef SQLITE_CPP
#define SQLITE_CPP
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QVector<QString> * MainWindow::_getTextFromDatabase(const QString & tableName)
{
    QVector<QString> * tableEntries = new QVector<QString>;
    if(_openDatabase() && _dbquery)
    {
        QString query = "SELECT * FROM " + tableName;
        _dbquery->exec(query);

        while(_dbquery->next()) tableEntries->push_back(_dbquery->value(0).toString());

        _db->close();
    }
    else qDebug() << tr("_db not open or _dbquery is NULL.");

    return tableEntries;
}

void MainWindow::_addTextToDatabase(const QString & text, const QString & tableName)
{
    if(_openDatabase() && _dbquery)
    {
        QString query = ("INSERT INTO " + tableName + " VALUES (\"" + text + "\")");
        _dbquery->exec(query);

        _db->close();
    }
    else qDebug() << tr("_db not open or _dbquery is NULL.");
}

bool MainWindow::_openDatabase()
{
    _db->setHostName("CWI");
    _db->setDatabaseName("CWIDB");
    bool ok = _db->open();

    if(ok)
    {
        qDebug() << tr("Database opened!");

        delete _dbquery;
        _dbquery = new QSqlQuery(*_db);
        _dbquery->exec("CREATE TABLE initials(TITLE TEXT UNIQUE)");
        _dbquery->exec("CREATE TABLE removedprograms(TITLE TEXT UNIQUE)");
    }
    else qDebug() << tr("Database failed to open.");

    return ok;
}

#endif
