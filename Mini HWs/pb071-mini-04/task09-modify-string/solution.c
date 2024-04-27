#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 20

void remove_last(char *str);
void increment_by_one(char *str);
void string_to_upper(char *str);

/*
 * The functions can be stored as pointers with specified parameters.
 * The syntax is:
 * <return type of function> (*<name of function>)(<types of parameters>)
 * In this case, the func_array parameter can be interpreted as pointer to
 * array of pointers to functions taking char * as only argument and not
 * returning anything.
 * Note: Function passing is very useful in cases where you need to apply
 * different functions to data, but there is a lot of common functionality,
 * e.g. you have to filter it first.
 */

void modify_string(char *str, void (**func_array)(char *))
{
    while (*func_array != NULL) {
        (*func_array)(str);

        func_array++;
    }
}

int main(void)
{
    char str[BUFFER_SIZE];
    if (fgets(str, BUFFER_SIZE, stdin) == NULL) {
        return EXIT_FAILURE;
    }

    remove_last(str); // cut out a newline character
    printf("Original string: \"%s\"\n", str);

    void (*func_array[])(char *) = { remove_last, increment_by_one, string_to_upper, NULL };

    modify_string(str, func_array);

    printf("Modified string: \"%s\"\n", str);
    return EXIT_SUCCESS;
}

//*************** Modifier functions *****************

void remove_last(char *str)
{
    if (str == NULL || *str == '\0') {
        return;
    }

    size_t len = strlen(str);
    str[len - 1] = '\0';
}

void increment_by_one(char *str)
{
    for (; *str; ++str) {
        if (isalpha(*str)) {
            ++*str;
        }
    }
}

void string_to_upper(char *str)
{
    for (; *str; ++str) {
        *str = toupper((unsigned char) *str);
    }
}
