#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Minihomework 05: Substring count
 * ---------------
 * Author: Ondrej Machala
 * Email: 469122@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to implement the substr_count function. It takes two strings
 * as arguments, and should return the number of occurrences of second argument
 * in the first argument.
 *
 * If the second argument is an empty string, the function should return -1.
 *
 * The main function reads two strings from separate input lines and then
 * computes substr_count with these strings as arguments and prints the result
 * to standard output.
 *
 * You can assume that lengths of both strings do not exceed 255 characters.
 *
 * Just implement substr_count, everything else is already provided.
 *
 * The substrings can overlap, therefore substr_count("ababa","aba") should
 * return 2, not 1.
 */

#define MAX_SIZE 256

int substr_count(const char *str, const char *substr)
{
    if (strlen(substr) == 0){
        return -1;
    }
    int occurrences = 0;
    int substrLen = strlen(substr) - 1;
    for (int i = 0; i <= strlen(str); i++){
        if (strstr(str, substr) != NULL){
            occurrences++;
            str += substrLen;
        }
    }
    return occurrences;
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
