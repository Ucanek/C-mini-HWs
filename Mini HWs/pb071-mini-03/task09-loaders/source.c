#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 03: Loaders
 * ---------------
 * Author: Antonín Dufka
 * Email:  xdufka1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * This task should help you to understand pointer arithmetics better.
 *
 * Your task is to implement functions "intloader", "floatloader"
 * and "charloader".
 * Each of these takes in two arguments - a pointer to an array and an integer.
 * The goal of the functions is to read "count" elements (their type
 * corresponds to the function name) from standard input into given array.
 *
 * You can assume that no error will occur during reading and given array has
 * enough memory for at least count elements.
 *
 * DO NOT modify main function, your task is only to implement
 * "*loader" functions.
 *
 * Hint: scanf, " %c"
 */

void intloader(int *buffer, unsigned int count)
{
    for (int i = 0; i < count; i++){
        scanf("%d,", &(buffer[i]));
    }
}

void floatloader(float *buffer, unsigned int count)
{
    for (int i = 0; i < count; i++){
        scanf("%f,", &(buffer[i]));
    }
}

void charloader(char *buffer, unsigned int count)
{
    for (int i = 0; i < count; i++){
        scanf(" %c,", &(buffer[i]));
    }
}

// DO NOT MODIFY
int main(void)
{
    int ibuff[100];
    for (int i = 0; i < 100; ++i) {
        ibuff[i] = i;
    }
    intloader(ibuff, 2);
    for (int j = 0; j < 2; j++){
        printf("%d, ", ibuff[j]);
    }
    /*intloader(ibuff + 20, 5);
    intloader(ibuff + 20, 3);
    intloader(ibuff + 30, 0);
    intloader(ibuff + 50, 43);
    intloader(ibuff + 100, 0);
    for (int i = 0; i < 100; ++i) {
        printf("%d\n", ibuff[i]);
    }

    char cbuff[10];
    for (int i = 0; i < 10; ++i) {
        cbuff[i] = 'a' + i;
    }
    charloader(cbuff + 1, 8);
    for (int i = 0; i < 10; ++i) {
        printf("%c\n", cbuff[i]);
    }

    float fbuff[5];
    for (int i = 0; i < 5; ++i) {
        fbuff[i] = (float) i;
    }
    floatloader(fbuff + 1, 3);
    for (int i = 0; i < 5; ++i) {
        printf("%f\n", fbuff[i]);
    }*/

    return EXIT_SUCCESS;
}
