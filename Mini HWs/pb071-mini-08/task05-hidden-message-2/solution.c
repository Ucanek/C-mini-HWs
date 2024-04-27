#include <stdio.h>
#include <stdlib.h>

/**
 * hidden-message-2
 *
 * \author Michal Zima
 */

/*
 * The SEEK_CUR macro defines the current position in stream.
 */

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    int character = fgetc(input_file);
    while (character != EOF && character != 0xff) {
        if (fseek(input_file, (char) character, SEEK_CUR) != 0) {
            perror("fseek");
            return EXIT_FAILURE;
        }

        character = fgetc(input_file);
        if (character == EOF) {
            fprintf(stderr, "Error: incorrect file format\n");
            return EXIT_FAILURE;
        }
        putchar(character);

        character = fgetc(input_file);
    }

    fclose(input_file);

    return EXIT_SUCCESS;
}
