#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 11: Bitfields
 * ---------------
 * Author: Peter Navrátil 445700
 * Email:  445700@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * In this assignment you will work with bitfields.
 *
 * Your assignment is to parse a number from input and print which bits are set
 * to 1 or 0 respectively. Input files will be always correct. Numbers in the
 * input file range from 0 to 255. Use bitwise operators (&, |, ^, <<, >>).
 *
 * Input file:
 * - first line of input file consists of 1 (one) number that describes the
 *   number of lines with values that you are supposed to transform.
 * - every following line contains only 1 (one) number, that you are supposed to
 *   transform.
 *
 * Output file:
 * - N lines (N is equal to the number on the first line in the input file) and
 *   on each line there is a sequence of 1 and 0 for every bit of the number.
 *
 * Transformation example:
 * - 1   -> 10000000
 * - 128 -> 00000001
 * - 107 -> 11010110
 * - 90  -> 01011010
 * - 255 -> 11111111
 *
 * Bitfields are very common way to pass big amount of arguments to a function
 * in POSIX - you can specify some flags through it. Good example of use can be
 * found in function open (man 2 open /
 * http://man7.org/linux/man-pages/man2/open.2.html).
 */

void convert(unsigned value)
{
    /* TODO your code here */
}

int main(void)
{
    unsigned count;
    if (scanf("%u", &count) != 1) {
        fputs("File reading error\n", stderr);
        return EXIT_FAILURE;
    }
    for (unsigned i = 0; i < count; i++) {
        unsigned value;
        if (scanf("%u", &value) != 1) {
            fputs("File reading error\n", stderr);
            return EXIT_FAILURE;
        }
        convert(value);
        printf("\n");
    }
    return EXIT_SUCCESS;
}
