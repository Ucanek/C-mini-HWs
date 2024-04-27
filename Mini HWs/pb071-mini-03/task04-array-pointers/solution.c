#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * array-pointers
 *
 * \author Dominik Dubravický
 */

/*
 * For working with strings, use string.h library with many useful functions.
 * Note: Bool is just a type alias for int.
 */

bool is_in_range(char *string, int index)
{
    return (index >= 0) && ((size_t) index < strlen(string));
}

char get_letter(char *string, int index)
{
    if (is_in_range(string, index)) {
        return string[index];
    }
    return 0;
}

void set_letter(char *string, int index, char value)
{
    if (is_in_range(string, index)) {
        string[index] = value;
    }
}

int main(void)
{
    char s[] = "Ahoj";

    printf("%d %d %d\n", get_letter(s, 3), get_letter(s, 7), get_letter(s, 0));
    printf("%s\n", s);

    for (size_t i = 0; i < strlen(s); i++) {
        set_letter(s, i, get_letter(s, i) + 1);
    }
    printf("%s\n", s);

    return 0;
}
