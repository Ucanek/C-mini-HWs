#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * url-encode
 *
 * \author Adrian Hrinko
 */

/*
 * Dynamic allocation is necessary because the maximum length of URL is
 * not specified.
 */

void compute_table(int table[256])
{
    for (int i = 0; i < 256; i++) {
        table[i] = isalnum(i) || i == '~' || i == '-' || i == '.' || i == '_' ? i : 0;
    }
}

size_t char_as_hex_ascii(char *where, char c)
{
    char hex_num[5];
    sprintf(hex_num, "%%%02X", c);
    strcpy(where, hex_num);
    return strlen(hex_num);
}

size_t get_input(char **input)
{
    int c;
    size_t size = 0;
    size_t buff_size = 256;
    if ((*input = (char *) malloc(buff_size)) == NULL) {
        fprintf(stderr, "Allocation error\n");
        return 0;
    }
    char *temp;

    c = getchar();

    while (c != '\n') {
        if (size >= buff_size) {
            buff_size *= 2;
            temp = (char *) realloc(input, buff_size);

            if (temp == NULL) {
                fprintf(stderr, "Allocation error\n");
                free(input);
                return 0;
            }

            *input = temp;
        }

        (*input)[size] = (char) c;
        c = getchar();
        size++;
    }
    (*input)[size] = '\0';
    return size;
}

int main(void)
{
    int table[256] = { 0 };

    char *url;
    size_t size = get_input(&url);

    if (size == 0) {
        free(url);
        return EXIT_FAILURE;
    }

    compute_table(table);

    char encoded[size * 3 + 1];

    size_t j = 0;

    for (size_t i = 0; i < size; i++) {
        char c = url[i];
        if (table[(int) c] > 0) {
            encoded[j] = c;
            j++;
        } else {
            j += char_as_hex_ascii(encoded + j, c);
        }
    }

    encoded[j] = '\0';

    printf("%s\n", encoded);

    free(url);

    return EXIT_SUCCESS;
}
