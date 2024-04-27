#define _BSD_SOURCE
// the above macro is required to define DT_*
#include <stdio.h>
#include <stdlib.h>

#include <dirent.h>
#include <sys/stat.h>

/**
 * list-files
 *
 * \author Lukas Kurcik
 */

/*
 * You will not find documentation to these functions at cppreference.com,
 * since they are specific to UNIX-like systems and will most probably work
 * on e.g. Windows.
 */

void list_regular_files(const char *dirpath)
{
    static char path[PATH_MAX];

    DIR *dir = NULL;
    if ((dir = opendir(dirpath)) == NULL) {
        return;
    }

    struct dirent *entry = NULL;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf("%s\n", entry->d_name);
            // POSIX requires to handle DT_UNKNOWN value for d_type
        } else if (entry->d_type == DT_UNKNOWN) {
            struct stat info;
            snprintf(path, PATH_MAX - 1, "%s/%s", dirpath, entry->d_name);
            if (stat(path, &info) == -1) {
                perror(path);
            } else if (S_ISREG(info.st_mode)) {
                printf("%s\n", entry->d_name);
            }
        }
    }

    closedir(dir);
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
