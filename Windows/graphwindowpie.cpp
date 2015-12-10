/*
 * Source file: graphwindowpie.cpp
 * ---------------------------------
 * + Defines a class that generates pie graphs for
 *   passed data
 */

#include "graphwindowpie.h"
#include "ui_graphwindowpie.h"
#include "graphcolors.h"
#include "Charts/Nightcharts/nightchartswidget.h"
#include "Charts/Nightcharts/nightcharts.h"
#include "Reading_Files/read_database.h"
#include <iomanip>

/*
 * Constructor: graphwindowpie
 * --------------------------------
 * WHAT THE CONSTRUCTOR DOES:
 * + Creates and defines the ui for the pie graph dialog window
 *
 * PARAMETER LIST:
 * - parent: a reference to the parent widget
 * - data_for_graphs: data from a database that information for the graph will be extracted from
 * - name: the faculty memeber the data on the graph is associated with
 * - tab_index: the current tab selected by the user
 */
graphwindowpie::graphwindowpie(QWidget *parent, QVector<teaching_entry> data_for_graphs, QString passed_name, int tab_index) :
    QDialog(parent),
    ui(new Ui::graphwindowpie)
{
    name = passed_name;

    ui->setupUi(this);
    ui->button_print->toolTip();

    this->setStyleSheet("background-color:white;");
    ui->label_subject->setText("Teaching Summary for ");

    // + Change to what graph generation code to use based on what the current tab is
    // + Makes a graph for the teaching data
    if(tab_index == 0)
    {
        make_teaching_pie_graph(data_for_graphs, name);
    }

    // + Makes a graph for the Presentations
    else if (tab_index == 1)
    {

    }

    // + Makes a graph for the Grants
    else if (tab_index == 2)
    {

    }

    // + Makes a graph for the Publications
    else if (tab_index == 3)
    {

    }


}
/*
 * Function: make_teaching_pie_graph
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Animates a stacked bar graph to the screen
 *
 * PARAMETER LIST:
 * - data_for_graphs: The data to display on the graph
 * - name: the faculty member associated with the graph data
 */
void graphwindowpie::make_teaching_pie_graph(QVector<teaching_entry> data_for_graphs, QString name)
{
    int pme_total = 0;
    int ume_total = 0;
    int cme_total = 0;
    int other_total = 0;

    // + Loop for the values in the passed database
    while(!data_for_graphs.isEmpty())
    {

        // + Get a teaching entry items from the database
        teaching_entry current_teaching_entry = data_for_graphs.takeFirst();

        // + Extract information from the aformentioned teaching_entry
        QString teaching_date = QString::fromStdString(current_teaching_entry.get_date());
        QString teaching_member = QString::fromStdString(current_teaching_entry.get_member());
        QString teaching_program = QString::fromStdString(current_teaching_entry.get_program());

        if(teaching_member != name)
        {
            continue;
        }

        if(teaching_date == "0" || teaching_date == "")
        {
            continue;
        }

        // + If a blank value is found, skip the whole entry
        if(teaching_program == "Postgraduate Medical Education")
        {
          pme_total++;
          years.append(teaching_date);
        }

        else if(teaching_program == "Undergraduate Medical Education")
        {
          ume_total++;
          years.append(teaching_date);
        }

        else if(teaching_program == "Continuing Medical Education")
        {
          cme_total++;
          years.append(teaching_date);
        }

        else
        {
          other_total++;
          years.append(teaching_date);
        }

    }

    // + Put the totals into a QVectot that the pie will pull from
    values.append(pme_total);
    values.append(ume_total);
    values.append(cme_total);
    values.append(other_total);

    // + Titles for the above data
    titles << "PME" << "UME" << "CME" << "Other";

    // + Create the colours for the graph
    QVector<QColor> pie_pie_colors = generate_graph_colors(values.size());

    // + Define the Nightcharts widget on the UI
    ui->piechart->setType(Nightcharts::Pie);

    // + Build and animate the pie graph
    for(int i = 0; i < values.size(); i++)
    {
        ui->piechart->addItem(titles[i], pie_pie_colors[i], values[i]);
    }

    // + Get rid of an duplicate information from the years list
    years = years.toSet().toList();

    // + Find the max and min year in the 'years' QStringList
    QString min = *std::min_element(years.begin(), years.end());
    QString max = *std::max_element(years.begin(), years.end());

    // + Set the above information to labels on the screen
    ui->label_year_start->setText(min);
    ui->label_year_finish->setText(max);
    ui->label_name->setText(name);
}

/*
 * Function: on_button_print_clicked
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Prints the current graph
 */
void graphwindowpie::on_button_print_clicked()
{
    QPainter painter;
    QPrinter printer;

    // + Dialog window for print options
    QPrintDialog *print_window = new QPrintDialog(&printer);

    // + Open the print window
    if (print_window->exec() != QDialog::Accepted)
        return;

    // + Start the painter
    painter.begin(&printer);

    // + Set the scale for capturing the widget
    double xscale = printer.pageRect().width()/double(ui->piechart->width());
    double yscale = printer.pageRect().height()/double(ui->piechart->height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                      printer.paperRect().y() + printer.pageRect().height()/2);
    painter.scale(scale, scale);
    painter.translate(-width()/2, -height()/2);

    // + The widget to the apply the painter to
    ui->piechart->render(&painter);

    // + Stop the painter
    painter.end();
}

/*
 * Destory the window when it is closed
 */
graphwindowpie::~graphwindowpie()
{
    delete ui;
}



