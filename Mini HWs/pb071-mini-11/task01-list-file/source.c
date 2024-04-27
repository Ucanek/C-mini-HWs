#define _BSD_SOURCE
// the above macro is required if you want to use DT_*
#include <stdio.h>
#include <stdlib.h>

#include <dirent.h>
#include <sys/stat.h>

/*
 * Minihomework 11: List regular files in folder
 * ---------------
 * Author: Lukas Kurcik
 * Email:  greenmansk@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task here is to write a function list_regular_files taking a path to
 * directory and printing names of all regular files in the directory.
 *
 * Each file name should be on a separate line.
 *
 * If the directory does not exist or cannot be opened, do not print anything.
 *
 * To implement this, use <dirent.h> library, especially opendir, readdir and
 * closedir functions. You will also need to check dirent structure and its
 * parameter d_type to check whether a file is regular.
 *
 * Do not forget to close any resources you open.
 *
 * Useful links:
 * - struct dirent:
 *   https://www.gnu.org/software/libc/manual/html_node/Directory-Entries.html
 * - opendir:
 *   http://pubs.opengroup.org/onlinepubs/009604599/functions/opendir.html
 * - readdir:
 *   http://pubs.opengroup.org/onlinepubs/7908799/xsh/readdir.html
 * - closedir:
 *   http://pubs.opengroup.org/onlinepubs/7908799/xsh/closedir.html
 */

void list_regular_files(const char *dirpath)
{
    if (dirpath == NULL){
        fprintf(stderr, "Invalid path\n");
        return;
    }

    DIR *directory;
    directory = opendir(dirpath);
    if (dirpath == NULL){
        fprintf(stderr, "Open failed\n");
        return;
    }
    
    struct dirent* names;
    while ((names = readdir(directory)) != NULL){
        if (names->d_type == DT_REG){
            printf("%s\n", names->d_name);
        }
    }
    
    closedir(directory);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s DIR\n", argv[0]);
        return EXIT_FAILURE;
    }

    list_regular_files(argv[1]);
    return EXIT_SUCCESS;
}
