#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * up256c
 *
 * \author Lukas Rucka
 */

/*
 * Type size_t is an unsigned one, so why not use bitwise operations?
 */

size_t up256(size_t round_me_up)
{
    size_t mask = 0xff;
    return (round_me_up + 256) & ~mask;
}

int main(void)
{
    size_t input = 0;
    while (scanf("%zu", &input) == 1) {
        printf("up256(%zu) = %zu\n", input, up256(input));
    }

    return EXIT_SUCCESS;
}
