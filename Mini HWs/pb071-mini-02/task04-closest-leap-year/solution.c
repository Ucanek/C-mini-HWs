#include <stdio.h>
#include <stdlib.h>

/**
 * Closest leap year
 *
 * \author Imrich Nagy
 */

/*
 * The only trick here is to use modulo operator for finding out
 * whether the given year is yet a leap one.
 * Note: solution eliminating the need of "if else" statement is
 *     { printf("%d", 4 * ((year + 3) / 4)); }
 */

void closest_leap_year(int year)
{
    if (year % 4 == 0) {
        printf("%d", year);
    } else {
        printf("%d", year + 4 - year % 4);
    }
}

// do not change following code!
int main(void)
{
    int years[8] = { 2000, 1995, 1996, 1997, 1998, 1999, 14, 4 };

    for (size_t i = 0; i < 8; i++) {
        closest_leap_year(years[i]);
        putchar(' ');
    }
    return EXIT_SUCCESS;
}
