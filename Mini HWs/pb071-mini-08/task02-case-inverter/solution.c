#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * case-inverter
 *
 * \author Matus Dugacek
 */

/*
 * Printing usage is common output of incorrectly called functions.
 */

#define BUFFER_SIZE 128

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *original_file = fopen(argv[1], "r");
    if (original_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *new_file = fopen(argv[2], "w+");
    if (new_file == NULL) {
        perror("fopen");
        fclose(original_file);
        return EXIT_FAILURE;
    }

    int c = getc(original_file);
    while (c != EOF) {
        if (isalpha(c) != 0) {
            if (isupper(c)) {
                c = tolower(c);
            } else {
                c = toupper(c);
            }
        }

        putc(c, new_file);
        c = getc(original_file);
    }

    fclose(original_file);

    /* dump everything to stdout */
    rewind(new_file);
    char buffer[BUFFER_SIZE];
    size_t ret;
    while ((ret = fread(buffer, sizeof(char), BUFFER_SIZE, new_file)) > 0) {
        fwrite(buffer, sizeof(char), ret, stdout);
    }
    fclose(new_file);

    return EXIT_SUCCESS;
}
