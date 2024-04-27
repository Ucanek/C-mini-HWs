#include <stdio.h>
#include <stdlib.h>

/**
 * very-simple-functions
 *
 * \author Erik Moravec
 */

/*
 * Simple task for practising function annotations.
 * Note: Unlike in Python, the type annotations are mandatory.
 * Note: Unlike in Python, functions with no parameters must have
 * return-type function(void) signature.
 */

char simple_cipher(char c, int x)
{
    return c + x;
}

int reverse(int x)
{
    return x * -1;
}

int bigger(int x, int y)
{
    if (y > x) {
        return y;
    }
    return x;
}

int smaller(int x, int y)
{
    if (y < x) {
        return y;
    }
    return x;
}

int give_me_five(void)
{
    return 5;
}

void print_int(int x)
{
    printf("%d\n", x);
}

void print_char(char c)
{
    printf("%c\n", c);
}

int main(void)
{
    print_char(simple_cipher('a', 5));
    print_int(bigger(give_me_five(), reverse(give_me_five())));
    print_char(simple_cipher(simple_cipher('a', bigger(8, 9)), smaller(give_me_five(), reverse(-18))));
    print_int(smaller(reverse(-20), reverse(bigger(give_me_five() * 5, give_me_five() * 4))));
    return 0;
}
