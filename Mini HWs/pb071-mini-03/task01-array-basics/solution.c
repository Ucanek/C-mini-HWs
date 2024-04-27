#include <stdio.h>
#include <stdlib.h>

/**
 * array-basics
 *
 * \author Erik Moravec
 */

/*
 * Simple use of array indexing.
 * Note: The sums could be computed without even creating the arrays, but
 * that is not what we want from you in this minihomework.
 * Note: You cannot use something like "for elem in array: ..." (as in Python),
 * since C does not know the size of your array (even though you specified it).
 */

int crazy_sum(void)
{
    int array[100];
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        array[i] = i;
        sum += array[i];
    }
    return sum;
}

int magic_number(void)
{
    int array[1000];
    for (int i = 0; i < 1000; i++) {
        array[i] = 999 - i;
    }
    int sum = array[0];
    for (int j = 1; j < 1000; j++) {
        if ((j % 2) == 1) {
            sum -= array[j];
        } else {
            sum += array[j];
        }
    }
    return sum;
}

int main(void)
{
    int sum = crazy_sum();
    printf("%d\n", sum);
    int num = magic_number();
    printf("%d\n", num);
    return 0;
}
