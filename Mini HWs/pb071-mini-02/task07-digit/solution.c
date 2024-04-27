#include <stdio.h>
#include <stdlib.h>

/**
 * Last-but-one digit
 *
 * \author Imrich Nagy
 */

/*
 * A simple example of int division and modulo operators.
 * Note: Only works for integers.
 */

void digit(int n)
{
    printf("%d", n / 10 % 10);
}

// do not change following code!
int main(void)
{
    digit(1);
    digit(12);
    digit(123);
    digit(1234);
    digit(12345);
    digit(123456);
    return EXIT_SUCCESS;
}
