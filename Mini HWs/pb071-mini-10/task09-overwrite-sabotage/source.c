#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Minihomework 10: Overwrite sabotage
 * ---------------
 * Author: Jakub Hanko
 * Email:  451880@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to overwrite the function strcmp so that it always returns 0,
 * so that all strings are equal!
 *
 */

#define strcmp(x, y) strcmp(x, y) /* TODO your code here instead of the second strcmp */

int main(void)
{
    printf("%d\n", strcmp("abc", "abc"));
    printf("%d\n", strcmp("This task is stupid", "It really is"));
    return EXIT_SUCCESS;
}
