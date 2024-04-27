#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 10: Absolute Value
 * ---------------
 * Author: Sandra Galovičová
 * Email:  469302@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to define macro ABSOLUTE(x) which computes the absolute value
 * of the given number.
 */

#define ABSOLUTE(x) ((x < 0) ? -x : x)

int main(void)
{
    printf("%d ", ABSOLUTE(5));
    printf("%d ", ABSOLUTE(-5));
    printf("%d ", ABSOLUTE(0));
    printf("%d ", ABSOLUTE(45892));
    printf("%d ", ABSOLUTE(-341234));
    printf("%d ", ABSOLUTE(-7239748));
    printf("%d ", ABSOLUTE(-1 + 9));
    printf("%d ", ABSOLUTE(46739 * -133));
    printf("%d", ABSOLUTE(-1));
    return EXIT_SUCCESS;
}
