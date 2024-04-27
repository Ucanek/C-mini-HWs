#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define UNUSED(x) ((void) (x))

/**
 * threads
 *
 * \author Peter Navrátil
 */

/*
 * The structure of this program can be interpreted like this:
 *
 * main thread      first thread      second thread
 *           t
 *   pthread_create------>t
 *           h            h
 *   pthread_create-------r----------------->t
 *           r            e                  h
 *   pthread_join         a                  r
 *           e            d                  e
 *           a            r                  a
 *           d            u                  d
 *           r            n                  r
 *           u <----------s                  u
 *   pthread_join                            n
 *           n                               n
 *           s                               i
 *           |                               n
 *           |<------------------------------g
 *          end
 */

void *snd_thread(void *unused)
{
    UNUSED(unused);
    printf("second thread\n");
    return NULL;
}

void *fst_thread(void *unused)
{
    UNUSED(unused);
    sleep(2);
    printf("first thread\n");
    return NULL;
}

int main(void)
{
    pthread_t fst_id;
    pthread_t snd_id;

    if (pthread_create(&fst_id, NULL, &fst_thread, NULL) != 0) {
        fprintf(stderr, "first thread failed to create\n");
        return EXIT_FAILURE;
    }

    if (pthread_create(&snd_id, NULL, &snd_thread, NULL) != 0) {
        fprintf(stderr, "second thread failed to create\n");
        return EXIT_FAILURE;
    }

    if (pthread_join(fst_id, NULL) != 0) {
        fprintf(stderr, "first thread failed to join\n");
        return EXIT_FAILURE;
    }

    if (pthread_join(snd_id, NULL) != 0) {
        fprintf(stderr, "second thread failed to join\n");
        return EXIT_FAILURE;
    }

    printf("main thread\n");
    return EXIT_SUCCESS;
}
