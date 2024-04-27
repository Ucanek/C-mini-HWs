#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Minihomework 08: Case inverter
 * ---------------
 * Author: Matus Dugacek
 * Email:  456426@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to copy all characters from the file given in the first
 * argument to the file given in the second argument with changed case of all
 * alpha characters (i.e., a -> A, Z -> z, 9 -> 9).
 *
 * Open the output file for both writing and reading. After you finish the
 * processing, read the output file from the beginning and print it to standard
 * output.
 *
 * Implement also case where too many/too few arguments are passed to compiled
 * binary - print out the usage to standard error output. You can test it
 * yourselves by executing the binary with no arguments.
 *
 * Create your own auxiliary functions if you want to.
 *
 * For arguments that have to be passed to compiled binary, see .args file(s).
 */



int main(int argc, char *argv[])
{
    if (argc != 3) {
        /*
         * TODO: error handling here
         * Usage: <argv[0]> input_file output_file
         */
        fprintf(stderr, "Incorrect input.\nUsage: <argv[0]> input_file output_file\n");
        return EXIT_FAILURE;
    }

    FILE* input = NULL;
    FILE* output = NULL;
    char symbol;
    int value;

    input = fopen(argv[1], "r");
    if (input == NULL){
        fprintf(stderr, "Open failed.\n");
        return EXIT_FAILURE;
    }

    output = fopen(argv[2], "w");
    if (output == NULL){
        fprintf(stderr, "Open failed.\n");
        fclose(input);
        return EXIT_FAILURE;
    }

    while ((value = getc(input)) != EOF){
        symbol = value;
        if (islower(symbol) != 0){
            symbol = toupper(symbol);
        }
        else if (isupper(symbol) != 0){
            symbol = tolower(symbol);
        }
        fputc(symbol, output);
    }
 
    fclose(input);
    fclose(output);

    output = fopen(argv[2], "r");
    if (output == NULL){
        fprintf(stderr, "Open failed.\n");
        return EXIT_FAILURE;
    }

    while ((value = getc(output)) != EOF){
        symbol = value;
        putchar(symbol);
    }

    fclose(output);

    return EXIT_SUCCESS;
}
