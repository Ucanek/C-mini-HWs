#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <err.h>

/*
 * Minihomework 11: Print size of a file
 * ---------------
 * Author: Vojtech Jelinek
 * Email:  vojtechjelinek@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task here is to write function that takes a path to a file and prints
 * its size in bytes.
 *
 * If the path does not represent a regular file, print -1.
 *
 * To retrieve the size and type of file use stat function and stat structure
 * from sys/stat.h. The two fields you're interested in struct stat are st_size
 * and st_mode.
 *
 * Do not print newline after the size of file.
 *
 * Useful links:
 * - man fstat(2):
 *   https://linux.die.net/man/2/fstat
 */

void print_filesize(const char *filepath)
{
    struct stat file_info;

    if (filepath == NULL){
        printf("-1 first fail\n");
        return;
    }

    if (stat(filepath, &file_info) == -1){
        warn("-1 second fail\n");
        return;
    }

    if (S_ISREG(file_info.st_mode)){
        printf("%d\n", file_info.st_size);
        return;
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
