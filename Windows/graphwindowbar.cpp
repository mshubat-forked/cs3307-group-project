/*
 * Source file: graphwindowbar.cpp
 * ---------------------------------
 * + Defines a class that makes bar graphs from the current data
 *   on a tab
 */

#include "graphwindowbar.h"
#include "ui_graphwindowbar.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))


/*
 * Constructor: graphwindowbar
 * --------------------------------
 * WHAT THE CONSTRUCTOR DOES:
 *
 *
 * PARAMETER LIST:
 * - parent: a reference to the parent widget
 * - data_for_graphs: data from a database to extract and get data for the graph
 * - years_for_graphs: a list of years associated with graph data
 * - name: the faculty memeber associated with the data on graph
 * - tab_index: the current tab selected by the user
 */
graphwindowbar::graphwindowbar(QWidget *parent, QVector<teaching_entry> data_for_graphs, QStringList years_for_graphs, QString name, int tab_index) :
    QDialog(parent),
    ui(new Ui::graphwindowbar)
{

    ui->setupUi(this);

    // + Set up some visual elements on the graph
    ui->label_name->setText(name);
    ui->label_year_start->setText(years_for_graphs.first());
    ui->label_year_finish->setText(years_for_graphs.last());
    this->setStyleSheet("background-color: white;");

    years = years_for_graphs;

    // + Change to what graph generation code to use based on what the current tab is
    // + Makes a graph for the teaching data
    if(tab_index == 0)
    {
        make_teaching_bar_graph(data_for_graphs, name);
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
 * Function: make_teaching_bar_graph
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Gets the program totals for the teaching graph
 *
 * PARAMETER LIST:
 * - data_for_graphs: The data to display on the graph
 * - name: the faculty member associated with the graph data
 */
void graphwindowbar::make_teaching_bar_graph(QVector<teaching_entry> data_for_graphs, QString name)
{

    double pme_total = 0.0;
    double ume_total = 0.0;
    double cme_total = 0.0;
    double other_total = 0.0;

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

    // + Put the totals into a QVector that the pie will pull from
    values.append(pme_total);
    values.append(ume_total);
    values.append(cme_total);
    values.append(other_total);

    draw_teaching_bar_graph(values, years, generate_graph_colors(values.size()));
    values.clear();
}

/*
 * Function: draw_teaching_graph
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Creates the bar graph and displays screen
 *
 * PARAMETER LIST:
 * - values: The totals to display on the graph
 * - years: The range of the data
 * - colors: The colors to paint the bars
 */
void graphwindowbar::draw_teaching_bar_graph(QVector<double> values, QStringList years, QVector<QColor> colors)
{

    QString first_year = years.first();
    QString last_year = years.last();

    QCPBars *barsPME = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    QCPBars *barsUME = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    QCPBars *barsCME = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    QCPBars *barsOther = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);


    // + Add the plot to the graph widget on the UI
    ui->graph->addPlottable(barsPME);
    ui->graph->addPlottable(barsUME);
    ui->graph->addPlottable(barsCME);
    ui->graph->addPlottable(barsOther);

    // + Set the title of the x and y axis
    ui->graph->xAxis->setLabel("Year Range: "+first_year+" - "+last_year);
    ui->graph->yAxis->setLabel("Total Intances");

    ui->graph->xAxis->setTickLabelRotation(90);

    // + Set the range of the axis based in the number of years by
    //   4 (for each of the program types) plus 1 for spacing purposes
    ui->graph->xAxis->setRange(0,(1*4)+1);



    // + Determine the range for the y-axis
    int temp_range = 0;
    int max_range = 0;

    for(int i = 0; i < values.length(); i++)
    {

        if(temp_range < values.value(i))
            temp_range = values.value(i);


        // + Set the greatest number of occuernces of a category
        //   to be the max range for the graph
        if(temp_range > max_range)
            max_range = temp_range;

    }

    // + Creates a range for the y-axis times 1/10 of the max_range for spacing
    ui->graph->yAxis->setRange(0,max_range+(max_range*0.75));

     //+ Set the slots where data bars will go
    QVector<double> tick_slot;

    for(int i = 1; i <= 5; i++)
    {
        tick_slot << i;
    }

    QVector<double> pmeData, umeData, cmeData, otherData;

    //for(int t = 0; t < values.length(); t++)

       pmeData << values.value(0);
       umeData << values.value(1);
       cmeData << values.value(2);
       otherData << values.value(3);


    // + Apply the data to bars
    barsPME->setData(tick_slot, pmeData);
    barsUME->setData(tick_slot.mid(1,-1), umeData);
    barsCME->setData(tick_slot.mid(1*2,-1), cmeData);
    barsOther->setData(tick_slot.mid(1*3,-1), otherData);

    // + Format the thickness of the bars
    barsPME->setWidth(0.65);

    QVector<QString> labels;

    labels << "PME" << "UME" << "CME" << "Other";

    // + Apply the number of ticks and labels to the x-axis
    barsPME->keyAxis()->setAutoTicks(false);
    barsPME->keyAxis()->setAutoTickLabels(false);
    barsPME->keyAxis()->setTickVector(tick_slot);
    barsPME->keyAxis()->setTickVectorLabels(labels);
    barsPME->keyAxis()->setSubTickCount(0);

    // + Colour the graph
    barsPME->setPen(QPen(colors[0]));
    barsPME->setAntialiased(false);
    barsPME->setAntialiasedFill(false);
    barsPME->setBrush(colors[0]);
    barsPME->keyAxis()->setSubTickCount(0);

    barsUME->setPen(QPen(colors[1]));
    barsUME->setAntialiased(false);
    barsUME->setAntialiasedFill(false);
    barsUME->setBrush(colors[1]);
    barsUME->keyAxis()->setSubTickCount(0);

    barsCME->setPen(QPen(colors[2]));
    barsCME->setAntialiased(false);
    barsCME->setAntialiasedFill(false);
    barsCME->setBrush(colors[2]);
    barsCME->keyAxis()->setSubTickCount(0);

    barsOther->setPen(QPen(colors[3]));
    barsOther->setAntialiased(false);
    barsOther->setAntialiasedFill(false);
    barsOther->setBrush(colors[3]);
    barsOther->keyAxis()->setSubTickCount(0);

    // + Setup legend

    barsPME->setName("Undergraduate Medical Education");
    barsUME->setName("Post Medical Education");
    barsCME->setName("Continuing Education");
    barsOther->setName("Other");

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
 * Destory the window when it is closed
 */
graphwindowbar::~graphwindowbar()
{
    delete ui;
}
