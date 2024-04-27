#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * up256a
 *
 * \author Lukas Rucka
 */

/*
 * Looping by one is not ideal solution of this task, better use integer
 * division.
 */

size_t up256a(size_t round_me_up)
{
    // acceptable:
    // for (; round_me_up % 256 != 0; ++round_me_up);

    // welcomed:
    return 256 * ((round_me_up + 256 - 1) / 256);
}

int main(void)
{
    size_t input = 0;
    while (scanf("%zu", &input) == 1) {
        printf("up256a(%zu) = %zu\n", input, up256a(input));
    }

    return EXIT_SUCCESS;
}
