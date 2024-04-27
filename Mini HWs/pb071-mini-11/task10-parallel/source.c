#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * Minihomework 11: Parallel thread
 * ---------------------------------
 * Author: Pavel Simovec
 * Email: palusus@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to "make all tests pass" [to make kontr function print that
 * test passed without editing it.] You can achieve that by running something
 * in parallel with that function.
 *
 * Kontr is evil, so it resets your points (global variable) when it starts.
 * After two seconds the tests do not pass, because you do not have any points.
 *
 * You can edit main or create new functions as you wish, but kontr MUST be
 * called once (as it is now, or can be threaded).
 *
 * You will need [man 3 pthread_create]
 * and you might need [man 3 pthread_join], depending on your implementation.
 *
 * -----------------------------------------------------------------
 *                            DISCLAIMER
 *
 * The **ACTUAL** Kontr cannot be persuaded to change the points
 * with this kind of shenanigans. Do not even try it.
 * -----------------------------------------------------------------
 *
 * links:
 *	- http://man7.org/linux/man-pages/man3/pthread_create.3.html
 *	- http://man7.org/linux/man-pages/man3/pthread_join.3.html
 *
 * Task06 may help you to understand threads better.
 */

int points;
void *kontr(void *);

/* TODO your code here */

int main(void)
{
    /* TODO or here? */
    kontr(NULL); // can be edited, but kontr must be called once in main.
    /* TODO or maybe here? */
    return EXIT_SUCCESS;
}

//=============================================================================
// DO NOT EDIT ANYTHING BELOW THIS LINE
//=============================================================================

void *kontr(void *arg)
{
    (void) arg; // unused
    puts("Kontr zapocal sve dilo!");
    points = 0;
    sleep(2);
    puts(points ? "TESTY PROSLY KOMPLETNE SPRAVNE!" : "TEST NEPROSEL");
    return NULL;
}
