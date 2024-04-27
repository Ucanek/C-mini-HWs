#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * ctype-counts-table
 *
 * \author Ondrej Sebek
 */

/*
 * This task should help you to get familiar with function pointers
 * and their use.
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

int main(void)
{
    // array of functions
    isctype fun[FUN_COUNT] = {
        &isalnum, &isalpha, &isdigit,
        &islower, &isupper, &ispunct,
        &isspace, &isprint, &iscntrl
    };
    // here go the counts
    size_t chars_shared[FUN_COUNT][FUN_COUNT] = {
        { 0 }
    };

    int c; // character on input
    while ((c = getchar()) != EOF) {
        for (int i = 0; i < FUN_COUNT; ++i) {
            for (int j = 0; (fun[i])(c) && j < FUN_COUNT; ++j) {
                if ((fun[j])(c)) {
                    ++chars_shared[i][j];
                }
            }
        }
    }
    table_print(chars_shared);
    return EXIT_SUCCESS;
}
