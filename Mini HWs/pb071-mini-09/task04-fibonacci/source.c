#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
 * Minihomework 09: Fibonacci number
 * ---------------
 * Author: Roman Lacko
 * Email:  xlacko1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Implement a function 'fibonacci' that will compute a value
 * of the n-th Fibonnaci number, starting from zero, using a TAIL RECURSION.
 *
 * One of possible definitions is as follows:
 *
 *             /-- 0                if n == 0
 *      f(n) = --- 1                if n == 1
 *             \-- f(n-1) + f(n-2)  otherwise
 *
 * The problem is that implementing this formula directly will result
 * in an incredibly inefficient program and will possibly fail the tests.
 * Correctly implemented tail recursion should compute fibonacci(90) in a few
 * miliseconds even without optimizations (GCC 7.3.0).
 *
 * HINT: Define an auxiliary function and use its parameters to iterate
 *       a Fibonacci sequence.
 *
 * The main function is already implemented for you. It reads a sequence
 * of numbers separated by whitespaces and for each number it prints
 *
 *      fib(NUMBER) = RESULT
 *
 * using your implementation of fibbonaci().
 *
 * The main fuction takes care of the input. You do not need to modify it.
 */


/**
 * Fibonacci number.
 *
 * \param   n       input number
 * \returns n-th Fibonacci number or -1 if the input is negative
 */
long long fibonacci(long long n)
{
    long long memo[100];

    if (n <= 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else if (memo[n] != 0){
        return memo[n];
    }
    else {
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    }
    
}


int main(void)
{
    int retval;
    long long num;

    while ((retval = scanf(" %lld", &num)) == 1) {
        printf("fib(%lld) = %lld\n", num, fibonacci(num));
        errno = 0;
    }

    // scanf sets errno on read failure
    if (retval == EOF && errno != 0) {
        perror("scanf");
        return EXIT_FAILURE;
    }

    // otherwise the input did not represent a valid number
    if (retval == 0) {
        fprintf(stderr, "scanf: Invalid input\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
