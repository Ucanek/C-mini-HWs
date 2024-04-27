#include <stdio.h>
#include <stdlib.h>

void swap(int *fst, int *snd);

/**
 * median
 *
 * \author Igor Sivý
 */

/*
 * This solution puts all values into an array, sorts it and returns
 * the second element.
 * Note: C standard library also contains qsort function for sorting.
 */

int *median(int *num1, int *num2, int *num3)
{
    int *values[3] = {num1, num2, num3};

    if (*values[0] > *values[1]) {
        swap(values[0], values[1]);
    }

    if (*values[0] > *values[2]) {
        swap(values[0], values[2]);
    }

    if (*values[1] > *values[2]) {
        swap(values[1], values[2]);
    }

    return values[1];
}

void swap(int *fst, int *snd)
{
    int tmp = *fst;
    *fst = *snd;
    *snd = tmp;
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
