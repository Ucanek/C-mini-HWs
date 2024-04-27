#include <stdio.h>
#include <stdlib.h>

#define N_ROWS 2
#define N_COLS 3

/*
 * Here the solution is even syntactically very similar to one you would write
 * in Python.
 * Note: You can see here how global variables (N_ROWS, N_COLS) are defined.
 * During compilation, those in code are textually replaced with their
 * definitions - the rows starting with #define.
 */

void matrix_sum(int rows, int cols, int first[rows][cols], int second[rows][cols], int result[rows][cols])
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result[row][col] = first[row][col] + second[row][col];
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
