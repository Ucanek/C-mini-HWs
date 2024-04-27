#include <stdio.h>
#include <stdlib.h>

/**
 * sum-diff-multiply
 *
 * \author Sandra Galovičová
 */

/*
 * The math_op function does not make much sense here, but the concept - in OOP
 * called polymorphism - of having one function for more similar purposes is
 * quite common.
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

#define SUM(x, y) (math_op(OPERATION_ADD, x, y))
#define DIFF(x, y) (math_op(OPERATION_SUBSTRACT, x, y))
#define MULTIPLY(x, y) (math_op(OPERATION_MULTIPLY, x, y))

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
