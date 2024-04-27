#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 10: obfuscation
 * ---------------
 * Author: Dominik Jochec
 * Email:  456673@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is, using just macros `S` and `EXTRACT`, to print `Hello world!`.
 */

#define S "ad!vrfdlog wjlHe"
#define EXTRACT(string, index) (printf("%c", string[index]))

int main(void)
{
    /* TODO your code here */
    return EXIT_SUCCESS;
}
