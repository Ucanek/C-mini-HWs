#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 08: bin2hex
 * ---------------
 * Author: Michal Zima
 * Email:  xzima1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise. you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to convert binary data given on standard input to hexadecimal
 * and print them to standard output.
 *
 * Keep in mind that this conversion is usually zero-padded and lower-case.
 * example: 1 will convert to 01
 *          16 will convert to a0
 */

int main(void)
{
    int character;

    while ((character = getchar()) != EOF){
        printf("%02x ", character);
    }

    return EXIT_SUCCESS;
}
