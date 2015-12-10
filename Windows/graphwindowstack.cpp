/*
 * Source file: graphwindowbar.cpp
 * ---------------------------------
 * + Defines a class that makes bar graphs from the current data
 *   on a tab
 */

#include "graphwindowstack.h"
#include "ui_graphwindowstack.h"

/*
 * Constructor: graphwindowstack
 * --------------------------------
 * WHAT THE CONSTRUCTOR DOES:
 * + Creates and defines the ui for the stack graph dialog window
 *
 * PARAMETER LIST:
 * - parent: a reference to the parent widget
 * - data_for_graphs: data from a database that information for the graph will be extracted from
 * - passeed_years: a list of year values that give the range for the graph
 * - name: the faculty memeber the data on the graph is associated with
 * - tab_index: the current tab selected by the user
 */
graphwindowstack::graphwindowstack(QWidget *parent , QVector<teaching_entry> data_for_graphs, QStringList passed_years, QString name, int tab_index) :
    QDialog(parent),
    ui(new Ui::graphwindowstack)
    {
        ui->setupUi(this);

        // + Set up visual elements on the graph
        ui->label_name->setText(name);
        ui->label_year_start->setText(passed_years.first());
        ui->label_year_finish->setText(passed_years.last());
        this->setStyleSheet("background-color:white;");

        years = passed_years;

        // + Change to what graph generation code to use based on what the current tab is
        // + Makes a graph for the teaching data
        if(tab_index == 0)
        {
            make_teaching_stacked_graph(data_for_graphs, name);
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
 * Function: make_teaching_stack_graph
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Gets the program totals for the teaching graph
 *
 * PARAMETER LIST:
 * - data_for_graphs: The data to display on the graph
 * - name: the faculty member associated with the graph data
 */
void graphwindowstack::make_teaching_stacked_graph(QVector<teaching_entry> data_for_graphs, QString name)
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
        }

        else if(teaching_program == "Undergraduate Medical Education")
        {
          ume_total++;
        }

        else if(teaching_program == "Continuing Medical Education")
        {
          cme_total++;
        }

        else
        {
          other_total++;
        }

    }

    // + Put the totals into a QVectot that the pie will pull from
    values.append(pme_total);
    values.append(ume_total);
    values.append(cme_total);
    values.append(other_total);

    // + Create the colours for the graph
    draw_teaching_stacked_graph(values, years, generate_graph_colors(values.size()));
}

/*
 * Function: draw_teaching_stacked_graph
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Animates a stacked bar graph to the screen
 *
 * PARAMETER LIST:
 * - values: the total program information to display on the graph
 * - years: a list of years for the range of the graph
 * - colors: a vector of colors to paint the bars
 *
 */
void graphwindowstack::draw_teaching_stacked_graph(QVector<int> values, QStringList years, QVector<QColor> colors)
{

    // + Make QString for the first and last years dates to communicate the
    //   range of data on the x-axis to the user
    QString first_year = years.first();
    QString last_year = years.last();

    // + Create empty bar chart objects:
    QCPBars *undergrad = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    QCPBars *postgrad = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    QCPBars *continuing = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    QCPBars *other = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    ui->graph->addPlottable(undergrad);
    ui->graph->addPlottable(postgrad);
    ui->graph->addPlottable(continuing);
    ui->graph->addPlottable(other);

    // + Take the prepped bars and apply names and colours to them
    QPen pen;
    pen.setWidthF(1.2);

    postgrad->setName("Post Medical Education");
    pen.setColor(colors[0]);
    postgrad->setPen(pen);
    postgrad->setBrush(colors[0]);

    // Sets the names for the legend
    undergrad->setName("Undergraduate Medical Education");
    pen.setColor(colors[1]);
    undergrad->setPen(pen);
    undergrad->setBrush(colors[1]);

    continuing->setName("Continuing Education");
    pen.setColor(colors[2]);
    continuing->setPen(pen);
    continuing->setBrush(colors[2]);

    other->setName("Other");
    pen.setColor(colors[3]);
    other->setPen(pen);
    other->setBrush(colors[3]);


    // + Stack bars ontop of each other:
    continuing->moveAbove(other);
    undergrad->moveAbove(continuing);
    postgrad->moveAbove(undergrad);

    //---PREPARE THE X-AXIS----//

    // + Apply category labels to the x-axis:
    QVector<double> ticks;
    QVector<QString> labels;

    labels << "";

    // + The size of the array passed should be years (total number of years available)
    for(int i = 1; i <= 1; i++){
        ticks << i;
        labels << years.at(i);
    }

    // + Other x-axis formatting
    ui->graph->xAxis->setLabel("Year Range: "+first_year+" - "+last_year);
    ui->graph->xAxis->setAutoTicks(false);
    ui->graph->xAxis->setAutoTickLabels(false);
    ui->graph->xAxis->setTickVector(ticks);
    ui->graph->xAxis->setTickVectorLabels(labels);
    ui->graph->xAxis->setTickLabelRotation(60);
    ui->graph->xAxis->setSubTickCount(0);
    ui->graph->xAxis->setTickLength(1, 4);
    ui->graph->xAxis->grid()->setVisible(true);

    // + Sets the range of the ticks along the x-axis
    ui->graph->xAxis->setRange(0, values.length()*2);


    //----PREPARE THE Y-AXIS----//

    // + Where we set the range of the y axis
    int max_range = 0;

    // + Loop and determine the which year has the largest number
    //   of category occurencs and set that as the max range of the
    //   graph
    for(int i = 0; i < values.length(); i++)
    {
        max_range += values.at(i);
    }

    ui->graph->yAxis->setRange(0, max_range+(max_range*0.25));

    // + Other y-axis formatting
    ui->graph->yAxis->setPadding(5); // a bit more space to the left border
    ui->graph->yAxis->setLabel("Intances of Programs");
    ui->graph->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    ui->graph->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    ui->graph->yAxis->grid()->setSubGridPen(gridPen);

    QVector<double> undergradData, postgradData, continuingData, otherData;

    undergradData << values.at(1);
    postgradData << values.at(0);
    continuingData << values.at(2);
    otherData << values.at(3);

    // + Set the input data in relation to the ticks on the graph
    undergrad->setData(ticks, undergradData);
    postgrad->setData(ticks, postgradData);
    continuing->setData(ticks, continuingData);
    other->setData(ticks,otherData);

    // + Set up the legend on the screen
    ui->graph->legend->setVisible(true);
    ui->graph->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    ui->graph->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    ui->graph->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->graph->legend->setFont(legendFont);
    ui->graph->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

/*
 * Function: on_button_print_clicked
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Prints the current graph
 */
void graphwindowstack::on_button_print_clicked()
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
    double xscale = printer.pageRect().width()/double(ui->graph->width());
    double yscale = printer.pageRect().height()/double(ui->graph->height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                      printer.paperRect().y() + printer.pageRect().height()/2);
    painter.scale(scale, scale);
    painter.translate(-width()/2, -height()/2);

    // + The widget to the apply the painter to
    ui->graph->render(&painter);

    // + Stop the painter
    painter.end();
}

/*
 * Destory the window
 */
graphwindowstack::~graphwindowstack()
{
    delete ui;
}


