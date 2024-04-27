#include <stdio.h>
#include <stdlib.h>

/**
 * file-size
 *
 * \author Lukáš Zaoral
 */

/*
 * For handling file as group of bytes, use "b" mode when opening it.
 */

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s source_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    if (fseek(file, 0, SEEK_END)) {
        perror("fseek");

        if (fclose(file)) {
            perror("fclose");
        }

        return EXIT_FAILURE;
    }

    long int bytes = ftell(file);
    if (bytes == -1) {
        perror("ftell");

        if (fclose(file)) {
            perror("fclose");
        }

        return EXIT_FAILURE;
    }

    printf("%s: %ld bytes\n", argv[1], bytes);

    if (fclose(file)) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
