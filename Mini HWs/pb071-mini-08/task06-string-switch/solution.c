#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * string-switch
 *
 * \author Matus Dugacek
 */

/*
 * Functions like rename() and remove() make it possible to work directly with
 * files/filesystems.
 */

#define BUFFER_SIZE 128

void switch_parts(char input[100], char output[100])
{
    char *first_string = strtok(input, ";");
    char *second_string = first_string + strlen(first_string) + 1;

    sprintf(output, "%s%c%s\n", second_string, ';', first_string);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: <argv[0]> input_file output_file\n");
        return EXIT_FAILURE;
    }

    FILE *source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        perror("fopen");
        fprintf(stderr, "Error: Unable to open source file.\n");
        return EXIT_FAILURE;
    }
    FILE *destination_file = fopen(argv[2], "w+");
    if (destination_file == NULL) {
        perror("fopen");
        fprintf(stderr, "Error: Unable to open destination file.\n");
        fclose(source_file);
        return EXIT_FAILURE;
    }

    char input_string[100] = { 0 };
    char output_string[100] = { 0 };

    int read_elements = 0;
    while ((read_elements = fscanf(source_file, "%99s\n", input_string)) != EOF) {
        if (read_elements != 1) {
            perror("Wrong file format");
            return EXIT_FAILURE;
        }

        switch_parts(input_string, output_string);
        fputs(output_string, destination_file);
    }
    fclose(source_file);

    if (rename(argv[2], "output.txt") != 0) {
        perror("Unable to rename the file");
        return EXIT_FAILURE;
    }

    /* dump everything to stdout */
    rewind(destination_file);
    char buffer[BUFFER_SIZE];
    size_t ret;
    while ((ret = fread(buffer, sizeof(char), BUFFER_SIZE, destination_file)) > 0) {
        fwrite(buffer, sizeof(char), ret, stdout);
    }
    fclose(destination_file);

    if (remove("output.txt") != 0) {
        perror("remove");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
