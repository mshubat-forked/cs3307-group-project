/*
 * Header file: read_database.h
 * ---------------------------------
 * + Contains function declarations for reading data from
 *   a database for the file read_database.cpp
 */

#ifndef READ_DATABASE_H
#define READ_DATABASE_H

#include "DataEntry/teaching_entry.h"
#include "DataEntry/grants_entry.h"
#include "iostream"
#include "fstream"
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <Commdlg.h>
#include <tchar.h>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <algorithm>
#include "Reading_Files/db.h"

using namespace boost;
using namespace std;

// + Trims down a date to a year
string dateTrim(string t);

// + Reads a teaching database into the program
void readTeach(QWidget *parent, DB db);
void readPresentations(QWidget *parent, DB db);
void readGrants(QWidget *parent, DB db);
void readPublications(QWidget *parent, DB db);


#endif // READ_DATABAS_H
