#include "graphwindow.h"
#include "ui_graphwindow.h"

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

graphwindow::graphwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphwindow)
{
    ui->setupUi(this);

    // + ERASE THIS
    // + Temporary information used to test building a graph
    // + Information passed like this would be handy to build the graph
    QString temp_years[] = {"2009","2010","2011","2012"};
    int temp_pme_total[] = {4,2,4,5};
    int temp_ume_total[] = {1,7,2,6};
    int temp_cme_total[] = {5,1,2,7};
    int temp_other_total[] = {3,3,3,7};

    // + Create an pointer to an array of YearInformationGraph items
    // + Set the size of the array to the number of years in the range
    // + Ie. A range of 2009, 2010, 2011 would set the size of
    //   the array to 3 (with help fro mthe ARRAY_SIZE marco
    YearInformationGraph *p_yi = new YearInformationGraph[ARRAY_SIZE(temp_years)];

    for (int i = 0; i < ARRAY_SIZE(temp_years); i++)
    {
        p_yi[i].year = temp_years[i];
        p_yi[i].pme_total = temp_pme_total[i];
        p_yi[i].ume_total = temp_ume_total[i];
        p_yi[i].cme_total = temp_cme_total[i];
        p_yi[i].other_total = temp_other_total[i];
    }

    graphwindow::make_plot(p_yi, ARRAY_SIZE(temp_years));
}

graphwindow::~graphwindow()
{
    delete ui;
}


// + Draw the graph in the dialog window
void graphwindow::make_plot(YearInformationGraph *p_yi, int number_of_years)
{

    // create empty bar chart objects:
    QCPBars *undergrad = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    QCPBars *postgrad = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    QCPBars *continuing = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    QCPBars *other = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);
    ui->graph->addPlottable(undergrad);
    ui->graph->addPlottable(postgrad);
    ui->graph->addPlottable(continuing);
    ui->graph->addPlottable(other);


    // set names and colors:
    QPen pen;
    pen.setWidthF(1.2);
    // sets the legend name
    undergrad->setName("Undergraduate Medical Education");
    pen.setColor(QColor(255, 131, 0));
    undergrad->setPen(pen);
    undergrad->setBrush(QColor(255, 131, 0, 50));
    postgrad->setName("Post Medical Education");
    pen.setColor(QColor(1, 92, 191));
    postgrad->setPen(pen);
    postgrad->setBrush(QColor(1, 92, 191, 50));

    continuing->setName("Continuing Education");
    pen.setColor(QColor(150, 222, 0));
    continuing->setPen(pen);
    continuing->setBrush(QColor(150, 222, 0, 70));

    other->setName("Other");
    pen.setColor(QColor(230, 92, 2));
    other->setPen(pen);
    other->setBrush(QColor(230, 92, 2, 50));


    // stack bars ontop of each other:
    postgrad->moveAbove(undergrad);
    continuing->moveAbove(postgrad);
    other->moveAbove(continuing);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;

    // + The size of the array passed should be years (total number of years available)
    for(int i = 1; i <= number_of_years; i++){
        ticks << i;
        labels << p_yi[i-1].year;
    }

    ui->graph->xAxis->setAutoTicks(false);
    ui->graph->xAxis->setAutoTickLabels(false);
    ui->graph->xAxis->setTickVector(ticks);
    ui->graph->xAxis->setTickVectorLabels(labels);
    ui->graph->xAxis->setTickLabelRotation(60);
    ui->graph->xAxis->setSubTickCount(0);
    ui->graph->xAxis->setTickLength(0, 4);
    ui->graph->xAxis->grid()->setVisible(true);

    // + Sets the range of the ticks along the x-axis
    ui->graph->xAxis->setRange(0, number_of_years*2);

    // prepare y axis:

    // where we set the range of the y axis
    int max_range, temp_range = 0;

    // + Loop and determine the
    for(int i = 0; i < number_of_years; i++)
    {
        temp_range = p_yi[i].pme_total + p_yi[i].ume_total + p_yi[i].cme_total + p_yi[i].other_total;

        // + Set the greatest number of occuernces of a category
        //   to be the max range for the graph
        if(temp_range > max_range)
            max_range = temp_range;

    }

    ui->graph->yAxis->setRange(0, max_range+1);
    ui->graph->yAxis->setPadding(5); // a bit more space to the left border
    ui->graph->yAxis->setLabel("Intances of Programs");
    ui->graph->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    ui->graph->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    ui->graph->yAxis->grid()->setSubGridPen(gridPen);

    // Add data:
    // Input data as a vector for a single instance of a grash
    // Set the data in relation the the ticks on the y-axis
    QVector<double> undergradData, postgradData, continuingData, otherData;



    // + Access the individual totals for each category depending on the year
    // + Ie. @ p_yi[j] j could be 0 meaning it will access the YearInformation struct
    //   at index 0
    // + The the specifc totals stored in this struct will be accessed and be given to
    //   the vector that specifies the matching category
    // + For example: Lets say when j is 0, the struct pointed to by p_yi[0] could be
    /*   struct YearInformation{
             QString year; // = 2009
             int pme_total; // = 5
             int ume_total; // = 3
             int cme_total; // = 2
             int other_total; // = 3
        };
    */
    // + p_yi[0] is referecing information for the year 2009, and the p_yi[0].ume_total
    //   would access the value 5
    // + The value of 5 is what is set to the vector undergradData
    for(int j = 0; j < number_of_years; j++)
    {
        undergradData << p_yi[j].ume_total;
        postgradData << p_yi[j].pme_total;
        continuingData << p_yi[j].cme_total;
        otherData << p_yi[j].other_total;
    }


    // + Set the input data in relation to the ticks on the graph
    undergrad->setData(ticks, undergradData);
    postgrad->setData(ticks, postgradData);
    continuing->setData(ticks, continuingData);
    other->setData(ticks,otherData);

    // + Set up the legend
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

