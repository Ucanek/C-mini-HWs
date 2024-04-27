#include <stdio.h>
#include <stdlib.h>

/**
 * compare
 *
 * \author Lukáš Zaoral
 */

/*
 * You can have opened as many files as you want, as long as their FILE data
 * fits into memory.
 */

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file01 source_file02\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        perror("fopen - source01");
        return EXIT_FAILURE;
    }

    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        perror("fopen - source02");
        fclose(file1);
        return EXIT_FAILURE;
    }

    // First we read both files, then we check if already reached EOF or if
    // an error occurred, and finally, we compare both values.
    int c1, c2;
    do {
        c1 = fgetc(file1);
        c2 = fgetc(file2);
    } while (c1 != EOF && c1 == c2);

    int ret;
    if ((ret = ferror(file1) || ferror(file2))) {
        fprintf(stderr, "I/O ERROR\n");
    } else if ((ret = feof(file1) != feof(file2) || c1 != c2)) {
        fprintf(stderr, "NO MATCH\n");
    } else {
        puts("MATCH");
    }

    if (fclose(file1) == EOF) {
        ret = 1;
        perror("fclose - source01");
    }

    if (fclose(file2) == EOF) {
        ret = 1;
        perror("fclose - source02");
    }

    return ret ? EXIT_FAILURE : EXIT_SUCCESS;
}
