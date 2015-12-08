#include "Windows/mainwindow.h"
#include "Windows/summary_window.h"

#include "Reading_Files/read_database.h"

using namespace boost;
using namespace std;


/*
 * Function: main
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Runs the program by opening the 'mainwindow'
 */
int main(int argc, char *argv[])
{

    //DB database;
    //readTeach(database);
    //QVector<teaching_entry> tVect = database.getTeachFull();

    /*
    while(!tVect.isEmpty()){
        teaching_entry teach1 = tVect.takeFirst();
        std::cout <<teach1.get_date()<< " " << teach1.get_member() << " " <<
                    teach1.get_program() << " " << teach1.get_total_hours() << " " << teach1.get_trainees()<<"\n\n\n";
    }
    */


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
