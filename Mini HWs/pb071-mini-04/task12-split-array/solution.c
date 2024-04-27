#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void clear(int *input, int **output, size_t n);
void print_result(int **result, size_t n, size_t m);

/**
 * split-array
 *
 * \author Igor Sivý
 */

/*
 * Once you have reserved space in memory for both arrays, only thing
 * to do is copy the content.
 * Note: The space here is allocated on heap (=halda) via dynamic allocation,
 * you will learn about it a lot later :)
 */

void split_array(int *input, int **output, size_t n, size_t m)
{
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            output[i][j] = input[i * m + j];
        }
    }
}

void clear(int *input, int **output, size_t n)
{
    free(input);
    for (size_t i = 0; i < n; ++i) {
        free(output[i]);
    }
    free(output);
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

void print_result(int **result, size_t n, size_t m)
{
    for (size_t i = 0; i < n; ++i) {
        printf("[%zu]: ", i);
        print_array(result[i], m);
    }
}

int main(void)
{
    unsigned n, m;
    printf("Insert values n,m (n*m):\n");
    if (scanf("%u %u", &n, &m) != 2) {
        printf("Input format error\n");
        return EXIT_FAILURE;
    }

    int *array = calloc(n * m, sizeof(int));
    assert(array != NULL);

    int **result = calloc(n, sizeof(int *));
    assert(result != NULL);
    for (size_t i = 0; i < n; ++i) {
        result[i] = malloc(m * sizeof(int));
        assert(result[i] != NULL);
    }

    printf("Insert array elements:\n");
    for (size_t i = 0; i < n * m; ++i) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Input format error\n");
            return EXIT_FAILURE;
        }
    }

    split_array(array, result, n, m);

    printf("Split array:\n");
    print_result(result, n, m);

    clear(array, result, n);

    return EXIT_SUCCESS;
}
