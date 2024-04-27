#include <stdio.h>
#include <stdlib.h>

/**
 * Vertices distance
 *
 * \author Samuel Gorta
 */

/*
 * You should use the Pythagorean theorem here.
 * Note: Do not worry about dx or dy being negative,
 * they are both squared afterward.
 */

double square_root(double n);

double vertices_distance(double a_x, double a_y, double b_x, double b_y)
{
    double dx = a_x - b_x;
    double dy = a_y - b_y;
    return square_root(dx * dx + dy * dy);
}

// do not change following code!
double square_root(double n)
{
    double lo = 0, hi = n, mid = 0;
    for (int i = 0; i < 1000; i++) {
        mid = (lo + hi) / 2;
        if (mid * mid == n) {
            return mid;
        }
        if (mid * mid > n) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return mid;
}

int main(void)
{
    printf("%0.4lf\n", vertices_distance(0, 0, 0, 0));
    printf("%0.4lf\n", vertices_distance(0, 0, 0, 22));
    printf("%0.4lf\n", vertices_distance(1, 1, 2, 2));
    printf("%0.4lf\n", vertices_distance(2, 2, 1, 1));
    printf("%0.4lf\n", vertices_distance(7, 8, 1, 1));
    return EXIT_SUCCESS;
}
