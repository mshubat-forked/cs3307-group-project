#include "summary_window.h"
#include "ui_summary_window.h"
#include <graphwindow.h>
#include <graphwindowpie.h>
#include <QTextStream>

struct TeachingField
{
    QString member_name;
    int date;
    QString program;
    double hours;
    int students;
};

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

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

    // + Create roots for the 4 main program heads: CME, UME, PME, and Other
    // + Ideally this would be done with a loop

    TeachingField *p_tf = make_list_information();


    QTreeWidgetItem *pme = make_root(NULL, "PME", NULL, NULL , QString::number(p_tf[0].hours), QString::number(p_tf[0].students));
    QTreeWidgetItem *ume = make_root(NULL, "UME", NULL, NULL, QString::number(p_tf[1].hours), QString::number(p_tf[1].students));
    QTreeWidgetItem *cme = make_root(NULL, "CME", NULL, NULL, QString::number(p_tf[2].hours), QString::number(p_tf[2].students));
    QTreeWidgetItem *other = make_root(NULL, "Other", NULL, NULL, QString::number(p_tf[3].hours), QString::number(p_tf[3].students));

    // + Make each of the categories top level items in the tree widget
    ui->treeWidget->addTopLevelItem(pme);
    ui->treeWidget->addTopLevelItem(ume);
    ui->treeWidget->addTopLevelItem(cme);
    ui->treeWidget->addTopLevelItem(other);

    // + Make new nodes depending on the date range set by the user; again a loop
    //   will be preferred here

    // + Here is an example how a subroot could be added to a main category root
    QTreeWidgetItem *p_year_row = make_child(pme, NULL, QString::number(p_tf[1].date), NULL, QString::number(p_tf[1].hours), QString::number(p_tf[1].students));

    // + Here is adding a child to the sub root just made above
    make_child(p_year_row, NULL, NULL, p_tf[1].member_name, QString::number(p_tf[1].hours), QString::number(p_tf[1].students));

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
}

// + Makes a top level root item for the tree widget
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

// + Makes sub items to the root items on the tree widget
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

Summary_Window::~Summary_Window()
{
    delete ui;
}

void Summary_Window::on_fromDateCombo_activated(const QString &arg1)
{
    //checks to make sure from date is before to date
    if((ui->toDateCombo->currentText()).toInt() < arg1.toInt()){
        //gives warning and sets box back to previous index
        QMessageBox::warning(this, "Warning", "From Date must fall before To Date");
        ui->fromDateCombo->setCurrentIndex(fromDateIndex);
    }
    else{
        fromDateIndex = ui->fromDateCombo->currentIndex();
        //then get the selected year value using: arg1.toInt() to pass to filter function
    }
}

void Summary_Window::on_toDateCombo_activated(const QString &arg1)
{
    //checks to make sure to date is before from date
    if(arg1.toInt() < (ui->fromDateCombo->currentText()).toInt()){
        //gives warning and sets box back to previous index
        QMessageBox::warning(this, "Warning", "To Date must fall after From Date");
        ui->toDateCombo->setCurrentIndex(toDateIndex);
    }
    else{
        toDateIndex = ui->toDateCombo->currentIndex();
        //then get the selected year value using: arg1.toInt() to pass to filter function
    }
}

void Summary_Window::on_graphComboBox_activated(int index)
{
    switch(index){
    case 0: //stack bar graph
        graph_window = new graphwindow(this);
        graph_window->show();
        break;
    case 1: //pie graph
        graph_pie_window = new graphwindowpie(this);
        graph_pie_window->show();
        break;
    case 2: //pain bar graph
        graph_bar_window = new graphwindowbar(this);
        graph_bar_window->show();
    default:
        break;
    }
}

TeachingField * Summary_Window::make_list_information(){


    QString temp_names[] = {"Malcomson, Paul","Dragon, Smaug","Smith, Drew","Strangelove, Dr.","Snuffleupagus, Mr","Baggins, "
                            "Bilbo","Parker Peter","Schwarzenegger, Arnold","Harper, Stephen","Larson, Gary"}; //10

    int temp_years[] = {2010,2010,2011,2011,2012,2012,2013,2013,2014,2014}; //10
    QString temp_program[] = {"PME","UME","CME","Other", "PME", "PME", "UME", "CME","Other","UME"};//10
    double temp_hours[] = {1.5,1,2.5,7,8,10,3,2,1.4,1,2,6,6,4.5,1.2,3,4,12}; //20
    int temp_students[] = {3,14,20,7,8,1,13,23,56,8,9,10,11,12,38,12,3,2,7,8}; //20



    // + Create an pointer to an array of YearInformationGraph items
    // + Set the size of the array to the number of years in the range
    // + Ie. A range of 2009, 2010, 2011 would set the size of
    //   the array to 3 (with help fro mthe ARRAY_SIZE marco
    TeachingField *p_tf = new TeachingField[ARRAY_SIZE(temp_names)];

    for (int i = 0; i < (int)ARRAY_SIZE(temp_names); i++)
    {
        p_tf[i].member_name = temp_names[i];
        p_tf[i].date = temp_years[i];
        p_tf[i].program = temp_program[i];
        p_tf[i].hours = temp_hours[i];
        p_tf[i].students = temp_students[i];
    }

 return p_tf;
}

// + This function will be eventually be used for calculating totals for hours and students
int Summary_Window::make_program_totals(TeachingField *pointer, int array_size)
{



}
