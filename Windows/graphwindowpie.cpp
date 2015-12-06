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

    this->setStyleSheet("background-color:white;");

    ui->label_subject->setText("Teaching Summary for Dr.Doctor");
    ui->label_year_start->setText("2009");
    ui->label_year_finish->setText("2010");

    // + Create the colours for the graph
    QVector<QColor> pie_pie_colors = generate_graph_colors(values.size());

    // + Define the Nightcharts widget on the UI
    ui->piechart->setType(Nightcharts::Pie);

    // + Build and animate the pie graph
    for(int i = 0; i < values.size(); i++)
    {
        ui->piechart->addItem(titles[i], pie_pie_colors[i], values[i]);
    }
}

/*
 * Destory the window when it is closed
 */
graphwindowpie::~graphwindowpie()
{
    delete ui;
}

