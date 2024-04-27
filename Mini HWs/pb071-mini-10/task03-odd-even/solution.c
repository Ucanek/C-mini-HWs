#include <stdio.h>
#include <stdlib.h>

/**
 * odd-even
 *
 * \author Jakub Hanko
 */

/*
 * Note the format of macro names - it should be written in
 * UNDERSCORE_UPPERCASE.
 */

#define ODD_EVEN(n) ((n) % 2) == 0 ? puts("Even") : puts("Odd")

int main(void)
{
    ODD_EVEN(5);
    ODD_EVEN(1000);
    ODD_EVEN(0);
    ODD_EVEN(-2);
    return EXIT_SUCCESS;
}
