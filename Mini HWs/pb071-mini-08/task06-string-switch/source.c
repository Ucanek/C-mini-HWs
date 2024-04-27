#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 08: String switch
 * ---------------
 * Author: Matus Dugacek
 * Email:  456426@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to swap strings from input file.
 *
 * In the first argument, you will be given path to an input file, in which
 * there will be always two strings on each line separated with ';'.
 *
 * Given strings will have together less than 99 characters.
 *
 * You should print these into the file given in the second parameter, but
 * their position will be swapped (yet still separated with ';').
 *
 * After that you will rename the second file to "output.txt". At the end, you
 * need to print its contents to stdout and remove the file "output.txt".
 *
 * Example:
 * in: "abcd;xyz"
 * out: "xyz;abcd"
 *
 * For insufficient number of parameters for binary, print out usage to stderr.
 *
 * Create your own auxiliary functions if you want to.
 *
 * For arguments that have to be passed to compiled binary, see .args file(s).
 *
 * Hint: fputs() and remove() functions may help you
 */

int main(int argc, char *argv[])
{
    if (argc != 3){
        fprintf(stderr, "Invalid input\n");
        return EXIT_FAILURE;
    }

    FILE* input;
    input = fopen(argv[2], "r");
    if (input == NULL){
        fprintf(stderr, "Open failed\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
