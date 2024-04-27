#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * palindrome
 *
 * \author Stepanka Gennertova
 */

/*
 * Although bool is just an alias for int (0 true, 1 false), using these
 * aliases makes the code cleaner and more readable.
 */

bool is_palindrome(char *string)
{
    unsigned length = strlen(string);

    if (length == 0) {
        return true;
    }

    for (unsigned i = 0; 2 * i <= length; i++) {
        if (string[i] != string[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    char buffer[64];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        return EXIT_FAILURE;

    char *nl = strchr(buffer, '\n');
    if (nl != NULL)
        *nl = '\0';

    if (is_palindrome(buffer)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return EXIT_SUCCESS;
}
