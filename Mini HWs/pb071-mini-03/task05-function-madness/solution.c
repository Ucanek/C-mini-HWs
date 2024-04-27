#include <stdio.h>
#include <stdlib.h>

/**
 * function-madness
 *
 * \author Stanislav Soták
 */

/*
 * Simple example of function syntax.
 * Note: When naming your function parameters, try to be precise
 * and consistent, yet not redundant - "int integer" is not good.
 */

int plus_5(int x)
{
    return x + 5;
}

int minus_8(int x)
{
    return x - 8;
}

int times_3(int x)
{
    return x * 3;
}

void say_number(int x)
{
    printf("number is %d\n", x);
}

int main(void)
{
    say_number(times_3(minus_8(plus_5(2))));
    say_number(minus_8(times_3(plus_5(3))));
    say_number(plus_5(plus_5(times_3(minus_8(16)))));
    say_number(times_3(times_3(times_3(10))));
    return EXIT_SUCCESS;
}
