#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * Print content of file
 *
 * \author Vojtech Jelinek
 */

/*
 * POSIX functions work with file descriptors even if printing out to standard
 * output - its descriptor is 1 (as in STDOUT_FILENO macro).
 * Note: Yes, standard output is handled as a file.
 */

int read_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        return -1;
    }

    char buffer[1024];
    ssize_t size = 0;

    while ((size = read(fd, buffer, 1024)) > 0) {
        if (write(STDOUT_FILENO, buffer, size) == -1) {
            return -1;
        }
    }

    close(fd);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (read_file(argv[1]) != 0) {
        fprintf(stderr, "File reading error\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
