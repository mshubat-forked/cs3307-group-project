/*
 * Source file: summary_window.cpp
 * ---------------------------------
 * + Defines a Dialog window class that handles the main
 *   interaction pane for the user
 */

#include "summary_window.h"
#include <QTextStream>
#include <QDebug>
#include <QHash>
#include <QVector>
#include <iostream>
#include <string>
#include <Reading_Files/read_database.h>
#include <QStringList>
#include <fstream>
#include <QProgressDialog>

static DB database;

using namespace std;

/*
 * Constructor: Summary_Window
 * -----------------------------------------
 * WHAT THE CONSTRUCTOR DOES:
 * + Defines a Dialog window that shows the summarization of csv file
 *   information and the functionality to view that information in different
 *   ways (ie. date range filters and graphs)
 *
 * PARAMETERS:
 * - parent: a reference to the parent widget
 * - new_db: boolean indication of if a new db file is needed
 *   true: delete and make a new database file
 *   false: keep the old database file
 */
Summary_Window::Summary_Window(QWidget *parent, bool new_db) :
    QDialog(parent),
    ui(new Ui::Summary_Window)
{
    ui->setupUi(this);

    // + Validator to ensure only year values can be entered into the date filter
    QIntValidator *v = new QIntValidator(0, 9999);
    ui->fromDate->setValidator( v );
    ui->toDate->setValidator( v );

    
    // + Define the headers for a teaching tree widget
    make_tree_header();

    // + Make a connection to the database
    if(new_db == false){

        // + Filter data only for the teaching tab
        if(current_tab_index == 0)
        {

            vector_teaching_entries = database.getTeachFull();

            // + Set the data aside for the graphs aswell
            data_for_teaching_graphs = database.getTeachFull();

            years = build_teaching_tree(vector_teaching_entries);

            ui->label_start_year_teaching->setText(years.first());
            ui->label_to_teaching->setText("to");
            ui->label_end_year_teaching->setText(years.last());

        }

        // + Filter data only for the Presentations tab
        else if(current_tab_index == 1)
        {
            vector_presentations_entries = database.getPresFull();

            // + Set the data aside for the graphs aswell
            data_for_presentations_graphs = database.getPresFull();

            years = build_presentations_tree(vector_presentations_entries);

            ui->label_start_year_presentations->setText(years.first());
            ui->label_to_presentations->setText("to");
            ui->label_end_year_presentations->setText(years.last());

        }

        // + Filter data only for the Grants tab
        else if(current_tab_index == 2)
        {
            vector_grantfunding_entries = database.getGrantFull();

            // + Set the data aside for the graphs aswell
            data_for_grantfunding_graphs = database.getGrantFull();

            years = build_grants_tree(vector_grantfunding_entries);

            ui->label_start_year_grants->setText(years.first());
            ui->label_to_grants->setText("to");
            ui->label_end_year_grants->setText(years.last());

        }

        // + Filter data only for the Publications tab
        else if(current_tab_index == 3)
        {
            vector_publications_entries = database.getPubFull();

            // + Set the data aside for the graphs aswell
            data_for_publications_graphs = database.getPubFull();

            years = build_publications_tree(vector_publications_entries);

            ui->label_start_year_publications->setText(years.first());
            ui->label_to_publications->setText("to");
            ui->label_end_year_publications->setText(years.last());

        }
    }

    // + If a new session was chosen clear the table and start fresh
    else
    {
        ui->treeWidget_teach->clear();
    }

}


/*
 * Function: make_root
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Makes a root QTreeWidgetItem that could be the parent to
 *   child QTreeWidgetItems
 *
 * PARAMETER:
 * - parent: A QTreeWidgetItem pointer that refers to a QTreeWidgetItem
 *           that will be above the to be made child in the summary tree
 * - category: A QString that can be one of four subject areas (PME, UME, CME, Other)
 * - date: A QString that represents a year
 * - faculty_name: A QString that represents the name of a member of a faculty
 * - num_hours: A QString that represents the hours associated with a subject area for a year
 * - num_students: A QString that represents the number of students in a subject for a year
 *
 * RETURNS:
 * + A newly made root QTreeWidgetItem
 */
QTreeWidgetItem* Summary_Window::make_root(QString category, QString num_hours, QString num_students)
{

    // + Create a new tree widget to add to the treeWidget table on the main window
    QTreeWidgetItem *new_tree_widget = new QTreeWidgetItem(ui->treeWidget_teach);

    new_tree_widget->setText(0, category);
    new_tree_widget->setText(3, num_hours);
    new_tree_widget->setText(4, num_students);

    return new_tree_widget;
}

QTreeWidgetItem* Summary_Window::make_root_pres(QString category)
{

    // + Create a new tree widget to add to the treeWidget table on the main window
    QTreeWidgetItem *new_tree_widget = new QTreeWidgetItem(ui->treeWidget_pres);

    new_tree_widget->setText(0, category);

    return new_tree_widget;
}

QTreeWidgetItem* Summary_Window::make_root_grants(QString category, QString total, QString total_dollars)
{

    // + Create a new tree widget to add to the treeWidget table on the main window
    QTreeWidgetItem *new_tree_widget = new QTreeWidgetItem(ui->treeWidget_grant);

    new_tree_widget->setText(0, category);
    new_tree_widget->setText(3, total);
    new_tree_widget->setText(4, total_dollars);

    return new_tree_widget;
}


