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

/**
 * benchmarking
 *
 * \authors Pavel Simovec, Zoltan Fridrich
 */

/*
 * If you are looking for some new hardware, benchmarking can help you with
 * choosing - internet is full of such videos and websites (but check their
 * trustworthiness first!).
 */

void ultra_heavy_process(void);
int cmp(const void *a, const void *b);

long nsec_subtract(const struct timespec *a, const struct timespec *b)
{
    return (a->tv_sec - b->tv_sec) * BILLION + a->tv_nsec - b->tv_nsec;
}

int main(void)
{
    struct timespec start, end;
    long samples[NUM_ITERS];

    for (int i = 0; i < NUM_ITERS; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        ultra_heavy_process();
        clock_gettime(CLOCK_MONOTONIC, &end);
        samples[i] = nsec_subtract(&end, &start);
    }

    qsort(samples, NUM_ITERS, sizeof(long), cmp);
    long median = samples[NUM_ITERS / 2];
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
