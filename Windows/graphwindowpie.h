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
    explicit graphwindowpie(QWidget *parent = 0, QVector<teaching_entry> data_for_graphs = {}, QString passed_name = "", int tab_index = 0);
     ~graphwindowpie();

private slots:
    void make_teaching_pie_graph(QVector<teaching_entry> data_for_graphs, QString name);


private:
    Ui::graphwindowpie *ui;
    QVector<double> values;
    QStringList titles;
    QStringList years;
    QString name;

};

#endif // GRAPHWINDOWPIE_H
