#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 04: Median
 * ---------------
 * Author: Igor Sivý
 * Email:  434088@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 *
 * Implement the median function, which returns a pointer to the median of
 * three values passed in by reference.
 * For more information visit: https://en.wikipedia.org/wiki/Median
 *
 * Hint: Decompose solution to more functions.
 *
 * Do not change anything else except function median.
 */

int *median(int *num1, int *num2, int *num3)
{
    int *pointer = NULL;
    if (*num1 >= *num2 && *num1 <= *num3){
        pointer = num1;
    }
    else if (*num2 >= *num1 && *num2 <= *num3){
        pointer = num2;
    }
    else{
        pointer = num3;
    }
    return pointer;
}

int main(void)
{
    int num1, num2, num3;
    printf("Please insert three numbers:\n");
    if (scanf("%d %d %d", &num1, &num2, &num3) != 3) {
        printf("Input format error\n");
        return EXIT_FAILURE;
    }

    int *result = median(&num1, &num2, &num3);

    printf("Median: %d\n", *result);

    return EXIT_SUCCESS;
}
