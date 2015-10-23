#include "summarywindow.h"
#include "ui_summarywindow.h"

SummaryWindow::SummaryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SummaryWindow)
{
    ui->setupUi(this);
}

SummaryWindow::~SummaryWindow()
{
    delete ui;
}

