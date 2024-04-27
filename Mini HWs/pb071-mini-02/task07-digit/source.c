#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 02: Last-but-one digit
 * ---------------
 * Author: Imrich Nagy
 * Email:  456271@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Implement function which prints last-but-one digit
 * (second from the right) if n is at least 10, otherwise prints 0 (zero).
 *
 * Example: n = 7654 -> function prints "5" to standard output.
 */

void digit(int n)
{
    if (n < 10){
        printf(0);
    }
    int last_but_one = (n / 10) % 10;
    printf("%d\n", last_but_one);
}

int main(void)
{
    digit(1);
    digit(12);
    digit(123);
    digit(1234);
    digit(12345);
    digit(123456);
    return 0;
}
