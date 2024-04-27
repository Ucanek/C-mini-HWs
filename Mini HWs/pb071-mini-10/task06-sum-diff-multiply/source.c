#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 10: Sum, diff, multiply
 * ---------------
 * Author: Sandra Galovičová
 * Email:  469302@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to define SUM, DIFF and MULTIPLY macros for adding/subtracting
 * /multiplying two given integers.
 *
 * Use provided math_op function in each macro.
 */

typedef enum operation
{
    OPERATION_ADD,
    OPERATION_SUBSTRACT,
    OPERATION_MULTIPLY
} operation;

int math_op(operation op, int x, int y)
{
    switch (op) {
    case OPERATION_ADD:
        return x + y;
    case OPERATION_SUBSTRACT:
        return x - y;
    case OPERATION_MULTIPLY:
        return x * y;
    default:
        return 0;
    }
}

/* TODO your macro definition here */

int main(void)
{
    printf("%d, ", SUM(5, 4));
    printf("%d, ", SUM(22176, 547652));
    printf("%d, ", SUM(6753, 2334));
    printf("%d, ", DIFF(6788, -42));
    printf("%d, ", DIFF(777, 7902));
    printf("%d, ", DIFF(77327, 3221));
    printf("%d, ", MULTIPLY(5, 20));
    printf("%d, ", MULTIPLY(3873, 5));
    printf("%d", MULTIPLY(46783, 7));
    return EXIT_SUCCESS;
}
