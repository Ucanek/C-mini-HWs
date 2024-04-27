#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define DIMENSION 4

/*
 * Minihomework 04: Vector norm
 * ---------------
 * Your task is to implement a function that calculates the length of a vector.
 * For more information visit (Euclidean norm):
 * https://en.wikipedia.org/wiki/Norm_(mathematics)
 *
 * Function vector_norm returns vector length. The formula is similar to
 * one you use in two-dimensional space.
 *
 * Hint: use sqrt function from math.h
 *
 * Explore the main function to determine the signature of the function.
 *
 * Do not change anything else except function vector_norm.
 */

double vector_norm(int vector[], int cols)
{
    int variable = 0;
    for (int i = 0; i < cols; i++){
        variable += vector[i] * vector[i];
    }
    return sqrt(variable);
}

int read_vector(int vector[], size_t cols)
{
    printf("Insert %zu vector elements:\n", cols);
    for (size_t i = 0; i < cols; i++) {
        if (scanf("%d", &vector[i]) != 1) {
            printf("Input format error\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int main(void)
{
    int vector[DIMENSION];

    if (read_vector(vector, DIMENSION) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    printf("Vector length: %f\n", vector_norm(vector, DIMENSION));
    return EXIT_SUCCESS;
}
