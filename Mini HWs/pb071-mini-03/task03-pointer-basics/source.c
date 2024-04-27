#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 03: Pointer basics
 * ---------------
 * Author: Dominik Dubravický
 * Email:  xdubrav@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Your task is to write the following functions:
 *
 * Function 1: double_value
 * Takes an integer pointer and doubles the value it is pointing to.
 * It does not reurn anything.
 *
 * Function 2: get_value
 * Takes an integer pointer and returns the value it is pointing to.
 *
 * As in task 02, it is again up to you to come up with appropriate
 * function signatures.
 * Lastly, you have to complete the second line in the main function.
 * Do not add or remove anything else from the main function.
 */

void double_value(int *pointer){
    *pointer *= 2;
}

int get_value(int *pointer){
    return *pointer;
}

int main(void)
{
    int a = 50;
    int *p = &a;

    double_value(p);
    printf("%d\n", a);

    a += 6;
    printf("%d\n", get_value(p));

    double_value(p);
    printf("%d %d\n", get_value(p), a);

    return 0;
}
