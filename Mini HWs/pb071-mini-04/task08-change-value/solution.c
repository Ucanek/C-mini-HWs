#include <stdio.h>
#include <stdlib.h>

/**
 * change-value
 *
 * \author Igor Sivý
 */

/*
 * No return statement is necessary in this solution.
 */

void change_value(int *v1, int *v2)
{
    if (*v1 < *v2) {
        *v2 = *v2 - *v1;
    } else if (*v1 > *v2) {
        *v1 = *v1 - *v2;
    }
}

int main(void)
{
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Input format error\n");
        return EXIT_FAILURE;
    }

    printf("Before: x: %d, y: %d\n", x, y);

    change_value(&x, &y);

    printf("After: x: %d, y: %d\n", x, y);

    return EXIT_SUCCESS;
}
