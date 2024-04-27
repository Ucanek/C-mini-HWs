#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Minihomework 05: replace_substring
 * ---------------
 * Author: Stepanka Gennertova
 * Email:  451432@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to implement a function replace, which replaces the first
 * occurrence of 'orig_substr' in 'str' with 'rep_str'. All these three are
 * read from separate lines in standard input (this is already done in main).
 *
 * The result of this function should be returned in 'result_str' and printed
 * (also already done).
 *
 * If there is no occurrence of orig_substr in str, return unchanged str.
 *
 * If the resulting string would be longer than MAX_LEN, so it would not fit in
 * result_str pointer, return unchanged str.
 *
 * Example:
 * replace("abced", "ed", "de", result_str) -> "abcde".
 */

#define MAX_LEN 256

void replace(const char *str, const char *orig_substr, const char *rep_str, char *result_str)
{
    char *substr_ptr = strstr(str, orig_substr);
    if (substr_ptr == NULL || strlen(str) + strlen(rep_str) - strlen(orig_substr) >= MAX_LEN) {
        strcpy(result_str, str);
        return;
    }
    strncpy(result_str, str, substr_ptr - str);
    strcat(result_str, rep_str);
    strcat(result_str, substr_ptr + strlen(orig_substr));
}

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
