#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

/*
 * It is necessary to pass both height and width of a matrix to the function,
 * because it is iterated over both.
 */

int scalar_product(int first[], int second[], unsigned len);

int *orthogonal(unsigned cols, unsigned rows, int vector[], int matrix[][rows])
{
    for (size_t i = 0; i < rows; i++) {
        if (scalar_product(matrix[i], vector, cols) == 0) {
            return matrix[i];
        }
    }
    return NULL;
}

int read_vector(int vector[], size_t len)
{
    for (size_t i = 0; i < len; i++) {
        if (scanf("%d", &vector[i]) != 1) {
            printf("Input format error\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int read_matrix(unsigned cols, unsigned rows, int matrix[][cols])
{
    for (size_t i = 0; i < rows; i++) {
        if (read_vector(matrix[i], cols) == EXIT_FAILURE) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

void print_vector(int vector[], unsigned len)
{
    if (vector == NULL) {
        printf("No such line found.\n");
        return;
    }
    for (size_t i = 0; i < len; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int scalar_product(int first[], int second[], unsigned len)
{
    int result = 0;
    for (unsigned i = 0; i < len; i++) {
        result += first[i] * second[i];
    }
    return result;
}

int main(void)
{
    unsigned cols, rows;

    if (scanf("%u", &cols) != 1 || scanf("%u", &rows) != 1) {
        printf("Input format error\n");
        return EXIT_FAILURE;
    }

    int vector[MAX_SIZE];
    int matrix[MAX_SIZE][MAX_SIZE];

    if (read_vector(vector, cols) == EXIT_FAILURE
            || read_matrix(cols, rows, matrix) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    int *ortogonal_row = orthogonal(cols, rows, vector, matrix);
    print_vector(ortogonal_row, cols);

    return EXIT_SUCCESS;
}
