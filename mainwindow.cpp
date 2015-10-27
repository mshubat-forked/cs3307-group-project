#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "summary_window.h"

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
    Summary_Window s(this);
    s.setModal(true);
    s.exec();
}
