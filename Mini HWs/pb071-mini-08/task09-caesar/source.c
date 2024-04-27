#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Minihomework 08: caesAr cipHer
 * ---------------
 * Author: Adrian Hrinko
 * Email:  456684@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to decode famous Caesar cipher
 * (https://en.wikipedia.org/wiki/Caesar_cipher).
 *
 * There is going to be input on stdin in the following format:
 *
 * 1 aBc_DeFg
 * 26 aaaa
 *
 * 27 aaaa
 * 2 abcd
 * END
 * 
 * On every line there is a number, then space and then some character sequence
 * with random length (but not more than 256 characters) with no whitespaces.
 * The number represents the shift in alphabet in positive direction (you can
 * expect only positive numbers or 0).
 *
 * For example, if we have number 3 and letter c we will get letter f as result.
 *
 * Watch out for the end of the alphabet!!! For example, when we have number 2
 * and letter Z we will get letter B as result and so on.
 *
 * Only alphabetic characters can be shifted. Other symbols should stay intact!
 * Empty lines are to be omitted. Input is always closed by a character
 * sequence END.
 *
 * So to make things clear, for the input on stdin above, there is going to be
 * the following output on stdout:
 *
 * bCd_EfGd
 * aaaa
 * bbbb
 * cdef
 */

int main(void)
{
    int shift = 0;
    char shifted_string[256];
    scanf("%d %s", &shift, shifted_string);
    //printf("%d %s\n", shift, shifted_string);
    shift = shift % 26;
    //printf("%d\n", shift);

    for (int i = 0; i < strlen(shifted_string); i++){
        if (isalpha(shifted_string[i])){
            shifted_string[i] += shift;
            if (shifted_string[i] > 122){
                shifted_string[i] = 96 + (shifted_string[i] - 122);
            }
            else if (shifted_string[i] > 90){
                shifted_string[i] = 64 + (shifted_string[i] - 90);
            }
        }
        printf("%c", shifted_string[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
