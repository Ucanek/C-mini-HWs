#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * implication-equivalence
 *
 * \author Jakub Hanko
 */

/*
 * Macros can be nested, the only requirement is that macros used inside
 * must be defined earlier.
 */

#define NEGATION(x) (!x)
#define CONJUNCTION(x, y) (x && y)

#define IMPLICATION(x, y) (NEGATION(CONJUNCTION(x, NEGATION(y))))

#define EQUIVALENCE(x, y) (CONJUNCTION(IMPLICATION(x, y), IMPLICATION(y, x)))

int main(void)
{
    bool x = true;
    bool y = false;
    printf("%d\n", IMPLICATION(x, y));
    printf("%d\n", IMPLICATION(x, x));
    printf("%d\n", IMPLICATION(y, y));
    printf("%d\n", IMPLICATION(y, x));
    printf("%d\n", IMPLICATION(IMPLICATION(x, y), x));
    printf("%d\n", IMPLICATION(x, IMPLICATION(x, y)));
    printf("%d\n", EQUIVALENCE(x, y));
    printf("%d\n", EQUIVALENCE(x, x));
    printf("%d\n", EQUIVALENCE(y, y));
    printf("%d\n", EQUIVALENCE(y, x));
    printf("%d\n", EQUIVALENCE(EQUIVALENCE(x, x), y));
    printf("%d\n", EQUIVALENCE(x, EQUIVALENCE(x, y)));
    return EXIT_SUCCESS;
}
