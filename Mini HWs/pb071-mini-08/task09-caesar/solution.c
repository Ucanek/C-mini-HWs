#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * caesar
 *
 * \author Adrian Hrinko
 */

/*
 * You do not have to care about the "END" sequence since it does not parse
 * to the "%d %s" string.
 */

#define START_LOWER_CASE 'a'
#define START_UPPER_CASE 'A'

int main(void)
{
    char string[256];
    int number;

    while (scanf("%d %s", &number, string) == 2) {
        size_t size = strlen(string);
        for (size_t i = 0; i < size; i++) {
            if (islower(string[i])) {
                string[i] = (string[i] + number - START_LOWER_CASE) % 26 + START_LOWER_CASE;
            } else if (isupper(string[i])) {
                string[i] = (string[i] + number - START_UPPER_CASE) % 26 + START_UPPER_CASE;
            }
        }
        printf("%s\n", string);
    }

    return EXIT_SUCCESS;
}