QTreeWidgetItem* Summary_Window::make_root_pubs(QString category, QString total)
{

    // + Create a new tree widget to add to the treeWidget table on the main window
    QTreeWidgetItem *new_tree_widget = new QTreeWidgetItem(ui->treeWidget_pub);

    new_tree_widget->setText(0, category);
    new_tree_widget->setText(4, total);

    return new_tree_widget;
}

/*
 * Function: make_child
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Makes a child QTreeWidgetItem that gets assoicated with a parent
 *   QTreeWidgetItem
 *
 * PARAMETER:
 * - parent: A QTreeWidgetItem pointer that refers to a QTreeWidgetItem
 *           that will be above the to be made child in the summary tree
 * - category: A QString that can be one of four subject areas (PME, UME, CME, Other)
 * - date: A QString that represents a year
 * - faculty_name: A QString that represents the name of a member of a faculty
 * - num_hours: A QString that represents the hours associated with a subject area for a year
 * - num_students: A QString that represents the number of students in a subject for a year
 *
 * RETURNS:
 * + A newly made child QTreeWidgetItem
 */
QTreeWidgetItem * Summary_Window::make_child(QTreeWidgetItem *parent, QString date, QString faculty_name,
                                             QString num_hours, QString num_students)
{
    // + Create a new tree widget to add to the teaching_tree table on the main window
    QTreeWidgetItem *new_tree_widget = new QTreeWidgetItem();

    // + If the date is not NULL then the sub item just after the main root item
    if(date != NULL)
    {
        new_tree_widget->setText(1, date);
        new_tree_widget->setText(3, num_hours);
        new_tree_widget->setText(4, num_students);
    }

    // + The sub item store the faculty name and should be set after date sub item
    else
    {
        new_tree_widget->setText(2, faculty_name);
        new_tree_widget->setText(3, num_hours);
        new_tree_widget->setText(4, num_students);
    }
    parent->addChild(new_tree_widget);

    return new_tree_widget;
}


QTreeWidgetItem * Summary_Window::make_child_grants(QTreeWidgetItem *parent, QString type,
                                                    QString faculty_name, QString num_total, QString num_dollars)
{
    // + Create a new tree widget to add to the teaching_tree table on the main window
    QTreeWidgetItem *new_tree_widget = new QTreeWidgetItem();

    // + If the date is not NULL then the sub item just after the main root item
    if(type != NULL)
    {
        new_tree_widget->setText(1, type);
        new_tree_widget->setText(3, num_total);
        new_tree_widget->setText(4, num_dollars);
    }

    // + The sub item store the faculty name and should be set after date sub item
    else
    {
        new_tree_widget->setText(2, faculty_name);
        new_tree_widget->setText(3, num_total);
        new_tree_widget->setText(4, num_dollars);
    }
    parent->addChild(new_tree_widget);

    return new_tree_widget;
}


QTreeWidgetItem * Summary_Window::make_child_pres(QTreeWidgetItem *parent, QString faculty_name, QString total)
{
    // + Create a new tree widget to add to the teaching_tree table on the main window
    QTreeWidgetItem *new_tree_widget = new QTreeWidgetItem();

    new_tree_widget->setText(1, faculty_name);
    new_tree_widget->setText(2, total);


    parent->addChild(new_tree_widget);

    return new_tree_widget;
}


QTreeWidgetItem * Summary_Window::make_child_pubs(QTreeWidgetItem *parent, QString faculty_name, QString total)
{
    // + Create a new tree widget to add to the teaching_tree table on the main window
    QTreeWidgetItem *new_tree_widget = new QTreeWidgetItem();

    new_tree_widget->setText(1, faculty_name);
    new_tree_widget->setText(2, total);


    parent->addChild(new_tree_widget);

    return new_tree_widget;
}


/*
 * Function: make_tree_header
 * -------------------------------
 * WHAT THE FUNCTION DOES:
 * + Sets the titles for the tree widget header
 */
void Summary_Window::make_tree_header()
{
    // + Set the header for the teaching tree window
    ui->treeWidget_teach->setColumnCount(5);
    ui->treeWidget_teach->headerItem()->setText(0,"Category:");
    ui->treeWidget_teach->headerItem()->setText(1,"Start Year:");
    ui->treeWidget_teach->headerItem()->setText(2,"Faculty Member:");
    ui->treeWidget_teach->headerItem()->setText(3,"Hours:");
    ui->treeWidget_teach->headerItem()->setText(4,"Students:");

    // + Spaces the headers evenly along the top of the tree widget
    for(int n=0; n<5; n++)
    {
        ui->treeWidget_teach->resizeColumnToContents(n);
    }

    // + Set the header for the presentation tree window
    ui->treeWidget_pres->setColumnCount(3);
    ui->treeWidget_pres->headerItem()->setText(0,"Category:");
    ui->treeWidget_pres->headerItem()->setText(1,"Faculty Member:");
    ui->treeWidget_pres->headerItem()->setText(2, "Total Number:");

    // + Spaces the headers evenly along the top of the tree widget
    for(int n=0; n<3; n++)
    {
        ui->treeWidget_pres->resizeColumnToContents(n);
    }

    // + Set the header for the grants/funding header
    ui->treeWidget_grant->setColumnCount(5);
    ui->treeWidget_grant->headerItem()->setText(0,"Category:");
    ui->treeWidget_grant->headerItem()->setText(1,"Type:");
    ui->treeWidget_grant->headerItem()->setText(2,"Faculty Member:");
    ui->treeWidget_grant->headerItem()->setText(3,"Total Number:");
    ui->treeWidget_grant->headerItem()->setText(4,"Total Dollars:");

    // + Spaces the headers evenly along the top of the tree widget
    for(int n=0; n<5; n++)
    {
        ui->treeWidget_grant->resizeColumnToContents(n);
    }


    // + Set the header for the publications header
    ui->treeWidget_pub->setColumnCount(3);
    ui->treeWidget_pub->headerItem()->setText(0,"Category:");
    ui->treeWidget_pub->headerItem()->setText(1,"Faculty Member:");
    ui->treeWidget_pub->headerItem()->setText(2,"Total:");

    // + Spaces the headers evenly along the top of the tree widget
    for(int n=0; n<3; n++)
    {
        ui->treeWidget_pub->resizeColumnToContents(n);
    }

    ui->treeWidget_pub->setColumnWidth(0, 200);
}

