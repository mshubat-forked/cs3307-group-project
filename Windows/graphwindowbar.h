/*
 * Header File: graphwindowbar.h
 * --------------------------------
 * + Defines the declarations for functions and variables
 *   for graphwindowbar.cpp
 */

#ifndef GRAPHWINDOWBAR_H
#define GRAPHWINDOWBAR_H

#include <QDialog>
#include <Charts/qcustomplot.h>
#include <Windows/graphcolors.h>
#include <Reading_Files/teaching_entry.h>


namespace Ui {
class graphwindowbar;
}

class graphwindowbar : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindowbar(QWidget *parent = 0,QVector<teaching_entry> data_for_graphs = {}, QStringList years_for_graphs = {}, QString name = "", int tab_index = 0);
    ~graphwindowbar();

private slots:
    void make_teaching_bar_graph(QVector<teaching_entry> data_for_graphs, QString name);
    void draw_teaching_bar_graph(QVector<double> values, QStringList years, QVector<QColor> colors);

private:
    Ui::graphwindowbar *ui;
      QVector<double> values;
      QStringList years;
};

#endif // GRAPHWINDOWBAR_H
