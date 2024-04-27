#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

/*
 * Minihomework 04: Orthogonal
 * ---------------
 * Your task is to implement a function that returns either pointer to the
 * first line of given matrix orthogonal to given vector (scalar product
 * of the line and vector is 0) or null if such a line does not exist.
 * For more information visit:
 * https://en.wikipedia.org/wiki/Euclidean_space#Orthogonality
 *
 * Function orthogonal returns either pointer to the first row of given matrix
 * that is orthogonal to given vector or null if such line does not exist.
 *
 * You can assume that dimension of vector and number of columns in matrix
 * are equal, thus their scalar product can be computed.
 *
 * Explore the main function to determine the signature of the function.
 *
 * Do not change anything else except function orthogonal.
 */

int *orthogonal(void /* TODO parameters here instead of void */)
{
    /* TODO your code here instead of returning null */
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
