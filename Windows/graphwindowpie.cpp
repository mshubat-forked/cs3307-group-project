#include "graphwindowpie.h"
#include "ui_graphwindowpie.h"
#include "graphcolors.h"
#include "Charts/Nightcharts/nightchartswidget.h"
#include "Charts/Nightcharts/nightcharts.h"
#include <iomanip>

/*
 * Constructor: graphwindowpie
 * --------------------------------
 * WHAT THE CONSTRUCTOR DOES:
 * + Creates and defines the ui for the pie graph dialog window
 *
 * PARAMETER LIST:
 * - parent: a reference to the parent widget
 * - values: the data to be shown on the graph
 *
 */
graphwindowpie::graphwindowpie(QWidget *parent,QVector<double> values, QList<QString> titles) :
    QDialog(parent),
    ui(new Ui::graphwindowpie)
{
    ui->setupUi(this);

    QVector<QColor> pie_pie_colors = generate_graph_colors(values.size());

    ui->piechart->setType(Nightcharts::Pie);
    for(int i = 0; i < values.size(); i++)
    {
        ui->piechart->addItem(titles[i], pie_pie_colors[i], values[i]);
    }

/*
    // + Set the background of the dialog window to white
    this->setStyleSheet("background-color: white;");

    QVector<QColor> pie_piece_colors = generate_graph_colors(values.size());

    // + Put a pie graph on the dialog window
    ui->piegraph->create_pie_graph(values, pie_piece_colors);

    QVector<QString> subjects = {"Post Medical Education", "Undergraduate Medical Education", "Continuing Medical Education", "Other"};

    double sum_of_value = 0.0;

    for(int j = 0; j < values.size(); j++)
    {
        sum_of_value += values[j];
    }

    for(int i = 0; i < 4; i++)
    {
        QListWidgetItem *temp_item = new QListWidgetItem("\n%"+QString::number((values[i]/sum_of_value)*100,'f',0) +" - "+ subjects[i]);
        temp_item->setForeground(pie_piece_colors[i]);
        ui->legend_list_widget->addItem(temp_item);
    }
*/
}

/*
 * Destory the window when it is closed
 */
graphwindowpie::~graphwindowpie()
{
    delete ui;
}

