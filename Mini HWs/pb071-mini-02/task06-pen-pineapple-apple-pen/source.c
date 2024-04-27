#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 02: PPAP
 * ---------------
 * Author: Marko Řeháček
 * Email:  456490@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Write a program that prints numbers from 1 to 105 (including 105).
 * But for multiples of 3, print "PenPineapple" instead of the number,
 * for the multiples of 5, print "ApplePen",
 * and for multiples of both 3 and 5, print "PenPineappleApplePen".
 *
 * Numbers are separated by 1 space. Last number is also followed by space.
 * Output should look like this for the first 10 numbers:
 *     "1 2 PenPineapple 4 ApplePen PenPineapple 7 8 PenPineapple ApplePen"
 */

int main(void)
{
    // TODO: your solution here
    for (size_t number = 1; number < 106; number++)
    {
        if (number % 3 == 0 && number % 5 != 0)
        {
            printf("PenPineapple \n");
        }
        else if (number % 3 != 0 && number % 5 == 0)
        {
            printf("ApplePen \n");
        }
        else if (number % 3 == 0 && number % 5 == 0)
        {
            printf("PenPineappleApplePen \n");
        }
        else
        {
            printf("%d \n", number);
        }
    }
    
}
