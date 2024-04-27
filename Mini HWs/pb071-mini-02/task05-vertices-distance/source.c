#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 02: Vertices distance
 * ---------------
 * Author: Samuel Gorta
 * Email:  samuel.gorta@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Implement function vertices_distance which counts Euclidean distance
 * between vertices A and B in two-dimensional space.
 * Arguments a_x, a_y are coordinates of vertex A;
 * b_x, b_y are coordinates of vertex B.
 * Distance is always non-negative number.
 * Use (kindly) provided function square_root below.
 */

// do not change this line:
double square_root(double n);

double vertices_distance(double a_x, double a_y, double b_x, double b_y)
{
    double distance_x = a_x - b_x;
    double distance_y = a_y - b_y;
    double distance_AB;
    if (distance_x < 0){
        distance_x = distance_x * (-1);
    }
    if (distance_y < 0){
        distance_y = distance_y * (-1);
    }
    double n = (distance_x * distance_x) + (distance_y * distance_y);
    distance_AB = square_root(n);
    return distance_AB;
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
