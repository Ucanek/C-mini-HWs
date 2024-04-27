#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

/*
 * Minihomework 05: Rotate the string
 * ---------------
 * Author: Peter Stanko
 * Email:  stanko@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to read a number from the first line of the input, string from
 * the second line of the input and rotate the string by the given number.
 * 
 * Reading of the number is already implemented in the function "read_number"
 * To read the string we endorse the usage of the `fgets` function
 * 
 * If the string given is longer than 254 characters, only use the first
 * 254 characters and discard the others.
 *
 * Rotation:
 * You will be rotating the characters in the string to the left side, which
 * means moving characters from index X to index X-1 and from 0 to the end.
 *
 * If rotate_n is greater than length of the string, you should use modulus.
 *
 * You can use provided helper functions.
 *
 * Examples:
 * rotate_string(1, "ahoj") ~> "hoja"
 * rotate_string(0, "ahoj") ~> "ahoj"
 * rotate_string(4, "ahoj") ~> "ahoj"
 * rotate_string(N, "") ~> ""
 *
 */

void read_input_string(char *input);
void rotate_string(char *input, unsigned rotate_n, char *rotated);
void read_end_of_line(void);
unsigned read_number(void);

void read_input_string(char *input)
{
    fgets(input, MAX_LEN, stdin);
    input[strlen(input) - 1] = '\0';
}

void rotate_string(char *input, unsigned rotate_n, char *rotated)
{
    for (int i = 0; i < rotate_n; i++){
        char first_char = input[0];
        strcpy(rotated, input + 1);
        rotated[strlen(input) - 1] = first_char;
        rotated[strlen(input)] = '\0';
        strcpy(input, rotated);
    }
}

//
// HELPER FUNCTIONS
//
void read_end_of_line(void)
{
    int c;
    while ((c = getchar()) != EOF && c != '\n' && c != '\r');
}

unsigned read_number(void)
{
    unsigned rotate_n = 0;
    if (scanf("%u", &rotate_n) == 0) {
        fprintf(stderr, "Invalid input for the rotate N factor.\n");
        exit(EXIT_FAILURE);
    }
    read_end_of_line();

    return rotate_n;
}

int main(void)
{
    /* Reads N - already provided*/
    unsigned rotate_n = read_number();

    /* Reads provided string that will be rotated - You should implement */
    char input_string[MAX_LEN];
    read_input_string(input_string);

    /* Rotates the string */
    char rotated_string[MAX_LEN];
    rotate_string(input_string, rotate_n, rotated_string);

    /* Prints rotated string */
    puts(rotated_string);
    return EXIT_SUCCESS;
}