/*
 * Function: top_level_teaching
 * -------------------------------
 * WHAT THE FUNCTION DOES:
 * + Sets the top level items of the tree summary window for
 *   teaching data
 *
 * PARAMETERS:
 * - pme: a pointer to a root treeWidget to put pme data under
 * - ume: a pointer to a root treeWidget to put ume data under
 * - cme: a pointer to a root treeWidget to put cme data under
 * - other: a pointer to a root treeWidget to put other data under
 */
void Summary_Window::top_level_teaching(QTreeWidgetItem *pme, QTreeWidgetItem *ume,
                                        QTreeWidgetItem *cme, QTreeWidgetItem *other)
{

    // + Make each of the categories top level items in the tree widget
    ui->treeWidget_teach->addTopLevelItem(pme);
    ui->treeWidget_teach->addTopLevelItem(ume);
    ui->treeWidget_teach->addTopLevelItem(cme);
    ui->treeWidget_teach->addTopLevelItem(other);

}

void Summary_Window::top_level_pres(QTreeWidgetItem *invited, QTreeWidgetItem *abstracts,
                                    QTreeWidgetItem *presentations, QTreeWidgetItem *other)
{

    // + Make each of the categories top level items in the tree widget
    ui->treeWidget_pres->addTopLevelItem(invited);
    ui->treeWidget_pres->addTopLevelItem(abstracts);
    ui->treeWidget_pres->addTopLevelItem(presentations);
    ui->treeWidget_pres->addTopLevelItem(other);

}


void Summary_Window::top_level_grants(QTreeWidgetItem *grants, QTreeWidgetItem *funding)
{

    // + Make each of the categories top level items in the tree widget
    ui->treeWidget_grant->addTopLevelItem(grants);
    ui->treeWidget_grant->addTopLevelItem(funding);

}


void Summary_Window::top_level_pubs(QTreeWidgetItem *publications, QTreeWidgetItem *journals,
                                    QTreeWidgetItem *books, QTreeWidgetItem *chapters, QTreeWidgetItem *letters)
{

    // + Make each of the categories top level items in the tree widget
    ui->treeWidget_pub->addTopLevelItem(publications);
    ui->treeWidget_pub->addTopLevelItem(journals);
    ui->treeWidget_pub->addTopLevelItem(books);
    ui->treeWidget_pub->addTopLevelItem(chapters);
    ui->treeWidget_pub->addTopLevelItem(letters);

}

/*
 * Function: on_button_graph_clicked
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Open a dialog window that lets the user choose what type of graph they
 *   would like to view and for what name
 */
void Summary_Window::on_button_graph_clicked()
{
    setup_graph = new GraphSetup(faculty, data_for_teaching_graphs, years, current_tab_index, this);
    setup_graph->show();
}

/*
 * Function: on_tabWidget_tabBarClicked
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Stores the current tab index value into current_tab_index
 *   which can be accessed anywhere from in the class
 */
void Summary_Window::on_tabWidget_tabBarClicked(int index)
{
    current_tab_index = index;
}

/*
 * Function: on_button_load_file_clicked
 * ---------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Loads a CSV into the currently selected tab
 */
