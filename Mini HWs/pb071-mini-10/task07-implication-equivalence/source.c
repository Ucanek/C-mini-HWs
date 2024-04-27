#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 10: Implication, equivalence
 * ---------------
 * Author: Jakub Hanko
 * Email:  451880@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to implement IMPLICATION and EQUIVALENCE macros. Both of them
 * take 2 bool arguments and behave exactly like their counterparts in
 * propositional logic.
 *
 * You can use only predefined NEGATION and EQUIVALENCE macros.
 */

#define NEGATION(x) (!x)
#define CONJUNCTION(x, y) (x && y)

#define IMPLICATION(x, y) false /* TODO your code here instead of false */
#define EQUIVALENCE(x, y) false /* TODO your code here instead of false */

int main(void)
{
    bool x = true;
    bool y = false;
    printf("%d\n", IMPLICATION(x, y));
    printf("%d\n", IMPLICATION(x, x));
    printf("%d\n", IMPLICATION(y, y));
    printf("%d\n", IMPLICATION(y, x));
    printf("%d\n", IMPLICATION(IMPLICATION(x, y), x));
    printf("%d\n", IMPLICATION(x, IMPLICATION(x, y)));
    printf("%d\n", EQUIVALENCE(x, y));
    printf("%d\n", EQUIVALENCE(x, x));
    printf("%d\n", EQUIVALENCE(y, y));
    printf("%d\n", EQUIVALENCE(y, x));
    printf("%d\n", EQUIVALENCE(EQUIVALENCE(x, x), y));
    printf("%d\n", EQUIVALENCE(x, EQUIVALENCE(x, y)));
    return EXIT_SUCCESS;
}
