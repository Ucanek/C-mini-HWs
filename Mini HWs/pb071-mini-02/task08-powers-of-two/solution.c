#include <stdio.h>
#include <stdlib.h>

/**
 * Powers of 2
 *
 * \author Samuel Gorta
 */

/*
 * Do not compute 2 ** i each time, multiply the previous power by two.
 */

void powers_of_two(int n)
{
    int current = 1;
    for (int i = 0; i < n; i++) {
        printf("%d ", current);
        current *= 2;
    }
}

// do not change following code!
int main(void)
{
    powers_of_two(10);
    powers_of_two(0);
    powers_of_two(19);
    powers_of_two(1);
    powers_of_two(11);
    return EXIT_SUCCESS;
}
