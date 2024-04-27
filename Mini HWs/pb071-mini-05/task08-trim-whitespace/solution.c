#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 * trim-whitespace
 *
 * \author Ondrej Machala
 */

/*
 * In the for loop you can see that there is no obligation about executing
 * just one command in the end of each iteration - just separate all your
 * commands to be executed with commas.
 */

#define MAX_SIZE 256

void trim(char *str)
{
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (isspace((unsigned char) *start)) {
        start++;
    }
    while (start <= end && isspace((unsigned char) *end)) {
        end--;
    }
    for (; start <= end; str++, start++) {
        *str = *start;
    }
    *str = '\0';
}

void read_input(char *buf)
{
    if (fgets(buf, MAX_SIZE, stdin) == NULL) {
        *buf = '\0';
    }

    char *new_line = strchr(buf, '\n');

    if (new_line) {
        *new_line = '\0';
    }
}

int main(void)
{
    char str[MAX_SIZE];

    read_input(str);
    trim(str);

    printf("\"%s\"\n", str);

    return EXIT_SUCCESS;
}
