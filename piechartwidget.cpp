/*
 * Source File: piechartwidget
 * --------------------------------
 * Define a widget that draws a pie chart to the screen
 */

#include "piechartwidget.h"
#include "graphcolors.h"
#include <QPainter>

PieChartWidget::PieChartWidget(QWidget *parent) : QWidget(parent){}


/*
 * Function: create_pie_graph
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Captures parameters to assign to global variabes
 * + Paint the pie chart to the screen
 *
 * PARAMETER LIST:
 * - values: the data to represent on the pie graph
 * - colors: the colours to make the pie slices
 *
 */
void PieChartWidget::create_pie_graph(QVector<double> values, QVector<QColor> colors)
{
    // + Capture and store in a global variables so
    //   it can be accessed by the paintEvent
    graph_values = values;
    graph_colors = colors;

    // + Force the control to repaint the image to the screen
    repaint();

    // + Process any pending paint images immediately
    update();
}

/*
 * Function: paintEvent
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Draws a pie graph to screen.  Each piece of the pie graph
 *   is created using information from a global variable 'graph_values'
 *   and are coloured by using a helper function 'generate_graph_colors'
 *   kept in the 'graphcolors' class
 *
 * PARAMETER LIST:
 * - QPaintEvent * is the region that shall be painted
 *
 */
void PieChartWidget::paintEvent(QPaintEvent *)
{

    // + Define drawing objects
    QPainter painter(this);
    QPen pen;
    QRectF size;

    // + Get the all the colours for the pie slices
    QVector<QColor> pie_slice_colours = graph_colors;

    // + Set the height and width of the graph to the smaller value between width
    //   and height.  This is done so the graph will always fit in the dialog window
    if(this->height() > this->width())
    {
        size = QRectF(5,5,this->width()-10, this->width()-10);
    }

    else
    {
        size = QRectF(5,5,this->height()-10, this->height()-10);
    }

    // + The summation of the numeric information to be display on the graph
    double sum = 0.0;

    // + The angle to start the current pie piece from
    double starting_angle = 0.0;

    // + The amount of angle a pie peice takes up on the graph
    double angle;

    // + The angle where a pie piece ends
    double ending_angle;

    // + What percentage a pie piece takes up on he pie graph
    double percent;

    // + Gather the sum
    for(int i = 0; i < graph_values.size(); i++)
    {
        sum += graph_values[i];
    }

    // + Put the pie graph together
    for(int i = 0; i < graph_values.size(); i++)
    {

        // + Determine how much a piece will take up of the pie graph
        percent = graph_values[i] / sum;

        // + Get an angle that is represents the percentage of a piece
        angle = percent*360.0;

        // + Determnine where that piece's angle will end
        ending_angle = starting_angle + angle;

        // + Set colour information for the piece
        pen.setColor(pie_slice_colours[i]);
        pen.setWidth(2);
        painter.setPen(pen);
        QColor temp_color = pie_slice_colours[i];
        temp_color.setAlpha(150);
        painter.setBrush(temp_color);

        // + Draw the piece to the screen
        painter.drawPie(size,starting_angle*16, angle*16);

        // + Start the next piece from where the current piece ends
        starting_angle = ending_angle;
    }
}

