#include <stdio.h>
#include <stdlib.h>

/**
 * Minihomework 03: loaders
 *
 * \author Antonín Dufka <xdufka1@fi.muni.cz>
 */

/*
 * For reading from standard input, use scanf function. The format string has
 * the same meaning as in printf.
 * Note: (buffer + i) is equal to &(buffer[i]) - refers to address of
 * i-th element in buffer.
 * Note: With fprintf function, you can write to any output stream - in this
 * case, to standard error output, stderr.
 */

void intloader(int *buffer, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i) {
        if (scanf("%d", buffer + i) != 1) {
            fprintf(stderr, "Error: something nasty going on here\n");
            exit(1);
        }
    }
}

void floatloader(float *buffer, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i) {
        if (scanf("%f", buffer + i) != 1) {
            fprintf(stderr, "Error: something nasty going on here\n");
            exit(1);
        }
    }
}

void charloader(char *buffer, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i) {
        if (scanf(" %c", buffer + i) != 1) {
            fprintf(stderr, "Error: something nasty going on here\n");
            exit(1);
        }
    }
}

int main(void)
{
    int ibuff[100];
    for (int i = 0; i < 100; ++i) {
        ibuff[i] = i;
    }
    intloader(ibuff, 10);
    intloader(ibuff + 20, 5);
    intloader(ibuff + 20, 3);
    intloader(ibuff + 30, 0);
    intloader(ibuff + 50, 43);
    intloader(ibuff + 100, 0);
    for (int i = 0; i < 100; ++i) {
        printf("%d\n", ibuff[i]);
    }

    char cbuff[10];
    for (int i = 0; i < 10; ++i) {
        cbuff[i] = 'a' + i;
    }
    charloader(cbuff + 1, 8);
    for (int i = 0; i < 10; ++i) {
        printf("%c\n", cbuff[i]);
    }

    float fbuff[5];
    for (int i = 0; i < 5; ++i) {
        fbuff[i] = (float) i;
    }
    floatloader(fbuff + 1, 3);
    for (int i = 0; i < 5; ++i) {
        printf("%f\n", fbuff[i]);
    }

    return EXIT_SUCCESS;
}
