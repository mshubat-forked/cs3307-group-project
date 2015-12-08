#ifndef GRAPHCOLORS_H
#define GRAPHCOLORS_H

#include <QColor>
#include <QVector>

/*
 * + Creates a QVector that stores a number of QColor objects
 *   equal to the parameter num_elements
 */
QVector<QColor> generate_graph_colors(int num_elements);

#endif // GRAPHCOLORS_H
