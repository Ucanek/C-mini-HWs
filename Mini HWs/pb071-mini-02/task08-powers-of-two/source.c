#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Minihomework 02: Powers of 2
 * ---------------
 * Author: Samuel Gorta
 * Email:  samuel.gorta@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Write program that prints first n powers of 2.
 * Each power (including the last one) should be followed by single space.
 * Example output for n = 10: "1 2 4 8 16 32 64 128 256 512 "
 */

void powers_of_two(int n)
{
    int result;
    for (int i = 0; i <= n; i++){
        result = pow(2, i);
        printf("%d", result);
        printf("\n");
    }
    printf("\n");
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
