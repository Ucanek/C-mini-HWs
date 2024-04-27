#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * Minihomework 09: Modified Caesar cipher
 * ---------------
 * Author: Adam Štěpánek
 * Email:  xstepan1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to write function 'caesar' that takes a character (int) and
 * returns a transformed character (int) in this manner:
 *  - Shift the character forwards by 3 if it's lowercase.
 *  - Shift the character backwards by 3 if it's uppercase.
 *  - Return -1 if the input is punctuation or the space character.
 *  - Otherwise return input unchanged.
 * 
 * Example:
 *      Hello, World!
 * becomes
 *      EhoorTruog (the symbols returning -1 are omitted in main)
 * 
 * The 'main' function reads characters one by one and prints the ciphered
 * output back.
 * 
 * You can exit the program using ^D on *nix systems and ^Z + Enter on an
 * empty line on Windows.
 */


int caesar(int character)
{
    /* TODO your code here instead of returning character */
    return character;
}

//=============================================================================
// DO NOT EDIT ANYTHING BELOW THIS LINE
//=============================================================================

int main(void)
{
    int character;
    while ((character = getchar()) != -1) {
        if ((character = caesar(character)) != -1) {
            putchar(character);
        }
    }
    return EXIT_SUCCESS;
}
