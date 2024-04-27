#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 03: Very simple functions
 * ---------------
 * Author: Erik Moravec
 * Email:  xmoravec@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Your task is to implement a few simple functions.
 * It is also your job to come up with correct type annotations
 * for the return value and parameters of each function.
 * Take a look into the main() function to understand the expected usage of
 * the functions.
 *
 * For example, if there was a following function call in the main() function:
 *      int foo = bar('a', 5)
 * The function header should look something like:
 *      int bar(char first, int second)
 * Names of the parameters do not matter, you can name them however you want.
 *
 * As you implement the functions, uncomment the respective lines
 * in the main() function to test them.
 * Do not add any additional commands to the main function!
 */

/*
 * Function 1: simple_cipher
 * Takes two arguments, character and integer. It shifts the character
 * by the given value (simple_cipher(d, 3) => g). Do not care about
 * the "overflow", when the character would exceed the alphabet, it will
 * not be tested.
 */

char simple_cipher(char ch, int shift)
{
    return ch + shift;
}

/*
 * Function 2: reverse
 * Returns the opposite value of given integer (reverse(-8) => 8).
 */

int reverse(int number){
    return -number; // (-1);
}

/*
 * Function 3: bigger
 * Takes two integers, returns the bigger one.
 * If they are equal, returns the first one.
 */

int bigger(int a, int b){
    if (b > a){
        return b;
    }
    else {
        return a;
    }
}

/*
 * Function 4: smaller
 * Takes two integers, returns the smaller one.
 * If they are equal, return the first one.
 */

int smaller(int a, int b){
    if (b < a){
        return b;
    }
    else {
        return a;
    }
}

/*
 * Function 5: give_me_five
 * Returns number 5.
 */

int give_me_five(void){
    return 5;
}

/*
 * Function 6: print_int
 * Prints the given integer and a newline to the standard output.
 */

void print_int(int input){
    printf("%d\n", input);
}

/*
 * Function 7: print_char
 * Prints the given character and a newline to the standard output.
 */

void print_char(char letter){
    printf("%c\n", letter);
}

int main(void)
{
    print_char(simple_cipher('a', 5));
    print_int(bigger(give_me_five(), reverse(give_me_five())));
    print_char(simple_cipher(simple_cipher('a', bigger(8, 9)), smaller(give_me_five(), reverse(-18))));
    print_int(smaller(reverse(-20), reverse(bigger(give_me_five() * 5, give_me_five() * 4))));
    return 0;
}
