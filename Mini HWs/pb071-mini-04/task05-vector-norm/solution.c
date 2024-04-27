#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define DIMENSION 4

/*
 * If you define a variable as an array, it is still internally represented
 * as a pointer.
 */

double vector_norm(int vector[], size_t cols)
{
    int sum = 0;
    for (size_t i = 0; i < cols; i++) {
        sum += vector[i] * vector[i];
    }
    return sqrt(sum);
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