void Summary_Window::on_button_load_file_clicked()
{
    // + Make a connection to the database
    // + Load a Teaching table
    if(current_tab_index == 0)
    {

        if(dbexists())
        {
            database.dropTableTeaching();
            database.makeTableTeaching();
        }

        readTeach(this, database);

        // + Get the teaching information from the database
        vector_teaching_entries = database.getTeachFull();

        // + Set the data aside for the graphs aswell
        data_for_teaching_graphs = database.getTeachFull();

        // + Build the summary window
        years = build_teaching_tree(vector_teaching_entries);

        if(!years.isEmpty())
        {
            ui->label_start_year_teaching->setText(years.first());
            ui->label_to_teaching->setText("to");
            ui->label_end_year_teaching->setText(years.last());
        }
    }

    // + Load a Presentations table
    else if(current_tab_index == 1)
    {

        if(dbexists())
        {
            database.dropTablePresentations();
            database.makeTablePresentations();
        }

        readPresentations(this, database);

        // + Get the Presentation information from the database
        vector_presentations_entries = database.getPresFull();

        // + Set the data aside for the graphs aswell
        data_for_presentations_graphs = database.getPresFull();

        // + Build the summary window
        years = build_presentations_tree(vector_presentations_entries);

        if(!years.isEmpty())
        {
            ui->label_start_year_presentations->setText(years.first());
            ui->label_to_presentations->setText("to");
            ui->label_end_year_presentations->setText(years.last());
        }

    }


    // + Load a Grants table
    else if(current_tab_index == 2)
    {
        if(dbexists())
        {
            database.dropTableGrants();
            database.makeTableGrants();
        }

        readGrants(this, database);

        // + Get the Presentation information from the database
        vector_grantfunding_entries = database.getGrantFull();

        // + Set the data aside for the graphs aswell
        data_for_grantfunding_graphs = database.getGrantFull();

        // + Build the summary window
        years = build_grants_tree(vector_grantfunding_entries);

        if(!years.isEmpty())
        {
            ui->label_start_year_grants->setText(years.first());
            ui->label_to_grants->setText("to");
            ui->label_end_year_grants->setText(years.last());
        }
    }


    // + Load a Publications
    else if(current_tab_index == 3)
    {
        if(dbexists())
        {
            database.dropTablePublications();
            database.makeTablePublications();
        }

        readPublications(this, database);

        // + Get the Presentation information from the database
        vector_publications_entries = database.getPubFull();

        // + Set the data aside for the graphs aswell
        data_for_publications_graphs = database.getPubFull();

        // + Build the summary window
        years = build_publications_tree(vector_publications_entries);

        if(!years.isEmpty())
        {
            ui->label_start_year_publications->setText(years.first());
            ui->label_to_publications->setText("to");
            ui->label_end_year_publications->setText(years.last());
        }

    }

}

/*
 * Function: on_dateFilterButton_clicked()
 * -------------------------------
 * WHAT THE FUNCTION DOES:
 * + Makes a new data query to the database with a year
 *   range to display on the summary window
 */
void Summary_Window::on_dateFilterButton_clicked()
{
    //variables fromYear and to Year defined in header
    //reads in the dates to temp holders
    int tempFrom = (ui->fromDate->text()).toInt();
    int tempTo = (ui->toDate->text()).toInt();

    //compares to ensure from date is before to date
    if(tempFrom > tempTo){

        //prints warning message and resets textbox values to previous values
        QMessageBox::warning(this, "Warning", "To Date must fall after From Date");
        ui->fromDate->setText(QString::number(fromYear));
        ui->toDate->setText(QString::number(toYear));
    }

    else
    {
        // + Get the teaching information from the database

        // + Filter data only for the teaching tab
        if(current_tab_index == 0)
        {
            vector_teaching_entries = database.getTeachByDate(tempFrom,tempTo);

            // + Set the data aside for the graphs aswell
            data_for_teaching_graphs = database.getTeachByDate(tempFrom,tempTo);

            years = build_teaching_tree(vector_teaching_entries);

            // + Need if statement to handle empty year list
            if(years.size() > 0)
            {
                ui->label_start_year_teaching->setText(years.first());
                ui->label_to_teaching->setText("to");
                ui->label_end_year_teaching->setText(years.last());
            }

            // + Show data range with no data values
            else
            {
                ui->label_start_year_teaching->setText(QString::number(tempFrom));
                ui->label_to_teaching->setText("to");
                ui->label_end_year_teaching->setText(QString::number(tempTo));
            }


        }

        // + Filter data only for the Presentations tab
        else if(current_tab_index == 1)
        {
            vector_presentations_entries = database.getPresByDate(tempFrom,tempTo);

            // + Set the data aside for the graphs aswell
            data_for_presentations_graphs = database.getPresByDate(tempFrom,tempTo);

            years = build_presentations_tree(vector_presentations_entries);

            // + Need if statement to handle empty year list
            if(years.size() > 0)
            {
                ui->label_start_year_presentations->setText(years.first());
                ui->label_to_presentations->setText("to");
                ui->label_end_year_presentations->setText(years.last());
            }

            else
            {
                ui->label_start_year_presentations->setText(QString::number(tempFrom));
                ui->label_to_presentations->setText("to");
                ui->label_end_year_presentations->setText(QString::number(tempTo));
            }

        }

        // + Filter data only for the Grants tab
        else if(current_tab_index == 2)
        {
            vector_grantfunding_entries = database.getGrantByDate(tempFrom,tempTo);

            // + Set the data aside for the graphs aswell
            data_for_grantfunding_graphs = database.getGrantByDate(tempFrom,tempTo);

            years = build_grants_tree(vector_grantfunding_entries);

            if(years.size() > 0)
            {
                ui->label_start_year_grants->setText(years.first());
                ui->label_to_grants->setText("to");
                ui->label_end_year_grants->setText(years.last());
            }
            else
            {
                ui->label_start_year_grants->setText(QString::number(tempFrom));
                ui->label_to_grants->setText("to");
                ui->label_end_year_grants->setText(QString::number(tempTo));
            }

        }

        // + Filter data only for the Publications tab
        else if(current_tab_index == 3)
        {
            vector_publications_entries = database.getPubByDate(tempFrom,tempTo);

            // + Set the data aside for the graphs aswell
            data_for_publications_graphs = database.getPubByDate(tempFrom,tempTo);

            years = build_publications_tree(vector_publications_entries);

            if(years.size() > 0)
            {
                ui->label_start_year_publications->setText(years.first());
                ui->label_to_publications->setText("to");
                ui->label_end_year_publications->setText(years.last());
            }
            else
            {
                ui->label_start_year_publications->setText(QString::number(tempFrom));
                ui->label_to_publications->setText("to");
                ui->label_end_year_publications->setText(QString::number(tempTo));
            }

        }
    }
}

