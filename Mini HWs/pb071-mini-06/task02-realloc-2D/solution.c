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
 * realloc-2D
 *
 * \author Ondřej Pavlica
 * \author Lukas Rucka
 */

/*
 * Do not forget to reallocate not only each row, but the array as whole
 * (the number of rows).
 */

void free_2D(void **data)
{
    for (size_t i = 0; data[i] != NULL; ++i) {
        free(data[i]);
    }
    free(data);
}

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

void **realloc_2D(void **array, size_t size, size_t rows, size_t columns)
{
    size_t orig_rows = 0;
    while (array[orig_rows] != NULL) {
        ++orig_rows;
    }

    for (size_t i = 0; i < orig_rows; ++i) {
        if (!(array[i] = realloc(array[i], columns * size))) {
            return NULL; 
        }
    }

    if (!(array = realloc(array, (rows + 1) * sizeof(*array)))) {
        return NULL;
    }

    for (size_t i = orig_rows; i < rows; ++i) {
        if (!(array[i] = calloc(columns, size))) {
            return NULL;
        }
    }

    array[rows] = NULL;
    return array;
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

        void **ptr0 = array_2D(item, rows, cols);
        // double allocable memory
        state->max_bytes_allocable = (2 * rows + 1) * sizeof(*ptr0) + 2 * rows * 2 * cols * item;

        void **ptr = realloc_2D(ptr0, item, 2 * rows, 2 * cols);

        if (ptr == NULL) {
            printf("\tNULL");
            continue;
        }

        printf("\trow_allocations: %zu\n", pb071_info_allocated(ptr));

        for (size_t i = 0; i < rows; ++i) {
            printf("\tcol_allocations[%zu]: %zu\n", i, pb071_info_allocated(ptr[i]));
        }
        printf("\ttotal_allocations: %zu\n", state->already_allocated);

        free_2D(ptr);
        state->max_bytes_allocable = PB071_ALLOC_UNLIMITED;
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
