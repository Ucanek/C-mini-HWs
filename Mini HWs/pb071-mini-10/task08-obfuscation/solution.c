#include <stdio.h>
#include <stdlib.h>

/**
 * obfuscation
 *
 * \author Dominik Jochec
 */

/*
 * Defining macros like this does not really shorten the code nor make it
 * easier to understand, so do not use them just because "we learned about
 * them in lecture"!
 */

#define S "ad!vrfdlog wjlHe"
#define EXTRACT(string, index) (printf("%c", string[index]))

int main(void)
{
    EXTRACT(S, 14);
    EXTRACT(S, 15);
    EXTRACT(S, 13);
    EXTRACT(S, 13);
    EXTRACT(S, 8);
    EXTRACT(S, 10);
    EXTRACT(S, 11);
    EXTRACT(S, 8);
    EXTRACT(S, 4);
    EXTRACT(S, 13);
    EXTRACT(S, 6);
    EXTRACT(S, 2);
    return EXIT_SUCCESS;
}
