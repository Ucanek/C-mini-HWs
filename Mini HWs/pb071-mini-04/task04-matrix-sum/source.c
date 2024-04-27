#include <stdio.h>
#include <stdlib.h>

#define N_ROWS 2
#define N_COLS 3

/*
 * Minihomework 04: Matrix sum
 * ---------------
 * Your task is to implement a function that calculates the sum of two 2D matrices.
 * For more information visit: https://en.wikipedia.org/wiki/Matrix_addition
 *
 * Function matrix_sum should return the sum of two matrices in a new matrix.
 *
 * You can assume that input matrices has the same size, but they are not
 * necessary square, thus their height and width must be specified.
 *
 * Explore main function and auxiliary function print_matrix to determine
 * the parameters of matrix_sum.
 *
 * Do not change anything else except function matrix_sum.
 */

void matrix_sum(int rows, int cols, int first[rows][cols], int second[rows][cols], int result[rows][cols])
{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void print_matrix(int rows, int cols, int matrix[rows][cols])
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%3d", matrix[row][col]);
        }

        printf("\n");
    }
}

int main(void)
{
    int first[N_ROWS][N_COLS] = {
        {1, 1, 1},
        {0, 2, 1}
    };
    int second[N_ROWS][N_COLS] = {
        {0, 2, 1},
        {1, 1, 1}
    };
    int result[N_ROWS][N_COLS];

    print_matrix(N_ROWS, N_COLS, first);
    printf("+\n");
    print_matrix(N_ROWS, N_COLS, second);
    printf("=\n");
    matrix_sum(N_ROWS, N_COLS, first, second, result);
    print_matrix(N_ROWS, N_COLS, result);

    return EXIT_SUCCESS;
}
