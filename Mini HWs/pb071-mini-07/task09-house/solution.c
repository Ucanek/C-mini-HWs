#include <stdio.h>
#include <stdlib.h>

/**
 * house
 *
 * \author Daniel Zaťovič
 */

/*
 * Defining attribute length to bits can save some space in memory.
 * Note: The attribute can still take more space than defined (align, ...).
 */

typedef struct
{
    unsigned house_number;
    unsigned number_of_floors : 2;
    unsigned number_of_rooms : 5;
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
