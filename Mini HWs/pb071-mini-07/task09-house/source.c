#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 09: Family house
 * ---------------
 * Author: Daniel Zaťovič
 * Email:  469348@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ----------------------------------------------------------------------------
 *
 * Your task is to define structure family_house with members, number_of_floors
 * and number_of_rooms attributes (all of unsigned int type). number_of_floors
 * is supposed to be 2 bits long and number_of_rooms 5 bits long.
 *
 * Hint: ": n"
 *
 * Do not change anything else except struct family_house.
 */

typedef struct
{
    unsigned int members;
    unsigned int number_of_floors : 2;
    unsigned int number_of_rooms : 5;
} family_house;

int main(void)
{
    family_house test_house;
    test_house.number_of_floors = (1 << 2) - 1;
    printf("%u\n", test_house.number_of_floors);
    test_house.number_of_floors++;
    printf("%u\n", test_house.number_of_floors != (1 << 2));

    test_house.number_of_rooms = (1 << 5) - 1;
    printf("%u\n", test_house.number_of_rooms);
    test_house.number_of_rooms++;
    printf("%u\n", test_house.number_of_rooms != (1 << 5));

    return EXIT_SUCCESS;
}
