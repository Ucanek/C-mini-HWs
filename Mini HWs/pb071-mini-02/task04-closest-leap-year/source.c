#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 02: Closest leap year
 * ---------------
 * Author: Imrich Nagy
 * Email:  456271@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Print next closest leap year - year divisible by 4
 * (more complicated in reality).
 *
 * Example 1: closest_leap_year(1600) prints "1600".
 * Example 2: closest_leap_year(2009) prints "2012".
 */

void closest_leap_year(int year)
{
    while (year % 4 != 0) {
        year = year + 1;
    }
    printf("%d", year);
}

// do not change following code!
int main(void)
{
    int years[8] = { 2000, 1995, 1996, 1997, 1998, 1999, 14, 4 };

    for (size_t i = 0; i < 8; i++) {
        closest_leap_year(years[i]);
        putchar(' ');
    }
    printf("\n");
    return 0;
}
