#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

/*
 * Minihomework 04: Matrix min
 * ---------------
 * Your task is to implement a function that finds the minimal value
 * included in the square matrix.
 *
 * Function matrix_min finds the smallest element in matrix n*n (n is given
 * as an argument, so is matrix).
 *
 * If n (dimension of matrix) is invalid, function returns null pointer.
 *
 * Explore main function and auxiliary functions read_matrix and print_matrix
 * to determine the return type and parameters of matrix_min.
 *
 * Do not change anything else except function matrix_min.
 */

int *matrix_min(int dimension, int matrix[][dimension])
{
    int *min = &matrix[0][0];
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j < dimension; j++){
            if (matrix[i][j] < *min){
                min = &matrix[i][j];
            }
        }
    }
    return min;
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
