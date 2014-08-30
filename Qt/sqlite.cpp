#ifndef SQLITE_CPP
#define SQLITE_CPP
#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void MainWindow::_setupSQLiteDatabase()
{
    _db->setHostName("CWI");
    _db->setDatabaseName("CWIDB");
    bool ok = _db->open();

    if(ok)
    {
        qDebug() << tr("Database opened!");

        _dbquery = new QSqlQuery(*_db);
        _dbquery->exec("CREATE TABLE initials(TITLE TEXT UNIQUE)");
        _dbquery->exec("CREATE TABLE removedprograms(TITLE TEXT UNIQUE)");
    }
    else qDebug() << tr("Database failed to open.");
}

QVector<QString> * MainWindow::getTextFromDatabase(const QString & tableName)
{
    QVector<QString> * tableEntries = new QVector<QString>;
    if(_db->isOpen() && _dbquery)
    {
        QString query = "SELECT * FROM " + tableName;
        _dbquery->exec(query);

        while(_dbquery->next()) tableEntries->push_back(_dbquery->value(0).toString());
    }
    else qDebug() << tr("_db not open or _dbquery is NULL.");

    return tableEntries;
}

void MainWindow::addTextToDatabase(const QString & text, const QString & tableName)
{
    if(_db->isOpen() && _dbquery)
    {
        QString query = ("INSERT INTO " + tableName + " VALUES (\"" + text + "\")");
        _dbquery->exec(query);
    }
    else qDebug() << tr("_db not open or _dbquery is NULL.");
}

#endif
