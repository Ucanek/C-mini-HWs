#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 10: Power, div, square
 * --------------
 * Author: Martin Bendel
 * Email: 468932@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to create three different macros:
 *
 * POWER_OF_TWO(x) calculates 2^x
 * DIVIDE_BY_TWO(x) divides x by 2
 * SQUARE(x) squares x, that is calculates x^2
 *
 * To make the task easier (or more difficult?) you should use pow() function
 * from <math.h> library where suitable.
 *
 * You can assume the inputs to these macros being of int type
 */

/* TODO your macro definition here */

// Do not change the following code
int main(void)
{
    printf("%d\n", POWER_OF_TWO(20));
    printf("%d\n", DIVIDE_BY_TWO(20));
    printf("%d\n", SQUARE(5));
    printf("%d\n", SQUARE(POWER_OF_TWO(5)));
    printf("%d\n", DIVIDE_BY_TWO(POWER_OF_TWO(6)));
    printf("%d\n", POWER_OF_TWO(DIVIDE_BY_TWO(6)));
    printf("%d\n", SQUARE(SQUARE(5)));
    printf("%d\n", DIVIDE_BY_TWO(SQUARE(POWER_OF_TWO(4))));
    return EXIT_SUCCESS;
}
