#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * Minihomework 05: Palindrome
 * ---------------
 * Author: Stepanka Gennertova
 * Email:  451432@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to implement a function which checks if given string is a
 * palindrome (from backwards it is the same as from frontwards) or not.
 *
 * Return true if string is palindrome, false otherwise.
 *
 * (what is palindrome => https://en.wikipedia.org/wiki/Palindrome)
 *
 * The main function takes word from standard input and prints YES/NO based
 * on whether the word is palindrome (this is already implemented).
 *
 * Empty string is a palindrome.
 *
 * You can assume that input string is 63 characters long at most.
 *
 * Example:
 * is_palindrome("madam") -> 0
 * is_palindrome("abc") -> 1
 */

bool is_palindrome(char *string)
{
    if (strlen(string) == 0){
        return true;
    }
    int i = 0;
    while (i <= strlen(string) / 2){
        if (string[i] == string[strlen(string) - i - 1]){
            i++;
        }
        else{
            return false;
        }
    return true;
    }
}

// do not change following code!
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
