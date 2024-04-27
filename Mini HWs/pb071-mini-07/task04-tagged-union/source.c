#include <stdio.h>
#include <stdlib.h>

/*
 * Minihomework 07: Tagged union
 * ---------------
 * Author: Adam Považanec
 * Email:  469045@mail.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 * ----------------------------------------------------------------------------
 *
 * A tagged union is a type which can hold several different but fixed types.
 * Only one of the types can be in use at a time, and a tag field explicitly
 * indicates which one it is.
 * 
 * There is already a prepared definition of a 'tagged_union_t' structure, 
 * which can hold a value of type 'int', 'float' or 'char *'. What type is 
 * currently being used is indicated by 'tag' field in the structure.
 * 
 * Your task is to implement 'print_var' function, which will print out the
 * content of supplied 'tagged_union_t' structure according to its type.
 * 
 * Output format:
 *  - end output of your function with a newline
 *  - round floating values to 2 decimal places
 *  - if the structure has type empty, print "empty"
 *  - if supplied parameter pointer is NULL, don't print anything
 * 
 * Do not change anything else except function print_var.
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
    if (var == NULL){
        return;
    }
    else if (var->tag == empty){
        printf("empty\n");
    }
    else if (var->tag == integer){
        printf(" %d\n", var->value.i);
    }
    else if (var->tag == floating){
        printf(" %.2f\n", var->value.f);
    }
    else if (var->tag == string){
        if (var->value.s != NULL){
            printf(" %s\n", var->value.s);
        }
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
