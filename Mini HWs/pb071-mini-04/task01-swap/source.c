#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 04: Swap
 * ---------------
 * Author: Zoltan Fridrich
 * Email:  xfridri1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Your task is to implement a function that swaps the values of two integer
 * variables.
 *
 * 1. Complete function signature.
 *    The swap function should take two integer pointers as its arguments.
 *
 * 2. Implement the body of function.
 *    Swap the contents of pointers.
 *
 * 3. Call swap function in main.
 *    Pass variables x and y (pointers to them respectively) as arguments.
 *
 * Do not change anything else
 */

void swap(int *pointer1, int *pointer2)
{
    int help_var = *pointer1;
    *pointer1 = *pointer2; 
    *pointer2 = help_var;
}

int main(void)
{
    int *pointer1, *pointer2;
    int x, y;
    printf("Insert x, y values:\n");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Input error occurred\n");
        return EXIT_FAILURE;
    }
    printf("Before swap:\nx = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("After swap:\nx = %d, y = %d\n", x, y);
    return EXIT_SUCCESS;
}
