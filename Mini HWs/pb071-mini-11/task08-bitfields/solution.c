#include <stdio.h>
#include <stdlib.h>

/**
 * bitfields
 *
 * \author Peter Navrátil
 */

/*
 * Bitfields are much more space-effective than arrays, which are commonly
 * (at least in PB071 homeworks :) ) used instead to pass arguments.
 */

void convert(unsigned value)
{
    unsigned cursor;
    for (unsigned i = 0; i < 8; i++) {
        cursor = 1U << i;
        if (cursor & value) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

int main(void)
{
    unsigned count;
    if (scanf("%u", &count) != 1) {
        fputs("File reading error\n", stderr);
        return EXIT_FAILURE;
    }
    for (unsigned i = 0; i < count; i++) {
        unsigned value;
        if (scanf("%u", &value) != 1) {
            fputs("File reading error\n", stderr);
            return EXIT_FAILURE;
        }
        convert(value);
        printf("\n");
    }
    return EXIT_SUCCESS;
}
