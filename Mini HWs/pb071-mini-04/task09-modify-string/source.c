#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 20

void remove_last(char *str);
void increment_by_one(char *str);
void string_to_upper(char *str);

/*
 * Minihomework 04: Modify string
 * ---------------
 * Author: Zoltan Fridrich
 * Email:  xfridri1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Your task is to implement a function that takes an array of
 * pointers to functions as an argument and applies them to a given string.
 *
 * 1. Complete function signature.
 *    The second parameter should be an array of pointers to functions.
 *
 * 2. Implement the body of function.
 *    Just iterate over the array and call the functions. An array of pointers
 *    to functions is NULL-terminated, this means when you hit NULL you
 *    can stop iterating ;-)
 *
 * The array of function pointers contains functions you will need to apply
 * to a given string in the modify_string function.
 *
 * Explore the main function to determine the signature of the function and
 * the syntax of function pointers.
 *
 * Hint: Keep in mind that the function itself is a pointer :-)
 *
 * Warning: Tests might not work properly if line separator is not LF ("\n").
 * Windows CRLF ("\r\n") is a problem.
 *
 * Do not change anything else except function modify_string.
 */

void modify_string(char *str, void (*func_array[])(char *))
{
    //int function_number = sizeof(func_array) / sizeof(func_array[0]);
    for (int i = 0; i < 4; i++){
        if (func_array[i] == NULL){
            break;
        }
        func_array[i](str);
    }
}

int main(void)
{
    char str[BUFFER_SIZE];
    if (fgets(str, BUFFER_SIZE, stdin) == NULL) {
        return EXIT_FAILURE;
    }

    remove_last(str); // cut out a newline character
    printf("Original string: \"%s\"\n", str);

    void (*func_array[])(char *) = { remove_last, increment_by_one, string_to_upper, NULL };

    modify_string(str, func_array);

    printf("Modified string: \"%s\"\n", str);
    return EXIT_SUCCESS;
}

//**************** Modifier functions *****************

void remove_last(char *str)
{
    if (str == NULL || *str == '\0') {
        return;
    }

    size_t len = strlen(str);
    str[len - 1] = '\0';
}

void increment_by_one(char *str)
{
    for (; *str; ++str) {
        if (isalpha(*str)) {
            ++*str;
        }
    }
}

void string_to_upper(char *str)
{
    for (; *str; ++str) {
        *str = toupper((unsigned char) *str);
    }
}
