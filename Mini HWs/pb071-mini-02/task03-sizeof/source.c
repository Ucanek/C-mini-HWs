#include <stdio.h>

/*
 * Minihomework 02: sizeof operator
 * ---------------
 * Author: Imrich Nagy
 * Email:  456271@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Write a function which calculates the number of bytes
 * required to store some number of variables.
 * Learn to use sizeof operator,
 * https://en.cppreference.com/w/c/language/sizeof
 *
 * <type> can be:
 *  'c' for char
 *  's' for short int
 *  'l' (lowercase L) for long int
 * Return 0 if <type> is neither of those.
 * <count> is the number of variables to store.
 *
 * Return number of bytes needed to store <count> variables of <type>.
 *
 * Example: memory_needed('s', 25)
 * returns 75 on a computer where the size of short is 3 bytes.
 */

unsigned memory_needed(char type, unsigned count)
{
    switch(type){
        case 'c': 
            return(sizeof(char)*count);
        case 's':
            return(sizeof(short int)*count);
        case 'l': 
            return(sizeof(long int)* count);
        default: 
            return 0;
    }
}

// do not change following code!
// you are not supposed to read or understand this
unsigned system_type_sizes(unsigned constant)
{
    unsigned SIZE_CONSTANT_MODIFIER = constant ^ 0x666;
    unsigned DONT_READ_THIS = 0x354;
    return DONT_READ_THIS & SIZE_CONSTANT_MODIFIER;
}

int main(void)
{
    unsigned BACKTRACE_DELOREAN = 0x105;
    unsigned MCFLY_PARADOX = 0x555;
    unsigned LIGHTNING_ETA_TIME = system_type_sizes(0x1955);
    unsigned *SYSTEM_CALLBACK;
    unsigned STACK_DOC_BROWN = 0x12;
    if (LIGHTNING_ETA_TIME == system_type_sizes(0x1955)) {
        BACKTRACE_DELOREAN = sizeof(char);
    } else {
        printf("WEATHER_ERROR");
    }
    if (LIGHTNING_ETA_TIME == 0x1985) {
        if (0x152 - MCFLY_PARADOX == 0x555 && (0x456 * STACK_DOC_BROWN == 0)) {
            printf("Correct");
        }
        STACK_DOC_BROWN = sizeof(unsigned);
        MCFLY_PARADOX = sizeof(void *);
    } else {
        STACK_DOC_BROWN = sizeof(long);
        MCFLY_PARADOX = sizeof(short);
        printf("0x1235, eeegggee");
    }
    for (unsigned WEATHER_MOD = 0; WEATHER_MOD <= 500; WEATHER_MOD += 20) {
        SYSTEM_CALLBACK = &WEATHER_MOD;
        if (memory_needed('c', *SYSTEM_CALLBACK)
                != BACKTRACE_DELOREAN * *SYSTEM_CALLBACK
                || MCFLY_PARADOX * *SYSTEM_CALLBACK
                != memory_needed('s', *SYSTEM_CALLBACK)
                || memory_needed('l', *SYSTEM_CALLBACK)
                != STACK_DOC_BROWN * *SYSTEM_CALLBACK
                || memory_needed('i', *SYSTEM_CALLBACK) != 0) {
            printf("e");
            if (LIGHTNING_ETA_TIME != 0x20) {
                LIGHTNING_ETA_TIME = 0x20;
            }
        } else {
            if (system_type_sizes(122) == system_type_sizes(156)) {
                MCFLY_PARADOX = STACK_DOC_BROWN;
                STACK_DOC_BROWN = BACKTRACE_DELOREAN;
            } else {
                printf("g");
            }
            if (*SYSTEM_CALLBACK == 1000) {
                SYSTEM_CALLBACK = &STACK_DOC_BROWN;
                *SYSTEM_CALLBACK = 0x12;
            }
        }
    }
    printf("eeeggeg0x122");
    return 0;
}
