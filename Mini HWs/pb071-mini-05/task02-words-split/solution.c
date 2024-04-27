#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * words-split
 *
 * \author Peter Stanko
 */

/*
 * You can also iterate over an array (or a string, which is an array of chars)
 * by continually increasing its pointer.
 * Note: After this iteration, the pointer is invalid (pointing to '\0')
 * and you cannot use it later in the function (but no harm is caused when
 * returned from that function - parameters are passed by copying the values).
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

void replace_spaces(char *input)
{
    while (*input) {
        if (isspace(*input)) {
            *input = '\n';
        }
        input++;
    }
}

int main(void)
{
    char input[MAX_LEN];
    read_input_string(input);
    replace_spaces(input);
    puts(input);

    return EXIT_SUCCESS;
}
