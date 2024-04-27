#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * write-lower-upper
 *
 * \author Samuel Obuch
 */

/*
 * Printing character uppercase and lowercase is basically the same
 * funcionality, so it should be managed with single function with
 * different parameters (although these are other functions).
 */

#define MAX_LEN 255

void read_input_string(char *input)
{
    if (fgets(input, MAX_LEN, stdin) == NULL) {
        *input = '\0';
    }

    char *new_line = strchr(input, '\n');

    if (new_line) {
        *new_line = '\0';
    }
}

void print_func(char *input, int (*func)(int)) {
    size_t input_len = strlen(input);

    for (unsigned i = 0; i < input_len; i++) {
        putchar(func(input[i]));
    }
    putchar('\n');
}

void print_lower(char *input)
{
    print_func(input, &tolower);
}

void print_upper(char *input)
{
    print_func(input, &toupper);
}

int main(void)
{
    char input_string[MAX_LEN];
    read_input_string(input_string);

    print_lower(input_string);
    print_upper(input_string);

    return EXIT_SUCCESS;
}
