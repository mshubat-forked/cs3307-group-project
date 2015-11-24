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

    QPixmap pix("/Users/SamirahSiddiq/Desktop/Schulich and Western.jpg");

          ui ->label_2->setPixmap(pix);
}

/*
 * Function: Summary_Window
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + On the push of the button the program opens up the
 *   summary window
 */
void MainWindow::on_pushButton_clicked()
{
    Summary_Window s(this);
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
