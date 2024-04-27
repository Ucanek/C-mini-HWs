#include <stdio.h>
#include <stdlib.h>

/**
 * typedef
 *
 * \author Peter Navrátil
 */

/*
 * The name you give the structure can be different from the one you use
 * as typedef alias.
 */

typedef int index_type;

typedef struct account
{
    unsigned account_number;
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
