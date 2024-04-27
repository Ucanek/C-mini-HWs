#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 09: Transform
 * ----------------------------------------------------------------------------
 * Author: Martin Piatka
 * Email:  445597@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Function pointers can be used to implement higher order functions (functions
 * that take other functions as parameters).
 *
 * Your task in this exercise is to implement the transform function (sometimes
 * also called map). This function will take an array of ints and a function.
 * The function iterates through the whole array and replaces each element with
 * the result of calling the function passed as parameter.
 *
 * For example, if we call transform with the times_two function as
 * the parameter, each number in the array will be multiplied by 2.
 *
 * The main fuction takes care of the input. You do not need to modify it.
 */


void transform(int *array, int count /* TODO function pointer here */)
{
    for (int i = 0; i < count; i++) {
        /* TODO your code here */
    }
}

int times_two(int a)
{
    return a * 2;
}

void double_array(int *array, int count)
{
    /* TODO call transform with times_two parameter here */
}

//-----------------------------------------------------------------------------
// You do not need to modify anything under this line

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

    return EXIT_SUCCESS;
}
