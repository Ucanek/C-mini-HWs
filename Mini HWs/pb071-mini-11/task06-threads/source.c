#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define UNUSED(x) ((void) (x))

/*
 * Minihomework 11: Threads and stuff
 * ---------------
 * Author: Peter Navrátil 445700
 * Email:  445700@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * In this assignment you will write a simple program, that will
 * demonstrate how threads (vlákna) handled in POSIX.
 *
 * Your program should create 2 threads. First (second respectively) thread
 * should execute provided functions fst_thread (snd_thread respectively).
 * The catch is you need to use correctly pthread_join to match the provided
 * test output.
 *
 * Threads are not easy to understand, so here is an abstract guide how to do
 * complete this assignment:
 * 1. create thread, that will handle fst_thread function
 * 2. wait for the first thread to end
 * 3. create thread, that will handle snd_thread function
 * 4. wait for the second thread to end
 *
 * Keep in mind that to have correct implementation, you should check the return
 * value of every call to pthread_create and pthread_join.
 * If an error occurs, your program should return a non-zero value, and you can
 * print some error to stderr.
 *
 * Use POSIX methods for manipulation with threads, namely pthread_create and
 * pthread_join. You can find documentation for those functions:
    - in CLI:
      - man 3 pthread_create
      - man 3 pthread_join
    - or on web:
      - http://man7.org/linux/man-pages/man3/pthread_create.3.html
      - http://man7.org/linux/man-pages/man3/pthread_join.3.html
 *
 * Hint:
    - do not worry, some arguments may be NULL in the needed functions
    - you can use prepared variables in your implementation
    - you can also check the POSIX presentation
 *
 * It is not as hard as it may look :-). GL HF
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
    printf("first thread\n");
    sleep(2);
    return NULL;
}

int main(void)
{
    pthread_t fst_id;
    pthread_t snd_id;

    /* TODO your code here */

    printf("main thread\n");
    return EXIT_SUCCESS;
}
