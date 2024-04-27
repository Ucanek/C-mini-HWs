#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 10: Range
 * ---------------
 * Author: Sandra Galovičová
 * Email:  469302@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is define range based cycle, working almost as the range()
 * function in Python.
 *
 * It takes 4 arguments:
 *  i - iteration variable,
 *  from - the starting number,
 *  to - the highest number to include (differently from Python, where this
 *      value is excluded),
 *  step - the value by which increase i in each iteration
 *
 * and creates empty (without body) cycle corresponding to Python line
 * "for i in range(from, to+1, step):".
 */

#define RANGE(i, from, to, step) /* TODO your code here */

int main(void)
{
    int x = 0;
    RANGE(x, 10, 20, 2)
    {
        printf("%d ", x);
    }
    printf("\n");
    RANGE(x, 0, 1, 2)
    {
        printf("%d ", x);
    }
    printf("\n");
    RANGE(x, 1, 30, 3)
    {
        printf("%d ", x);
    }
    printf("\n");
    RANGE(x, 10, 100, 10)
    {
        printf("%d ", x);
    }
    return EXIT_SUCCESS;
}
