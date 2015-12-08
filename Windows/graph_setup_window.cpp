#include "Windows/graph_setup_window.h"
#include "ui_graph_setup_window.h"

graph_setup_window::graph_setup_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph_setup_window)
{
    ui->setupUi(this);
}

graph_setup_window::~graph_setup_window()
{
    delete ui;
}
