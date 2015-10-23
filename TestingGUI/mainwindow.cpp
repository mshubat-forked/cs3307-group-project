#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "summarywindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SummaryWindow s;
    s.setWindowModality(Qt::ApplicationModal);
    s.show();
    
}
