#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * substring-count
 *
 * \author Ondrej Machala
 */

/*
 * Do not reinvent wheel here, <string.h> has everything you need.
 */

#define MAX_SIZE 256

int substr_count(const char *str, const char *substr)
{
    if (strlen(substr) == 0) {
        return -1;
    }
    int count = 0;
    while ((str = strstr(str, substr)) != NULL) {
        str++;
        count++;
    }
    return count;
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
    char substr[MAX_SIZE];

    read_input(str);
    read_input(substr);

    int count = substr_count(str, substr);
    if (count == -1) {
        printf("Empty substring\n");
    } else {
        printf("Substring count: %d\n", count);
    }
    return EXIT_SUCCESS;
}
