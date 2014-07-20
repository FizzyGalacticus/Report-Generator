#ifndef IO_CPP
#define IO_CPP

#include <QInputDialog>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

inline const QString getUserInputString(QWidget *parent, const QString windowName, const QString prompt)
{
    bool ok = false;
    const QString input = QInputDialog::getText(parent, windowName,prompt, QLineEdit::Normal,"", &ok);

    if(ok) return input;
    else return "";
}

inline vector<string> getStringListFromFile(const QString & filename)
{
    vector<string> myList;

    ifstream in;

    in.open(filename.toStdString().c_str(), std::ios::in);

    if(in)
    {
        string temp;
        while(!in.eof())
        {
            getline(in,temp);
            if(temp != "")
                myList.push_back(temp);
        }
        in.close();
    }

    std::sort(myList.begin(),myList.end());

    for(unsigned int i = 0; i < myList.size(); i++) qDebug() << myList[i].c_str() << '\n';

    return myList;
}

inline bool appendLineToFile(const QString & filename, const QString & line)
{
    ofstream out;

    out.open(filename.toStdString().c_str(), std::ios::app);

    if(out)
    {
        out << line.toStdString() << '\n';
        out.close();
        return true;
    }
    else return false;
}

#endif
