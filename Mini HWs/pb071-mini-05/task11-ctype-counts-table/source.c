#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Minihomework 05: String statistics (fun)
 * =========================================
 *
 * Author:  Ondrej Sebek
 * Email:   xsebek@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * DON'T PANIC! the solution is 5 lines long :)
 *
 * Your task is to count the amount of characters conforming following ctype
 * functions in given string that you read from stdin.
 * 
 * So what you have to do is:
 *  1) to read a string from stdin
 *  2) to check how many ctype functions return true for each character
 *      in the string and save these counts in an array
 *  3) to feed the counts into a 2D array of `FUN_COUNT` rows and columns.
 *  4) to pass your array to `printer` function  which will print it for you.
 *
 * The functions you should try on each character are (from <ctype.h> library):
 *  alnum, alpha, digit, lower, upper, punct, space, print, cntrl
 *
 * In order to print the results correctly, keep the order of functions as
 * stated here. For your convenience, use array `fun` defined in main function.
 *
 * You can assume that the table is symmetric, just make sure to fill both
 * a[x][y] and a[y][x] :)
 *
 * Write your code directly into main function. Use provided functions for
 * table creating and printing. Reading their signature and documentation
 * might help you.
 *
 * To illustrate the functionality, on input `"Hello world!\n"` following
 * markdown formatted table will be printed:
 *
 * |     |alnum|alpha|digit|lower|upper|punct|space|print|cntrl|
 * |----:|----:|----:|----:|----:|----:|----:|----:|----:|----:|
 * |alnum|   10|   10|    0|    9|    1|    0|    0|   10|    0|
 * |alpha|     |   10|    0|    9|    1|    0|    0|   10|    0|
 * |digit|     |     |    0|    0|    0|    0|    0|    0|    0|
 * |lower|     |     |     |    9|    0|    0|    0|    9|    0|
 * |upper|     |     |     |     |    1|    0|    0|    1|    0|
 * |punct|     |     |     |     |     |    1|    0|    1|    0|
 * |space|     |     |     |     |     |     |    2|    1|    1|
 * |print|     |     |     |     |     |     |     |   12|    0|
 * |cntrl|     |     |     |     |     |     |     |     |    1|
 *
 * You can see the count of characters accepted by the functions themselves
 * on the main diagonal :) Read the rest in L-shape-like way ;)
 *
 * Warning: Lines on input can be of _any_ length and newline is a character(s)
 */

#define FUN_COUNT 9          /**< number of functions                     */
typedef int (*isctype)(int); /**< function signature to be used like type */

/** Print the table of counts of characters accepted by ctype functions.
 *
 * \param[in] chars_shared the 2D array of counts of accepted characters by both
 * the _i_-th **and** the _j_-th ctype.h functions.
 * 
 * \return 0 or standard error code
 */
int table_print(size_t chars_shared[FUN_COUNT][FUN_COUNT]);

/** Find the maximum of array and count its digits.
 * \param[in] array of numbers
 * \param[in] length of array
 * \param[in] base `!= 0` in which we count digits (heh octits sound funny :D )
 * \param[in] minimal number of digits
 * \return maximum number of digits in \p base of array and \p min
 */
int longest_digits(size_t *array, int length, int base, int min)
{
    size_t max = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    int digits = 1;
    while ((max /= base)) {
        ++digits;
    }
    return digits > min ? digits : min;
}

#define NRM "\x1B[0m" /**< all attributes off          */
#define BOL "\x1B[1m" /**< Bold or increased intensity */
#define FAI "\x1B[2m" /**< Faint, hope it works :/     */
#define MAG "\x1B[35m" /**< Bright magenta              */

int table_print(size_t chars_shared[FUN_COUNT][FUN_COUNT])
{
    int digits[FUN_COUNT];
    for (int i = 0; i < FUN_COUNT; ++i) {
        digits[i] = longest_digits(chars_shared[i], FUN_COUNT, 10, 5);
    }

    char *names[FUN_COUNT] = { "alnum", "alpha", "digit", "lower", "upper", "punct", "space", "print", "cntrl" };

    // print columns headers
    printf("|     |");
    for (int i = 0; i < FUN_COUNT; ++i) {
        printf(MAG "%*s" NRM "|", digits[i], names[i]);
    }
    // let's print the line for markdown :)
    printf("\n|----:|");
    for (int i = 0; i < FUN_COUNT; ++i) {
        for (int j = 0; j < digits[i] - 1; ++j) {
            putchar('-');
        }
        printf(":|");
    }
    putchar('\n'); // onto the rows!

    for (int i = 0; i < FUN_COUNT; ++i) {
        printf("|" MAG "%s" NRM "|", names[i]); // head of row
        for (int j = 0; j < FUN_COUNT; ++j) {
            if (j == i) // diagonal is important ==> bold
            {
                printf(BOL "%*zu" NRM "|", digits[j], chars_shared[i][j]);
            } else if (j > i) // upper triangle
            {
                if (chars_shared[i][j]) {
                    printf("%*zu|", digits[j], chars_shared[i][j]);
                } else // 0 is not important in upper triangle, make it faint
                {
                    printf(FAI "%*d" NRM "|", digits[j], 0);
                }
            } else // lower triangle is symmetric, padded space will do
            {
                printf("%*c|", digits[j], ' ');
            }
        }
        putchar('\n'); // onto the next row!
    }
    return 0;
}

/**********************************************************
 *   NOW YOU KNOW HOW TO PRINT WITH COLORS! COOL, HUH?    *
 *********************************************************/

int main(void)
{
    // array of functions, not using it is actually harder :/
    isctype fun[FUN_COUNT] = {
        &isalnum, &isalpha, &isdigit,
        &islower, &isupper, &ispunct,
        &isspace, &isprint, &iscntrl
    };
    // here go the counts
    size_t chars_shared[FUN_COUNT][FUN_COUNT];

    /* TODO your code here */

    table_print(chars_shared);
    return EXIT_SUCCESS;
}
