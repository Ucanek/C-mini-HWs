#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 03: Pointer arguments
 * ---------------
 * Author: Dominik Dubravický
 * Email:  xdubrav@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Implement following functions.
 */

/*
 * Function 1: get_digits
 * Returns number of decimal digits in given integer.
 * E.g. get_digits(555) = 3
 */

int get_digits(int number)
{
    int digits = 1;
    while (number > 9){
        number /= 10;
        digits++;
    }
    return digits;
}

/*
 * Function 2: get_bits
 * Returns the number of bits in binary representation of given integer.
 * E.g. get_bits(10) = 4, because 10 is 1010 in binary
 */

int get_bits(int number)
{
    int bits = 0;
    while (number > 0) {
        bits++;
        number >>= 1;
    }
    return bits;
}

/*
 * Function 3: is_even
 * Returns 1 if the number is even (=sudé, párne), 0 otherwise.
 */

int is_even(int number)
{
    if (number & 1 > 0){
        return 0;
    }
    return 1;
}

/*
 * Function 4: analyze_number
 * Takes an integer and changes the values in given pointers as follows:
 *     even   = 't' if the number is even, 'f' otherwise,
 *     bits   = the minimal amount of bits it takes to store the integer,
 *     digits = number of decimal digits the integer has.
 * Does not return anything.
 * Use already implemented functions.
 */

void analyze_number(int number, char *even, int *bits, int *digits)
{
    *even = 'f';
    if (is_even(number) == 1){
        *even = 't';
    }
    *bits = get_bits(number);
    *digits = get_digits(number);
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
