#include <stdio.h>
#include <stdlib.h>

/* Minihomework 07: Enumerating flags
 * ---------------
 * Author: Jakub Horváth
 * Email:  456438@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ----------------------------------------------------------------------------
 *
 * Your task is to create a new enum type 'colour'.
 *
 * It should contain any colours necessary to create following flags:
 * Armenia, Costa Rica, Ecuador and Lesotho (check the testing functions
 * if you do not know the colours).
 *
 * Save the colours to arrays provided in main function in top-down fashion.
 *
 * E.g. for the flag of Armenia, the array will contain
 * {COLOUR_RED, COLOUR_BLUE, COLOUR_ORANGE}
 *
 * Note: Good practice is to create elements of an enumeration with prefix
 * containing name of that enum and in uppercase, so you should do it too.
 */

enum colour {
    COLOUR_RED,
    COLOUR_BLUE,
    COLOUR_ORANGE,
    COLOUR_WHITE,
    COLOUR_YELLOW,
    COLOUR_GREEN
};

void check_armenia(const enum colour *colours)
{
    if (colours[0] != COLOUR_RED || colours[1] != COLOUR_BLUE || colours[2] != COLOUR_ORANGE) {
        printf("NOK\n");
        return;
    }
    printf("OK\n");
}

void check_costa_rica(const enum colour *colours)
{
    if (colours[0] != COLOUR_BLUE || colours[1] != COLOUR_WHITE || colours[2] != COLOUR_RED
            || colours[3] != COLOUR_WHITE || colours[4] != COLOUR_BLUE) {
        printf("NOK\n");
        return;
    }
    printf("OK\n");
}

void check_ecuador(const enum colour *colours)
{
    if (colours[0] != COLOUR_YELLOW || colours[1] != COLOUR_BLUE || colours[2] != COLOUR_RED) {
        printf("NOK\n");
        return;
    }
    printf("OK\n");
}

void check_lesotho(const enum colour *colours)
{
    if (colours[0] != COLOUR_BLUE || colours[1] != COLOUR_WHITE || colours[2] != COLOUR_GREEN) {
        printf("NOK\n");
        return;
    }
    printf("OK\n");
}

int main(void)
{
    // Armenia - https://en.wikipedia.org/wiki/Flag_of_Armenia
    enum colour armenia[3] = {COLOUR_RED, COLOUR_BLUE, COLOUR_ORANGE};
    check_armenia(armenia);

    // Costa Rica - https://en.wikipedia.org/wiki/Flag_of_Costa_Rica
    enum colour costa_rica[5] = {COLOUR_BLUE, COLOUR_WHITE, COLOUR_RED, COLOUR_WHITE, COLOUR_BLUE};
    check_costa_rica(costa_rica);

    // Ecuador - https://en.wikipedia.org/wiki/Flag_of_Ecuador
    enum colour ecuador[3] = {COLOUR_YELLOW, COLOUR_BLUE, COLOUR_RED};
    check_ecuador(ecuador);

    // Lesotho - https://en.wikipedia.org/wiki/Flag_of_Lesotho
    enum colour lesotho[3] = {COLOUR_BLUE, COLOUR_WHITE, COLOUR_GREEN};
    check_lesotho(lesotho);

    return EXIT_SUCCESS;
}
