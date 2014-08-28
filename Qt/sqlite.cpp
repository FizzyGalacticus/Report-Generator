#ifndef SQLITE_CPP
#define SQLITE_CPP
#include "mainwindow.h"
#include <QSqlQuery>
#include <QDebug>

void MainWindow::_setupSQLiteDatabase()
{
    _db->setHostName("CWI");
    _db->setDatabaseName("CWIDB");
    bool ok = _db->open();

    if(ok)
    {
        qDebug() << "Database opened!";

        _dbquery = new QSqlQuery(*_db);

        _dbquery->exec("CREATE TABLE IF NOT EXISTS initials(INITIALS TEXT UNIQUE)");
        _dbquery->exec("CREATE TABLE IF NOT EXISTS removedprograms(TITLE TEXT UNIQUE)");
    }
    else qDebug() << "Database failed to open.";
}

#endif
