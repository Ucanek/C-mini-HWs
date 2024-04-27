#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI

/*
 * Minihomework 09: Area of shapes
 * ---------------
 * Author: Adam Štěpánek
 * Email:  xstepan1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead. 
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to implement following functions computing areas of given
 * geometric shapes.
 *
 * 1. Implement 'area_of_triangle', 'area_of_square', and 'area_of_circle'.
 * Return the result without its decimal part.
 *
 * For correct functionality use functions and macros from <math.h> library.
 *
 * 2. Write function 'area_of' that generalizes the previous functions by
 * taking the shapes enum as its only parameter and returns a function pointer,
 * which points to the respective previous function.
 * 
 * HINT: Return a function pointer of type 'unsigned (*function(unsigned))'.
 */

// Do not modify this enum.
typedef enum shapes_t
{
    SHAPES_TRIANGLE = 0,
    SHAPES_SQUARE = 1,
    SHAPES_CIRCLE = 2
} shapes;

typedef unsigned (*area_of_shape)(unsigned);

/**
 * Calculates the area of an equilateral triangle.
 */
unsigned area_of_triangle(unsigned side)
{
    return ((pow(side, 2) * sqrt(3)) / 4);
}

/**
 * Calculates the area of a square.
 */
unsigned area_of_square(unsigned side)
{
    return (pow(side, 2));
}

/**
 * Calculates the area of a circle.
 */
unsigned area_of_circle(unsigned radius)
{
    return radius * radius * 3.14;
}

area_of_shape area_of(shapes shape){
    switch (shape){
        case SHAPES_TRIANGLE:
            return area_of_triangle;
        case SHAPES_SQUARE:
            return area_of_square;
        case SHAPES_CIRCLE:
            return area_of_circle;
        default:
            return NULL;
    }
}

//-----------------------------------------------------------------------------
// The main function takes care of the input and calling your 'area_of'
// function. Do not modify it.
int main(void)
{
    shapes shape;
    unsigned dimension;
    int retval;
    while ((retval = scanf("%d %u", (int *) &shape, &dimension)) == 2 && shape >= 0) {
        unsigned (*area_of_shape)(unsigned) = area_of(shape);
        if (area_of_shape) {
            unsigned area = area_of_shape(dimension);
            printf("Area: %u\n", area);
        } else {
            fprintf(stderr, "Invalid shape\n");
        }
    }
    if (retval != EOF && retval != 2) {
        fprintf(stderr, "Invalid input\n");
        return EXIT_SUCCESS; // required by specification for tests
    }
    return EXIT_SUCCESS;
}
