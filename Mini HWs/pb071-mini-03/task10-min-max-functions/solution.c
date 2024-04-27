#include <stdio.h>
#include <stdlib.h>

/**
 * min-max-functions
 *
 * \author Stanislav Soták
 */

/*
 * You have to pass the size argument to the function, otherwise C does
 * not know how big is the given array (it only has a pointer to first element).
 * Note: type unsigned is equal to an unsigned int.
 */

int minimum(int *array, unsigned size)
{
    int min = array[0];
    for (unsigned i = 0; i < size; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int maximum(int *array, unsigned size)
{
    int max = array[0];
    for (unsigned i = 0; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int main(void)
{
    int numbers[100];
    for (int i = 0; i < 100; ++i) {
        if (scanf("%d", &numbers[i]) != 1) {
            fprintf(stderr, "Error: something nasty going on here\n");
            return EXIT_FAILURE;
        }
    }
    int min = minimum(numbers, 100);
    int max = maximum(numbers, 100);
    printf("max is %d\n", max);
    printf("min is %d\n", min);
    return EXIT_SUCCESS;
}
