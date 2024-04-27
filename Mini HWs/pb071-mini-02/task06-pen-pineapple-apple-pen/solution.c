#include <stdio.h>
#include <stdlib.h>

/**
 * PPAP
 *
 * \author Marko Řeháček
 */

/*
 * A simple use of modulo operator.
 * Note: In this solution, it is not necessary to care
 * about the case of i % 15 == 0 as it triggers both if statements.
 */

int main(void)
{
    for (int i = 1; i < 106; i++) {
        if (i % 3 == 0) {
            printf("PenPineapple");
        }
        if (i % 5 == 0) {
            printf("ApplePen");
        }
        if (i % 3 != 0 && i % 5 != 0) {
            printf("%d", i);
        }
        putchar(' ');
    }
    return EXIT_SUCCESS;
}
