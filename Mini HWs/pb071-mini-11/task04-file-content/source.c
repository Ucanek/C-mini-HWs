#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * Minihomework 11: Print content of file
 * ---------------
 * Author: Vojtech Jelinek
 * Email:  vojtechjelinek@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * In this task, write a function that takes a path to a file and writes its
 * content to standard output. If the file does not exist, do not print out
 * anything and return code other than 0.
 *
 * Use POSIX methods for handling files, like open, read, write and close.
 *
 * Do not forget to close the file after you processed it.
 *
 * Useful links:
 * - open:
 *   https://pubs.opengroup.org/onlinepubs/009695399/functions/open.html
 * - read:
 *   https://pubs.opengroup.org/onlinepubs/009695399/functions/read.html
 * - write:
 *   https://pubs.opengroup.org/onlinepubs/009695399/functions/write.html
 * - close:
 *   https://pubs.opengroup.org/onlinepubs/009695399/functions/close.html
 */

int read_file(const char *filepath)
{
    /* TODO your code here instead of returning -1 */
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (read_file(argv[1]) != 0) {
        fprintf(stderr, "File reading error\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
