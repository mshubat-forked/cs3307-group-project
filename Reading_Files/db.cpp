/*
 * Source file: db.cpp
 * ---------------------------------
 * + Defines a class to handles the connection and queries to the SQLite database
 *   storing csv information
 */

#include "db.h"
#define GetCurrentDir _getcwd

/**
 * Database Construcor
 * - Creates Database 4 Tables within Database
 *
 */

//------- Class and Static variables -------/
static QSqlDatabase db;//static so remains in tact on different calls to DB
QString name = "/database.db";
QString curDir;




DB::DB()//constructor for the database - creates 4 data type tables
{

    std::string path = getcwd(NULL, 0);
    std::replace(path.begin(), path.end(), '\\', '/'); // replace all '\' to '/'

    curDir = QString::fromStdString(path);

    db = QSqlDatabase:: addDatabase("QSQLITE","db_connection");//static to remain for every created DB object


    db.setDatabaseName(curDir + name);

    if(!db.open())
        std::cout << "Failed to open the Database\n";
    else


        std::cout<< "Succeeded in opening Database\n";


    QString sql;

    //-------------- Create Teaching Table --------------//

    sql="CREATE TABLE teaching(StartDate int,MemberName varchar(40),Program varchar(40), TotalHours DOUBLE(4,2),NumStudents int);";
    db.exec(sql);

    //-------------- Create Grants and Clinical Funding Table --------------//

    sql="CREATE TABLE grantsClinicalFunding (StartDate int,MemberName varchar(40),FundingType varchar (16),PeerReviewed varchar(5),IndustryGrant varchar(5), Status varchar(12),Role varchar(30),TotalAmount money, Title varchar(40));";
    db.exec(sql);

    //-------------- Create Publications Table --------------//

    sql="CREATE TABLE publications(MemberName varchar(40),PrimaryDomain varchar(30),PublicationStatus varchar(10), Type varchar(30), StatusDate int, Role varchar(30), MediumName varchar(50), [Author(s)] varchar(200),Title varchar(200));";
    db.exec(sql);

    //-------------- Create Presentations Table --------------//

    sql="CREATE TABLE presentations(Date int, MemberName varchar(40),Type varchar(30), Role varchar(20));";
    db.exec(sql);



    //db.close();
}


//------------------------ OTHER FUNCTIONS ------------------------//
/**
 * @brief DB::dbexists
 * @return true if database.db exists in current dir
 * else @return false
 */
bool DB::dbexists(){

    //R eplace all '\' with '/'

    std::string s = getcwd(NULL, 0);;
    std::replace( s.begin(), s.end(), '\\', '/'); // replace all 'x' to 'y'

    //Check if DB exists
    if (ifstream(s+"/database.db")){//if database exists
        return true;
    }
    else{//if database does NOT exist
        return false;
    }

}

//------------------------ INPUT INTO DATABASE ------------------------//
/**
 * @brief DB::addTeachingEntry
 * @param a
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

    //convert sql statement to Qstring
    qsql = QString::fromStdString(sql);//convert to qstring

    db.exec(qsql);//execute Add teaching entry sql Statement

}


/**
 * @brief DB::addGrantsEntry
 * @param a
 */
void DB::addGrantEntry(grants_entry a){

    string sql;//used to hold sql string
    string Date,MemberName,FundingType,PeerReview,IndustrySpons,Status,Role,Amount,Title;
    QString qsql;//used to hold sql QString


    Date=a.get_date();
    MemberName=a.get_member();
    FundingType=a.get_ftype();
    PeerReview= std::to_string(a.get_preview());//bool
    IndustrySpons=std::to_string(a.get_ind_grant());//bool
    Status=a.get_status();
    Role=a.get_role();
    Amount=std::to_string(a.get_total_amount());//int
    Title=a.get_title();


    sql = std::string("INSERT INTO grantsClinicalFunding (StartDate, MemberName, FundingType, PeerReviewed, IndustryGrant, Status, Role, TotalAmount, Title) VALUES(")+"'"+Date+"','"+MemberName+"','"+FundingType+"','"+PeerReview+"','"+IndustrySpons+"','"+Status+"','"+Role+"',"+Amount+",'"+Title+"');";

    //convert sql statement to Qstring
    qsql = QString::fromStdString(sql);//convert to qstring

    db.exec(qsql);//execute Add teaching entry sql Statement


}

//------------------------ OUTPUT FROM DATABASE ------------------------//
/**
 * @brief DB::getTeachFull
 * @return Vector of all teaching entries
 */
QVector<teaching_entry> DB::getTeachFull(){

    ostringstream convert;
    QSqlQuery qry(db);
    string date;

    QVector<teaching_entry> tVector;
    qry.prepare("SELECT * FROM Teaching ORDER BY Program, StartDate");

    qry.exec();



    while(qry.next()){

        teaching_entry TE;//create teaching_entry to append to vector

        convert.str("");

        convert <<qry.value(0).toInt();

        date=convert.str();


        TE.set_date(convert.str());
        TE.set_member(qry.value(1).toString().toStdString());
        TE.set_program(qry.value(2).toString().toStdString());
        TE.set_total_hours(qry.value(3).toInt());
        TE.set_trainees(qry.value(4).toInt());


        tVector.append(TE);
    }//end of while

    return tVector;
}

/**
 * @brief DB::getGrantFull()
 * @return vector of all grant entries
 */
QVector<grants_entry> DB::getGrantFull(){

    ostringstream convert;
    QSqlQuery qry(db);
    string date;

    QVector<grants_entry> tVector;
    qry.prepare("SELECT * FROM grantsClinicalFunding ORDER BY FundingType, PeerReviewed, MemberName");

    qry.exec();



    while(qry.next())//loops through rows in table
    {
        grants_entry GE;//create grants_entry to append to vector

        GE.set_date(qry.value(0).toString().toStdString());
        GE.set_member(qry.value(1).toString().toStdString());
        GE.set_ftype(qry.value(2).toString().toStdString());
        GE.set_preview(qry.value(3).toInt());
        GE.set_ind_grant(qry.value(4).toInt());
        GE.set_status(qry.value(5).toString().toStdString());
        GE.set_role(qry.value(6).toString().toStdString());
        GE.set_total_amount(qry.value(7).toInt());
        GE.set_title(qry.value(8).toString().toStdString());


        tVector.append(GE);
    }//end of while


    return tVector;
}











