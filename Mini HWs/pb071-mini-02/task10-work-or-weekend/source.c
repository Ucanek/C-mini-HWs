#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 02: Work or weekend
 * ---------------
 * Author: Roman Chrenšť
 * Email:  469253@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ---------------
 * Implement work_or_weekend function which, for given number of days,
 * prints whether it is Saturday, Sunday or a regular working (Work) day.
 * - first day of the period is always Monday
 * - if given period of time is incorrect (negative or exceeds 30 days),
 *     function does not print anything
 * - every printed day (including the last one) should be followed by 1 space
 * - days are either "Work", "Saturday" or "Sunday"
 *
 * For 6, function prints: "Work Work Work Work Work Saturday "
 */

void work_or_weekend(int days)
{
    if (days < 1 || days > 30){
        printf(0);
    }
    for (int i = 1; i <= days; i++){
        if (i % 6 == 0){
            printf("%s ", "Saturday");
        }
        else if (i % 7 == 0){
            printf("%s ", "Sunday");
        }
        else{
            printf("%s ", "Work");
        }
    }
    printf("\n");
}

// do not change following code!
int main(void)
{
    work_or_weekend(-1);
    work_or_weekend(7);
    work_or_weekend(30);
    work_or_weekend(31);
    return EXIT_SUCCESS;
}
