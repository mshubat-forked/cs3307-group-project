#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <string.h>
#include "teaching_entry.h"
#include "grants_entry.h"
#include "publication_entry.h"
#include "presentation_entry.h"
#include <QVector>
#include <sstream>
#include <fstream>
#include <direct.h>
#include <algorithm>


class DB
{




public:
    DB();




    //------------------------ OTHER FUNCTIONS ------------------------//

    static bool dbexists ();//static - can be called w/o an object

    //------------------------ INPUT INTO DATABASE ------------------------//

    void addTeachingEntry(teaching_entry a);

    void addGrantEntry(grants_entry a);

    void addPublicationEntry();

    void addPresentationEntry();

    //------------------------ OUTPUT FROM DATABASE ------------------------//

    QVector<teaching_entry> getTeachFull();

    QVector<grants_entry> getGrantFull();

};


