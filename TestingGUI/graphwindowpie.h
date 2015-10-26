#ifndef GRAPHWINDOWPIE_H
#define GRAPHWINDOWPIE_H

#include <QDialog>
#include <qcustomplot.h>
#include <summarywindow.h>

struct YearInformationGraph;

namespace Ui {
class graphwindowpie;
}

class graphwindowpie : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindowpie(QWidget *parent = 0);
    ~graphwindowpie();

private slots:
    void make_bar_graph(YearInformationGraph *pointer, int number_of_years);

private:
    Ui::graphwindowpie *ui;
};

#endif // GRAPHWINDOWPIE_H
