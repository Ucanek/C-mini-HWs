#include <stdio.h>
#include <stdlib.h>

/**
 * array-max
 *
 * \author Zoltan Fridrich
 */

/*
 * When iterating over an array use size_t type (actually an alias for
 * unsigned long) for the "i" variable.
 * Note: max and array variables below are both integer pointers, but their
 * meaning is different - one points to a single number, the other to the
 * beginning of an array (or the first element of an array).
 */

int *array_max(int *array, size_t length)
{
    if (length == 0) {
        return NULL;
    }
    int *max = array;
    for (size_t i = 1; i < length; ++i) {
        if (*max < array[i]) {
            max = array + i;
        }
    }
    return max;
}

int main(void)
{
    unsigned length;

    printf("Amount of the elements in the array:\n");
    if (scanf("%u", &length) != 1) {
        printf("Input error occurred\n");
        return EXIT_FAILURE;
    }
    int *array = length > 0 ? malloc(length * sizeof(int)) : NULL;

    if (length > 0) {
        printf("Please specify %u element(s):\n", length);
    }

    for (unsigned i = 0; i < length; ++i) {
        if (scanf("%d", array + i) != 1) {
            printf("Input error occurred\n");
            return EXIT_FAILURE;
        }
    }

    int *max = array_max(array, (size_t) length);

    if (max) {
        printf("The maximum element is %d\n", *max);
    } else {
        printf("Was not able to find the maximum element.\n");
    }

    free(array);
    return EXIT_SUCCESS;
}
