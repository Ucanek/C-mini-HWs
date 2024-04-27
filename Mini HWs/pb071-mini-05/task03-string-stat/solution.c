#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

/**
 * string-stat
 *
 * \author Ondrej Sebek
 */

/*
 * For determining "type" of given char (uppercase, digit, control sequence...)
 * functions from <ctype.h> may come in handy.
 */

int printer(size_t counts[3]);

int line_print(size_t length)
{
    for (; length > 0; --length) {
        if (putchar('-') == EOF) {
            return ferror(stdin);
        }
    }
    if (putchar('\n') == EOF) {
        return ferror(stdin);
    }
    return EXIT_SUCCESS;
}

int printer(size_t counts[3])
{
    int result = 0;
    char *names[3] = {"Digits", "Lowercase", "Uppercase"};
    if ((result = line_print(30)) != EXIT_SUCCESS) {
        return result;
    }

    for (int i = 0; i < 3; ++i) {
        if (0 > printf("|%10s | %15zu|\n", names[i], counts[i])) {
            result = EIO; // some output problem \(°_°)/
            break;
        }
        if ((result = line_print(30)) != EXIT_SUCCESS) {
            break;
        }
    }
    return result;
}

int main(void)
{
    int c;
    size_t counts[3] = {0},
           *digits = counts,
           *lower = counts + 1,
           *upper = counts + 2;

    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            ++*digits;
        } else if (isupper(c)) {
            ++*upper;
        } else if (islower(c)) {
            ++*lower;
        }
    }

    return printer(counts);
}
