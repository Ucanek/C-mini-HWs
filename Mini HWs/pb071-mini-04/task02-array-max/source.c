#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 04: Array max
 * ---------------
 * Author: Zoltan Fridrich
 * Email:  xfridri1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Your task is to implement a function that finds the element with the biggest
 * value in the given array.
 *
 * 1. Complete function signature.
 *    The function should return a pointer to the maximum element or NULL if
 *    the array is empty (has zero length).
 *    The function should take pointer to an array of integers and the length
 *    of that array.
 *
 * 3. Implement the body of function.
 *    Find the maximal element in the array and return its pointer.
 *    If there are multiple maximal elements, return a pointer to any of them.
 *
 * 4. Call array_max function in main.
 *    Pass variables array and length as arguments.
 *
 * Do not change anything else.
 */

int *array_max(int *array_pointer, int array_lenght)
{
    if (array_lenght <= 0){
        return NULL;
    }
    int *max = array_pointer;
    for (int i = 0; i < array_lenght; i++){
        if (array_pointer[i] > *max){
            max = &array_pointer[i];
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
    /* TODO assign the result of array_max call here instead of NULL */

    if (max) {
        printf("The maximum element is %d\n", *max);
    } else {
        printf("Was not able to find the maximum element.\n");
    }

    free(array);
    return EXIT_SUCCESS;
}
