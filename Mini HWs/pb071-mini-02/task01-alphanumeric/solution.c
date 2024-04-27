#include <stdio.h>
#include <stdlib.h>

/**
 * Alphanumeric
 *
 * \author Roman Chrenšť
 */

/*
 * Just check whether the given number is ASCII code for alphanumeric character
 * and then print it in desired format.
 * Note: For better readability of the code, do not use ASCII codes
 * as numbers if they refer to a character.
 * Note: No conversion is necessary if printing out int as character,
 * only use another formatting string.
 */

void alphanumeric(int num)
{
    if ((num >= '1' && num <= '9') || (num >= 'A' && num <= 'Z') || (num >= 'a' && num <= 'z')) {
        printf("%c\n", num);
    } else {
        printf("%d\n", num);
    }
}

// do not change following code!
int main(void)
{
    alphanumeric(50);
    alphanumeric(100);
    alphanumeric(0);
    alphanumeric(1000);
    return EXIT_SUCCESS;
}
