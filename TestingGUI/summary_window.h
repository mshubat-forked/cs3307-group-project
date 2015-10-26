#ifndef SUMMARY_WINDOW_H
#define SUMMARY_WINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <graphwindow.h>
#include <graphwindowpie.h>
#include "ui_summary_window.h"


#include <QDialog>

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
    // void on_pushButton_clicked();

    QTreeWidgetItem * make_root(QTreeWidgetItem *parent, QString category, QString date, QString faculty_name,
                                              QString num_hours, QString num_students);


    QTreeWidgetItem * make_child(QTreeWidgetItem *parent, QString category, QString date, QString faculty_name,
                                                  QString num_hours, QString num_students);

    //void on_actionTeaching_Graph_triggered();
    //void on_actionPie_Graph_triggered();
    void on_fromDateCombo_currentIndexChanged(const QString &arg1);
    void on_toDateCombo_currentIndexChanged(const QString &arg1);

    void on_graphButton1_clicked();

    void on_graphButton2_clicked();

private:
   Ui::Summary_Window *ui;
   QDialog *graph_window;
   QDialog *graph_pie_window;

};

#endif // SUMMARY_WINDOW_H
