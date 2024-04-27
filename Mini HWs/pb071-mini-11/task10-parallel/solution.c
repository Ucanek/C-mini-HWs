#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * parallel
 *
 * \author Pavel Simovec
 */

/*
 * You can create as many threads as you want and these will run in parallel
 * as long as your CPU has enough thread capacity.
 */

int points;

void *kontr(void *arg)
{
    (void) arg; // unused
    puts("Kontr zapocal sve dilo!");
    points = 0;
    sleep(2);
    puts(points ? "TESTY PROSLY KOMPLETNE SPRAVNE!" : "TEST NEPROSEL");
    return NULL;
}

int main(void)
{
    pthread_t t;

    if (pthread_create(&t, NULL, kontr, NULL) != 0) {
        fprintf(stderr, "failed to create thread\n");
        return EXIT_FAILURE;
    }

    sleep(1);
    points = 1;

    if (pthread_join(t, NULL) != 0) {
        fprintf(stderr, "failed to join thread\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
