#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/pb071_alloc.h"

// do not alter following definitions
#define malloc(x) pb071_malloc(x)
#define realloc(x, y) pb071_realloc(x, y)
#define calloc(x, y) pb071_calloc(x, y)
#define free(x) pb071_free(x)

/**
 * malloc-int-ptr-array
 *
 * \author Lukas Rucka
 */

/*
 * Very similar to previous task, only change the signature.
 */

int **malloc_int_ptr_array(size_t n)
{
    int **ptr = calloc(n, sizeof(*ptr));
    if (ptr == NULL) {
        return NULL;
    }
    return ptr;
}

int main(void)
{
    pb071_alloc_init();
    if (sizeof(int *) != 8) {
        printf("This test may produce false-failures on your computer, it should however run fine on aisa.fi.muni.cz\n");
    }

    struct pb071_allocator_state *state = pb071_info_state();
    state->max_bytes_allocable = PB071_ALLOC_UNLIMITED;

    size_t array_length = 0;
    while (scanf("%zu", &array_length) == 1) {
        printf("%zu:\n", array_length);

        int **ptr = malloc_int_ptr_array(array_length);
        if (ptr == NULL) {
            printf("\tNULL");
            continue;
        }

        size_t allocated = pb071_info_allocated(ptr);
        printf("\tallocated: %zu %s\n", allocated, (allocated == state->already_allocated) ? "OK" : "OVER/UNDER KILL");

        for (size_t i = 0; i < array_length; ++i) {
            if (ptr[i] == NULL)
                printf("\t%zu: NULL\n", i);
            else
                printf("\t%zu: %p\n", i, (void *) ptr[i]);
        }

        free(ptr);
    }

    pb071_alloc_destroy();
    return EXIT_SUCCESS;
}

#if defined malloc
#undef malloc
#endif
#if defined calloc
#undef calloc
#endif
#if defined realloc
#undef realloc
#endif
#if defined free
#undef free
#endif
