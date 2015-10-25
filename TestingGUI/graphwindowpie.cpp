#include "graphwindowpie.h"
#include "ui_graphwindowpie.h"

graphwindowpie::graphwindowpie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graphwindowpie)
{
    ui->setupUi(this);
}

graphwindowpie::~graphwindowpie()
{
    delete ui;
}
