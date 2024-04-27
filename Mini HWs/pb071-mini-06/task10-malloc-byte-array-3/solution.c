#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "../libs/pb071_alloc.h"

// do not alter following definitions
#define malloc(x) pb071_malloc(x)
#define realloc(x, y) pb071_realloc(x, y)
#define calloc(x, y) pb071_calloc(x, y)
#define free(x) pb071_free(x)

/**
 * malloc-byte-array-3
 *
 * \author Lukas Rucka
 */

/*
 * It might seem weird why the dereferences and conversions are done, but it is
 * simple - access given address as conversed type (pointer) and write there
 * the data.
 */

uint8_t *malloc_byte_array_3(size_t n)
{
    uint8_t *ptr_total = malloc(n + sizeof(ptr_total) + sizeof(size_t) + 256);
    if (ptr_total == NULL) {
        return NULL;
    }
    uint8_t *return_ptr = ptr_total + sizeof(ptr_total) + sizeof(size_t);
    memset(return_ptr, 0x00, n);
    *(uint8_t **) (return_ptr - sizeof(ptr_total) - sizeof(size_t)) = ptr_total;
    *(size_t *) (return_ptr - sizeof(size_t)) = n;
    return return_ptr;
}

void free_byte_array_3(uint8_t *obtained_by_malloc_byte_array_3)
{
    free(obtained_by_malloc_byte_array_3 - sizeof(obtained_by_malloc_byte_array_3) - sizeof(size_t));
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

        uint8_t *ptr = malloc_byte_array_3(array_length);
        if (ptr == NULL) {
            printf("\tNULL");
            continue;
        }

        size_t allocated = pb071_info_allocated(ptr - sizeof(ptr) - sizeof(size_t));
        printf("\tallocated: %zu %s\n", allocated, (allocated == state->already_allocated) ? "OK" : "OVER/UNDER KILL");

        printf("\tHeader0: %s\n", (ptr - sizeof(ptr) - sizeof(size_t)) == *(uint8_t **) (ptr - sizeof(ptr) - sizeof(size_t)) ? "CHECK" : "INVALID");
        printf("\tHeader1: %s\n", array_length == *(size_t *) (ptr - sizeof(size_t)) ? "CHECK" : "INVALID");

        for (size_t i = 0; i < array_length; ++i) {
            printf("\t%zu: 0x%02x\n", i, ptr[i]);
        }

        free_byte_array_3(ptr);
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
