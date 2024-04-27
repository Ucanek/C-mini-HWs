#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

/*
 * Minihomework 05: string statistics (easy)
 * =========================================
 *
 * Author:  Ondrej Sebek
 * Email:   xsebek@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to count the number of digits, uppercase and lowercase letters
 * in the input until 'EOF' comes.
 *
 * Pass your results as array [Digits, Lowercase, Uppercase] to the 'printer'
 * function which will print them in the correct format.
 *
 * Do not change the 'printer' and 'line_print' functions, write your code
 * directly into main function.
 *
 * Hint: use functions from ctype.h library
 * 
 * Example input : Hello there!
 * Example output :
 *                  ------------------------------
                    |    Digits |               0|
                    ------------------------------
                    | Lowercase |               9|
                    ------------------------------
                    | Uppercase |               1|
                    ------------------------------
 */

/**
 * \defgroup Printing the character counts
 *
 * \brief Print results of your hard work
 *
 * \param[in] counts of characters in the following order
 * - Digits
 * - Lowercase
 * - Uppercase
 *
 * \return 0 or standard error code (see errno.h)
 */
int printer(size_t counts[3]);

/** Print a line of length `length`.
 * \return 0 or error code
 */
int line_print(size_t length)
{
    for (; length > 0; --length) {
        if (putchar('-') == EOF) {
            return ferror(stdin);
        }
    }
    if (putchar('\n') == EOF) {
        return ferror(stdin);
    }
    return EXIT_SUCCESS;
}

int printer(size_t counts[3])
{
    int result = 0;
    char *names[3] = {"Digits", "Lowercase", "Uppercase"};
    if ((result = line_print(30)) != EXIT_SUCCESS) {
        return result;
    }

    for (int i = 0; i < 3; ++i) {
        if (0 > printf("|%10s | %15zu|\n", names[i], counts[i])) {
            result = EIO; // some output problem \(°_°)/
            break;
        }
        if ((result = line_print(30)) != EXIT_SUCCESS) {
            break;
        }
    }
    return result;
}

int main(void)
{
    int counts[3];
    int Digits = 0;
    int Lowercase = 0;
    int Uppercase = 0;
    int c;
    
    while ((c = getchar()) != EOF){
        if (isdigit(c)){
            Digits++;
        }
        else if (islower(c)){
            Lowercase++;
        }
        else if (isupper(c)){
            Uppercase++;
        }
    }
    counts[0] = Digits;
    counts[1] = Lowercase;
    counts[3] = Uppercase;
    printf("%d", counts);
    return EXIT_SUCCESS;
}
