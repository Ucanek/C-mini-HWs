#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 03: Array basics
 * ---------------
 * Author: Erik Moravec
 * Email:  xmoravec@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Your task is to implement 2 simple functions.
 *
 * In the first function (crazy_sum) create an array of 100 integers, then
 * assign a value to each integer in the array.
 * The value of each integer is equal to its index in the array,
 * e.g. array of 3 integers would be [0, 1, 2].
 * Lastly, return the sum of all elements in this array.
 *
 * In the second function (magic_number), create an array of 1000 integers.
 * This time, however, assign the values in a reverse order,
 * e.g. an array with 3 integers would be [2, 1, 0].
 *
 * Lastly, calculate the return value by these rules:
 * If index of the number is even (=sudý, párný), then add it to the sum,
 * if it is odd (=lichý, nepárny), substract it.
 * E.g. array of 5 integers => [4, 3, 2, 1, 0] => 4-3+2-1+0 => return 2).
 *
 * Do not edit the main() function!
 */

int crazy_sum(void)
{
    int sum = 0;
    int array[100];
    for (int i = 0; i <= 99; i++){
        array[i] = i;
        sum += i;
    }
    return sum;
}

int magic_number(void)
{
    int num = 0;
    int array[1000];
    for (int i = 1000; i >= 0; i--){
        array[i] = i;
        if (i % 2 == 0){
            num += i;
        }
        else {
            num -= i;
        }
    }
    return num;
}

int main(void)
{
    int sum = crazy_sum();
    printf("%d\n", sum);
    int num = magic_number();
    printf("%d\n", num);
}
