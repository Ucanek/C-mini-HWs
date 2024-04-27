#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * areaof
 *
 * \author Adam Štěpánek <xstepan1@fi.muni.cz>
 */

/*
 * This is very similar to important concept in OOP (object-oriented
 * programming, you will have enough fun with it in later semesters) called
 * polymorphism:
 * https://cs.wikipedia.org/wiki/Polymorfismus_(programov%C3%A1n%C3%AD)
 */

typedef enum shapes_t
{
    SHAPES_TRIANGLE = 0,
    SHAPES_SQUARE = 1,
    SHAPES_CIRCLE = 2
} shapes;

unsigned area_of_triangle(unsigned side)
{
    return (unsigned) (side * side * sqrt(3) / 4);
}

unsigned area_of_square(unsigned side)
{
    return side * side;
}

unsigned area_of_circle(unsigned radius)
{
    return (unsigned) (radius * radius * acos(-1.0));
}

unsigned (*area_of(shapes shape))(unsigned)
{
    if (shape < 0 || shape > 2) {
        return NULL;
    }
    unsigned (*functions[3])(unsigned) = {
        area_of_triangle,
        area_of_square,
        area_of_circle
    };
    return functions[shape];
}

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
