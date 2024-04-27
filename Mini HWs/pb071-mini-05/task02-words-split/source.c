#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 255

/*
 * Minihomework 05: Line to words split
 * ---------------
 * Author: Peter Stanko
 * Email:  stanko@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to read a string from input line (function read_input_string)
 * and split it by the method described below (function replace_spaces).
 *
 * To read the string we endorse the usage of the `fgets` function.
 *
 * If the string given is longer than 254 characters, only use the first
 * 254 characters and discard the others.
 * 
 * SPLIT:
 * You should split the read string by space symbols (use `isspace` function
 * from ctype.h library to check whether the char is a space) and print each
 * substring on separate line.
 *
 * If there are consecutive spaces, you will not ignore them but threat them
 * as if they were separating an empty word.
 *
 * Hint: you can just replace each space with '\n' character.
 *
 * Examples:
 * replace_spaces("hello world") ~> "hello\nword\n"
 * replace_spaces("hello  world") ~> "hello\n\nword"
 *      (There are two spaces between "hello" and "world", so we get two \n)
 * replace_spaces("hello  world\tHow\rIs   Your day?")
 *      ~> "hello\n\nworld\nHow\nIs\n\n\nYour\nday?"
 */

void read_input_string(char *input);
void replace_spaces(char *input);

void read_input_string(char *input)
{
    fgets(input, MAX_LEN, stdin);
    input[strlen(input) - 1] = '\n';
}

void replace_spaces(char *input)
{
    for (int i = 0; i < MAX_LEN; i++){
        if (isspace(input[i]) != 0){
            input[i] = '\\';
            //input[i + 1] = 'n';
        }
    }
}

int main(void)
{
    char input[MAX_LEN];
    read_input_string(input);
    replace_spaces(input);
    puts(input);

    return EXIT_SUCCESS;
}
