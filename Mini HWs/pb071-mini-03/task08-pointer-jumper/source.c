#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 03: Pointer jumper
 * ---------------
 * Author: Antonín Dufka
 * Email:  xdufka1@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Your task is to implement the three following functions. First two functions
 * are very simple, just to lead you to the solution of the third one.
 *
 * The point of this task is to help you understand pointer dereference better.
 *
 * Advice: do not skip this task even if you are tempted. It will really
 * help you understand this very important concept of pointer dereference.
 * If you get stuck, try deleting the code and write the function again
 * from scratch.
 *
 * Function 1: pointer_jump
 * This function takes pointer to a pointer as only argument and returns its
 * dereference. In other words - returns the pointer to which points
 * the pointer passed in the argument.
 *
 * Function 2: pointer_doublejump
 * Let's take it a step further. This function takes in pointer to a pointer to
 * a pointer and should return its double dereference. In other words - returns
 * the pointer to which points the pointer to which points the pointer passed
 * in the argument.
 *
 * Function 3: pointer_jumper
 * Let's take it even further. This functions takes in pointer to an array of
 * pointers and a "goal" pointer. Each of the pointers (passed to this
 * function) points to some other pointer in the same array.
 * Example:
 *
 *                #########################################
 *                # 5 # 4 # 8 # 1 # 6 # 2 # 7 # 0 # 9 # 3 #
 *                #########################################
 *
 * Field 0 points to field 5, field 1 points to field 4, field 2 points to
 * field 8, ...
 *
 * The goal of the function is to start at the first element and return the
 * number of jumps (dereferences), before the goal pointer is reached.
 *
 * If the function was called on the example specified above and the goal
 * pointer would be 9, the number of jumps would be 4 (0 -> 5 -> 2 -> 8 -> 9).
 *
 *
 * DO NOT modify main function, your task is only to implement aforementioned
 * functions.
 */

void *pointer_jump(void **pointer)
{
    return *pointer;
}

void *pointer_doublejump(void ***pointer)
{
    return **pointer;
    return NULL;
}

int pointer_jumper(void **start, void *const goal)
{
    int jumps = 0;
    while (start != goal){
        start = *start;
        jumps++;
    }
    return jumps;
}

// DO NOT MODIFY
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
