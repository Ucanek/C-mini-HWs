#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*
 * Minihomework 05: Trim whitespace
 * ---------------
 * Author: Ondrej Machala
 * Email:  469122@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to implement a trim function trim which takes a string as
 * an argument and removes all leading and trailing whitespace characters from
 * the string.
 *
 * The program below accepts a string of up to 255 characters from stdin and
 * applies trim to that string. It then prints the resulting string in quotes.
 *
 * The function should remove the whitespace characters in-place (it returns
 * void), so you have to modify the input string.
 *
 * Hint: isspace
 *
 * Example:
 * trim("  word  ") -> "word"
 */

#define MAX_SIZE 256

void trim(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;

    while (isspace(str[start])){
        start++;
    }

    while (end > start && isspace(str[end])){
        end--;
    }

    memmove(str, str + start, end - start + 1);
    str[end - start + 1] = '\0';
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
