#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include "graphcolors.h"
#include <QWidget>

class PieChartWidget : public QWidget
{
    Q_OBJECT

public:
    // Intializes a PieChartWidget
    explicit PieChartWidget(QWidget *parent = 0);

    // Create a pie graph with the passed parameter 'values'
    void create_pie_graph(QVector<double> values, QVector<QColor> colors);

protected:
    void paintEvent(QPaintEvent *);

private:
    // Defines a the values to the graph
    QVector<double> graph_values;

    // Defines the colors to make pieces of the graph
    QVector<QColor> graph_colors;

signals:

public slots:
};

#endif // PIECHARTWIDGET_H
