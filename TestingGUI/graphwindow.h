#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <qcustomplot.h>
#include <summarywindow.h>

struct YearInformationGraph;

namespace Ui {
class graphwindow;
}

class graphwindow : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindow(QWidget *parent = 0);
    ~graphwindow();

private slots:
    void make_stacked_bar_graph(YearInformationGraph *pointer, int number_of_years);

private:
    Ui::graphwindow *ui;
};

#endif // GRAPHWINDOW_H
