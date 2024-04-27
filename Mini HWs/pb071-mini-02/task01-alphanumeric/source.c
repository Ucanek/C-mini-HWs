#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 02: Alphanumeric
 * ---------------
 * Author: Roman Chrenšť
 * Email:  469253@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Implement function alphanumeric, so that if a number has a corresponding
 * value in ASCII, i.e. a digit or a letter (1 - 9, a - z, A - Z),
 * it prints out that character, otherwise it prints the same number.
 * Every character should be followed by a newline character right after it.
 */

void alphanumeric(int num)
{
    if ((num >= 48 && num <= 57) || (num >= 65 && num <= 90) || (num >= 97 && num <= 122) ){
        printf("%c\n", num);
    }
    else{
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
