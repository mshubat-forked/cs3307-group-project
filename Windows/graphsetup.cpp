/*
 * Source File: graphsetup.cpp
 * --------------------------------
 * + Defines a source file that handles a users input for display
 *   a chosen graph
 */

#include "graphsetup.h"
#include "ui_graphsetup.h"
#include "Reading_Files/teaching_entry.h"
#include <string>
#include <iostream>

/*
 * Constructor: on_button_cancel_clicked
 * ---------------------------------------
 * WHAT THE CONSTRUCTOR DOES:
 * + Creates the GraphSetup dialog window so the user can enter meta information
 *   about the graph they would like to view
 *
 * PARAMETERS:
 * - faculty: a QStringList of the possible names the user can choose from
 * - data_for_graphs: data from the database to display on the graphwindow
 * - parent: a reference to the window that called GraphSetup
 */
GraphSetup::GraphSetup(QStringList faculty, QVector<teaching_entry> data_for_graphs, QStringList passed_years, int tab_index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphSetup)
{
    ui->setupUi(this);

    // + Add names to the combo that handles names
    ui->comboBox_name->addItems(faculty);

    // + Define what graphs the user can choose
    ui->comboBox_type->addItem("Bar Graph");
    ui->comboBox_type->addItem("Stack Graph");
    ui->comboBox_type->addItem("Pie Graph");

    data = data_for_graphs;
    years = passed_years;
    current_tab_index = tab_index;
    qDebug() << "Current index: " << QString::number(current_tab_index);
}

/*
 * Function: on_button_cancel_clicked
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Takes the input from the user and passes it on the
 *   proper graph
 */
void GraphSetup::on_button_ok_clicked()
{

    // + Go to a Stack Graph
    if(ui->comboBox_type->currentText() == "Stack Graph")
    {
        graph_stack_window = new graphwindowstack(this, data, years, ui->comboBox_name->currentText(),current_tab_index);
        graph_stack_window->show();
    }

    // + Go to a Bar Graph
    else if(ui->comboBox_type->currentText() == "Bar Graph")
    {
        graph_bar_window = new graphwindowbar(this, data, years, ui->comboBox_name->currentText(),current_tab_index);
        graph_bar_window->show();
    }

    // + Go to a Pie Graph
    else if(ui->comboBox_type->currentText() == "Pie Graph")
    {
        graph_pie_window = new graphwindowpie(this, data, ui->comboBox_name->currentText(),current_tab_index);
        graph_pie_window->show();
    }

    // + Close the GraphSetup window once the user has made their choices
    this->close();
}


/*
 * Function: on_button_cancel_clicked
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Closes the graph setup window
 */
void GraphSetup::on_button_cancel_clicked()
{
    this->close();
}


/*
 * Function: GraphSetup
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Destorys the window
 */
GraphSetup::~GraphSetup()
{
    delete ui;
}
