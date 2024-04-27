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
 * Minihomework 06: Malloc 256
 * ---------------
 * Author: Lukas Rucka
 * Email:  xrucka@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * Combine ptr_up_256 with malloc_byte_array_3.
 *
 * 1. Implement function malloc_256 which returns allocated array of n + 256
 *    uint8_t values.
 * 2. Zero-initialize the array.
 * 3. The pointer returned (and thus whole array) shall be aligned to address
 *    that is multiple of 256.
 * 4. Furthermore, the array shall be preceded by
 *    sizeof(uint8_t*) + sizeof(size_t) bytes which store the pointer to the
 *    original block of memory obtained from malloc, followed by bytes storing
 *    the argument n. That is, the service records hold both the original
 *    pointer from malloc number of bytes requested by caller to allocate.
 * 5. Complement malloc_256 with free_256, taking pointer to the array obtained
 *    from malloc_256 and invoking free on the correct position obtained
 *    from initial malloc.
 *
 * The return pointer will probably not point to beginning of allocated space,
 * thus the resulting array will not be (n + 256) values long, but that is the
 * desired behaviour.
 */

static void *ptr_up_256(void *round_me_up)
{
    /* TODO your coded here instead of returning NULL, you can copy-paste ptr-up-256 task */
    return NULL;
}

void *malloc_256(size_t n)
{
    /* TODO your code here instead of returning NULL, you can use one from malloc-byte-array-3 task */
    return NULL;
}

void free_256(void *obtained_by_malloc_256)
{
    (void *) obtained_by_malloc_256;
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

        uint8_t *ptr = malloc_256(array_length);
        if (ptr == NULL) {
            printf("\tNULL");
            continue;
        }

        size_t allocated = pb071_info_allocated(*(uint8_t **) (ptr - sizeof(ptr) - sizeof(size_t)));
        printf("\tallocated: %zu %s\n", allocated, (allocated == state->already_allocated) ? "OK" : "OVER/UNDER KILL");

        printf("\tHeader0: %s\n", (ptr - sizeof(ptr) - sizeof(size_t)) >= *(uint8_t **) (ptr - sizeof(ptr) - sizeof(size_t)) ? "CHECK" : "INVALID");
        printf("\tHeader1: %s\n", array_length == *(size_t *) (ptr - sizeof(size_t)) ? "CHECK" : "INVALID");

        for (size_t i = 0; i < array_length; ++i) {
            printf("\t%zu: 0x%02x\n", i, ptr[i]);
        }

        free_256(ptr);
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
