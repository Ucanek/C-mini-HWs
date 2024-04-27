#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * Minihomework 06: Pointer up256
 * ---------------
 * Author: Lukas Rucka
 * Email:  xrucka@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Implement function ptr_up_256 which returns the -round_me_up- argument
 * rounded up to nearest strictly higher (>) multiple of 256.
 *
 * Do not use any form of loop (do..while, while, for, goto, recursion),
 * and operating on pointers.
 *
 * Round the value of pointer, not the value it contains (it will most probably
 * be uninitialized)!
 *
 * Hint: use uintptr_t
 */

void *ptr_up_256(void *round_me_up)
{
    // todo
    return NULL;
}

int main(void)
{
    void *input = NULL;
    while (scanf("%p", &input) == 1) {
        printf("ptr_up_256(%p) = %p\n", input, ptr_up_256(input));
    }

    return EXIT_SUCCESS;
}
