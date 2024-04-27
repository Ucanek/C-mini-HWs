#include <stdio.h>
#include <stdlib.h>

/**
 * tagged-union
 *
 * \author Adam Považanec
 */

/*
 * If you have pointer to structure, use -> operator when accessing its
 * attributes (ptr->attr is a short for (*ptr).attr).
 */

typedef struct tagged_union
{
    enum
    {
        empty,
        integer,
        floating,
        string
    } tag;
    union
    {
        int i;
        float f;
        char *s;
    } value;
} tagged_union_t;

void print_var(const tagged_union_t *var)
{
    if (var == NULL) {
        return;
    }

    switch (var->tag) {
    case empty:
        printf("empty\n");
        break;
    case integer:
        printf("%d\n", var->value.i);
        break;
    case floating:
        printf("%.2f\n", var->value.f);
        break;
    case string:
        printf("%s\n", var->value.s);
        break;
    }
}

int main(void)
{
    print_var(NULL);

    tagged_union_t test_empty = {
        .tag = empty
    };
    print_var(&test_empty);

    tagged_union_t test_int = {
        .tag = integer,
        .value.i = 42
    };
    print_var(&test_int);

    tagged_union_t test_float_short = {
        .tag = floating,
        .value.f = 4.2
    };
    print_var(&test_float_short);

    tagged_union_t test_float_long = {
        .tag = floating,
        .value.f = 4.128
    };
    print_var(&test_float_long);

    tagged_union_t test_string = {
        .tag = string,
        .value.s = "Hello world!"
    };
    print_var(&test_string);

    return EXIT_SUCCESS;
}
