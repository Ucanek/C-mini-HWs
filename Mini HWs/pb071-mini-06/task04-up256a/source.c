#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 06: up256a
 * ---------------
 * Author: Lukas Rucka
 * Email:  xrucka@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Implement function up256a which returns the -round_me_up- argument
 * rounded up to nearest higher or equal (>=) multiple of 256.
 *
 * You can pass multiple numbers on one line of stdin to compiled binary if you
 * want to further test your solution.
 */

size_t up256a(size_t round_me_up)
{
    int multiples = round_me_up / 256;
    int rest = round_me_up - multiples * 256;
    if (rest < 128){
        return multiples * 256;
    }
    return (multiples + 1) * 256;
}

int main(void)
{
    size_t input = 0;
    while (scanf("%zu", &input) == 1) {
        printf("up256a(%zu) = %zu\n", input, up256a(input));
    }

    return EXIT_SUCCESS;
}
