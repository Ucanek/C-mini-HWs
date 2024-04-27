#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * up256-b
 *
 * \author Lukas Rucka
 */

/*
 * This task as even easier than previous one, because the behaviour
 * does not differ for multiples of 256.
 */

size_t up256b(size_t round_me_up)
{
    // acceptable:
    // for (++round_me_up; round_me_up % 256 != 0; ++round_me_up);

    // welcomed:
    return 256 * ((round_me_up + 256) / 256);
}

int main(void)
{
    size_t input = 0;
    while (scanf("%zu", &input) == 1) {
        printf("up256b(%zu) = %zu\n", input, up256b(input));
    }

    return EXIT_SUCCESS;
}
