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
#include <Windows/graphcolors.h>
#include <Reading_Files/teaching_entry.h>

namespace Ui {
class graphwindowstack;
}

class graphwindowstack : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindowstack(QWidget *parent = 0,QVector<teaching_entry> data_for_graphs = {}, QStringList passed_years = {}, QString name = "", int tab_index = 0);
    ~graphwindowstack();

private slots:
    void make_teaching_stacked_graph(QVector<teaching_entry> data_for_graphs, QString name);
    void draw_teaching_stacked_graph(QVector<int> values, QStringList years, QVector<QColor> colors);

    void on_button_print_clicked();

private:
    Ui::graphwindowstack *ui;
    QStringList years;
    QVector<int> values;
};

#endif // GRAPHWINDOWSTACK_H
