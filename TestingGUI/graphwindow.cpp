#include "graphwindow.h"
#include "ui_graphwindow.h"

graphwindow::graphwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphwindow)
{
    ui->setupUi(this);
    graphwindow::make_plot();
}

graphwindow::~graphwindow()
{
    delete ui;
}

// + Draw the graph in the dialog window
void graphwindow::make_plot()
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
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "2012" << "2013" << "2014" << "2015";
    ui->graph->xAxis->setAutoTicks(false);
    ui->graph->xAxis->setAutoTickLabels(false);
    ui->graph->xAxis->setTickVector(ticks);
    ui->graph->xAxis->setTickVectorLabels(labels);
    ui->graph->xAxis->setTickLabelRotation(60);
    ui->graph->xAxis->setSubTickCount(0);
    ui->graph->xAxis->setTickLength(0, 4);
    ui->graph->xAxis->grid()->setVisible(true);
    ui->graph->xAxis->setRange(0, 8);

    // prepare y axis:

    // where we set the range of the y axis
    ui->graph->yAxis->setRange(0, 25);
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
    // Set the data in relatio the the ticks on the y-axis
    QVector<double> undergradData, postgradData, continuingData, otherData;
    undergradData  << 1 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8;
    postgradData << 2 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8;
    continuingData   << 1 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8;
    otherData   << 2 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8;
    undergrad->setData(ticks, undergradData);
    postgrad->setData(ticks, postgradData);
    continuing->setData(ticks, continuingData);
    other->setData(ticks,otherData);

    // setup legend:
    ui->graph->legend->setVisible(true);
    ui->graph->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->graph->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    ui->graph->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->graph->legend->setFont(legendFont);
    ui->graph->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

