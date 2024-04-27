#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Minihomework 08: URL encoder
 * ---------------
 * Author: Adrian Hrinko
 * Email:  456684@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Your task is to write a simple URL encoder. I recommend you to check this
 * before you start: https://en.wikipedia.org/wiki/Percent-encoding
 *
 * Our encoder is doing nothing else but replacing some undesirable characters
 * by %{upper_case_hex_value_of_that_character}. For example, if we have ' '
 * (also known as space), it is going to be replaced by '%20' as 20 is
 * the hexadecimal value of space in ASCII table. Assume we have '\' - this
 * will be replaced by %5C as 5C is hexadecimal value of '\' in ASCII table.
 * Alphanumeric characters and few other characters like '~', '-', '.' and '_'
 * should stay intact! Other (undesirable ones) should be replaced according to
 * the rule mentioned above.
 *
 * HINT: Here is a format you can use to convert character to its substitution:
 * "%%%02X"
 *
 * Let's see an example with whole URL:
 *
 * Input: https://www.urlencoder.org/
 * Output: https%3A%2F%2Fwww.urlencoder.org%2F
 *
 * Input will be taken from stdin and output is expected on stdout.
 *
 * Length of URL on input is not limited.
 *
 * The newlines do not belong to URL, but they are expected on output.
 */

int main(void)
{
    char* URL = NULL;
    int size = 0;
    char symbol;
    URL = malloc(sizeof(char));
    if (URL == NULL){
        fprintf(stderr, "Alloc failed.\n");
        return EXIT_FAILURE;
    }

    while ((symbol = getchar()) != '\n'){
        URL[size] = symbol;
        size++;
        URL = realloc(URL, size + sizeof(char));
        if (URL == NULL){
            fprintf(stderr, "Realloc failed.\n");
            free(URL);
            URL = NULL;
            return EXIT_FAILURE;
        }
    }

    int i = 0;
    while (URL[i] != '\0'){
        switch (URL[i]){
            case '!':
                printf("%%21");
                break;
            case '#':
                printf("%%23");
                break;
            case '$':
                printf("%%24");
                break;
            case '&':
                printf("%%26");
                break;
            case '\'':
                printf("%%27");
                break;
            case '(':
                printf("%%28");
                break;
            case ')':
                printf("%%29");
                break;
            case '*':
                printf("%%2A");
                break;
            case '+':
                printf("%%2B");
                break;
            case ',':
                printf("%%2C");
                break;
            case '/':
                printf("%%2F");
                break;
            case ':':
                printf("%%3A");
                break;
            case ';':
                printf("%%3B");
                break;
            case '=':
                printf("%%3D");
                break;
            case '?':
                printf("%%3F");
                break;
            case '@':
                printf("%%40");
                break;
            case '[':
                printf("%%5B");
                break;
            case ']':
                printf("%%5D");
                break;
            default:
                printf("%c", URL[i]);
                break;
        }
        i++;
    }
    printf("\n");

    free(URL);
    URL = NULL;
    return EXIT_SUCCESS;
}