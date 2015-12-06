#include "summary_window.h"
#include "ui_summary_window.h"
#include <Windows/graphwindow.h>
#include <Windows/graphwindowpie.h>
#include <QTextStream>

static QString csv_file_name;

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

    setAcceptDrops(true);

    ui->treeWidget_teach->setColumnCount(5);
    ui->treeWidget_teach->headerItem()->setText(0,"Category:");
    ui->treeWidget_teach->headerItem()->setText(1,"Start Year:");
    ui->treeWidget_teach->headerItem()->setText(2,"Faculty Member:");
    ui->treeWidget_teach->headerItem()->setText(3,"Hours:");
    ui->treeWidget_teach->headerItem()->setText(4,"Students:");


    QTreeWidgetItem *pme = make_root(NULL, "PME", NULL, NULL , "23", "5");
    QTreeWidgetItem *ume = make_root(NULL, "UME", NULL, NULL, "18","10");
    QTreeWidgetItem *cme = make_root(NULL, "CME", NULL, NULL, "15", "12");
    QTreeWidgetItem *other = make_root(NULL, "Other", NULL, NULL, "34","3");

    // + Make each of the categories top level items in the tree widget
    ui->treeWidget_teach->addTopLevelItem(pme);
    ui->treeWidget_teach->addTopLevelItem(ume);
    ui->treeWidget_teach->addTopLevelItem(cme);
    ui->treeWidget_teach->addTopLevelItem(other);


    // + Make new nodes depending on the date range set by the user; again a loop
    //   will be preferred here

    // + Here is an example how a subroot could be added to a main category root
    QTreeWidgetItem *p_year_row = make_child(pme, NULL, "2011", NULL, "34", "45");

    // + Here is adding a child to the sub root just made above
    make_child(p_year_row, NULL, NULL, "Jack Johnson", "45", "100");

    // + Validator to ensure only year values can be entered into the date filter
    QIntValidator *v = new QIntValidator(0, 9999);
    ui->fromDate->setValidator( v );
    ui->toDate->setValidator( v );

    // + Populate the graph combo box with the graph options
    // + This needs to match switch statement in activated function
    ui->graphComboBox_teach->addItem("Stack"); //index 0
    ui->graphComboBox_teach->addItem("Pie"); //index 1
    ui->graphComboBox_teach->addItem("Bar"); //index 2

    graph_values.append(18);
    graph_values.append(45);
    graph_values.append(34);
    graph_values.append(40);

    title_values.append("PME");
    title_values.append("UME");
    title_values.append("CME");
    title_values.append("Other");

    for(int n=0; n<4; n++){
        ui->treeWidget_teach->resizeColumnToContents(n);
    }

    qDebug() << "Using file: " << csv_file_name;

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
QTreeWidgetItem* Summary_Window::make_root(QTreeWidgetItem *parent, QString category, QString date, QString faculty_name,
                           QString num_hours, QString num_students)
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
QTreeWidgetItem * Summary_Window::make_child(QTreeWidgetItem *parent, QString category, QString date, QString faculty_name,
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
 * Function: on_graphComboBox_teach_activated
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Defines the functionality of the combobox that controls
 *   what graphs the user can view
 *
 * PARAMETER:
 * - index: an integer value that represents the index
 *          of the graph chosen
 */
void Summary_Window::on_graphComboBox_teach_activated(int index)
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
    //variable fromYear and to Year defined in header
    //read in the dates
    int tempFrom = (ui->fromDate->text()).toInt();
    int tempTo = (ui->toDate->text()).toInt();
    if(tempFrom > tempTo){
        QMessageBox::warning(this, "Warning", "To Date must fall after From Date");
        ui->fromDate->setText(QString::number(fromYear));
        ui->toDate->setText(QString::number(toYear));
    }
    else{
        fromYear=tempFrom;
        toYear=tempTo;
        //now need to filter
    }
}
