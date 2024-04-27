#include <stdio.h>
#include <stdlib.h>

/**
 * Work or weekend
 *
 * \author Roman Chrenšť
 */

/*
 * Simple switch use. There does not have to be return statement at the end of
 * function if it has void signature.
 */

void work_or_weekend(int days)
{
    if (days < 1 || days > 30) {
        return;
    }
    for (int i = 1; i <= days; i++) {
        switch (i % 7) {
        case 6:
            printf("Saturday ");
            break;
        case 0:
            printf("Sunday ");
            break;
        default:
            printf("Work ");
            break;
        }
    }
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
