#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "summary_window.h"

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
