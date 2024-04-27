#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * local-time
 *
 * \author Peter Navrátil 445700
 */

/*
 * Do not forget that year saved in tm struct is not the real year, but
 * number of years since 1900.
 */

int main(void)
{
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    printf("year: %d\n", tm->tm_year + 1900);

    return EXIT_SUCCESS;
}
