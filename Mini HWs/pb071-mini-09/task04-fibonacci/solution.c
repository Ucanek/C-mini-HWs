#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Fibonacci number
 *
 * \author Roman Lacko <xlacko1@fi.muni.cz>
 */

/*
 * Fibonacci sequence is maybe the most typical example for using recursion.
 */

static long long fibaux(long long n, long long a, long long b)
{
    // The 'n' parameter tells us how many "shifts" we need to make
    // before we reach the desired number.
    // The 'a' and 'b' represent two consecutive numbers of the Fibonacci
    // sequence. Using these we can easily compute next parameter,
    // while we don't actually need to store previous values.

    // Consider the following example: we want to compute fibonacci(5),
    // which calls
    //
    //      fibaux(5, 0, 1)
    //    → fibaux(4, 1, 1) // 0 [1 1]
    //    → fibaux(3, 1, 2) // 0 1 [1 2]
    //    → fibaux(2, 2, 3) // 0 1 1 [2 3]
    //    → fibaux(1, 3, 5) // 0 1 1 2 [3 5]
    //    → fibaux(0, 5, 8) // 0 1 1 2 3 [5 8]
    //    → 5
    //
    // Each call to fibaux() "shifts" the parameters to the next elements
    // of the sequence. Because of this, fibaux() carries all required
    // information in its call parameters, and caller instances
    // do not need to modify the result. This allows the compiler
    // to get rid of function calls completely, yielding an iteration.
    return n == 0 ? a : fibaux(n - 1, b, a + b);
}

long long fibonacci(long long n)
{
    // return -1 for numbers less than zero
    if (n < 0)
        return -1;

    // the sequence starts with 0, 1
    return fibaux(n, 0, 1);
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
