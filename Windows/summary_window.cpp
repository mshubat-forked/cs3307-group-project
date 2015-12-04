#include "summary_window.h"
#include "ui_summary_window.h"
#include <Windows/graphwindow.h>
#include <Windows/graphwindowpie.h>
#include <QTextStream>

struct TeachingField
{
    QString member_name;
    int date;
    QString program;
    double hours;
    int students;
};

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
 */
Summary_Window::Summary_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Summary_Window)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(5);
    ui->treeWidget->headerItem()->setText(0,"Category:");
    ui->treeWidget->headerItem()->setText(1,"Start Year:");
    ui->treeWidget->headerItem()->setText(2,"Faculty Member:");
    ui->treeWidget->headerItem()->setText(3,"Hours:");
    ui->treeWidget->headerItem()->setText(4,"Students:");

    QTreeWidgetItem *pme = make_root(NULL, "PME", NULL, NULL , "23", "5");
    QTreeWidgetItem *ume = make_root(NULL, "UME", NULL, NULL, "18","10");
    QTreeWidgetItem *cme = make_root(NULL, "CME", NULL, NULL, "15", "12");
    QTreeWidgetItem *other = make_root(NULL, "Other", NULL, NULL, "34","3");

    // + Make each of the categories top level items in the tree widget
    ui->treeWidget->addTopLevelItem(pme);
    ui->treeWidget->addTopLevelItem(ume);
    ui->treeWidget->addTopLevelItem(cme);
    ui->treeWidget->addTopLevelItem(other);

    // + Make new nodes depending on the date range set by the user; again a loop
    //   will be preferred here

    // + Here is an example how a subroot could be added to a main category root
    QTreeWidgetItem *p_year_row = make_child(pme, NULL, "2011", NULL, "34", "45");

    // + Here is adding a child to the sub root just made above
    make_child(p_year_row, NULL, NULL, "Jack Johnson", "45", "100");

    // + Adding some test values for the to and from date combo box
    // + ideally these values would be based on the added data
    // + conversion from int to string as dates values are int in data structure

    ui->fromDateCombo->addItem(QString::number(2010));
    ui->fromDateCombo->addItem(QString::number(2011));
    ui->fromDateCombo->addItem(QString::number(2012));
    ui->fromDateCombo->addItem(QString::number(2013));
    ui->fromDateCombo->addItem(QString::number(2014));

    ui->toDateCombo->addItem(QString::number(2010));
    ui->toDateCombo->addItem(QString::number(2011));
    ui->toDateCombo->addItem(QString::number(2012));
    ui->toDateCombo->addItem(QString::number(2013));
    ui->toDateCombo->addItem(QString::number(2014));

    fromDateIndex = ui->fromDateCombo->currentIndex();
    toDateIndex = ui->toDateCombo->currentIndex();

    // + Populate the graph combo box with the graph options
    // + This needs to match switch statement in activated function
    ui->graphComboBox->addItem("Stack"); //index 0
    ui->graphComboBox->addItem("Pie"); //index 1
    ui->graphComboBox->addItem("Bar"); //index 2

    graph_values.append(18);
    graph_values.append(45);
    graph_values.append(34);
    graph_values.append(40);

    title_values.append("PME");
    title_values.append("UME");
    title_values.append("CME");
    title_values.append("Other");

    for(int n=0; n<4; n++){
        ui->treeWidget->resizeColumnToContents(n);
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
QTreeWidgetItem * Summary_Window::make_root(QTreeWidgetItem *parent, QString category, QString date, QString faculty_name,
                           QString num_hours, QString num_students)
{
    // + Create a new tree widget to add to the treeWidget table on the main window
    QTreeWidgetItem *new_tree_widget = new QTreeWidgetItem(ui->treeWidget);

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
QTreeWidgetItem * Summary_Window::make_child(QTreeWidgetItem *parent, QString category, QString date, QString faculty_name,
                                          QString num_hours, QString num_students)
{
    // + Create a new tree widget to add to the treeWidget table on the main window
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
 * Function: on_fromDateCombo_activated
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Defines a the first of two combo boxes that are used
 *   to create a date range for the data on the summary window
 *
 * PARAMETER:
 * - first_year: a string that represents a year
 */
void Summary_Window::on_fromDateCombo_activated(const QString &first_year)
{
    // Checks to make sure from date is before to date
    if((ui->toDateCombo->currentText()).toInt() < first_year.toInt())
    {
        // Gives warning and sets box back to previous index
        QMessageBox::warning(this, "Warning", "From Date must fall before To Date");

        ui->fromDateCombo->setCurrentIndex(fromDateIndex);
    }

    else
    {
        fromDateIndex = ui->fromDateCombo->currentIndex();
        //then get the selected year value using: first_year.toInt() to pass to filter function
    }
}

/*
 * Function: on_toDateCombo_activated
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Defines a the second of two combo boxes that are used
 *   to create a date range for the data on the summary window
 *
 * PARAMETER:
 * - second_year: a string that represents a year
 */
void Summary_Window::on_toDateCombo_activated(const QString &second_year)
{
    // Checks to make sure to date is before from date
    if(second_year.toInt() < (ui->fromDateCombo->currentText()).toInt())
    {
        //gives warning and sets box back to previous index
        QMessageBox::warning(this, "Warning", "To Date must fall after From Date");

        ui->toDateCombo->setCurrentIndex(toDateIndex);
    }

    else
    {
        toDateIndex = ui->toDateCombo->currentIndex();
        //then get the selected year value using: second_year.toInt() to pass to filter function
    }
}

/*
 * Function: on_graphComboBox_activated
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Defines the functionality of the combobox that controls
 *   what graphs the user can view
 *
 * PARAMETER:
 * - index: an integer value that represents the index
 *          of the graph chosen
 */
void Summary_Window::on_graphComboBox_activated(int index)
{

    switch(index)
    {
        // Show a Stack bar graph
        case 0:
            graph_window = new graphwindow(this,graph_values, title_values);
            graph_window->show();
            break;

        // Show a Pie graph
        case 1:
            graph_pie_window = new graphwindowpie(this,graph_values,title_values);
            graph_pie_window->show();
            break;

        // Show a Plain bar graph
        case 2:
            graph_bar_window = new graphwindowbar(this,graph_values, title_values);
            graph_bar_window->show();

        default:
            break;
    }
}

/*
 * Destory the window when it is closed
 */
Summary_Window::~Summary_Window()
{
    delete ui;
}
