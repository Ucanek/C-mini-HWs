#include <stdio.h>
#include <stdlib.h>

/**
 * Interval
 *
 * \author Samuel Gorta
 */

/*
 * Simple for loop for printing the iteration numbers.
 * Note: The numbers do not need to be saved anywhere (apart from i)
 * before printing.
 * Note: The loop variable i can be declared and initialized
 * inside the for statement (same for the others).
 */

void interval(int from, int to)
{
    for (int i = from; i <= to; i++) {
        printf("%d ", i);
    }
}

int main(void)
{
    interval(1, 20);
    interval(10, 18);
    interval(13, 27);
    interval(42, 41);
    interval(68, 68);
    return EXIT_SUCCESS;
}
