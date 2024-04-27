#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * caesar
 *
 * \author Adam Štěpánek <xstepan1@fi.muni.cz>
 */

/*
 * Below you can see a good example of using macros - describing numbers
 * whose meaning could not be clear if used in code as they are.
 */

#define SHIFT 3
#define ALPHABET_SIZE 26

int caesar(int character)
{
    if (islower(character)) {
        return (((character - 'a' + SHIFT) % ALPHABET_SIZE) + 'a');
    }
    if (isupper(character)) {
        return (((character - 'Z' - SHIFT) % ALPHABET_SIZE) + 'Z');
    }
    if (ispunct(character) || character == ' ') {
        return -1;
    }
    return character;
}

int main(void)
{
    int character;
    while ((character = getchar()) != EOF) {
        if ((character = caesar(character)) != EOF) {
            putchar(character);
        }
    }
    return EXIT_SUCCESS;
}
