#include <stdio.h>
#include <stdlib.h>

/**
 * swap
 *
 * \author Zoltan Fridrich
 */

/*
 * You do not need another variable when exchanging values of x and y
 * if you use XOR, but the computation is slower.
 * Note: You cannot use adding, because the result may exceed
 * the upper limit of int type and lead to undefined behaviour.
 */

void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main(void)
{
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
