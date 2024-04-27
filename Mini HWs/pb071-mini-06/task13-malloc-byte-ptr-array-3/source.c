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
 * Minihomework 06: Malloc byte pointer array 3
 * ---------------
 * Author: Lukas Rucka
 * Email:  xrucka@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * 1. Implement function malloc_byte_ptr_array_3 which allocates array of n+1
 *    pointers to uint8_t values.
 * 2. Pre-initialize all pointers except the first one with binary 0 (NULL).
 * 3. Assign the pointer to beginning of the array to first position of that
 *    array. That means (void*)(ptr[0]) == (void*)ptr.
 * 4. Make the return value a pointer to the first NULL pointer in the array.
 * 5. Complement malloc_byte_ptr_array_3 with free_byte_ptr_array_3 which takes
 *    pointer to the array obtained from malloc_byte_ptr_array_3 and invokes
 *    free on the correct position.
 */

uint8_t **malloc_byte_ptr_array_3(size_t n)
{
    /* TODO your code here instead of returning NULL */
    return NULL;
}

void free_byte_ptr_array_3(uint8_t **obtained_by_malloc_byte_ptr_array_3)
{
    (void *) obtained_by_malloc_byte_ptr_array_3;
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

        uint8_t **ptr = malloc_byte_ptr_array_3(array_length);
        if (ptr == NULL) {
            printf("\tNULL");
            continue;
        }

        size_t allocated = pb071_info_allocated(ptr - 1);
        printf("\tallocated: %zu %s\n", allocated, (allocated == state->already_allocated) ? "OK" : "OVER/UNDER KILL");

        printf("\tHeader: %s\n", (void *) (ptr[-1]) == (void *) (ptr - 1) ? "CHECK" : "INVALID");

        for (size_t i = 0; i < array_length; ++i) {
            if (ptr[i] == NULL)
                printf("\t%zu: NULL\n", i);
            else
                printf("\t%zu: %p\n", i, (void *) ptr[i]);
        }

        free_byte_ptr_array_3(ptr);
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
