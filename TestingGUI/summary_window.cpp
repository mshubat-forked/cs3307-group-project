#include "summary_window.h"
#include "ui_summary_window.h"
#include <graphwindow.h>
#include <graphwindowpie.h>
#include <QTextStream>

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
    QTreeWidgetItem *pme = make_root(NULL, "PME", NULL, NULL , "1620", "808");
    QTreeWidgetItem *ume = make_root(NULL, "UME", NULL, NULL, "1500", "498");
    QTreeWidgetItem *cme = make_root(NULL, "CME", NULL, NULL, "1200", "300");
    QTreeWidgetItem *other = make_root(NULL, "Other", NULL, NULL, "800", "121");

    // + Make each of the categories top level items in the tree widget
    ui->treeWidget->addTopLevelItem(pme);
    ui->treeWidget->addTopLevelItem(ume);
    ui->treeWidget->addTopLevelItem(cme);
    ui->treeWidget->addTopLevelItem(other);

    // + Make new nodes depending on the date range set by the user; again a loop
    //   will be preferred here

    // + Here is an example how a subroot could be added to a main category root
    QTreeWidgetItem *year_1 = make_child(pme, NULL, "2012", NULL, "500", "250");

    // + Here is adding a child to the sub root just made above
    make_child(year_1, NULL, NULL, "Dr.Watson", "125", "120");

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
    ui->graphComboBox->addItem("Bar Graph"); //index 0
    ui->graphComboBox->addItem("Pie Graph"); //index 1
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
    case 0: //bar graph
        graph_window = new graphwindow(this);
        graph_window->show();
        break;
    case 1: //pie graph
        graph_pie_window = new graphwindowpie(this);
        graph_pie_window->show();
        break;
    default:
        break;
    }
}
