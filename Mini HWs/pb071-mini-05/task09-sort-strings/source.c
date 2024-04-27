#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/*
 * Minihomework 09: Sort the strings
 * ---------------
 * Author: Samuel Obuch
 * Email:  456163@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is:
 *  1) to read a number N and then to N string from stdin.
 *  2) to print all the strings on stdout sorted case-insensitive.
 *
 *  You should write your code directly into the main function.
 *
 *  Write your own auxiliary functions if you found them useful.
 *
 *  Most of the functionality you have to implement can be found in C library,
 *  feel free to use them (namely <stdlib.h> and <strings.h>)
 *
 * If N is bigger than 128 count it as 128.
 * If string is longer than 127 chars, use only 127 and discard the others.
 *
 * Hint: strcasecmp, qsort
 *
 * Example:
 *
 * Input:
 * 4
 * abc
 * Abb
 * Abd
 * abe
 *
 * Output:
 * Abb
 * abc
 * Abd
 * abe
 */

int foo(void){
    int a = 0;
    return a;
}


int main(void)
{
    int b = 1;
    int a;
    a = foo();
    printf("%b\n%b\n", &a, &b);
}
