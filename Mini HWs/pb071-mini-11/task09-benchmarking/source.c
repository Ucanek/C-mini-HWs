#define _POSIX_C_SOURCE 199309L
// the macro above is required to enable clock_* functions
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_ITERS 5
#define BILLION 1000000000
#define LOWER_BOUND BILLION
#define UPPER_BOUND (BILLION + 50000000)

/*
 * Minihomework 11: Benchmarking tool
 * ------------------------------------
 *  Authors: Pavel Simovec, Zoltan Fridrich
 *  Email: palusus@mail.muni.cz
 *
 *  Please do NOT contact authors directly, use Discussions in IS MU instead.
 *  Otherwise, you might not get and answer.
 *
 *  ---------------------------------------------------------------------------
 *
 *  Your task is to finish this extremely simplified benchmarking tool.
 *
 *  CONTEXT:
 *  During benchmarking, multiple samples of running time of given function
 *  are produced. Extreme deviations should be then eliminated by taking median
 *  of these samples as result.
 *
 *  YOUR TASK:
 *  Capture start and end times into given variables.[man 3 clock_gettime]
 *  Implement nsec_subtract function which:
 *      - takes 2 timespec structures as arguments
 *      - returns the time between them in nanoseconds.
 *
 *  You can assume <a> parameter captures later time than <b>.
 *
 *  LINK:
 *  http://man7.org/linux/man-pages/man2/clock_gettime.2.html
 *  (also includes info about struct timespec)
 */

void ultra_heavy_process(void);
int cmp(const void *a, const void *b);

long nsec_subtract(const struct timespec *a, const struct timespec *b)
{
    /* TODO your code here instead of returning -1 */
    return -1;
}

int main(void)
{
    struct timespec start, end;
    long samples[NUM_ITERS];

    for (int i = 0; i < NUM_ITERS; ++i) {
        /* TODO capture start time here */
        ultra_heavy_process();
        /* TODO capture end time here */
        samples[i] = nsec_subtract(&end, &start);
    }

    qsort(samples, NUM_ITERS, sizeof(long), cmp);
    long median = samples[NUM_ITERS / 2]; // FINAL RESULT
    puts(median > LOWER_BOUND && median < UPPER_BOUND ? "OK" : "NOK");
    return EXIT_SUCCESS;
}

int cmp(const void *a, const void *b)
{
    long arg1 = *(const long *) a;
    long arg2 = *(const long *) b;
    return (arg1 > arg2) - (arg1 < arg2);
}

void ultra_heavy_process(void)
{
    sleep(1);
}
