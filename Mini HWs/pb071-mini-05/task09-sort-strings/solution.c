#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/**
 * sort-strings
 *
 * \author Samuel Obuch
 */

/*
 * The main goal here was to read the input correctly and understand the usage
 * of the qsort and strcasecmp functions.
 * Note: One of great sources to approach when looking for a C function:
 *  https://en.cppreference.com/w/
 */

#define MAX_LEN 128
#define MAX_N 128

void read_end_of_line(void)
{
    int c;
    while ((c = getchar()) != EOF && c != '\n' && c != '\r') {
        ;
    }
}

unsigned read_n(void)
{
    unsigned n = 0;
    if (scanf("%u", &n) == 0) {
        perror("Invalid input.");
        exit(EXIT_FAILURE);
    }
    read_end_of_line();

    return n;
}

void read_input_string(char *input)
{
    if (fgets(input, MAX_LEN, stdin) == NULL) {
        *input = '\0';
    }

    char *new_line = strchr(input, '\n');

    if (new_line) {
        *new_line = '\0';
    } else {
        read_end_of_line();
    }
}

int main(void)
{
    char strings[MAX_N][MAX_LEN];
    unsigned n = read_n();

    if (n > MAX_N) {
        n = MAX_N;
    }

    for (unsigned i = 0; i < n; ++i) {
        read_input_string(strings[i]);
    }

    qsort(strings, n, MAX_LEN, (int (*)(const void *, const void *)) strcasecmp);

    for (unsigned i = 0; i < n; ++i) {
        puts(strings[i]);
    }

    return EXIT_SUCCESS;
}
