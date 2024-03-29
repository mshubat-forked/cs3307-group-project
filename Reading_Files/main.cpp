#include "mainwindow.h"
#include "teaching_entry.h"
#include "grants_entry.h"
#include "hashtable.h"
#include "iostream"
#include "fstream"
#include <string>
#include <QApplication>
#include <stdlib.h>
#include <windows.h>
#include <Commdlg.h>
#include <tchar.h>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
#include <algorithm>
#include "db.h"



#ifndef NOMINMAX
#define NOMINMAX
#endif

using namespace boost;
using namespace std;

string dateTrim(string t);

int main(int argc, char *argv[])
{

    DB database;
    char buffer[MAX_PATH] = "";
    OPENFILENAMEA ofn = {0};  // note:  OPENFILENAMEA, not OPENFILENAME
    // the 'A' at the end specifies we want the 'char' version and not the 'TCHAR' version
    // if you want the 'wchar_t' version, you want to use OPENFILENAMEW instead

    ofn.lStructSize = sizeof(ofn);
    //ofn.hwndOwner = your_hwnd; // not entirely necessary if you don't have a window
    ofn.lpstrFilter = "CSVFiles\0*.csv";
    ofn.nFilterIndex = 1; // for some reason this is 1-based not zero-based.  grrrrr

    ofn.Flags = OFN_FILEMUSTEXIST;  // only allow the user to open files that actually exist

    // the most important bits:
    ofn.lpstrFile = buffer;
    ofn.nMaxFile = MAX_PATH;  // size of our 'buffer' buffer


    // Now that we've prepped the struct, actually open the dialog:
    //  the below function call actually opens the "File Open" dialog box, and returns
    //  once the user exits out of it
    if( !GetOpenFileNameA( &ofn ) ) // <- again note the 'A' at the end, signifying the 'char' version
    {
        // code reaches here if the user hit 'Cancel'
    }
    else
    {
        // code reaches here if the user hit 'OK'.  The full path of the file
        //  they selected is now stored in 'buffer'
    }

    //columns not consistent between documents, these variables account for that
    //they hold the location of the column that has the mandatory variable of the corresponding name
    int startDateLoc;
    int memberNameLoc;
    int programLoc;
    int hourLoc;
    int numberOfStudentsLoc;
    int lastModifiedUserLoc;

    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(
                ",", // dropped delimiters
                "",  // kept delimiters
                boost::keep_empty_tokens); // empty token policy

    ifstream indata;
    string line;
    indata.open(buffer);
    int counter = 0;
    if (indata.is_open())
    {
        while ( getline(indata,line) )
        {
            counter++;


            //split(tokenList, line, is_any_of(","), token_compress_on);
            /*
           *if this is the first row of the excel document
           * check to see which column holds the mandatory fields
           * and save these column locations in their designated variables
           */
            if(counter == 1){

                int locCounter = 0;//used to keep track of column location
                BOOST_FOREACH(string t, tokenizer(line, sep)){

                    if(t.compare("Last Modified User") == 0){
                        lastModifiedUserLoc = locCounter;
                        cout<< "checking t: " + t + " " << locCounter << endl;
                        locCounter++;
                    }
                    else if(t.compare("Start Date") == 0){
                        cout<< "checking t: " + t + " " << locCounter << endl;
                        startDateLoc = locCounter;
                    }
                    else if(t.compare("Member Name") == 0){
                        cout<< "checking t: " + t + " " << locCounter << endl;
                        memberNameLoc = locCounter;
                        locCounter++;
                    }
                    else if(t.compare("Program") == 0){
                        cout<< "checking t: " + t + " " << locCounter << endl;
                        programLoc = locCounter;
                    }
                    else if(t.compare("Total Hours") == 0){
                        cout<< "checking t: " + t + " " << locCounter<< endl;
                        hourLoc = locCounter;
                    }
                    else if(t.compare("Number Of Trainees") == 0){
                        cout<< "checking t: " + t + " " << locCounter<< endl;
                        numberOfStudentsLoc = locCounter;
                    }
                    else{
                        //do nothing
                    }

                    locCounter++;
                }
            }
            else{
                int locCounter2 = 0;
                teaching_entry temp = teaching_entry();
                BOOST_FOREACH(string t, tokenizer(line, sep))
                {
                    cout << locCounter2 << endl;

                    if(locCounter2 == lastModifiedUserLoc){
                        if(t.compare("") == 0){ //if the string is empty account for this with the pointer
                            locCounter2--;
                        }
                    }
                    else if(locCounter2 == startDateLoc){
                        t = dateTrim(t);
                        cout << "should be date: " << t << endl;
                        temp.set_date(t);
                    }
                    else if(locCounter2 == memberNameLoc){
                        temp.set_member(t);
                    }
                    else if(locCounter2 == memberNameLoc + 1){
                        if(temp.get_member().compare("") == 0){

                        }
                        else{
                            temp.set_member(temp.get_member() + " " + t);
                            string s = temp.get_member();
                            s.erase(
                                        remove( s.begin(), s.end(), '\"' ),
                                        s.end()
                                        );
                            temp.set_member(s);
                        }
                        cout << "should be member: " << temp.get_member() << endl;

                    }
                    else if(locCounter2 == programLoc){
                        cout << "should be program: " << t << endl;
                        temp.set_program(t);
                    }
                    else if(locCounter2 == hourLoc){
                        cout << "should be Total Hours: " << t << endl;
                        temp.set_total_hours(atof(t.c_str()));
                    }
                    else if(locCounter2 == numberOfStudentsLoc){
                        cout << "should be trainees: " << t << endl;
                        if(t.compare("")==0){
                            temp.set_trainees(0);
                        }
                        else{
                            temp.set_trainees(atoi(t.c_str()));
                        }
                    }
                    else{
                        //do nothing
                    }
                    locCounter2++;
                }
                cout << line << '\n';
                database.addTeachingEntry(temp);
            }

        }
        indata.close();
    }
    return 0;
}
string dateTrim(string str){
    size_t found = str.find("/");
    if (found == 4 || found == -1) {
        //year is the first 4 characters
        return str.substr(0, 4);
    }else{
        size_t found2 = str.find("/", found+1);
        if (found2 != -1 ) {
            //year is behind months
            return str.substr(found2+1, 4);
        }else{
            //year is the last 4 characters
            return str.substr(found+1, 4);
        }
    } cout << endl;
}

