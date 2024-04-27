#include <stdio.h>
#include <stdlib.h>

/**
 * hidden-message
 *
 * \author Ján Dovjak
 */

/*
 * Always close the files you opened.
 */

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input;
    input = fopen(argv[1], "r");

    if (input == NULL) {
        fprintf(stderr, "Problem with %s input file", argv[1]);
        return EXIT_FAILURE;
    }

    int even_position;

    while ((even_position = getc(input)) != EOF) {
        putchar(even_position);

        /* discard characters on odd positions */
        getc(input);
    }

    fclose(input);

    return EXIT_SUCCESS;
}
