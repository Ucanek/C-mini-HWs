#include <stdio.h>
#include <stdlib.h>

/**
 * bin2hex
 *
 * \author Michal Zima
 */

/*
 * Do not add yourself an extra work, the format string can convert for you.
 */

int main(void)
{
    int ch;

    while ((ch = getchar()) != EOF) {
        printf("%02x", (unsigned char) ch);
    }

    return EXIT_SUCCESS;
}
