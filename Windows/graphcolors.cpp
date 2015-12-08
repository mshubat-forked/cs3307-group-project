/*
 * Source file: graphcolors.cpp
 * ---------------------------------
 * + Defines a helper function generate_graph_colors()
 */

#include "graphcolors.h"
#include <ctime>

// Defines the total number of RGB values
#define RGB_TOTAL 3

/*
 * Function: generate_graph_colors
 * ------------------------------------
 * WHAT THE FUNCTION DOES:
 * + Creates a QVector that stores QColor values.  These QColor values are made
 *   up of 3 randomly generated integers and a forth perdefined alpha value.
 *   The passed parameter 'num_elements' dictates how many colours will be generated.
 *   Ie. if num_elements is 5, five colours will be created and store in the QVector.
 *
 * PARAMETER LIST:
 * - num_elements: an integer that defines the number of bars or
 *                 pie slices that we need a colour for
 *
 * RETURNS:
 * + A QVector storing QColor values
 */
QVector<QColor> generate_graph_colors(int num_elements)
{

    // The QVector that will store of the generated colours
    QVector<QColor> all_the_colors(4);

    // Stores the individual integers that represent either red, green, or blue (RGB)
    QVector<int> new_color(3);

    // Randomize the value based on time
    srand(time(0));

    // Loop for the number of colours needed (as defined by num_elements)
    for(int i = 0; i < num_elements; i++)
    {

        // Loop 3 times to generate the seperate integers for red, green and blue
        for(int j = 0; j < RGB_TOTAL; j++)
        {
            // Randomy create an rgb integer value
            int rgb_value = rand()%255+0;

            // Fill the QVector that keeps together the rgb values of an indivdual color
            new_color.append(rgb_value);
        }

        // Add a newly created colour to the QVector to return
        all_the_colors[i] = QColor(new_color[0], new_color[1], new_color[2], 255);

        // Clear the QVector so it can store three new RGB values
        new_color.clear();
    }
    // For some reason the first iteration through the loop to generate colours always generates 0 0 0
    // Doing this line afterward sets the first colour value to something other then black all the time
    all_the_colors[0] = QColor(rand()%255+0, rand()%255+0, rand()%255+0, 255);


    return all_the_colors;
}

