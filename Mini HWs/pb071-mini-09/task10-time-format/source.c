#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/*
 * Minihomework 09: time-format
 * ----------------------------------------------------------------------------
 * Author: Ondřej Metelka
 * Email:  514098@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * In this exercise your task is to do some time parsing.
 *
 * From the input file, dates in various formats will be read (these will be
 * also specified in main). Your goal is to load them correctly into the provided
 * structure (see the 'struct tm' from <time.h> for further information) and
 * print them out in correct format (will be specified too).
 *
 * Use strftime() function.
 */

int main(void)
{
    struct tm time_buf;

    setlocale(LC_TIME, "en_US.UTF-8"); // set the time locales to unified format

    // Task 1: input time is DD/MM/YYYY, print it as YYYY-MM-DD
    /* TODO your code here */

    // Task 2: input time is weekday D.month HH:MM AM/PM (e.g. Fri 6. May 01:23 PM, in 12H format),
    // print it as DD.MON. HH:MIN in 24H format (for given example 06.05. 13:23)
    /* TODO your code here */

    return EXIT_SUCCESS;
}
