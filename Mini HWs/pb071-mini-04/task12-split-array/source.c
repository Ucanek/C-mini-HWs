#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void clear(int *input, int **output, size_t n);
void print_result(int **result, size_t n, size_t m);

/*
 * Minihomework 04: Split array
 * ---------------
 * Author: Igor Sivý
 * Email:  434088@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 *
 * Your task is to implement the function which splits one-dimensional array
 * of size n * m and puts the values into a two-dimensional array of size [n][m].
 *
 * Explore the main function to determine correct function signature.
 *
 * Do not change anything else except function split_array.
 */

void split_array(int *array, int **result, int n, int m)
{
    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            result[i][j] = array[index];
            index++;
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
