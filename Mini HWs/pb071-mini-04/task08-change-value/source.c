#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 04: Change value
 * ---------------
 * Author: Igor Sivý
 * Email:  434088@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 *
 * Your task is to implement a function change_value which takes two integer
 * pointers and subtracts the smaller value from the larger value.
 *
 * If values are equal, nothing changes.
 *
 * Function does not return anything. Change the value in pointer to greater
 * value.
 *
 * Explore the main function to determine the signature of the function.
 *
 * Do not change anything else except function change_value.
 */

void change_value(int *x, int *y)
{
    if (*x > *y){
        *x -= *y;
    }
    else if (*y > *x){
        *y -= *x;
    }
}

int main(void)
{
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Input format error\n");
        return EXIT_FAILURE;
    }

    printf("Before: x: %d, y: %d\n", x, y);

    change_value(&x, &y);

    printf("After: x: %d, y: %d\n", x, y);

    return EXIT_SUCCESS;
}
