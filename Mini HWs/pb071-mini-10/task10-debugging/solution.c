#include <stdio.h>
#include <stdlib.h>

/**
 * Debugging
 *
 * \author Martin Bendel
 */

#define DEBUG // You can play with it!
// #undef DEBUG

#ifdef DEBUG
#define PRINT_INT(array, index) \
    printf("Number on index %d is %d\n", index, array[index])
#else
#define PRINT_INT(array, index) printf("%d ", array[index])
#endif

int main(void)
{
    int array[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        if (scanf(" %d", array + i) != 1) {
            fprintf(stderr, "Reading error\n");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < 10; i++) {
        PRINT_INT(array, i);
    }
    return EXIT_SUCCESS;
}
