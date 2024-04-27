#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * overwrite-sabotage
 *
 * \author Jakub Hanko
 */

/*
 * Overwriting standard functions can be used e.g. for debugging (valgrind
 * does something similar with allocation functions).
 */

#define UNUSED(x) ((void) (x))
// #define strcmp(x, y) 0 also works
#define strcmp(x, y) sabotaged_strcmp(x, y)

int sabotaged_strcmp(const char *x, const char *y)
{
    UNUSED(x);
    UNUSED(y);
    return 0;
}

int main(void)
{
    printf("%d\n", strcmp("abc", "abc"));
    printf("%d\n", strcmp("This task is stupid", "It really is"));
    return EXIT_SUCCESS;
}
