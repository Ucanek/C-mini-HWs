#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/**
 * time-format
 *
 * \author Ondřej Metelka
 */

/*
 * Note the non-regularities in month (0 == January) and year (0 == 1900), so
 * the that tm structure has to be modified.
 */

int main(void)
{
    struct tm time_buf = {0};
    char buf[128] = {0};

    setlocale(LC_TIME, "en_US.UTF-8"); // set the time locales to unified format

    // Task 1: input time is DD/MM/YYYY (e.g. 01/01/2012), print it as YYYY-MM-DD (2012-01-01)
    if (scanf("%d/%d/%d", &time_buf.tm_mday, &time_buf.tm_mon, &time_buf.tm_year) != 3) {
        fprintf(stderr, "Time format error\n");
        return EXIT_FAILURE;
    }
    time_buf.tm_year -= 1900;
    time_buf.tm_mon -= 1;
    if (strftime(buf, sizeof(buf), "%F", &time_buf) > 0) {
        puts(buf);
    } else {
        fprintf(stderr, "strftime error\n");
        return EXIT_FAILURE;
    }

    // Task 2: input time is WD DD.MON. HH:MIN in 24H format (for given example 5 06.09. 13:23),
    // print it as weekday D.month HH:MM AM/PM (e.g. Fri 6. September 01:23 PM, in 12H format)
    if (scanf("%d %d.%d. %d:%d", &time_buf.tm_wday, &time_buf.tm_mday, &time_buf.tm_mon,
                &time_buf.tm_hour, &time_buf.tm_min) != 5) {
        fprintf(stderr, "Time format error\n");
        return EXIT_FAILURE;
    }
    time_buf.tm_mon -= 1;
    if (strftime(buf, sizeof(buf), "%a%e. %B %I:%M %p", &time_buf) > 0) {
        puts(buf);
    } else {
        fprintf(stderr, "strftime error\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
