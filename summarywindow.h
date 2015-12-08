#ifndef SUMMARYWINDOW_H
#define SUMMARYWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <graphwindow.h>
#include <graphwindowpie.h>

namespace Ui {
class SummaryWindow;
}

class SummaryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SummaryWindow(QWidget *parent = 0);
    ~SummaryWindow();

private slots:
   // void on_pushButton_clicked();

    QTreeWidgetItem * make_root(QString category, QString num_hours, QString num_students);


    QTreeWidgetItem * make_child(QTreeWidgetItem *parent, QString date, QString faculty_name,
                                              QString num_hours, QString num_students);

    void on_actionTeaching_Graph_triggered();
    void on_actionPie_Graph_triggered();

private:
   Ui::SummaryWindow *ui;
   QDialog *graph_window;
   QDialog *graph_pie_window;
};

#endif // SUMMARYWINDOW_H