#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * reverse-array
 *
 * \author Igor Sivý
 */

/*
 * The easiest way to solve this task is swap n-th and n-th to last elements.
 * Note: Swapping should be iterated to half of the array, otherwise the array
 * will be swapped back to its initial state.
 */

void reverse_array(int *array, size_t n)
{
    for (size_t i = 0; i < n / 2; ++i) {
        int tmp = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = tmp;
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