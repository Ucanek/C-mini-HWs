#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 06: up256c
 * ---------------
 * Author: Lukas Rucka
 * Email:  xrucka@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Implement function up256c which returns the -round_me_up- argument
 * rounded up to nearest strictly higher (>) multiple of 256.
 *
 * This time, however, do not use loop of any kind (do..while, while, for,
 * goto, recursion) or / operator.
 *
 * Hint: use either (% and * operators) or (& and ~ operators),
 * not exclusively.
 */

size_t up256(size_t round_me_up)
{
    /* TODO your code here instead of returning -1 */
    return -1;
}

int main(void)
{
    size_t input = 0;
    while (scanf("%zu", &input) == 1) {
        printf("up256(%zu) = %zu\n", input, up256(input));
    }

    return EXIT_SUCCESS;
}
