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

    //make_pie_graph(p_yi, (int)ARRAY_SIZE(temp_years));

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
void graphwindowpie::make_pie_graph(YearInformationGraph *p_yi, int number_of_years)
{



}
