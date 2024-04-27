#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 08: File size printer
 * ---------------
 * Author: Lukáš Zaoral
 * Email:  x456487@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to write a simple program that prints out a size of given file
 * in bytes corresponding to the args in a following format:
 *
 * "<argv[1]>: <size> bytes\n"
 *
 * Beware, you are only allowed to use functions from the standard C library.
 * 
 * Hint: try `ftell()` and `fseek()`
 *
 * For insufficient number of parameters for binary, print out usage to stderr.
 *
 * Create your own auxiliary functions if you want to.
 *
 * For arguments that have to be passed to compiled binary, see .args file(s).
 *
 * Warning: Make sure the .txt files are handled with LF newlines, otherwise
 * the byte counts may differ.
 */

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Invalid arguments.\n");
        return EXIT_FAILURE;
    }

    FILE* input = NULL;
    input = fopen(argv[1], "rb");
    if (input == NULL){
        fprintf(stderr, "Open failed.\n");
        return EXIT_FAILURE;
    }

    if (fseek(input, 0, SEEK_END) != 0){
        fprintf(stderr, "Seek failed.\n");
        fclose(input);
        return EXIT_FAILURE;
    }

    long bytes = ftell(input);
    if (bytes == -1){
        fprintf(stderr, "Tell failed.\n");
        fclose(input);
        return EXIT_FAILURE;
    }
    printf("%s: %ld bytes\n", argv[1], bytes);

    fclose(input);
    return EXIT_SUCCESS;
}