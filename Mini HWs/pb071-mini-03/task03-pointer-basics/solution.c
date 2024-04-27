#include <stdio.h>
#include <stdlib.h>

/**
 * pointer-basics
 *
 * \author Dominik Dubravický
 */

/*
 * Example of unary * and & operators use.
 * Note: The meaning of * will change if used as unary and binary operator.
 * Note: Be aware of operator precedence - binary * evaluates earlier than
 * unary one.
 */

void double_value(int *p)
{
    (*p) *= 2;
}

int get_value(int *p)
{
    return *p;
}

int main(void)
{
    int a = 50;
    int *p = &a;

    double_value(p);
    printf("%d\n", a);

    a += 6;
    printf("%d\n", get_value(p));

    double_value(p);
    printf("%d %d\n", get_value(p), a);

    return 0;
}
