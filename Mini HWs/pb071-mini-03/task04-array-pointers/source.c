#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
 * Minihomework 03: Array pointers
 * ---------------
 * Author: Dominik Dubravický
 * Email:  xdubrav@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 *
 * Implement functions described below.
 * Remember that string is an array and as such is indexed from zero.
 */

/* Function 1: is_in_range
 * Returns whether the given index is in range of the string (between 0 and
 * string length, including).
 */

bool is_in_range(char *string, int index)
{
    int string_lenght = 0;
    while (string[string_lenght] != '\0'){
        string_lenght++;
    }
    if (index > string_lenght){
        return false;
    }
    return true;
}

/*
 * Function 2: get_letter
 * For indexes in range of given string, returns character at given index,
 * otherwise 0.
 */

char get_letter(char *string, int index)
{
    if (is_in_range(string, index)){
        return string[index];
    }
    return 0;
}

/*
 * Function 3: set_letter
 * For indexes in range of given string, sets character at given index to given
 * value, otherwise does nothing.
 */

void set_letter(char *string, int index, char value)
{
    if (is_in_range(string, index)){
        string[index] = value;
    }

}

int main(void)
{
    char s[] = "Ahoj";

    printf("%d %d %d\n", get_letter(s, 3), get_letter(s, 7), get_letter(s, 0));
    printf("%s\n", s);

    for (int i = 0; i < strlen(s); i++) {
        set_letter(s, i, get_letter(s, i) + 1);
    }
    printf("%s\n", s);

    return 0;
}
