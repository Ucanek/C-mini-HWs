#include <stdio.h>
#include <stdlib.h>

/**
 * Right-angled triangle
 *
 * \author Roman Chrenšť
 */

/*
 * The rightness of the triangle and the resulting area can be computed
 * altogether.
 */

int right_triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return -1;

    int area = a * a + b * b;
    if (area != c * c)
        return -1;

    return area;
}

// do not change following code!
int main(void)
{
    printf("%d ", right_triangle(3, 4, 5));
    printf("%d ", right_triangle(1, -4, 5));
    printf("%d ", right_triangle(0, 5, 5));
    printf("%d ", right_triangle(9, 12, 15));
    printf("%d ", right_triangle(1, 13, 13));
    printf("%d\n", right_triangle(2, 2, 5));
    return EXIT_SUCCESS;
}
