#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "summary_window.h"

/*
 * Constructor: Summary_Window
 * -----------------------------------------
 * WHAT THE CONSTRUCTOR DOES:
 * + Defines a QMainWindow that greets the user to what state
 *   they would like to open up the program in
 *
 * PARAMETER:
 * - parent: a reference to the parent widget
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        ui->label_2->setPixmap(QPixmap(":/Run_Images/Images/logo"));
        ui->label_2->show();
}

/*
 * Function: on_new_file_button_clicked
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + On the push of the button the program opens up the
 *   summary window
 * + Indicates new db file needed
 */
void MainWindow::on_new_file_button_clicked()
{
    bool new_file = true;
    Summary_Window s(this, new_file);
    s.setModal(true);
    s.exec();
}

/*
 * Function: on_last_session_button_clicked
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + On the push of the button the program opens up the
 *   summary window
 * + Indicates to use previous file needed
 */
void MainWindow::on_last_session_button_clicked()
{
    bool new_file = false;
    Summary_Window s(this, new_file);
    s.setModal(true);
    s.exec();
}

/*
 * Destory the window when it is closed
 */
MainWindow::~MainWindow()
{
    delete ui;
}


