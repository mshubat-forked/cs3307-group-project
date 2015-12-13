/*
 * Source file: read_database.cpp
 * ---------------------------------
 * + A class that defines functions for reading csv files
 *   and storing that read data into a SQLite database
 */


#include "read_database.h"
#include <QtCore>
#include <QtGui>
#include <QProgressDialog>
#include <QProgressBar>

/*
 * Function: readTeach
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Reads and parses a 'teaching' csv file to pass to a database
 */
void readTeach(QWidget *parent ,DB database){


    // + This whole chuck of code is for a loading window to let
    //   the user know the program is loading files
    int pw_x = parent->pos().x();
    int pw_y = parent->pos().y();

    int pw_width = parent->size().width();
    int pw_height = parent->size().height();

    QProgressDialog progress(parent);
    progress.setWindowModality(Qt::WindowModal);
    progress.setLabelText("Loading data...");
    progress.setCancelButton(0);
    progress.setRange(0,0);
    progress.setMinimumDuration(0);

    progress.setGeometry((pw_x+(pw_width/2))-175, (pw_y+(pw_height/2))-40, 350, 150);
    progress.show();


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

    //tokenizer for commas
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
      boost::char_separator<char> sep(
          ",", // dropped delimiters
          "",  // kept delimiters
          boost::keep_empty_tokens); // empty token policy
      //tokenizer for quotes
      typedef boost::tokenizer<boost::char_separator<char> > tokenizer2;
        boost::char_separator<char> sep2(
            "\"", // dropped delimiters
            "",  // kept delimiters
            boost::keep_empty_tokens);

    ifstream indata; //this is used to open the file we are reading from
    ofstream outdata2; //this is used to open a file we are outputting debugging info to
    outdata2.open("teaching.txt"); //output file for reading teraching entries
    string line;
    indata.open(buffer); //opens file that was selected
    int counter = 0; //used to count rows

    if (indata.is_open())
      {
        while ( getline(indata,line) )
        {

          /*
           * this removes commas between parts of the string that are in quotes
           * this addresses pointer issues that might otherwise arise
           * used mainly for names and lsits of names
           */
          int odd = 0; //keeps track of where we are in quotes
          string newLine = ""; //holds newly adjusted string
          BOOST_FOREACH(string t, tokenizer2(line, sep2)){

              if(odd%2 != 0){ //if we're between quotes
                 //outdata2 << "made it here" << endl;
                  t.erase(
                      remove( t.begin(), t.end(), ',' ),
                      t.end()
                      );//remove all commas within

              }
              newLine = newLine + t;
              odd++;
          }


          line = newLine; //copies over newLine with removed commas between quotes
          counter++;
          outdata2 << counter << endl;

          if(counter == 1){

              int locCounter = 0;//used to keep track of column location
              BOOST_FOREACH(string t, tokenizer(line, sep)){


               if(t.compare("Last Modified User") == 0){
                    lastModifiedUserLoc = locCounter;
                    outdata2<< "checking t: " + t + " " << locCounter << endl;
                }
                else if(t.compare("Start Date") == 0){
                    outdata2<< "checking t: " + t + " " << locCounter << endl;
                    startDateLoc = locCounter;
                }
                else if(t.compare("Member Name") == 0){
                    outdata2<< "checking t: " + t + " " << locCounter << endl;
                    memberNameLoc = locCounter;
                }
                else if(t.compare("Program") == 0){
                    outdata2<< "checking t: " + t + " " << locCounter << endl;
                    programLoc = locCounter;
                }
                else if(t.compare("Total Hours") == 0){
                    outdata2<< "checking t: " + t + " " << locCounter<< endl;
                    hourLoc = locCounter;
                }
                else if(t.compare("Number Of Trainees") == 0){
                    outdata2<< "checking t: " + t + " " << locCounter<< endl;
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



                if(locCounter2 == startDateLoc){
                   t = dateTrim(t);
                   outdata2 << "should be date: " << t << endl;
                   temp.set_date(t);
                }
                else if(locCounter2 == memberNameLoc){
                    temp.set_member(t);
                    outdata2 << "should be member: " << temp.get_member() << endl;

                }
                else if(locCounter2 == programLoc){
                    outdata2 << "should be program: " << t << endl;
                    temp.set_program(t);
                }
                else if(locCounter2 == hourLoc){
                    outdata2 << "should be Total Hours: " << atof(t.c_str())<< endl;
                    temp.set_total_hours(atof(t.c_str()));
                }
                else if(locCounter2 == numberOfStudentsLoc){
                    outdata2 << "should be trainees: " << t << endl;
                   temp.set_trainees(atoi(t.c_str()));
                }
                else{
                    //do nothing
                }
               locCounter2++;
            }
            database.addTeachingEntry(temp);
            outdata2 << line << '\n';
          }
        }
        indata.close();
        outdata2.close();
      }

    progress.cancel();

}

void readPresentations(QWidget *parent, DB db)
{
    // + This whole chuck of code is for a loading window to let
    //   the user know the program is loading files
    int pw_x = parent->pos().x();
    int pw_y = parent->pos().y();

    int pw_width = parent->size().width();
    int pw_height = parent->size().height();

    QProgressDialog progress(parent);
    progress.setWindowModality(Qt::WindowModal);
    progress.setLabelText("Loading data...");
    progress.setCancelButton(0);
    progress.setRange(0,0);
    progress.setMinimumDuration(0);

    progress.setGeometry((pw_x+(pw_width/2))-175, (pw_y+(pw_height/2))-40, 350, 150);
    progress.show();

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
    int dateLoc;
    int memberNameLoc;
    int typeLoc;
    int roleLoc;


    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
      boost::char_separator<char> sep(
          ",", // dropped delimiters
          "",  // kept delimiters
          boost::keep_empty_tokens); // empty token policy
      //tokenizer for quotes
      typedef boost::tokenizer<boost::char_separator<char> > tokenizer2;
        boost::char_separator<char> sep2(
            "\"", // dropped delimiters
            "",  // kept delimiters
            boost::keep_empty_tokens);

    ifstream indata;
    string line;
    ofstream outData;
    outData.open("presentation.txt");
    indata.open(buffer);
    int counter = 0;
    if (indata.is_open())
      {
        while ( getline(indata,line) )
        {
            /*
             * this removes commas between parts of the string that are in quotes
             * this addresses pointer issues that might otherwise arise
             * used mainly for names and lsits of names
             */
            int odd = 0; //keeps track of where we are in quotes
            string newLine = ""; //holds newly adjusted string
            BOOST_FOREACH(string t, tokenizer2(line, sep2)){

                if(odd%2 != 0){ //if we're between quotes
                   //outdata2 << "made it here" << endl;
                    t.erase(
                        remove( t.begin(), t.end(), ',' ),
                        t.end()
                        );//remove all commas within

                }
                newLine = newLine + t;
                odd++;
            }


          line = newLine; //copies over newLine with removed commas between quotes
          counter++;
          outData << counter << endl;


          if(counter == 1){

              int locCounter = 0;//used to keep track of column location
              BOOST_FOREACH(string t, tokenizer(line, sep)){

               if(t.compare("Date") == 0){
                    outData<< "checking t: " + t + " " << locCounter << endl;
                    dateLoc = locCounter;
                }
                else if(t.compare("Member Name") == 0){
                    outData<< "checking t: " + t + " " << locCounter << endl;
                    memberNameLoc = locCounter;
                }
                else if(t.compare("Type") == 0){
                    outData<< "checking t: " + t + " " << locCounter << endl;
                    typeLoc = locCounter;
                }
                else if(t.compare("Role") == 0){
                    outData<< "checking t: " + t + " " << locCounter<< endl;
                    roleLoc = locCounter;
                }
                else{
                    //do nothing
                }

                locCounter++;
              }
          }
          else{
            int locCounter2 = 0;
            presentation_entry temp = presentation_entry();//temporary grants_entry to be added to database
            BOOST_FOREACH(string t, tokenizer(line, sep))
            {

                if(locCounter2 == dateLoc){
                   t = dateTrim(t);
                   outData << "should be date: " << t << endl;
                   temp.set_date(t);
                }
                else if(locCounter2 == memberNameLoc){
                    temp.set_member(t);
                    outData << "should be member: " << temp.get_member() << endl;
                }
                else if(locCounter2 == typeLoc){
                    outData << "should be type: " << t << endl;
                    temp.set_type(t);
                }
                else if(locCounter2 == roleLoc){
                    outData << "should be role: " << t << endl;
                    temp.set_role(t);
                }
                else{
                    //do nothing
                }
               locCounter2++;
            }
            db.addPresentationEntry(temp);
            outData << line << '\n';

          }
        }

        indata.close();
        outData.close();
      }
    progress.cancel();
}
void readGrants(QWidget *parent, DB db)
{
    // + This whole chuck of code is for a loading window to let
    //   the user know the program is loading files
    int pw_x = parent->pos().x();
    int pw_y = parent->pos().y();

    int pw_width = parent->size().width();
    int pw_height = parent->size().height();

    QProgressDialog progress(parent);
    progress.setWindowModality(Qt::WindowModal);
    progress.setLabelText("Loading data...");
    progress.setCancelButton(0);
    progress.setRange(0,0);
    progress.setMinimumDuration(0);

    progress.setGeometry((pw_x+(pw_width/2))-175, (pw_y+(pw_height/2))-40, 350, 150);
    progress.show();

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
    int fundTypeLoc;
    int peerReviewLoc;
    int statusLoc;
    int roleLoc;
    int amountLoc;
    int titleLoc;


    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
      boost::char_separator<char> sep(
          ",", // dropped delimiters
          "",  // kept delimiters
          boost::keep_empty_tokens); // empty token policy
      //tokenizer for quotes
      typedef boost::tokenizer<boost::char_separator<char> > tokenizer2;
        boost::char_separator<char> sep2(
            "\"", // dropped delimiters
            "",  // kept delimiters
            boost::keep_empty_tokens);

    ifstream indata;
    string line;
    ofstream outData;
    outData.open("grants.txt");
    indata.open(buffer);
    int counter = 0;
    if (indata.is_open())
      {
        while ( getline(indata,line) )
        {
            /*
             * this removes commas between parts of the string that are in quotes
             * this addresses pointer issues that might otherwise arise
             * used mainly for names and lsits of names
             */
            int odd = 0; //keeps track of where we are in quotes
            string newLine = ""; //holds newly adjusted string
            BOOST_FOREACH(string t, tokenizer2(line, sep2)){

                if(odd%2 != 0){ //if we're between quotes
                   //outdata2 << "made it here" << endl;
                    t.erase(
                        remove( t.begin(), t.end(), ',' ),
                        t.end()
                        );//remove all commas within

                }
                newLine = newLine + t;
                odd++;
            }


          line = newLine; //copies over newLine with removed commas between quotes
          counter++;
          outData << counter << endl;


          if(counter == 1){

              int locCounter = 0;//used to keep track of column location
              BOOST_FOREACH(string t, tokenizer(line, sep)){

               if(t.compare("Start Date") == 0){
                    outData<< "checking t: " + t + " " << locCounter << endl;
                    startDateLoc = locCounter;
                }
                else if(t.compare("Member Name") == 0){
                    outData<< "checking t: " + t + " " << locCounter << endl;
                    memberNameLoc = locCounter;
                }
                else if(t.compare("Funding Type") == 0){
                    outData<< "checking t: " + t + " " << locCounter << endl;
                    fundTypeLoc = locCounter;
                }
                else if(t.compare("Role") == 0){
                    outData<< "checking t: " + t + " " << locCounter<< endl;
                    roleLoc = locCounter;
                }
                else if(t.compare("Title") == 0){
                    outData<< "checking t: " + t + " " << locCounter<< endl;
                    titleLoc = locCounter;
                }
               else if(t.compare("Total Amount") == 0){
                   outData<< "checking t: " + t + " " << locCounter<< endl;
                   amountLoc = locCounter;
               }
               else if(t.compare("Status") == 0){
                   outData<< "checking t: " + t + " " << locCounter<< endl;
                   statusLoc = locCounter;
               }
               else if(t.compare("Peer Reviewed?") == 0){
                   outData<< "checking t: " + t + " " << locCounter<< endl;
                   peerReviewLoc = locCounter;
               }
                else{
                    //do nothing
                }

                locCounter++;
              }
          }
          else{
            int locCounter2 = 0;
            grants_entry temp = grants_entry();//temporary grants_entry to be added to database
            BOOST_FOREACH(string t, tokenizer(line, sep))
            {

                if(locCounter2 == startDateLoc){
                   t = dateTrim(t);
                   outData << "should be date: " << t << endl;
                   temp.set_date(t);
                }
                else if(locCounter2 == memberNameLoc){
                    temp.set_member(t);
                    outData << "should be member: " << temp.get_member() << endl;
                }
                else if(locCounter2 == fundTypeLoc){
                    outData << "should be type: " << t << endl;
                    temp.set_ftype(t);
                }
                else if(locCounter2 == peerReviewLoc){
                    outData << "should be PReview: " << t << endl;
                    bool check = false;
                    if(t.compare("TRUE") == 0){
                        check = true;
                    }
                    temp.set_preview(check);
                }
                else if(locCounter2 == roleLoc){
                    outData << "should be role: " << t << endl;
                    temp.set_role(t);
                }
                else if(locCounter2 == titleLoc){
                    outData << "should be title: " << t << endl;
                   temp.set_title(t);
                }
                else if(locCounter2 == statusLoc){
                    outData << "should be status: " << t << endl;
                   temp.set_status(t);
                }
                else if(locCounter2 == amountLoc){
                   outData << "should be Total amount: " << t << endl;
                   temp.set_total_amount(atof(t.c_str()));
                }
                else{
                    //do nothing
                }
               locCounter2++;
            }
            db.addGrantEntry(temp);
            outData << line << '\n';
          }
        }
        indata.close();
        outData.close();
      }
    progress.cancel();
}
void readPublications(QWidget *parent, DB db)
{
    // + This whole chuck of code is for a loading window to let
    //   the user know the program is loading files
    int pw_x = parent->pos().x();
    int pw_y = parent->pos().y();

    int pw_width = parent->size().width();
    int pw_height = parent->size().height();

    QProgressDialog progress(parent);
    progress.setWindowModality(Qt::WindowModal);
    progress.setLabelText("Loading data...");
    progress.setCancelButton(0);
    progress.setRange(0,0);
    progress.setMinimumDuration(0);

    progress.setGeometry((pw_x+(pw_width/2))-175, (pw_y+(pw_height/2))-40, 350, 150);
    progress.show();

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
    int statusDateLoc;
    int memberNameLoc;
    int typeLoc;
    int titleLoc;
    int roleLoc;
    int authorLoc;
    int lastModifiedUserLoc;

    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
      boost::char_separator<char> sep(
          ",", // dropped delimiters
          "",  // kept delimiters
          boost::keep_empty_tokens); // empty token policy
      //tokenizer for quotes
      typedef boost::tokenizer<boost::char_separator<char> > tokenizer2;
        boost::char_separator<char> sep2(
            "\"", // dropped delimiters
            "",  // kept delimiters
            boost::keep_empty_tokens);

    ifstream indata;
    string line;
    ofstream outData;
    outData.open("publication.txt");
    indata.open(buffer);
    int counter = 0;
    if (indata.is_open())
      {
        while ( getline(indata,line) )
        {
            /*
             * this removes commas between parts of the string that are in quotes
             * this addresses pointer issues that might otherwise arise
             * used mainly for names and lsits of names
             */
            int odd = 0; //keeps track of where we are in quotes
            string newLine = ""; //holds newly adjusted string
            BOOST_FOREACH(string t, tokenizer2(line, sep2)){

                if(odd%2 != 0){ //if we're between quotes
                   //outdata2 << "made it here" << endl;
                    t.erase(
                        remove( t.begin(), t.end(), ',' ),
                        t.end()
                        );//remove all commas within

                }
                newLine = newLine + t;
                odd++;
            }


          line = newLine; //copies over newLine with removed commas between quotes
          counter++;
          outData << counter << endl;


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
                    outData << "checking t: " + t + " " << locCounter << endl;
                }
                else if(t.compare("Status Date") == 0){
                    outData<< "checking t: " + t + " " << locCounter << endl;
                    statusDateLoc = locCounter;
                }
                else if(t.compare("Member Name") == 0){
                    outData<< "checking t: " + t + " " << locCounter << endl;
                    memberNameLoc = locCounter;
                }
                else if(t.compare("Type") == 0){
                    outData<< "checking t: " + t + " " << locCounter << endl;
                    typeLoc = locCounter;
                }
                else if(t.compare("Role") == 0){
                    outData<< "checking t: " + t + " " << locCounter<< endl;
                    roleLoc = locCounter;
                }
                else if(t.compare("Title") == 0){
                    outData<< "checking t: " + t + " " << locCounter<< endl;
                    titleLoc = locCounter;
                }
               else if(t.compare("Author(s)") == 0){
                   outData<< "checking t: " + t + " " << locCounter<< endl;
                   authorLoc = locCounter;
               }
                else{
                    //do nothing
                }

                locCounter++;
              }
          }
          else{
            int locCounter2 = 0;
            publication_entry temp = publication_entry();
            BOOST_FOREACH(string t, tokenizer(line, sep))
            {

                if(locCounter2 == statusDateLoc){
                   t = dateTrim(t);
                   outData << "should be date: " << t << endl;
                   temp.set_DOI(t);
                }
                else if(locCounter2 == memberNameLoc){
                    temp.set_member(t);
                    outData << "should be member: " << temp.get_member() << endl;
                }
                else if(locCounter2 == typeLoc){
                    outData << "should be type: " << t << endl;
                    temp.set_type(t);
                }
                else if(locCounter2 == roleLoc){
                    outData << "should be role: " << t << endl;
                    temp.set_role(t);
                }
                else if(locCounter2 == titleLoc){
                    outData << "should be title: " << t << endl;
                   temp.set_title(t);
                }
                else if(locCounter2 == authorLoc){
                   outData << "should be authorlist: " << t << endl;
                   temp.set_authors(t);
                }
                else{
                    //do nothing
                }
               locCounter2++;
            }
            db.addPublicationEntry(temp);
            outData << line << '\n';
          }
        }
        indata.close();
        outData.close();
      }
     progress.cancel();
}

/*
 * Function: dateTrim
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Trims a date from a the teaching csv down to a year value
 *
 * PARAMETERS:
 * - str: a data value in the form of a string
 *
 * RETURNS:
 * + Only the year value of the date passed
 */
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
