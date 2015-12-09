/*
 * Header File: graphwindowstack.h
 * --------------------------------
 * + Defines the declarations for functions and variables
 *   for graphwindowstack.cpp
 */

#ifndef GRAPHWINDOWSTACK_H
#define GRAPHWINDOWSTACK_H

#include <QDialog>
#include <Charts/qcustomplot.h>
#include <Reading_Files/teaching_entry.h>

namespace Ui {
class graphwindowstack;
}

class graphwindowstack : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindowstack(QWidget *parent = 0,QVector<teaching_entry> data_for_graphs = {}, QStringList passed_years = {}, QString name = "");
    ~graphwindowstack();

private slots:
    void make_stacked_bar_graph(QVector<QVector<int>> values, QStringList years);

private:
    Ui::graphwindowstack *ui;
    QStringList years;
    QVector<QVector<int>> values_by_year;
};

#endif // GRAPHWINDOWSTACK_H
