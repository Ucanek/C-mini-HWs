#include <stdio.h>
#include <stdlib.h>

/**
 * Minihomework 03: pointer-jumper
 *
 * \author: Antonín Dufka <xdufka1@fi.muni.cz>
 */

/*
 * Only thing you have to do in this task is dereference.
 * Note: If you do not know to which type of data a pointer refers,
 * you can use void * and convert the data later.
 */

void *pointer_jump(void **pointer)
{
    return *pointer;
}

void *pointer_doublejump(void ***pointer)
{
    return **pointer;
}

int pointer_jumper(void **start, void *const goal)
{
    int i = 0;
    while (start != goal) {
        start = *start;
        ++i;
    }
    return i;
}

int main(void)
{
    void *pointers[60];
    for (int i = 0; i < 60; ++i) {
        pointers[i] = pointers + ((i + 1) * 2) % 61 - 1;
    }
    if (pointer_jump(pointers + 29) == pointers + 59) {
        puts("pointer_jump is OK");
    } else {
        puts("pointer_jump is NOK");
    }
    if (pointer_doublejump((void ***) (pointers + 29)) == pointers + 58) {
        puts("pointer_doublejump is OK");
    } else {
        puts("pointer_doublejump is NOK");
    }
    printf("%d\n", pointer_jumper(pointers, pointers + 16));
    return EXIT_SUCCESS;
}
