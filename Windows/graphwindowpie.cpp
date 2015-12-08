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
 * - values: the data to be shown on the graph
 *
 */
graphwindowpie::graphwindowpie(QWidget *parent, QVector<teaching_entry> data_for_graphs, QString name) :
    QDialog(parent),
    ui(new Ui::graphwindowpie)
{
    ui->setupUi(this);

    setup_look();

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

    // + Get rid of an duplicate information from the years list
    years = years.toSet().toList();

    // + Find the max and min year in the 'years' QStringList
    QString min = *std::min_element(years.begin(), years.end());
    QString max = *std::max_element(years.begin(), years.end());

    // + Set the above information to labels on the screen
    ui->label_year_start->setText(min);
    ui->label_year_finish->setText(max);
    ui->label_name->setText(name);


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


void graphwindowpie::setup_look()
{
    this->setStyleSheet("background-color:white;");
    ui->label_subject->setText("Teaching Summary for ");
}

/*
 * Destory the window when it is closed
 */
graphwindowpie::~graphwindowpie()
{
    delete ui;
}

