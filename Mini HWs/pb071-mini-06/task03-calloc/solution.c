#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../libs/pb071_alloc.h"

// do not alter following definitions
#define malloc(x) pb071_malloc(x)
#define realloc(x, y) pb071_realloc(x, y)
#define calloc(x, y) pb071_calloc(x, y)
#define free(x) pb071_free(x)

/**
 * calloc
 *
 * \author Ondřej Pavlica
 */

/*
 * Calloc is useful for e.g. manipulating strings, because you do not have to
 * worry about terminating '\0' (except for writing to whole allocated space),
 * if whole space is set to '\0'.
 */

void *calloc_2(size_t num, size_t size)
{
    void *ptr = malloc(num * size);
    if (!ptr) {
        return NULL;
    }
    if (!memset(ptr, 0, num * size)) {
        return NULL;
    }
    return ptr;
}

int main(void)
{
    pb071_alloc_init();

    struct pb071_allocator_state *state = pb071_info_state();
    state->max_bytes_allocable = PB071_ALLOC_UNLIMITED;

    size_t array_length = 0, item_length = 0;
    while (scanf("%zu %zu", &array_length, &item_length) == 2) {
        printf("%zu:\n", array_length);

        uint8_t *ptr = (uint8_t *) calloc_2(array_length, item_length);
        if (!ptr) {
            printf("\tNULL");
            continue;
        }

        size_t allocated = pb071_info_allocated(ptr);
        printf("\tallocated: %zu %s\n", allocated, (allocated == state->already_allocated) ? "OK" : "OVER/UNDER KILL");

        for (size_t i = 0; i < array_length; ++i) {
            printf("\t%zu: 0x", i);
            for (size_t j = 0; j < item_length; ++j)
                printf("%02x", ptr[i * item_length + j]);
            printf("\n");
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
