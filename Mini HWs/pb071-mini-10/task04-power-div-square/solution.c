#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * power-div-square
 *
 * \author Martin Bendel
 */

/*
 * You should not use bitwise << operator since it may lead to undefined
 * behaviour with signed integers.
 */

#define POWER_OF_TWO(n) ((int) pow(2, n))
#define DIVIDE_BY_TWO(n) ((int) ((n) / 2))
#define SQUARE(n) ((int) pow(n, 2))

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
