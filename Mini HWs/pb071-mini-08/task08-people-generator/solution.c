#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * people-generator
 *
 * \author Ján Dovjak
 */

/*
 * Note that many IO functions from standard library have twins with "s"
 * and "f" prefix for working with buffers and streams respectively.
 * Note: They also have safer siblings with "_s" suffix from C11 version.
 */

int main(void)
{
    char people[4][80] = { "John Doe 21 474",
        "Joe Smith 34 3343",
        "Anna Johnson 40 6642",
        "Martin Jones 18 9432" };

    char firstnames[4][20], lastnames[4][20];
    int age[4], points[4];

    // Parsing attributes of people
    for (size_t i = 0; i < 4; i++) {
        if (sscanf(people[i], "%s %s %d %d", firstnames[i], lastnames[i], &age[i], &points[i]) != 4) {
            fprintf(stderr, "Parsing error\n");
        }
    }

    char result[2][80];

    for (size_t i = 0; i < 2; i++) {
        // Storing to result[i]
        sprintf(result[i], "%s %s %d %d", firstnames[0 + i * 3], lastnames[1 + i * 1], age[2 - i * 1], points[3 - 3 * i]);
        printf("%s\n", result[i]);
    }

    return EXIT_SUCCESS;
}
