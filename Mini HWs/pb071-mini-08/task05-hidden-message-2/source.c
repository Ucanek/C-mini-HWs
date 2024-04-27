#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 08: Hidden message 2
 * ---------------
 * Author: Michal Zima
 * Email:  xzima1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to decode a secret message hidden inside a binary file.
 *
 * Read a binary file char-by-char. The file has a special structure that
 * encodes a message:
 *
 *  1) The first byte tells you a relative position of the first character of
 *  the message from your current position.
 *  2) Get to the position and print the character on that position to stdout.
 *  3-..) Read the following byte. Use its value as an offset to your current
 *  position in the file. On the new position is your next character of the
 *  message. Again, print it out. And so on.
 *
 *  If the offset is 0xff, halt reading, clean up and exit.
 *
 * Hint: you can use the fseek() function.
 * 
 * For insufficient number of parameters for binary, print out usage to stderr.
 *
 * Create your own auxiliary functions if you want to.
 *
 * For arguments that have to be passed to compiled binary, see .args file(s).
 */

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }

    FILE* input = NULL;
    input = fopen(argv[1], "rb");
    if (input == NULL){
        fprintf(stderr, "Open failed.\n");
        return EXIT_FAILURE;
    }

    int offset = 0;
    char symbol;
    while (offset != 0xff){
        fseek(input, offset, SEEK_SET);
        symbol = fgetc(input);
        printf("%c", symbol);
    }

    return EXIT_SUCCESS;
}
