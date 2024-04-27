#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fnmatch.h>

/**
 * pattern-match
 *
 * \author Vojtech Jelinek
 */

/*
 * Regular expressions have the same syntax in POSIX C as in for example Linux
 * grep function (for searching in files).
 */

int count_matching_files(int filenames_count, char **filenames)
{
    int count = 0;
    for (int i = 0; i < filenames_count; i++) {
        if (fnmatch("dog_*_2018-*.jpg", filenames[i], FNM_PATHNAME) == 0) {
            count++;
        }
    }

    return count;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s files\n", argv[0]);
        return EXIT_FAILURE;
    }

    int count = count_matching_files(argc - 1, argv + 1);
    printf("%d\n", count);
    return EXIT_SUCCESS;
}
