#include "Windows/mainwindow.h"
#include "Windows/summary_window.h"
#include <QApplication>

/*
 * Function: main
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Runs the program by opening the 'mainwindow'
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //SummaryWindow l;
    //l.setWindowModality(Qt::ApplicationModal);
    //l.show();

    return a.exec();
}
