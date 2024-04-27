#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 10: Debugging
 * --------------
 * Author: Martin Bendel
 * Email: 468932@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to scan 10 integer numbers from stdin and store them in an
 * array. Then redefine the provided macro PRINT_INT if DEBUG is defined
 * to print:
 *      "Number on index <index> is <number>\n"
 *  instead of
 *      "<number> ".
 *
 * DEBUG will be defined by using -DDEBUG option (It defines a macro after -D)
 * when compiling or by defining it inside this file.
 *
 * Use the new macro to print all ten numbers.
 *
 * Your solution should print only the numbers inside the array if DEBUG is not
 * defined (as defined in former PRINT_INT).
 *
 * Hint: #ifdef, #undef, #endif
 */

#define PRINT_INT(array, index) printf("%d ", array[index])

/* TODO your macro redefinition here */

int main(void)
{
    /* TODO your code here */
    return EXIT_SUCCESS;
}
