#define _POSIX_C_SOURCE 2
// the macro above is required to use getopt()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * parse-cli
 *
 * \author Lukas Kurcik
 */

void with_a(void)
{
    printf("A!\n");
}

void with_d(char *val)
{
    printf("Hello %s!\n", val);
}

int main(int argc, char **argv)
{
    int flag_a = false;
    int flag_c = false;
    int flag_d = false;
    char *value_d;

    int c;
    while ((c = getopt(argc, argv, "acd:")) != -1) {
        switch (c) {
        case 'a':
            flag_a = true;
            break;
        case 'c':
            flag_c = true;
            break;
        case 'd':
            flag_d = true;
            value_d = optarg;
            break;
        default:
            fprintf(stderr, "Invalid argument\n");
            return EXIT_FAILURE;
        }
    }

    if (!flag_c) {
        fprintf(stderr, "Invalid argument\n");
        return EXIT_SUCCESS;
    }

    if (flag_a) {
        with_a();
    }

    if (flag_d) {
        with_d(value_d);
    }

    return EXIT_SUCCESS;
}
