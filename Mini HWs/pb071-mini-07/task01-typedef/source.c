#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 07: Typedefing
 * ---------------
 * Author: Peter Navrátil
 * Email:  445700@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ----------------------------------------------------------------------------
 *
 * In this assignment, you will write simple typedefs.
 *
 * Firstly, define simple integer typedef from int to index_type. Note that it
 * will not matter if you use ordinary int or index_type for array indexing.
 *
 * Secondly, you have to implement (ideally with typedef) structure account_t.
 * It should have four different attributes: account_number (unsigned integer),
 * interest (floating point number), balance (integer), class_mark (character).
 *
 * The compiled program does not need any input, it will check the correctness
 * of your typedefs in main.
 *
 * Do not change the main function.
 */

typedef int index_type;

typedef struct account {
    unsigned int account_number;
    float interest;
    int balance;
    char class_mark;
} account_t;

int main(void)
{
    index_type idx = 5;
    printf("Index is: %d\n", idx);
    int array[10];
    int i;
    for (i = 0; i < 10; i++) {
        array[i] = i * 3;
    }

    printf("Get value with index_type value: %d\n", array[idx]);

    printf("Get value with an ordinary integer value: %d\n", array[3]);

    account_t acc = {
        .account_number = 44570,
        .interest = 1.003,
        .balance = -130,
        .class_mark = 'C',
    };

    printf("Account\n");
    printf("Account number: %u\n", acc.account_number);
    printf("Account interest: %.3f\n", acc.interest);
    printf("Account balance: %d\n", acc.balance);
    printf("Account class: %c\n", acc.class_mark);

    return EXIT_SUCCESS;
}
