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
#include <Windows/summary_window.h>
#include <Reading_Files/teaching_entry.h>


namespace Ui {
class graphwindowbar;
}

class graphwindowbar : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindowbar(QWidget *parent = 0,QVector<teaching_entry> data_for_graphs = {}, QStringList years = {}, QString name = "");
    ~graphwindowbar();

private slots:
    void make_bar_graph(QVector<double> values);

private:
    Ui::graphwindowbar *ui;
      QVector<double> values;
};

#endif // GRAPHWINDOWBAR_H
