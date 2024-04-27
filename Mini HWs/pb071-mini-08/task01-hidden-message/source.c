#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 08: Hidden message decoder
 * ---------------
 * Author: Ján Dovjak
 * Email:  xdovjak@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to decode hidden message from the input file and print decoded
 * message to the standard output. Message is hidden in every second character
 * in input file, starting from position 0.
 *
 * Read input file char-by-char. The input file is given in the first argument.
 *
 * So basically you have to print every character on even (sudá, párna)
 * position to decode the message.
 *
 * Do not forget to check the arguments and whether the file was opened
 * correctly.
 *
 * For arguments that have to be passed to compiled binary, see .args file(s).
 *
 * Good luck, have fun :)
 */

int main(int argc, char **argv)
{
    if (argc != 2){
        return EXIT_FAILURE;
    }

    FILE *input;
    input = fopen(argv[1], "r");

    if (input == NULL){
        return EXIT_FAILURE;
    }

    int even_position;

    while ((even_position = getc(input)) != EOF){
        putchar(even_position);
        getc(input);
    }

    fclose(input);

    return EXIT_SUCCESS;
}
