#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define RET_OK 0
#define RET_INVARG 1
#define RET_IOERR 2

#define MAX_LINE_LEN 256u // buffer size - including newline, not to be printed

/**
 * cvs-nth-column
 *
 * \author Ondrej Sebek
 */

/*
 * Some functions here were already used in previous tasks, you can save
 * yourself time and energy by reusing them.
 */

void read_end_of_line(void)
{
    int c;
    while ((c = getchar()) != EOF && c != '\n' && c != '\r') {
    }
}

/** Read at most \c MAX_LINE_LEN characters into \p input.
 *
 * @param input buffer into which at most \c MAX_LINE_LEN will be read
 */
void read_input_string(char *input)
{
    if (fgets(input, MAX_LINE_LEN, stdin) == NULL) {
        *input = '\0'; // no characters were read
    }

    char *new_line = strchr(input, '\n');

    if (new_line) {
        *new_line = '\0'; // (1) do not read or write newline
    }

    if (strlen(input) == MAX_LINE_LEN - 1) {
        read_end_of_line(); // line longer then promised!
    }
}

/** Read a number from current line in the stream.
 *
 * \param number to be read from stream
 * \return 0 or error code
 */
int read_number(long *number)
{
    char input_number[MAX_LINE_LEN];
    char *end;

    read_input_string(input_number);

    *number = strtol(input_number, &end, 0);

    if (errno || end == input_number) {
        return RET_INVARG;
    }

    return RET_OK;
}

/** Return desired column.
 *
 * \warning Splits the \p string into at least \p column of tokens, no copying
 *
 * \param string of \p delimiter separated substrings
 * \param column index has to be `>= 0`
 * \param delimiter is the character by which columns are separated
 * \return pointer to \p column
 */
char *nth_column(char *string, long column, char *delimiter)
{
    strtok(string, delimiter);
    while (string && (column-- > 0)) {
        string = strtok(NULL, delimiter); // continues where it ended
    }
    return string;
}

/** Print desired column.
 *
 * \param column to be printed
 * \return 0 or error code
 */
int print_column(long column)
{
    char input_cvs_line[MAX_LINE_LEN];

    read_input_string(input_cvs_line);

    char *nth_substring = nth_column(input_cvs_line, column, ",");
    if (nth_substring == NULL) {
        return RET_INVARG; // not enough columns
    }

    if (printf("%s\n", nth_substring) < 0)
        return RET_IOERR; // error writing to stream

    return RET_OK;
}

/** Call functions on standard input
 * \return \c EXIT_SUCCESS or error code
 */
int main(void)
{
    long rows, column;
    if (read_number(&rows) || rows < 0)
        return EXIT_FAILURE; // no number on first line

    if (read_number(&column) || column < 0)
        return EXIT_FAILURE;

    while (rows-- > 0)
        if ((errno = print_column(column)) != 0)
            return EXIT_FAILURE; // either it did not read enough or could not write

    return EXIT_SUCCESS; // yay!
}
