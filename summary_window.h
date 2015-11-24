#ifndef SUMMARY_WINDOW_H
#define SUMMARY_WINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <graphwindow.h>
#include <graphwindowpie.h>
#include <graphwindowbar.h>
#include "ui_summary_window.h"


#include <QDialog>

struct TeachingField;

namespace Ui {
class Summary_Window;
}

class Summary_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Summary_Window(QWidget *parent);
    ~Summary_Window();

private slots:

    QTreeWidgetItem * make_root(QTreeWidgetItem *parent, QString category, QString date, QString faculty_name,
                                              QString num_hours, QString num_students);


    QTreeWidgetItem * make_child(QTreeWidgetItem *parent, QString category, QString date, QString faculty_name,
                                                  QString num_hours, QString num_students);

    void on_fromDateCombo_activated(const QString &arg1);

    void on_toDateCombo_activated(const QString &arg1);

    void on_graphComboBox_activated(int index);

private:
   Ui::Summary_Window *ui;
   QDialog *graph_window;
   QDialog *graph_pie_window;
   QDialog *graph_bar_window;
   int fromDateIndex;
   int toDateIndex;

   // Defines a the values to the graph
   QVector<double> graph_values;

};

#endif // SUMMARY_WINDOW_H
