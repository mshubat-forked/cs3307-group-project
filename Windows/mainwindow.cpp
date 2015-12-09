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

    QPixmap pix("/Users/SamirahSiddiq/Desktop/Schulich and Western");

          ui ->label_2->setPixmap(pix);

      //  QSplashScreen *splash = new QSplashScreen;
        // splash ->setPixmap(QPixmap("/Users/SamirahSiddiq/Desktop/schulich_pic.jpg"));
         // splash->show();

          //QBrush brush = new QBrush();
            //QPixmap pixmap("/Users/SamirahSiddiq/Desktop/schulich_pic.jpg");
            //brush->setTexture(pixmap);
          //ui ->label_3-> setAutoFillBackground(brush);


          }



/*
 * Function: Summary_Window
 * -----------------------------------------
 * WHAT THE FUNCTION DOES:
 * + On the push of the button the program opens up the
 *   summary window
 */
void MainWindow::on_new_file_button_clicked()
{
    bool new_file = true;
    Summary_Window s(this, new_file);
    s.setModal(true);
    s.exec();
}

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


