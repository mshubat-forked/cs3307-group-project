/*
 * Header File: graphsetup.h
 * --------------------------------
 * + Defines the declarations of functions and variables for
 *   graphsetup.cpp
 */

#ifndef GRAPHSETUP_H
#define GRAPHSETUP_H

#include <QDialog>
#include "DataEntry/teaching_entry.h"
#include "Windows/graphwindowstack.h"
#include "Windows/graphwindowbar.h"
#include "Windows/graphwindowpie.h"

namespace Ui {
class GraphSetup;
}

class GraphSetup : public QDialog
{
    Q_OBJECT

public:
    explicit GraphSetup(QStringList faculty, QVector<teaching_entry> data_for_graphs, QStringList passed_years, int tab_index, QWidget *parent = 0);
    ~GraphSetup();

private slots:

    void on_button_ok_clicked();

    void on_button_cancel_clicked();

private:
    Ui::GraphSetup *ui;
    QDialog *graph_stack_window;
    QDialog *graph_pie_window;
    QDialog *graph_bar_window;
    QVector<teaching_entry> data;
    QStringList years;
    int current_tab_index;
};

#endif // GRAPHSETUP_H
