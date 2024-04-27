#include <stdio.h>
#include <stdlib.h>

/**
 * flags
 *
 * \author Jakub Horváth
 */

/*
 * Complying to certain coding style makes your code much more readable
 * for others.
 */

typedef enum
{
    COLOUR_RED,
    COLOUR_BLUE,
    COLOUR_ORANGE,
    COLOUR_WHITE,
    COLOUR_YELLOW,
    COLOUR_GREEN
} colour;

void check_armenia(const colour *colours)
{
    if (colours[0] != COLOUR_RED || colours[1] != COLOUR_BLUE || colours[2] != COLOUR_ORANGE) {
        printf("NOK\n");
        return;
    }
    printf("OK\n");
}

void check_costa_rica(const colour *colours)
{
    if (colours[0] != COLOUR_BLUE || colours[1] != COLOUR_WHITE || colours[2] != COLOUR_RED
            || colours[3] != COLOUR_WHITE || colours[4] != COLOUR_BLUE) {
        printf("NOK\n");
        return;
    }
    printf("OK\n");
}

void check_ecuador(const colour *colours)
{
    if (colours[0] != COLOUR_YELLOW || colours[1] != COLOUR_BLUE || colours[2] != COLOUR_RED) {
        printf("NOK\n");
        return;
    }
    printf("OK\n");
}

void check_lesotho(const colour *colours)
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
    colour armenia[3] = {COLOUR_RED, COLOUR_BLUE, COLOUR_ORANGE};

    check_armenia(armenia);

    // Costa Rica - https://en.wikipedia.org/wiki/Flag_of_Costa_Rica
    colour costa_rica[5] = {COLOUR_BLUE, COLOUR_WHITE, COLOUR_RED, COLOUR_WHITE, COLOUR_BLUE};

    check_costa_rica(costa_rica);

    // Ecuador - https://en.wikipedia.org/wiki/Flag_of_Ecuador
    colour ecuador[3] = {COLOUR_YELLOW, COLOUR_BLUE, COLOUR_RED};

    check_ecuador(ecuador);

    // Lesotho - https://en.wikipedia.org/wiki/Flag_of_Lesotho
    colour lesotho[3] = {COLOUR_BLUE, COLOUR_WHITE, COLOUR_GREEN};

    check_lesotho(lesotho);
    return EXIT_SUCCESS;
}
