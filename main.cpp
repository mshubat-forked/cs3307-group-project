#include "mainwindow.h"
#include "summary_window.h"
#include <QApplication>

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
