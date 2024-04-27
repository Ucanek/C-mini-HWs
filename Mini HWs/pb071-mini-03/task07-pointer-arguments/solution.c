#include <stdio.h>
#include <stdlib.h>

/**
 * pointer-arguments
 *
 * \author Dominik Dubravický
 */

/*
 * You can use plenty of built-in operators (/, %, >> ternary ? : and so on)
 * to ease your coding.
 * Note: x >> n is equal to x / (2 ** n)
 */

int get_digits(int number)
{
    int digits = 0;
    while (number > 0) {
        digits++;
        number /= 10;
    }
    return digits;
}

int get_bits(int number)
{
    int bits = 0;
    while (number > 0) {
        bits++;
        number >>= 1;
    }
    return bits;
}

int is_even(int number)
{
    return 1 - (number % 2);
}

void analyze_number(int number, char *even, int *bits, int *digits)
{
    (*even) = is_even(number) ? 't' : 'f';
    (*bits) = get_bits(number);
    (*digits) = get_digits(number);
}

int main(void)
{
    char even;
    int bits;
    int digits;

    for (int i = 1; i <= 15; i++) {
        analyze_number(i, &even, &bits, &digits);
        printf("%d - even: %c, bits: %d, digits: %d\n", i, even, bits, digits);
    }

    return 0;
}
