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
#include <DataEntry/presentation_entry.h>
#include <DataEntry/grants_entry.h>
#include <DataEntry/publication_entry.h>
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
    QTreeWidgetItem * make_root_pres(QString category);
    QTreeWidgetItem * make_root_grants(QString category, QString total, QString total_dollars);
    QTreeWidgetItem * make_root_pubs(QString category, QString total);

    QTreeWidgetItem * make_child(QTreeWidgetItem *parent, QString date, QString faculty_name,
                                                  QString num_hours, QString num_students);

    QTreeWidgetItem * make_child_pres(QTreeWidgetItem *parent, QString faculty_name, QString total);

    QTreeWidgetItem * make_child_grants(QTreeWidgetItem *parent, QString type, QString faculty_name, QString num_total, QString num_dollars);

    QTreeWidgetItem * make_child_pubs(QTreeWidgetItem *parent, QString faculty_name, QString num_total);

    void on_dateFilterButton_clicked();

    void make_tree_header();


    void top_level_teaching(QTreeWidgetItem *pme, QTreeWidgetItem *ume,
                            QTreeWidgetItem *cme, QTreeWidgetItem *other);

    void top_level_pres(QTreeWidgetItem *invited, QTreeWidgetItem *abstracts,
                                 QTreeWidgetItem *presentations, QTreeWidgetItem *other);

    void top_level_grants(QTreeWidgetItem *grants, QTreeWidgetItem *funding);

    void top_level_pubs(QTreeWidgetItem *publications, QTreeWidgetItem *journals,
                                 QTreeWidgetItem *books, QTreeWidgetItem *chapters, QTreeWidgetItem *letters);

     QStringList build_teaching_tree(QVector<teaching_entry> vector_teaching_entries);

     QStringList build_presentations_tree(QVector<presentation_entry> vector_teaching_entries);

     QStringList build_grants_tree(QVector<grants_entry> vector_teaching_entries);

     QStringList build_publications_tree(QVector<publication_entry> vector_teaching_entries);

     void on_button_graph_clicked();

     void on_tabWidget_tabBarClicked(int index);

     void on_button_load_file_clicked();

     bool dbexists();

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

   // + The totals for the presentations window
   int abstract_total = 0;
   int invited_total = 0;
   int presentation_total = 0;
   int other_pres_total = 0;

   // + The totals for grants
   double grant_total_dollars = 0.0;
   double funding_total_dollars = 0.0;
   int grant_total = 0;
   int funding_total = 0;
   
   int grant_peer_total = 0;
   int grant_sponsored_total = 0;
   double grant_peer_dollar_total = 0.0;
   double grant_sponsored_dollar_total = 0.0;
   
   int funding_peer_total = 0;
   int funding_sponsored_total = 0;
   double funding_peer_dollar_total = 0.0;
   double funding_sponsored_dollar_total = 0.0;
      
   int grant_industry_total;
   double grant_industry_dollar_total;
   
   int funding_industry_total;
   double funding_industry_dollar_total;
   
   // + The publications total
   int published_abstracts_total = 0;
   int journals_total = 0;
   int book_total = 0;
   int chapter_total = 0;
   int letters_total = 0;
   int publications_total = 0;
   
   
   // + Keeps track of the total hours for a year
   double year_total_hours = 0.0;

   // + Keeps track of the total trainees for a year
   int year_total_trainees = 0;

   // + Keeps track of the total hours for a faculty member
   double member_total_hours = 0.0;

   // + Keeps track of the total trainees for a faculty member
   int member_total_trainees = 0;

   int counter_for_current_name_pres = 0;
   int counter_for_current_name_pubs = 0;

   // + Defines a the values to the graph
   QVector<double> graph_values;

   // + The titles to display on the graph
   QList<QString> title_values;

   // + Stores the faculty names
   QStringList faculty;
   QStringList faculty_pres;
   QStringList faculty_grants;
   QStringList faculty_pubs;

   // + The current tab index
   int current_tab_index = 0;

   // + Gets information for all enteries
   QVector<teaching_entry> vector_teaching_entries;
   QVector<grants_entry> vector_grantfunding_entries;
   QVector<presentation_entry> vector_presentations_entries;
   QVector<publication_entry> vector_publications_entries;

   // + Collects data for graphs
   QVector<teaching_entry> data_for_teaching_graphs;
   QVector<grants_entry> data_for_grantfunding_graphs;
   QVector<presentation_entry> data_for_presentations_graphs;
   QVector<publication_entry> data_for_publications_graphs;



};

#endif // SUMMARY_WINDOW_H