/*
 * Function: build_teaching_tree
 * ----------------------------------
 * WHAT THE FUNCTION DOES:
 * + Fills out the summary tree with teaching entry information
 *
 * PARAMETERS:
 * - vector_teaching_entries: teaching entry information to parse through and display
 *
 * RETURNS:
 * + A QStringList of years found when reading through the data
 */
QStringList Summary_Window::build_teaching_tree(QVector<teaching_entry> vector_teaching_entries)
{

    ui->treeWidget_teach->clear();

    // + Keeps track of total hours for each main heading
    pme_total_hours = 0.0;
    ume_total_hours = 0.0;
    cme_total_hours = 0.0;
    other_total_hours = 0.0;

    // + Keeps track of total traineers for each main heading
    pme_total_trainees = 0;
    ume_total_trainees = 0;
    cme_total_trainees = 0;
    other_total_trainees = 0;


    QStringList temp_years;



    // + Setup the root categories on the tree
    QTreeWidgetItem *pme = make_root("PME", "", "");
    QTreeWidgetItem *ume = make_root("UME", "","");
    QTreeWidgetItem *cme = make_root("CME", "", "");
    QTreeWidgetItem *other = make_root("Other", "","");

    // + Used for keeping track of values through looping
    QString current_date = "99999";
    QString current_member = "-1";
    int iteration = 0;

    // + Pointers to the current row of the tree
    QTreeWidgetItem *p_year_row;
    QTreeWidgetItem *p_member_row;

    // + Set the top level of items in the tree
    top_level_teaching(pme,ume,cme,other);

    // + Loop for the values in the passed database
    while(!vector_teaching_entries.isEmpty())
    {

        // + Get a teaching entry items from the database
        teaching_entry current_teaching_entry = vector_teaching_entries.takeFirst();

        // + Extract information from the aformentioned teaching_entry
        QString teaching_date = QString::fromStdString(current_teaching_entry.get_date());
        QString teaching_member = QString::fromStdString(current_teaching_entry.get_member());
        QString teaching_hours = QString::number(current_teaching_entry.get_total_hours());
        QString teaching_trainees = QString::number(current_teaching_entry.get_trainees());
        QString teaching_program = QString::fromStdString(current_teaching_entry.get_program());

        // + If a blank value is found, skip the whole entry
        if(teaching_date == "" || teaching_date == "0")
            continue;
        if(teaching_member == "")
            continue;
        if(teaching_hours == "")
            continue;
        if(teaching_trainees == "")
            continue;
        if(teaching_program == "")
            continue;


        // + Determing which root the current teaching entry should be put under
        QTreeWidgetItem *program;
        if(teaching_program == "Postgraduate Medical Education")
        {
            program = pme;
            pme_total_hours += current_teaching_entry.get_total_hours();
            pme_total_trainees += current_teaching_entry.get_trainees();
            temp_years.append(teaching_date);
        }

        else if(teaching_program == "Undergraduate Medical Education")
        {
            program = ume;
            ume_total_hours += current_teaching_entry.get_total_hours();
            ume_total_trainees += current_teaching_entry.get_trainees();
            temp_years.append(teaching_date);
        }

        else if(teaching_program == "Continuing Medical Education")
        {
            program = cme;
            cme_total_hours += current_teaching_entry.get_total_hours();
            cme_total_trainees += current_teaching_entry.get_trainees();
            temp_years.append(teaching_date);
        }

        else
        {
            program = other;
            temp_years.append(teaching_date);
        }


        // + When dates differ, a new data has been found, and change over to
        //   that new date is inorder
        if(current_date != teaching_date)
        {
            // + Update the current data to the new data
            current_date = teaching_date;

            // + Only do this for the first iternation of the loop
            if(iteration == 0)
            {
                // + Create the first year row
                p_year_row = make_child(program, current_date, NULL, "", "");

                // + Keep a tally of the totals for the first year row
                year_total_hours += current_teaching_entry.get_total_hours();
                year_total_trainees += current_teaching_entry.get_trainees();
            }

            // + Otherwise the loop is passed the first year row and is putting together
            //   other year rows
            else
            {
                // + Apply the totals to current year row before the change over to
                //   a new year row occurs
                p_year_row->setText(3,QString::number(year_total_hours,'f',0));
                p_year_row->setText(4,QString::number(year_total_trainees,'f',0));

                // + Create the new year row
                p_year_row = make_child(program, current_date, NULL, "", "");

                // + Start the totals over at the current hour and student valleys
                year_total_hours = current_teaching_entry.get_total_hours();
                year_total_trainees = current_teaching_entry.get_trainees();
            }


        }
        // + Keep a running total of the hour and student for a particular year
        else
        {
            year_total_hours += current_teaching_entry.get_total_hours();
            year_total_trainees += current_teaching_entry.get_trainees();
        }


        // + Add a name row to the year row made above
        // + The code here is similar to what the year row code does above
        if(current_member != teaching_member)
        {
            current_member = teaching_member;

            // + Add a new name to the faculty vector for other functions
            faculty.append(current_member);

            if(iteration == 0)
            {
                p_member_row = make_child(p_year_row, NULL, current_member, teaching_hours, teaching_trainees);
                member_total_hours += current_teaching_entry.get_total_hours();
                member_total_trainees += current_teaching_entry.get_trainees();

            }

            else
            {

                p_member_row->setText(3,QString::number(member_total_hours,'f',0));
                p_member_row->setText(4,QString::number(member_total_trainees,'f',0));

                p_member_row = make_child(p_year_row, NULL, current_member, teaching_hours, teaching_trainees);
                member_total_hours = current_teaching_entry.get_total_hours();
                member_total_trainees = current_teaching_entry.get_trainees();

            }

        }

        else
        {
            member_total_hours += current_teaching_entry.get_total_hours();
            member_total_trainees += current_teaching_entry.get_trainees();
        }

        iteration++;

    }

    // + Set totals for program categories
    pme->setText(3,QString::number(pme_total_hours,'f',0));
    pme->setText(4,QString::number(pme_total_trainees,'f',0));

    ume->setText(3,QString::number(ume_total_hours,'f',0));
    ume->setText(4,QString::number(ume_total_trainees,'f',0));

    cme->setText(3,QString::number(cme_total_hours,'f',0));
    cme->setText(4,QString::number(cme_total_trainees,'f',0));


    faculty = faculty.toSet().toList();

    // + Get rid of an duplicate information from the years list
    temp_years = temp_years.toSet().toList();

    // + Sort the list in ascending order
    qSort(temp_years);

    return temp_years;
}

