#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 04: Pointer array
 * ---------------
 * Author: Igor Sivý
 * Email:  434088@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 *
 * Your task is to implement the function which fills the second parameter
 * output with pointers to values from the first parameter input of size n.
 *
 * Hint: Do not overthink it ;)
 *
 * Explore the main function to determine correct types of parameters.
 *
 * Do not change anything else except function pointer_array.
 */

void pointer_array(int *input, int *output[], unsigned int size)
{
    for (int i = 0; i < size; i++){
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
