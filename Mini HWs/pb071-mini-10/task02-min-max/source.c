#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 10: MIN-MAX
 * ---------------
 * Author: Dominik Jochec
 * Email:  456673@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to define two macros MIN and MAX, that, given 2 numbers, choose
 * the smaller/larger one.
 */

#define MIN(x, y) ((x < y) ? x : y)
#define MAX(x, y) ((x > y) ? x : y)

// Do not modify the following code!
int main(void)
{
    printf("%d ", MIN(1, 0));
    printf("%d ", MIN(-555, 555));
    printf("%d ", MIN(262, -42));
    printf("%d ", MAX(50000, -768));
    printf("%d ", MAX(-97564, 982));
    printf("%d", MAX(6794, 5612387));
    return EXIT_SUCCESS;
}