/*
 * Function: build_presentations_tree
 * ----------------------------------
 * WHAT THE FUNCTION DOES:
 * + Fills out the summary tree with presentation entry information
 *
 * PARAMETERS:
 * - vector_teaching_entries: teaching entry information to parse through and display
 *
 * RETURNS:
 * + A QStringList of years found when reading through the data
 */
QStringList Summary_Window:: build_presentations_tree(QVector<presentation_entry> vector_presentations_entries)
{


    ui->treeWidget_pres->clear();

    // + Keeps track of total hours for each main heading
    abstract_total = 0;
    invited_total = 0;
    presentation_total = 0;
    other_pres_total = 0;

    QStringList temp_years;

    // + Setup the root categories on the tree
    QTreeWidgetItem *abstract = make_root_pres("Abstract Presented");
    QTreeWidgetItem *invited = make_root_pres("Invited Lectures");
    QTreeWidgetItem *presentations = make_root_pres("Various Presentations");
    QTreeWidgetItem *other = make_root_pres("Other");

    // + Used for keeping track of values through looping
    QString current_date = "99999";
    QString current_member = "-1";

    // + Pointers to the current row of the tree
    QTreeWidgetItem *p_member_row;

    int iteration = 0;

    int max_length = 0;

    // + Set the top level of items in the tree
    top_level_pres(abstract, invited, presentations, other);

    // + Loop for the values in the passed database
    while(!vector_presentations_entries.isEmpty())
    {

        // + Get a presentation entry items from the database
        presentation_entry current_presentation_entry = vector_presentations_entries.takeFirst();

        // + Extract information from the aformentioned current_presentation_entry
        QString presentation_program = QString::fromStdString(current_presentation_entry.get_type());

        if(presentation_program.length() > max_length)
        {
            max_length = presentation_program.length();
        }
        
        QString presentation_member = QString::fromStdString(current_presentation_entry.get_member());
        
        QString presenation_year = QString::fromStdString(current_presentation_entry.get_date());

        QString current_member = "-1";

        // + If a blank value is found, skip the whole entry
        if(presentation_program == "" || presenation_year == "0")
            continue;
        if(presentation_member == "")
            continue;

        // + Determing which root the current teaching entry should be put under
        QTreeWidgetItem *current_type;
        if(presentation_program == "Abstract Presented")
        {
            current_type = abstract;
        }

        else if(presentation_program == "Invited Lectures")
        {
            current_type = invited;
        }

        else if(presentation_program.contains("Presentation"))
        {
            current_type = presentations;
        }

        else
        {
            current_type = other;
        }

        temp_years.append(presenation_year);


        if(current_member != presentation_member)
        {
            current_member = presentation_member;

            // + Add a new name to the faculty vector for other functions
            faculty_pres.append(current_member);

            if(iteration == 0)
            {
                p_member_row = make_child_pres(current_type, current_member, "");
                counter_for_current_name_pres++;
            }

            else
            {

                p_member_row->setText(2,QString::number(counter_for_current_name_pres));

                p_member_row = make_child_pres(current_type, current_member, QString::number(counter_for_current_name_pres));
                counter_for_current_name_pres++;

            }

        }

        else
        {
            counter_for_current_name_pres++;
        }

        iteration++;

    }

    ui->treeWidget_pres->setColumnWidth(0,(max_length)*10);

    faculty_pres = faculty_pres.toSet().toList();

    // + Get rid of an duplicate information from the years list
    temp_years = temp_years.toSet().toList();

    // + Sort the list in ascending order
    qSort(temp_years);

    return temp_years;


}

