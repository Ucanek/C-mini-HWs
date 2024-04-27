#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 06: up256b
 * ---------------
 * Author: Lukas Rucka
 * Email:  xrucka@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Implement function up256b which returns the -round_me_up- argument
 * rounded up to nearest strictly higher (>) multiple of 256.
 *
 * You can pass multiple numbers on one line of stdin to compiled binary if you
 * want to further test your solution.
 */

size_t up256b(size_t round_me_up)
{
    /* TODO your code here instead of returning -1 */
    return -1;
}

int main(void)
{
    size_t input = 0;
    while (scanf("%zu", &input) == 1) {
        printf("up256b(%zu) = %zu\n", input, up256b(input));
    }

    return EXIT_SUCCESS;
}
