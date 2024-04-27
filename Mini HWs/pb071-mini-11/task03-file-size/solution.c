#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * file-size
 *
 * \author Vojtech Jelinek
 */

/*
 * Stat structure holds many interesting facts about a file, for example
 * its mode of access (who can read/write/execute it).
 */

void print_filesize(const char *filepath)
{
    struct stat st;
    stat(filepath, &st);
    if (S_ISREG(st.st_mode)) {
        printf("%li", st.st_size);
    } else {
        printf("-1");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_filesize(argv[1]);
    return EXIT_SUCCESS;
}
