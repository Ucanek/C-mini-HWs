#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

/*
 * You can define multidimensional arrays by using multiple square brackets
 * (the number of dimensions is possibly unlimited).
 */

int *matrix_min(int dimension, int matrix[][dimension])
{
    if (dimension <= 0) {
        return NULL;
    }

    int *min_value = *matrix;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (*min_value > matrix[i][j]) {
                min_value = &matrix[i][j];
            }
        }
    }
    return min_value;
}

int read_matrix(int dimension, int matrix[][dimension])
{
    printf("Insert matrix %dx%d, elements delimit by space:\n", dimension, dimension);
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Input format error\n");
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

void print_matrix(int dimension, int matrix[][dimension])
{
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("%3d", matrix[i][j]);
        }

        printf("\n");
    }
}

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    if (read_matrix(MAX_SIZE, matrix) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }
    printf("Matrix:\n");
    print_matrix(MAX_SIZE, matrix);
    int *min = matrix_min(MAX_SIZE, matrix);
    printf("has a minimum: %d\n", *min);
    return EXIT_SUCCESS;
}
