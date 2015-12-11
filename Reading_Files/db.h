/*
 * Header File: db.h
 * --------------------------------
 * + Defines the declarations for inputting and outputting
 *   into and from the database respectively for the class
 *   db.cpp
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <string.h>
#include "teaching_entry.h"
#include "grants_entry.h"
#include "DataEntry/publication_entry.h"
#include "DataEntry/presentation_entry.h"
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

       void addPublicationEntry(publication_entry a);

       void addPresentationEntry(presentation_entry a);

       //------------------------ OUTPUT FROM DATABASE ------------------------//

       QVector<teaching_entry> getTeachFull();

       QVector<teaching_entry> getTeachByDate(int date1, int date2);

       QVector<grants_entry> getGrantFull();

       QVector<grants_entry> getGrantByDate(int date1, int date2);

       QVector<publication_entry> getPubFull();

       QVector<publication_entry> getPubByDate(int date1, int date2);

       QVector<presentation_entry> getPresFull();

       QVector<presentation_entry> getPresByDate(int date1, int date2);

};


