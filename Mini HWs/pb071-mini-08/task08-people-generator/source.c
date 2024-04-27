#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Minihomework 08: Unknown people generator
 * ---------------
 * Author: Ján Dovjak
 * Email:  xdovjak@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to create new people from the information given in -people-
 * array and store them in -result-.
 *
 * First, parse the strings in -people-. They are written in this format:
 *
 * "Firstname Lastname Age Points"
 *
 * Then store parsed attributes to the given arrays -firstnames-, -lastnames-,
 * -age- and -points-.
 *
 * Then, create two new people as follows:
 *
 *  Person1: firstname of first person, lastname of second person, age of
 *  third person, points of fourth person
 *
 *  Person2: firstname of fourth person, lastname of third person, age of
 *  second person, points of first person
 *
 * Lastly, store these people to -result- array and print each of them to
 * standard output in format:
 *
 * "firstname lastname age points\n"
 *
 * Hint: sscanf()
 */

int main(void)
{
    char people[4][80] = { "John Doe 21 474",
        "Joe Smith 34 3343",
        "Anna Johnson 40 6642",
        "Martin Jones 18 9432" };

    char firstnames[4][20], lastnames[4][20];
    int age[4], points[4];

    char result[2][80];

    for (int i = 0; i < 4; i++){
        sscanf(people[i], "%s %s %d %d", firstnames[i], lastnames[i], &age[i], &points[i]);
        printf("%s %s %d %d\n", firstnames[i], lastnames[i], age[i], points[i]);
    }
    printf("\n");

    for (size_t i = 0; i < 2; i++) {
        sprintf(result[i], "%s %s %d %d", firstnames[0 + i * 3], lastnames[1 + i * 1], age[2 - i * 1], points[3 - 3 * i]);
        printf("%s\n", result[i]);
    }

    return EXIT_SUCCESS;
}
