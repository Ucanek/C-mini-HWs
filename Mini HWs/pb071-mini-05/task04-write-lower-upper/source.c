#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 255
/*
 * Minihomework 04: Uppercase and lowercase string print
 * ---------------
 * Author: Samuel Obuch
 * Email:  456163@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to read a line from standard input and then print that line
 * to the standard output, first in all lowercase and then in all uppercase.
 *
 * If the line is longer than 254 characters, only use the first
 * 254 characters and discard the other ones.
 *
 * Only empty body of main function is provided, make your own auxiliary
 * functions if you find useful.
 *
 * Hint: You might want to convert a character to uppercase (lowercase resp.)
 * and these functions can be found somewhere in C library.
 *
 * Example
 *
 * Input:
 * abCDe123
 *
 * Output:
 * abcde123
 * ABCDE123
 *
 */


int main(void)
{
    char my_string[MAX_LEN];
    fgets(my_string, MAX_LEN, stdin);
    char Lowercase[strlen(my_string)];
    char Uppercase[strlen(my_string)];

    for (int i = 0; i < strlen(my_string) - 1; i++){
        if (isupper(my_string[i])){
            Lowercase[i] = tolower(my_string[i]);
            Uppercase[i] = my_string[i];
        }
        else if (islower(my_string[i])){
            Lowercase[i] = my_string[i];
            Uppercase[i] = toupper(my_string[i]);
        }
        else{
            Lowercase[i] = my_string[i];
            Uppercase[i] = my_string[i];
        }
    }

    printf("%s\n%s\n", Lowercase, Uppercase);
    //printf("%s", Uppercase);
    return EXIT_SUCCESS;
}
