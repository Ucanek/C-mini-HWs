#include <stdio.h>
#include <stdlib.h>

/**
 * min-max
 *
 * \author Dominik Jochec
 */

/*
 * For avoiding unexpected (and unwanted) behaviour which may occur after
 * textual replacement of the macro in code, it is desired to enclose its
 * definition in parentheses.
 */

#define MIN(a, b) ((a < b) ? (a) : (b))
#define MAX(a, b) ((a > b) ? (a) : (b))

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
