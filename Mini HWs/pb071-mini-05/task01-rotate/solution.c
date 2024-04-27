#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * rotate
 *
 * \author Peter Stanko
 */

/*
 * Never forget the ending '\0' when manipulating with strings!
 */

#define MAX_LEN 255

void read_end_of_line(void);
unsigned read_number(void);
void read_input_string(char *input);
void rotate_string(char *input, unsigned rotate_n, char *rotated);

void read_end_of_line(void)
{
    int c = 0;
    while ((c = getchar()) != EOF && c != '\n' && c != '\r');
}

unsigned read_number(void)
{
    unsigned rotate_n = 0;
    if (scanf("%u", &rotate_n) == 0) {
        fprintf(stderr, "Invalid input for the rotate N factor.\n");
        exit(EXIT_FAILURE);
    }
    read_end_of_line();

    return rotate_n;
}

void read_input_string(char *input)
{
    if (fgets(input, MAX_LEN, stdin) == NULL) {
        *input = '\0';
    }

    char *new_line = strchr(input, '\n');

    if (new_line != NULL) {
        *new_line = '\0';
    }
}

void rotate_string(char *input, unsigned rotate_n, char *rotated)
{
    size_t input_len = strlen(input);

    if (input_len == 0) {
        strncpy(rotated, input, input_len + 1);
        return;
    }

    rotate_n %= input_len;

    if (rotate_n == 0) {
        strncpy(rotated, input, input_len + 1);
        return;
    }

    for (unsigned i = 0; i < input_len; i++) {
        unsigned new_position = (rotate_n + i) % (input_len);
        rotated[i] = input[new_position];
    }

    rotated[input_len] = '\0';
}

int main(void)
{
    unsigned rotate_n = read_number();
    char input_string[MAX_LEN];
    read_input_string(input_string);
    char rotated_string[MAX_LEN];
    rotate_string(input_string, rotate_n, rotated_string);
    puts(rotated_string);
    return EXIT_SUCCESS;
}
