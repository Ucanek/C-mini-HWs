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
 * Minihomework 06: Malloc byte array 2
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
 * 3. However, the array shall be preceded by (sizeof(uint8_t*)+sizeof(size_t))
 *    bytes, which store the pointer to the data including the service records
 *    preceding it, followed by sizeof(size_t) bytes storing the argument n.
 *    That is, the service records hold both the original pointer from malloc
 *    and number of uint8_t values requested by caller to allocate.
 * 4. Complement malloc_byte_array with free_byte_array which takes pointer to
 *    the array obtained from malloc_byte_array and invokes free on the correct
 *    position.
 *
 * For illustration, the array should look like this:
 *
 * | (1) *uint8_t pointing to (1) | (2) size_t n | (3) n * uint8_t |
 *
 * and malloc_byte_array should return pointer to (3).
 */

uint8_t *malloc_byte_array_2(size_t n)
{
    /* TODO your code here instead of returning NULL */
    return NULL;
}

void free_byte_array_2(uint8_t *obtained_by_malloc_byte_array_2)
{
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

        uint8_t *ptr = malloc_byte_array_2(array_length);
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

        free_byte_array_2(ptr);
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
