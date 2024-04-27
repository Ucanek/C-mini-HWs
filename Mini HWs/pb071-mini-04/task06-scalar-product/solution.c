#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

/*
 * Dot (scalar) product is just a sum of multiplied members of the vectors.
 */

int scalar_product(int vector_fst[], int vector_snd[], size_t len)
{
    int result = 0;
    for (size_t i = 0; i < len; i++) {
        result += vector_fst[i] * vector_snd[i];
    }
    return result;
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
