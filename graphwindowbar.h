#ifndef GRAPHWINDOWBAR_H
#define GRAPHWINDOWBAR_H

#include <QDialog>
#include <qcustomplot.h>
#include <summary_window.h>

struct YearInformationGraph;

namespace Ui {
class graphwindowbar;
}

class graphwindowbar : public QDialog
{
    Q_OBJECT

public:
    explicit graphwindowbar(QWidget *parent = 0, QVector<double> values = {});
    ~graphwindowbar();

private slots:
    void make_bar_graph(YearInformationGraph *pointer, int number_of_years);

private:
    Ui::graphwindowbar *ui;
};

#endif // GRAPHWINDOWBAR_H
