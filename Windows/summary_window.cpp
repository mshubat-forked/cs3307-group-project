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

static QString csv_file_name;

QVector<double> values(4);

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

/*
 * Constructor: Summary_Window
 * -----------------------------------------
 * WHAT THE CONSTRUCTOR DOES:
 * + Defines a Dialog window that shows the summarization of csv file
 *   information and the functionality to view that information in different
 *   ways (ie. date range filters and graphs)
 *
 * PARAMETER:
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

    setAcceptDrops(true);





    // + Make a connection to the database
    DB database;

    readTeach(database);

    // + Get the teaching information from the database
    QVector<teaching_entry> vector_teaching_entries = database.getTeachFull();
    data_for_graphs = database.getTeachFull();

    years = build_teaching_tree(vector_teaching_entries);

    qDebug() << "Got a year: " << years.at(0);

    // + Validator to ensure only year values can be entered into the date filter
    QIntValidator *v = new QIntValidator(0, 9999);
    ui->fromDate->setValidator( v );
    ui->toDate->setValidator( v );

    // + Populate the graph combo box with the graph options
    // + This needs to match switch statement in activated function
    //ui->graphComboBox_teach->addItem("Stack"); //index 0
    //ui->graphComboBox_teach->addItem("Pie"); //index 1
    //ui->graphComboBox_teach->addItem("Bar"); //index 2


    graph_values.append(18);
    graph_values.append(45);
    graph_values.append(34);
    graph_values.append(40);

    title_values.append("PME");
    title_values.append("UME");
    title_values.append("CME");
    title_values.append("Other");
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


/*
 * + Allow items to be dragged on the Summary_Window
 */
void Summary_Window::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls())
    {
        e->acceptProposedAction();
    }

}

/*
 * + Allow items to be dropped on the Summary_Window
 */
void Summary_Window::dropEvent(QDropEvent *e)
{
    foreach(const QUrl &url, e->mimeData()->urls())
    {
        const QString &file_name = url.toLocalFile();

        std::string s_file_name = file_name.toUtf8().constData();
        std::string accepted_file_type = ".csv";

        std::size_t found = s_file_name.find(accepted_file_type);

        // + Check if the dropped file by the user is a .csv file
        // + Only accept .csv files for input
        if(found != -1)
        {
            qDebug() << "Acceptable file: " << file_name;
            csv_file_name = file_name;
        }

        else
        {
            qDebug() << "Unacceptable file: " << file_name;
        }
    }
}

/*
 * Destory the window when it is closed
 */
Summary_Window::~Summary_Window()
{
    delete ui;
}

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
    else{
        //assigns the entered values to the the fromYear and toYear variables to be used for filtering
        fromYear=tempFrom;
        toYear=tempTo;
        //now need to filter
    }
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
    for(int n=0; n<4; n++)
    {
        ui->treeWidget_teach->resizeColumnToContents(n);
    }
}

/*
 * Function: top_level_teaching
 * -------------------------------
 * WHAT THE FUNCTION DOES:
 * + Sets the top level items of the tree summary window for
 *   teaching data
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

/*
 * Function: build_teaching_tree
 * ----------------------------------
 * WHAT THE FUNCTION DOES:
 * + Fills out the summary tree with teaching entry information
 */
QStringList Summary_Window::build_teaching_tree(QVector<teaching_entry> vector_teaching_entries)
{

    QStringList temp_years;

    // + Define the headers for a teaching tree widget
    make_tree_header();

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

// + Open the graph setup dialog box
void Summary_Window::on_button_graph_clicked()
{
    setup_graph = new GraphSetup(faculty, data_for_graphs, years, this);
    setup_graph->show();
}
