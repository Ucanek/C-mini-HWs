#include <stdio.h>
#include <stdlib.h>

/**
 * range
 *
 * \author Sandra Galovičová
 */

/*
 * You can create also "incomplete" constructions with macros.
 * Note: "from" is not a keyword in C language (in Python it is).
 */

#define RANGE(i, from, to, step) for (i = from; i <= (to); i = i + (step))

int main(void)
{
    int x = 0;
    RANGE(x, 10, 20, 2)
    {
        printf("%d ", x);
    }
    printf("\n");
    RANGE(x, 0, 1, 2)
    {
        printf("%d ", x);
    }
    printf("\n");
    RANGE(x, 1, 30, 3)
    {
        printf("%d ", x);
    }
    printf("\n");
    RANGE(x, 10, 100, 10)
    {
        printf("%d ", x);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