/*
 * Function: build_grants_tree
 * ----------------------------------
 * WHAT THE FUNCTION DOES:
 * + Fills out the summary tree with grant entry information
 *
 * PARAMETERS:
 * - vector_grants_entries: teaching entry information to parse through and display
 *
 * RETURNS:
 * + A QStringList of years found when reading through the data
 */
QStringList Summary_Window:: build_grants_tree(QVector<grants_entry> vector_grantfunding_entries)
{
    /*
    ui->treeWidget_teach->clear();

    grant_total_dollars = 0.0;
    funding_total_dollars = 0.0;

    grant_peer_total = 0;
    grant_sponsored_total = 0;
    grant_peer_dollar_total = 0.0;
    grant_sponsored_dollar_total = 0.0;

    grant_total = 0;
    funding_total = 0;

    QStringList temp_years;

    // + Setup the root categories on the tree
    QTreeWidgetItem *grants = make_root_grants("Grants", "", "");
    QTreeWidgetItem *funding = make_root_grants("Clinical Funding", "","");

    // + Used for keeping track of values through looping
    QString current_member = "-1";
    QString current_main_type = "Dogs";

    int iteration = 0;

    // + Pointers to the current row of the tree
    QTreeWidgetItem *p_member_row;

    // + Set the top level of items in the tree
    top_level_grants(grants,funding);

    QTreeWidgetItem p_gpr = make_child_grants(grants,"Peer Reviewed","","","");
    QTreeWidgetItem p_gis = make_child_grants(grants,"Industry Sponsored","","","");
    QTreeWidgetItem p_fpr = make_child_grants(grants,"Peer Reviewed","","","");
    QTreeWidgetItem p_fis = make_child_grants(grants,"Industry Sponsored","","","");

    // + Loop for the values in the passed database
    while(!vector_grantfunding_entries.isEmpty())
    {

        // + Get a teaching entry items from the database
        grants_entry current_grant_entry = vector_grantfunding_entries.takeFirst();

        // + Extract information from the aformentioned teaching_entry
        QString grant_type = QString::fromStdString(current_grant_entry.get_ftype());
        QString grant_date = QString::fromStdString(current_grant_entry.get_date());
        QString grant_member = QString::fromStdString(current_grant_entry.get_member());
        bool peer_reviewed = current_grant_entry.get_preview();
        int amount = current_grant_entry.get_total_amount();
        QString member_amount = QString::number(amount);

        // + If a blank value is found, skip the whole entry
        if(grant_date == "" || grant_date == "0")
            continue;
        if(grant_member == "")
            continue;
        if(grant_dollars == "")
            continue;

        // + Determing which root the current teaching entry should be put under
        QTreeWidgetItem *main_type;
        if(grant_type == "Grants" )
        {
            main_type = grants;

            grant_total++;
            grant_total_dollars += amount;

            if(peer_reviewed == true)
            {
                grant_peer_total++;
                grant_peer_dollar_total += amount;
            }

            else
            {
                grant_industry_total++;
                grant_industry_dollar_total += amount;
            }

            temp_years.append(teaching_date);
        }

        else if(grant_type == "Clinical Trials")
        {
            main_type = funding;

            funding_total++;
            funding_total_dollars += amount;

            if(peer_reviewed == true)
            {
                funding_peer_total++;
                funding_peer_dollar_total += amount;
            }

            else
            {
                funding_industry_total++;
                funding_industry_dollar_total += amount;
            }

            temp_years.append(teaching_date);

        }


        // + Add a name row to the year row made above
        // + The code here is similar to what the year row code does above
        if(current_member != grant_member)
        {
            current_member = grant_member;

            // + Add a new name to the faculty vector for other functions
            faculty_grants.append(current_member);

            if(iteration == 0)
            {
                if(grant_type == "Grants" && peer_reviewed == true)
                {
                    p_member_row = make_child(p_gpr, NULL, current_member, QString::number(grants_member_total), member_amount);
                }
                
                
                else if (grant_type == "Grants" && peer_reviewed == false)
                {
                     p_member_row = make_child(p_gis, NULL, current_member, QString::number(grants_member_total, member_amount);
                }

                else if (grant_type == "Clinical Trials" && peer_reviewed == true)
                {
                     p_member_row = make_child(p_fpr, NULL, current_member, QString::number(grants_member_total, member_amount);
                }


                else if (grant_type == "Clinical Trials" && peer_reviewed == false)
                {
                     p_member_row = make_child(p_fis, NULL, current_member, QString::number(grants_member_total, member_amount);
                }
                

                member_total_hours += current_teaching_entry.get_total_hours();
                member_total_trainees += current_teaching_entry.get_trainees();

            }

            else
            {

                p_member_row->setText(3,QString::number(member_total_hours,'f',0));
                p_member_row->setText(4,QString::number(member_total_trainees,'f',0));
                grants_member_total = 0;


                p_member_row = make_child(p_year_row, NULL, current_member, teaching_hours, teaching_trainees);
                member_total_hours = current_teaching_entry.get_total_hours();
                member_total_trainees = current_teaching_entry.get_trainees();

            }

        }

        else
        {
            member_total_hours += current_teaching_entry.get_total_hours();
            member_total_trainees += current_teaching_entry.get_trainees();
        }

        iteration++;

    }

    // + Set totals for program categories
    pme->setText(3,QString::number(pme_total_hours,'f',0));
    pme->setText(4,QString::number(pme_total_trainees,'f',0));

    ume->setText(3,QString::number(ume_total_hours,'f',0));
    ume->setText(4,QString::number(ume_total_trainees,'f',0));

    cme->setText(3,QString::number(cme_total_hours,'f',0));
    cme->setText(4,QString::number(cme_total_trainees,'f',0));


    faculty = faculty.toSet().toList();

    // + Get rid of an duplicate information from the years list
    temp_years = temp_years.toSet().toList();

    // + Sort the list in ascending order
    qSort(temp_years);

    return temp_years;
*/

}

