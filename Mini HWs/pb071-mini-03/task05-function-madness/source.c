#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 03: Function madness
 * ---------------
 * Author: Stanislav Soták
 * Email:  xsotak@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Your task is to implement four different functions, each taking only one
 * argument - an integer.
 * Functions times_3, minus_8 and plus_5 do such arithmetic operations as
 * stated in their names, returning result as an integer.
 * Function say_number prints exactly (!) "number is x\n" to the output,
 * where 'x' is the input argument for the function.
 * 
 * Once you're done with your functions, do not forget to uncomment
 * function calls in main() function to test your solution.
 */

int times_3(int number){
    return number * 3;
}

int minus_8(int number){
    return number - 8;
}

int plus_5(int number){
    return number + 5;
}

void say_number(int number){
    printf("number is %d\n", number);
}

int main(void)
{
    say_number(times_3(minus_8(plus_5(2))));
    say_number(minus_8(times_3(plus_5(3))));
    say_number(plus_5(plus_5(times_3(minus_8(16)))));
    say_number(times_3(times_3(times_3(10))));
    return EXIT_SUCCESS;
}
