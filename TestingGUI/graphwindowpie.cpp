#include "graphwindowpie.h"
#include "ui_graphwindowpie.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

// + Defines a structure that store a years information for eventual
//   display on the graph
struct YearInformationGraph
{
    QString year;
    int pme_total;
    int ume_total;
    int cme_total;
    int other_total;
};

graphwindowpie::graphwindowpie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphwindowpie)
{
    ui->setupUi(this);


    QString temp_years[] = {"2010","2011","2012","2013","2014"};
    int temp_pme_total[] = {4,2,4,5,8};
    int temp_ume_total[] = {1,7,2,6,8};
    int temp_cme_total[] = {5,1,2,7,8};
    int temp_other_total[] = {3,3,3,7,8};

    // + Create an pointer to an array of YearInformationGraph items
    // + Set the size of the array to the number of years in the range
    // + Ie. A range of 2009, 2010, 2011 would set the size of
    //   the array to 3 (with help fro mthe ARRAY_SIZE marco
    YearInformationGraph *p_yi = new YearInformationGraph[ARRAY_SIZE(temp_years)];

    for (int i = 0; i < (int)ARRAY_SIZE(temp_years); i++)
    {
        p_yi[i].year = temp_years[i];
        p_yi[i].pme_total = temp_pme_total[i];
        p_yi[i].ume_total = temp_ume_total[i];
        p_yi[i].cme_total = temp_cme_total[i];
        p_yi[i].other_total = temp_other_total[i];
    }

    make_bar_graph(p_yi, (int)ARRAY_SIZE(temp_years));

}

graphwindowpie::~graphwindowpie()
{
    delete ui;
}


/* + Draws a stacked bar graph to the screen based on the information passed as parameters
 *
 * YearInformationGraph *p_yi: A pointer to an array of YearInformation structures
 * int number_of_years: The total number of unique years associated with a faculty name
*/
void graphwindowpie::make_bar_graph(YearInformationGraph *p_yi, int number_of_years)
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
    ui->graph->xAxis->setRange(0,(number_of_years*4)+1);

    // + Determine the range for the y-axis
    int temp_range = 0;
    int max_range = 0;

    for(int i = 0; i < number_of_years; i++)
    {

        if(temp_range < p_yi[i].pme_total)
            temp_range = p_yi[i].pme_total;

        if(temp_range < p_yi[i].ume_total)
            temp_range = p_yi[i].ume_total;

        if(temp_range < p_yi[i].cme_total)
            temp_range = p_yi[i].cme_total;

        if(temp_range < p_yi[i].other_total)
            temp_range = p_yi[i].other_total;


        // + Set the greatest number of occuernces of a category
        //   to be the max range for the graph
        if(temp_range > max_range)
            max_range = temp_range;

    }

    // + Creates a range for the y-axis times 1/10 of the max_range for spacing
    ui->graph->yAxis->setRange(0,max_range+(max_range*0.75));

    // + Set the label names by year
    QVector<QString> year_labels;
    for(int k = 0; k < number_of_years; k++)
    {
        for(int l = 0; l < number_of_years; l++)
            year_labels << p_yi[l].year;
    }

     //+ Set the slots where data bars will go
    QVector<double> tick_slot;

    for(int i = 1; i <= number_of_years*4; i++)
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

    for(int t = 0; t < number_of_years; t++)
    {
       pmeData << p_yi[t].pme_total;
       umeData << p_yi[t].ume_total;
       cmeData << p_yi[t].cme_total;
       otherData << p_yi[t].other_total;
    }

    // + Apply the data to bars
    barsPME->setData(tick_slot, pmeData);
    barsUME->setData(tick_slot.mid(number_of_years,-1), umeData);
    barsCME->setData(tick_slot.mid(number_of_years*2,-1), cmeData);
    barsOther->setData(tick_slot.mid(number_of_years*3,-1), otherData);

    // + Format the thickness of the bars
    barsPME->setWidth(0.65);

    // + Apply the number of ticks and labels to the x-axis
    barsPME->keyAxis()->setAutoTicks(false);
    barsPME->keyAxis()->setAutoTickLabels(false);
    barsPME->keyAxis()->setTickVector(tick_slot);
    barsPME->keyAxis()->setTickVectorLabels(year_labels);
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