/*
 * Function: build_publications_tree
 * ----------------------------------
 * WHAT THE FUNCTION DOES:
 * + Fills out the summary tree with publication entry information
 *
 * PARAMETERS:
 * - vector_publications_entries: teaching entry information to parse through and display
 *
 * RETURNS:
 * + A QStringList of years found when reading through the data
 */
QStringList Summary_Window:: build_publications_tree(QVector<publication_entry> vector_publications_entries)
{

    ui->treeWidget_pub->clear();

    // + Keeps track of total hours for each main heading
    published_abstracts_total = 0;
    journals_total = 0;
    book_total = 0;
    chapter_total = 0;
    letters_total = 0;

    QStringList temp_years;

    // + Setup the root categories on the tree
    QTreeWidgetItem *published_abstacts = make_root_pubs("Abstract Presented","");
    QTreeWidgetItem *journals = make_root_pubs("Journal Articles","");
    QTreeWidgetItem *books = make_root_pubs("Books","");
    QTreeWidgetItem *chapters = make_root_pubs("Book Chapters","");
    QTreeWidgetItem *letters = make_root_pubs("Letters to Editor","");

    // + Used for keeping track of values through looping
    QString current_member = "-1";

    // + Pointers to the current row of the tree
    QTreeWidgetItem *p_member_row;

    int iteration = 0;

    int max_length = 0;

    // + Set the top level of items in the tree
    top_level_pubs(published_abstacts,journals,books,chapters,letters);

    // + Loop for the values in the passed database
    while(!vector_publications_entries.isEmpty())
    {

        // + Get a presentation entry items from the database
        publication_entry current_publication_entry = vector_publications_entries.takeFirst();

        // + Extract information from the aformentioned current_presentation_entry
        QString publications_type = QString::fromStdString(current_publication_entry.get_type());

        QString publications_member = QString::fromStdString(current_publication_entry.get_member());

        if(publications_type.length() > max_length)
        {
            max_length = publications_type.length();
        }

        QString publications_year = QString::fromStdString(current_publication_entry.get_date());

        QString current_member = "-1";

        // + If a blank value is found, skip the whole entry
        if(publications_type == "" || publications_year == "0")
            continue;
        if(publications_member == "")
            continue;



        // + Determing which root the current teaching entry should be put under
        QTreeWidgetItem *current_type;
        if(publications_type == "Book Chapters")
        {
            current_type = chapters;
            chapter_total++;
        }

        else if(publications_type == "Books")
        {
            current_type = books;
            book_total++;
        }

        else if(publications_type.contains("Journal Article"))
        {
            current_type = journals;
            journals_total++;
        }

        else if(publications_type.contains("Letters to Editor"))
        {
            current_type = letters;
            letters_total++;
        }


        else if(publications_type.contains("Published Abstract"))
        {
            current_type = published_abstacts;
            published_abstracts_total++;
        }


        temp_years.append(publications_year);


        if(current_member != publications_member)
        {
            current_member = publications_member;

            // + Add a new name to the faculty vector for other functions
            faculty_pubs.append(current_member);

            if(iteration == 0)
            {
                p_member_row = make_child_pubs(current_type, current_member, "0");
                counter_for_current_name_pubs++;
            }

            else
            {

                p_member_row->setText(2,QString::number(counter_for_current_name_pubs));

                p_member_row = make_child_pres(current_type, current_member, QString::number(counter_for_current_name_pubs));
                counter_for_current_name_pubs++;

            }

        }

        else
        {
            counter_for_current_name_pubs++;
        }

        iteration++;

    }

    chapters->setText(2,QString::number(chapter_total));
    books->setText(2,QString::number(book_total));
    journals->setText(2,QString::number(journals_total));
    letters->setText(2,QString::number(letters_total));
    published_abstacts->setText(2,QString::number( published_abstracts_total));

    faculty_pubs = faculty_pubs.toSet().toList();



    // + Get rid of an duplicate information from the years list
    temp_years = temp_years.toSet().toList();

    // + Sort the list in ascending order
    qSort(temp_years);

    return temp_years;

}
/**
 * @brief DB::dbexists
 * @return true if database.db exists in current dir
 * else @return false
 */

/*
 * Function: dbexists
 * ----------------------------------
 * WHAT THE FUNCTION DOES:
 * + Checks if the database exists
 *
 * RETURNS:
 * + True if the database exists, false otherwise
 */
bool Summary_Window::dbexists()
{

    //R eplace all '\' with '/'

    std::string s = getcwd(NULL, 0);
    std::replace( s.begin(), s.end(), '\\', '/'); // replace all 'x' to 'y'

    //Check if DB exists
    if (ifstream(s+"/database.db")){//if database exists
        return true;
    }
    else{//if database does NOT exist

        return false;
    }
}

/*
 * Destory the window when it is closed
 */
Summary_Window::~Summary_Window()
{
    delete ui;
}




