#include <stdio.h>
#include <stdlib.h>

/*
 * Simple iteration over given array with step 2.
 */

void print_odd(char txt[], size_t len)
{
    for (size_t i = 1; i < len; i += 2) {
        printf("%c", txt[i]);
    }

    printf("\n");
}

int main(void)
{
    char txt1[] = {'H', 'e', 'l', 'l', 'o'};
    char txt2[] = {'w', 'o', 'r', 'l', 'd', '!'};
    char txt3[] = {'a', 'b'};
    char txt4[] = {'a'};

    print_odd(txt1, 5);
    print_odd(txt2, 6);
    print_odd(txt3, 2);
    print_odd(txt4, 1);

    return EXIT_SUCCESS;
}
