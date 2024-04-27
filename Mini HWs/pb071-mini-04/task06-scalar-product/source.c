#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

/*
 * Minihomework 04: Scalar product
 * ---------------
 * Your task is to implement a function that calculates the scalar product
 * of two vectors. For more information visit:
 * https://en.wikipedia.org/wiki/Dot_product
 *
 * Function scalar_product returns the scalar product of two vectors as integer.
 *
 * Explore the main function to determine the signature of the function.
 *
 * Do not change anything else except function scalar_product.
 */

int scalar_product(int vector_fst[], int vector_snd[], int len)
{
    int scalar = 0;
    for (int i = 0; i < len; i++){
        scalar += vector_fst[i] * vector_snd[i];
    }
    return scalar;
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

void print_vector(int vector[], size_t len)
{
    for (size_t i = 0; i < len; i++) {
        printf("%d", vector[i]);
    }
}

int main(void)
{
    unsigned len;

    if (scanf("%u", &len) != 1) {
        printf("Input format error\n");
        return EXIT_FAILURE;
    }

    int vector_fst[MAX_SIZE];
    int vector_snd[MAX_SIZE];
    if (read_vector(vector_fst, len) == EXIT_FAILURE
            || read_vector(vector_snd, len) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    int product = scalar_product(vector_fst, vector_snd, len);

    print_vector(vector_fst, len);
    printf("\nx\n");
    print_vector(vector_snd, len);
    printf("\n=\n%d\n", product);

    return EXIT_SUCCESS;
}
