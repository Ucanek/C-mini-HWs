#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * pointer-array
 *
 * \author Igor Sivý
 */

/*
 * With inserting pointers into the output array, the values are not copied.
 * Thus modifying them will result in change in both arrays (change in value
 * pointer in the output array points to respectively).
 */

void pointer_array(int *input, int **output, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        output[i] = &input[i];
    }
}

void print_array(int **array, size_t size)
{
    const char *separator = "";
    for (size_t i = 0; i < size; ++i) {
        printf("%s%d", separator, *array[i]);
        separator = ", ";
    }
    printf("\n");
}

int main(void)
{
    unsigned size;

    printf("Array size:\n");
    if (scanf("%u", &size) != 1) {
        printf("Input format error\n");
        return EXIT_FAILURE;
    }

    int *array = malloc(size * sizeof(int));
    assert(array != NULL);

    int **output = malloc(size * sizeof(int *));
    assert(output != NULL);

    printf("Insert %u element(s):\n", size);
    for (size_t i = 0; i < size; ++i) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Input format error\n");
            return EXIT_FAILURE;
        }
    }

    pointer_array(array, output, size);

    printf("Output array:\n");
    print_array(output, size);

    free(array);
    free(output);

    return EXIT_SUCCESS;
}
