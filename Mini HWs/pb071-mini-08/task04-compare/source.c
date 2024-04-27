#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 08: Char-by-char comparison tool
 * ---------------
 * Author: Lukáš Zaoral
 * Email:  x456487@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwi,se you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to create a simple char-by-char comparison tool which checks
 * two files with their corresponding names as arguments (usage is below).
 *
 * If the two files match, print "MATCH\n" to the standard output, otherwise
 * print "NO MATCH\n" to the standard error output.
 *
 * Let's denote that files match if and only if they have same contents
 * and both reach their end simultaneously.
 *
 * For insufficient number of parameters for binary, print out usage to stderr.
 *
 * Create your own auxiliary functions if you want to.
 *
 * For arguments that have to be passed to compiled binary, see .args file(s).
 */

int compareFiles(FILE *file1, FILE *file2) {
    int char1, char2;

    do {
        char1 = fgetc(file1);
        char2 = fgetc(file2);

        if (char1 != char2) {
            return 0; // Files do not match
        }

    } while (char1 != EOF && char2 != EOF);

    // If both files reach the end simultaneously, consider them as a match
    return char1 == char2;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    // Check if files are opened successfully
    if (file1 == NULL || file2 == NULL) {
        perror("Error opening files");
        return EXIT_FAILURE;
    }

    // Compare the files
    if (compareFiles(file1, file2)) {
        printf("MATCH\n");
    } else {
        fprintf(stderr, "NO MATCH\n");
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    return EXIT_SUCCESS;
}