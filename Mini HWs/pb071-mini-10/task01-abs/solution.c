#include <stdio.h>
#include <stdlib.h>

/**
 * abs
 *
 * \author Sandra Galovičová
 */

/*
 * You can also use abs(), respectively labs() or llabs() functions instead
 * of the expression.
 */

#define ABSOLUTE(x) ((x) < 0 ? -(x) : (x))

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
