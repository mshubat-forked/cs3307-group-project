/*
 * Header File: graphwindowpie.h
 * --------------------------------
 * + Defines the declarations for functions and variables
 *   for graphwindowpie.cpp
 */

#ifndef GRAPHWINDOWPIE_H
#define GRAPHWINDOWPIE_H

#include <QDialog>
#include <Charts/qcustomplot.h>
#include <Reading_Files/teaching_entry.h>

namespace Ui {
class graphwindowpie;
}

class graphwindowpie : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindowpie(QWidget *parent = 0, QVector<teaching_entry> data_for_graphs = {}, QString passed_name = "");

    ~graphwindowpie();

private:
    Ui::graphwindowpie *ui;
    QVector<double> values;
    QStringList titles;
    QStringList years;
    QString name;


    void setup_look();

};

#endif // GRAPHWINDOWPIE_H
