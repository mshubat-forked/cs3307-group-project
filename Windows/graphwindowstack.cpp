#include "graphwindowstack.h"
#include "ui_graphwindowstack.h"


graphwindowstack::graphwindowstack(QWidget *parent ,QVector<teaching_entry> data_for_graphs, QStringList passed_years, QString name) :
    QDialog(parent),
    ui(new Ui::graphwindowstack)
    {
        ui->setupUi(this);
        this->setStyleSheet("background-color:white;");
        ui->label_name->setText(name);

        years = passed_years;

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

        make_stacked_bar_graph(values, years);

}

/*
 * Function: generate_graph_colors
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 *
 * PARAMETER LIST:
 *
 * RETURNS:
 *
 */
void graphwindowstack::make_stacked_bar_graph(QVector<int> values, QStringList years)
{

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
    pen.setColor(QColor(1, 92, 191));
    postgrad->setPen(pen);
    postgrad->setBrush(QColor(1, 92, 191, 50));

    // Sets the names for the legend
    undergrad->setName("Undergraduate Medical Education");
    pen.setColor(QColor(255, 131, 0));
    undergrad->setPen(pen);
    undergrad->setBrush(QColor(255, 131, 0, 50));

    continuing->setName("Continuing Education");
    pen.setColor(QColor(150, 222, 0));
    continuing->setPen(pen);
    continuing->setBrush(QColor(150, 222, 0, 70));

    other->setName("Other");
    pen.setColor(QColor(230, 92, 2));
    other->setPen(pen);
    other->setBrush(QColor(230, 92, 2, 50));


    // + Stack bars ontop of each other:
    continuing->moveAbove(other);
    undergrad->moveAbove(continuing);
    postgrad->moveAbove(undergrad);

    // + PREPARE THE X-AXIS

    // + Apply category labels to the x-axis:
    QVector<double> ticks;
    QVector<QString> labels;

    // + The size of the array passed should be years (total number of years available)
    for(int i = 0; i < 1; i++){
        ticks << i;
        labels << years.at(i);
    }

    // + Other x-axis formatting
    ui->graph->xAxis->setAutoTicks(false);
    ui->graph->xAxis->setAutoTickLabels(false);
    ui->graph->xAxis->setTickVector(ticks);
    ui->graph->xAxis->setTickVectorLabels(labels);
    ui->graph->xAxis->setTickLabelRotation(60);
    ui->graph->xAxis->setSubTickCount(0);
    ui->graph->xAxis->setTickLength(0, 4);
    ui->graph->xAxis->grid()->setVisible(true);

    // + Sets the range of the ticks along the x-axis
    ui->graph->xAxis->setRange(0, values.length()*2);


    // + PREPARE THE Y-AXIS


    // + Where we set the range of the y axis
    int max_range, temp_range = 0;

    // + Loop and determine the which year has the largest number
    //   of category occurencs and set that as the max range of the
    //   graph
    for(int i = 0; i < values.length(); i++)
    {

        temp_range += values.at(i);

        // + Set the greatest number of occuernces of a category
        //   to be the max range for the graph
        if(temp_range > max_range)
            max_range = temp_range;

    }

    ui->graph->yAxis->setRange(0, max_range+1);

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

    for(int n = 0; n < values.length(); n++)
    {
            undergradData << values.at(n);
            postgradData << values.at(n);
            continuingData << values.at(n);
            otherData << values.at(n);
    }


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

graphwindowstack::~graphwindowstack()
{
    delete ui;
}
