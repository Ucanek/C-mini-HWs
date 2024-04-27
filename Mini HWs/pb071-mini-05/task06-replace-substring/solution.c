#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * replace-substring
 *
 * \author Stepanka Gennertova
 */

/*
 * Copying strings can be tricky, always check the size of destination string
 * and do not forget about ending '\0'.
 */

#define MAX_LEN 256

void read_string(char *input)
{
    if (fgets(input, MAX_LEN, stdin) == NULL) {
        input[0] = '\0';
    }

    char *newline = strchr(input, '\n');

    if (newline) {
        *newline = '\0';
    }
}

void replace(const char *str, const char *orig_substr, const char *rep_str, char *result_str)
{
    char *start = strstr(str, orig_substr);

    if (start == NULL) {
        strncpy(result_str, str, MAX_LEN);
        return;
    }

    if (strlen(str) - strlen(orig_substr) + strlen(rep_str) >= MAX_LEN) {
        strncpy(result_str, str, MAX_LEN);
        return;
    }

    strncpy(result_str, str, start - str);
    strncpy(result_str + (start - str), rep_str, MAX_LEN - (size_t)(start - str));

    strncat(result_str, start + strlen(orig_substr), MAX_LEN - strlen(orig_substr));
}

int main(void)
{
    char orig_str[MAX_LEN];
    char orig_substr[MAX_LEN];
    char rep_str[MAX_LEN];
    char result_str[MAX_LEN];

    read_string(orig_str);
    read_string(orig_substr);
    read_string(rep_str);

    replace(orig_str, orig_substr, rep_str, result_str);
    puts(result_str);

    return EXIT_SUCCESS;
}
