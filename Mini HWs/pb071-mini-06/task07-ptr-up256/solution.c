#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * ptr-up256
 *
 * \author Lukas Rucka
 */

/*
 * Pointers are numbers too, just use another type.
 */

void *ptr_up_256(void *round_me_up)
{
    uintptr_t _round_me_up = (uintptr_t) round_me_up;
    uintptr_t mask = (uintptr_t) 0xff;
    return (void *) ((_round_me_up + 256) & ~mask);
}

int main(void)
{
    void *input = NULL;
    while (scanf("%p", &input) == 1) {
        printf("ptr_up_256(%p) = %p\n", input, ptr_up_256(input));
    }

    return EXIT_SUCCESS;
}
