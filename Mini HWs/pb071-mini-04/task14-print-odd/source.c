#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 04: Print odd
 * ---------------
 * Your task is to implement a function that prints characters from
 * an array on odd (=liché, nepárne) indices.
 *
 * Do not forget that indexing of arrays start from 0.
 *
 * Hint: Loop variable can be incremented by any value, not only by 1.
 *
 * Explore main function to determine correct function signature.
 *
 * Do not change anything else except function print_odd.
 */

void print_odd(char array[], int array_len)
{
    for (int i = 1; i < array_len; i += 2){
        printf("%c", array[i]);
    }
    printf("\n");
}

int main(void)
{
    char txt1[] = {'H', 'e', 'l', 'l', 'o'};
    char txt2[] = {'w', 'o', 'r', 'l', 'd', '!'};
    char txt3[] = {'a', 'b'};
    char txt4[] = {'a'};

    print_odd(txt1, 5);
    print_odd(txt2, 6);
    print_odd(txt3, 2);
    print_odd(txt4, 1);
    printf("\n");

    return EXIT_SUCCESS;
}
