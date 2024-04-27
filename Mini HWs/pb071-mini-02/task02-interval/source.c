#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 02: Interval
 * ---------------
 * Author: Samuel Gorta
 * Email:  samuel.gorta@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Write function void interval(int from, int to),
 * that prints out all numbers in interval <from, to>.
 * Numbers are separated by 1 space. Last number is also followed by space.
 * Examples: 
 * interval(1, 20) outputs:
 * "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 "
 * interval(10, 18) outputs:
 * "10 11 12 13 14 15 16 17 18 "
 */

void interval(int from, int to)
{
    if (from <= to){
        for (int i = from; i <= to; i++){
            printf("%d ", i);
        }
        printf("\n");
    } else {
        for (int i = from; i >= to; i--){
            printf("%d ", i);
        }
        printf("\n");
    }

}

// do not change following code!
int main(void)
{
    interval(1, 20);
    interval(10, 18);
    interval(13, 27);
    interval(42, 41);
    interval(68, 68);
    return EXIT_SUCCESS;
}
