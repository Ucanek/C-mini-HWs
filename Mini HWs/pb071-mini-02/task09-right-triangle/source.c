#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 02: Right triangle
 * ---------------
 * Author: Roman Chrenšť
 * Email:  469253@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Implement a function which calculates the area of the square above
 * the hypotenuse (=přepona) of a right (=pravoúhlý) triangle.
 *
 * First, validate input. None of the sides can have negative or zero length,
 * otherwise return -1 right away.
 * Assume c represents hypotenuse and a, b represent the other two sides.
 * Check rightness of triangle using Pythagorean theorem, otherwise return -1.
 * Return area of the square (a squared plus b squared).
 */

int right_triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0){
        return -1;
    }
    if (a*a + b*b == c*c){
        return c*c;
    }
    else{
        return -1;
    }
}

// do not change following code!
int main(void)
{
    printf("%d ", right_triangle(3, 4, 5));
    printf("%d ", right_triangle(1, -4, 5));
    printf("%d ", right_triangle(0, 5, 5));
    printf("%d ", right_triangle(9, 12, 15));
    printf("%d ", right_triangle(1, 13, 13));
    printf("%d\n", right_triangle(2, 2, 5));
    return EXIT_SUCCESS;
}
