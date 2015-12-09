/*
 * Header File: summary_window.h
 * --------------------------------
 * + Defines the declarations for functions
 *   for summary_window.cpp
 */

#ifndef SUMMARY_WINDOW_H
#define SUMMARY_WINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <stdlib.h>
#include <Windows/graphwindowstack.h>
#include <Windows/graphwindowpie.h>
#include <Windows/graphwindowbar.h>
#include <Windows/graphsetup.h>
#include <DataEntry/teaching_entry.h>
#include "ui_summary_window.h"

#include <QDialog>

namespace Ui {
class Summary_Window;
}

class Summary_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Summary_Window(QWidget *parent, bool new_db);
    void getVector(QVector<teaching_entry> &tVect);
    ~Summary_Window();

private slots:

    QTreeWidgetItem * make_root(QString category, QString num_hours, QString num_students);

    QTreeWidgetItem * make_child(QTreeWidgetItem *parent, QString date, QString faculty_name,
                                                  QString num_hours, QString num_students);

    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

    void on_dateFilterButton_clicked();

    void make_tree_header();

    void top_level_teaching(QTreeWidgetItem *pme, QTreeWidgetItem *ume,
                            QTreeWidgetItem *cme, QTreeWidgetItem *other);

     QStringList build_teaching_tree(QVector<teaching_entry> vector_teaching_entries);
     void on_button_graph_clicked();

private:
   Ui::Summary_Window *ui;
   QDialog *graph_window;
   QDialog *graph_pie_window;
   QDialog *graph_bar_window;
   QDialog *setup_graph;
   QStringList years;
   int fromYear;
   int toYear;

   // + Keeps track of total hours for each main heading
   double pme_total_hours = 0.0;
   double ume_total_hours = 0.0;
   double cme_total_hours = 0.0;
   double other_total_hours = 0.0;

   // + Keeps track of total traineers for each main heading
   int pme_total_trainees = 0;
   int ume_total_trainees = 0;
   int cme_total_trainees = 0;
   int other_total_trainees = 0;

   // + Keeps track of the total hours for a year
   double year_total_hours = 0.0;

   // + Keeps track of the total trainees for a year
   int year_total_trainees = 0;

   // + Keeps track of the total hours for a faculty member
   double member_total_hours = 0.0;

   // + Keeps track of the total trainees for a faculty member
   int member_total_trainees = 0;

   // + Defines a the values to the graph
   QVector<double> graph_values;

   // + The titles to display on the graph
   QList<QString> title_values;

   // + Collects data for graphs
   QVector<teaching_entry> data_for_graphs;

   // + Stores the faculty names
   QStringList faculty;

};

#endif // SUMMARY_WINDOW_H
