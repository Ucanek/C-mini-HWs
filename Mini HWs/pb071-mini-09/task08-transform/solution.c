#include <stdio.h>
#include <stdlib.h>

/**
 * transform
 *
 * \author Martin Piatka <445597@mail.muni.cz>
 */

/*
 * The 'map x y' function in Haskell works the same.
 */

int times_two(int a)
{
    return a * 2;
}

void transform(int *array, int count, int (*fun)(int))
{
    for (int i = 0; i < count; i++) {
        array[i] = fun(array[i]);
    }
}

void double_array(int *array, int count)
{
    transform(array, count, times_two);
}

void print_numbers(int *array, int count)
{
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int main(void)
{
    int num;
    if (scanf(" %d", &num) != 1) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }

    int *in = malloc(num * sizeof(int));
    if (!in) {
        fprintf(stderr, "Malloc failed!\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num; i++) {
        if (scanf(" %d", &in[i]) != 1) {
            fprintf(stderr, "Invalid input!\n");
            return EXIT_FAILURE;
        }
    }

    printf("Before transform:\n");
    print_numbers(in, num);

    double_array(in, num);

    printf("After transform:\n");
    print_numbers(in, num);

    free(in);

    return EXIT_SUCCESS;
}
