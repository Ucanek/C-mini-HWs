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
 * array-2D
 *
 * \author Ondřej Pavlica
 */

/*
 * The (re/de)allocating functions you use in this task are not those from
 * standard library, they were modified to watch allocated space. For the
 * magic, see definitions in the beginning of this file.
 * Note: Valgrind uses very similar approach when torturing you with
 * memory leaks.
 */

void **array_2D(size_t size, size_t rows, size_t columns)
{
    void **rows_ptr = calloc(rows + 1, sizeof(void *));
    if (rows_ptr == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < rows; i++) {
        //The same thing as above, just compacted
        if (!(rows_ptr[i] = calloc(columns, size))) {
            return NULL;
        }
    }
    return rows_ptr;
}

void free_2D(void **data)
{
    for (size_t i = 0; data[i] != NULL; ++i) {
        free(data[i]);
    }
    free(data);
}

int main(void)
{
    pb071_alloc_init();
    if (sizeof(int *) != 8) {
        printf("This test may produce false-failures on your computer, it should however run fine on aisa.fi.muni.cz\n");
    }

    struct pb071_allocator_state *state = pb071_info_state();
    state->max_bytes_allocable = PB071_ALLOC_UNLIMITED;

    size_t item = 0, rows = 0, cols = 0;
    while (scanf("%zu %zu %zu", &rows, &cols, &item) == 3) {
        printf("%zu x %zu of %zu\n", rows, cols, item);

        void **ptr = array_2D(item, rows, cols);
        if (!ptr) {
            printf("\tNULL");
            continue;
        }

        printf("\trow_allocations: %zu\n", pb071_info_allocated(ptr));

        for (size_t i = 0; i < rows; ++i)
            printf("\tcol_allocations[%zu]: %zu\n", i, pb071_info_allocated(ptr[i]));
        printf("\ttotal_allocations: %zu\n", state->already_allocated);

        free_2D(ptr);
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
