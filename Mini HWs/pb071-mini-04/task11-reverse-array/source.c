#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size);

/*
 * Minihomework 04: Reverse array
 * ---------------
 * Author: Igor Sivý
 * Email:  434088@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 *
 * Your task is to implement the function which reverses given array in place
 * (it reverses the order of all array elements and does not return anything).
 *
 * Do not worry about empty array, the case is already checked in main.
 *
 * Explore the main function to determine the correct function signature.
 *
 * Do not change anything else except function reverse_array.
 */

void reverse_array(int array[], int size)
{
    int array_help[size];
    for (int i = 0; i < size; i++){
        array_help[i] = array[size - 1 - i];
    }
    for (int i = 0; i < size; i++){
        array[i] = array_help[i];
    }
}

void print_array(int *array, size_t size)
{
    const char *separator = "";
    for (size_t i = 0; i < size; ++i) {
        printf("%s%d", separator, array[i]);
        separator = ", ";
    }
    printf("\n");
}

int main(void)
{
    unsigned size;
    printf("Insert array size:\n");
    if (scanf("%u", &size) != 1) {
        printf("Input format error\n");
        return EXIT_FAILURE;
    }

    if(size <= 0) {
        printf("Empty array...");
        return EXIT_SUCCESS;
    }

    int *array = malloc(size * sizeof(int));
    assert(array != NULL);

    printf("Insert %u number(s) (array elements):\n", size);
    for (size_t i = 0; i < size; ++i) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Input format error\n");
            return EXIT_FAILURE;
        }
    }

    reverse_array(array, size);

    printf("Reversed array:\n");
    print_array(array, size);

    free(array);

    return EXIT_SUCCESS;
}
