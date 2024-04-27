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

/*
 * Minihomework 06: Malloc byte array
 * ---------------
 * Author: Lukas Rucka
 * Email:  xrucka@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Complete following subtasks:
 * 1. Implement function malloc_byte_array which returns allocated array of n
 *    uint8_t values.
 * 2. Zero-initialize the array.
 * 3. However, the array shall be preceded by sizeof(uint8_t*) bytes, which
 *    store the pointer to the data including the service pointer preceding it.
 * 4. Complement malloc_byte_array with free_byte_array which takes pointer to
 *    the array obtained from malloc_byte_array and invokes free on the correct
 *    position.
 *
 * For illustration, the array should look like this:
 *
 * |(1) *uint8_t pointing to (1) | (2) n * uint8_t |
 *
 * and malloc_byte_array should return pointer to (2).
 */

uint8_t *malloc_byte_array(size_t n)
{
    uint8_t array = calloc(n, sizeof(uint8_t));
    if (array == NULL){
        return NULL;
    }
}

void free_byte_array(uint8_t *obtained_by_malloc_byte_array)
{
    (void *) obtained_by_malloc_byte_array;
    /* TODO your code here */
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

        uint8_t *ptr = malloc_byte_array(array_length);
        if (!ptr) {
            printf("\tNULL");
            continue;
        }

        size_t allocated = pb071_info_allocated(ptr - sizeof(ptr));
        printf("\tallocated: %zu %s\n", allocated, (allocated == state->already_allocated) ? "OK" : "OVER/UNDER KILL");

        printf("\tHeader: %s\n", (void *) (ptr - sizeof(ptr)) == *(uint8_t **) (ptr - sizeof(ptr)) ? "CHECK" : "INVALID");

        for (size_t i = 0; i < array_length; ++i) {
            printf("\t%zu: 0x%02x\n", i, ptr[i]);
        }

        free_byte_array(ptr);
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
