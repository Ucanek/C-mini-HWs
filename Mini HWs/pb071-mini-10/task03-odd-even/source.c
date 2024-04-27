#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 10: odd-even
 * ---------------
 * Author: Jakub Hanko
 * Email:  451880@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to implement ODD_EVEN macro which takes one integer argument
 * and prints either "Odd" if the number is odd (liché, párne) or "Even"
 * otherwise.
 *
 * The print should end with a newline.
 */

#define ODD_EVEN(n) ((n % 2 == 1) ? printf("Odd\n") : printf("Even\n"))

int main(void)
{
    ODD_EVEN(5);
    ODD_EVEN(1000);
    ODD_EVEN(0);
    ODD_EVEN(-2);
    return EXIT_SUCCESS;
}
