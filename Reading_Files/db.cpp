/*
 * Source file: db.cpp
 * ---------------------------------
 * + Defines a class to handles the connection and queries to the SQLite database
 *   storing csv information
 */

#include "db.h"

/**
 * Database Construcor
 * - Creates Database 4 Tables within Database
 *
 */

static QSqlDatabase db;


/*
 * Constructor: DB
 * ---------------------------------------
 * WHAT THE CONSTRUCTOR DOES:
 * + Creates DB object which creates tables to store
 *   information from read csv files
 */
DB::DB()//constructor for the database - creates 4 data type tables
{
    db = QSqlDatabase:: addDatabase("QSQLITE","db_connection");//static to remain for every created DB object
    QString name = "database.db";

    db.setDatabaseName(QDir::homePath() + QDir::separator()+ name);

    if(!db.open())
        std::cout << "Failed to open the Database\n";
    else
        std::cout<< "Succeeded in opening Database\n";


    QString sql;

    //-------------- Create Grants and Clinical Funding Table --------------//

    sql="CREATE TABLE grantsClinicalFunding (StartDate int,MemberName varchar(40),FundingType varchar (16),PeerReviewed varchar(5), Status varchar(12),Role varchar(30),TotalAmount money, Title varchar(40), PrimaryDomain varchar(30), IndustryGrant varchar(5), PrincipalInvestigator varchar(30),CoInvestigators varchar(40),TotalAmount money);";


    db.exec(sql);

    //-------------- Create Publications Table --------------//

    sql="CREATE TABLE publications(MemberName varchar(40),PrimaryDomain varchar(30),PublicationStatus varchar(10), Type varchar(30), StatusDate int, Role varchar(30), MediumName varchar(50), [Author(s)] varchar(200),Title varchar(200));";


    db.exec(sql);

    //-------------- Create Presentations Table --------------//

    sql="CREATE TABLE presentations(Date int, MemberName varchar(40),Type varchar(30), Role varchar(20));";
    db.exec(sql);

    //-------------- Create Teaching Table --------------//

    sql="CREATE TABLE teaching(StartDate int,MemberName varchar(40),Program varchar(40), TotalHours DOUBLE(4,2),NumStudents int);";
    db.exec(sql);

    //db.close();
}

//------------------------ INPUT INTO DATABASE ------------------------//

/*
 * Function: addTeachEntry
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Adds read in teaching_entry items from the teaching csv file
 *   into the database
 */
void DB::addTeachingEntry(teaching_entry a){

    string sql;
    string Date,Name,Prog,Hours,NumStudents;
    QString qsql;

    //QString::fromStdString(a.get_date());

    Date=a.get_date();
    Name=a.get_member();
    Prog=a.get_program();
    Hours=std::to_string(a.get_total_hours());//total_hours is a double
    NumStudents=std::to_string(a.get_trainees());//trainess is an int



    sql = std::string("INSERT INTO teaching (StartDate,MemberName, Program, TotalHours, NumStudents) VALUES(")+"'"+Date+"','"+Name+"','"+Prog+"',"+Hours+","+NumStudents+");";


    qsql = QString::fromStdString(sql);//convert to qstring

    db.exec(qsql);//execute Add teaching entry sql Statement
}








//------------------------ OUTPUT FROM DATABASE ------------------------//

/*
 * Function: addTeachFull
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Gets data from the database to the program so it can be
 *   displayed to the GUI
 *
 * RETURNS
 * + A QVector that stores paired down teaching_entry items that are relevant to the GUI
 */
QVector<teaching_entry> DB::getTeachFull(){

    ostringstream convert;
    QSqlQuery qry(db);
    string date;


    QVector<teaching_entry> tVector;
    qry.prepare("SELECT * FROM Teaching\
                ORDER BY Program, StartDate, MemberName");
                qry.exec();
            while(qry.next()){
        teaching_entry TE;

        convert.str("");

        convert <<qry.value(0).toInt();

        date=convert.str();



          TE.set_date(convert.str());
          TE.set_member(qry.value(1).toString().toStdString());
          TE.set_program(qry.value(2).toString().toStdString());
          TE.set_total_hours(qry.value(3).toDouble());
          TE.set_trainees(qry.value(4).toInt());


         tVector.append(TE);
    }

    return tVector;
}









