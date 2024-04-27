#define _POSIX_C_SOURCE 2
// the macro above is required to use getopt()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*
 * Minihomework 11: Parsing command line arguments
 * ---------------
 * Author: Lukas Kurcik
 * Email:  greenmansk@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * In this task, you will parse command line arguments using getopt function.
 *
 * Your program will accept 3 arguments:
 * 1. -a
 *    Optional: Yes
 *    Call function with_a() if argument is present
 * 2. -c
 *    Optional: No
 *    If not present print string "Error" and end program
 * 3. -d [value]
 *    Optional: Yes
 *    Value: string
 *    Call function with_d(value) if present
 *
 * For unknown or missing arguments, print "Invalid argument" to standard error
 * output and end program with exit code EXIT_FAILURE.
 *
 * Functions should be called in order 1st with_a(), 2nd with_d().
 *
 * HINT: Use optarg variable for -d
 *
 * Useful links:
 * - getopt:
 *   https://pubs.opengroup.org/onlinepubs/009696799/functions/getopt.html
 */

void with_a(void)
{
    printf("A!\n");
}

void with_d(char *val)
{
    printf("Hello %s!\n", val);
}

int main(int argc, char **argv)
{
    bool optional = false;
    char *sentence;
    extern char *optarg;
    int arg;

    while ((arg = getopt(argc, argv, "acd:")) != -1){
        switch (arg){
            case 'a':
                with_a();
                break;
            case 'c':
                optional = true;
                break;
            case 'd':
                sentence = optarg;
                with_d(sentence);
                break;
        }
    }

    if (optional == false){
        fprintf(stderr, "Error\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
