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
 * - values: the data to be shown on the graph
 *
 */
graphwindowbar::graphwindowbar(QWidget *parent, QVector<teaching_entry> data_for_graphs, QStringList years, QString name) :
    QDialog(parent),
    ui(new Ui::graphwindowbar)
{
    ui->setupUi(this);

    ui->label_name->setText(name);

    this->setStyleSheet("background-color: white;");


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

    make_bar_graph(values);

}

/*
 * Function: generate_graph_colors
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * +
 *
 * PARAMETER LIST:
 * -
 *
 */
void graphwindowbar::make_bar_graph(QVector<double> values)
{
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
    ui->graph->xAxis->setLabel("Year of Program");
    ui->graph->yAxis->setLabel("Intances of Programs");

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

    // + Set the label names by year
    /*
    QVector<QString> year_labels;
    for(int k = 0; k < number_of_years; k++)
    {
        for(int l = 0; l < number_of_years; l++)
            year_labels << p_yi[l].year;
    }
    */
    QString year_label = "Date Here";

     //+ Set the slots where data bars will go
    QVector<double> tick_slot;

    for(int i = 1; i <= 5; i++)
    {
        tick_slot << i;
    }

    /*
    // + Set the data for the bars
    for(int j = 0; j < number_of_years; j++)
    {
        for(int k = 0; k < number_of_years; k++)
            data_value << p_yi[k].ume_total << p_yi[k].pme_total << p_yi[k].cme_total << p_yi[k].other_total;
    }
    */

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

    // + Apply the number of ticks and labels to the x-axis
    barsPME->keyAxis()->setAutoTicks(false);
    barsPME->keyAxis()->setAutoTickLabels(false);
    barsPME->keyAxis()->setTickVector(tick_slot);
    barsPME->keyAxis()->setSubTickCount(0);

    // + Colour the graph
    barsPME->setPen(QPen(Qt::black));
    barsPME->setAntialiased(false);
    barsPME->setAntialiasedFill(false);
    barsPME->setBrush(QColor("#705BE8"));
    barsPME->keyAxis()->setSubTickCount(0);

    barsUME->setPen(QPen(Qt::black));
    barsUME->setAntialiased(false);
    barsUME->setAntialiasedFill(false);
    barsUME->setBrush(QColor("#2ECCFA"));
    barsUME->keyAxis()->setSubTickCount(0);

    barsCME->setPen(QPen(Qt::black));
    barsCME->setAntialiased(false);
    barsCME->setAntialiasedFill(false);
    barsCME->setBrush(QColor("#FE9A2E"));
    barsCME->keyAxis()->setSubTickCount(0);

    barsOther->setPen(QPen(Qt::black));
    barsOther->setAntialiased(false);
    barsOther->setAntialiasedFill(false);
    barsOther->setBrush(QColor("#74DF00"));
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
