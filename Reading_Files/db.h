#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QtSql/QtSql>
#include <QDebug>
#include <QFileInfo>
#include <string.h>
#include "DataEntry/teaching_entry.h"
#include <QVector>
#include <sstream>

class DB
{




public:
    DB();

    //------------------------ INPUT INTO DATABASE ------------------------//

    void addGrantEntry();

    void addPublicationEntry();

    void addPresentationEntry();

    void addTeachingEntry(teaching_entry a);


    //------------------------ OUTPUT FROM DATABASE ------------------------//

    QVector<teaching_entry> getTeachFull();

};


