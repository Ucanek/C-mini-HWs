#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../libs/pb071_alloc.h"

// Do not alter following definitions
#define malloc(x) pb071_malloc(x)
#define realloc(x, y) pb071_realloc(x, y)
#define calloc(x, y) pb071_calloc(x, y)
#define free(x) pb071_free(x)

/*
 * Minihomework 06: Array 2D
 * ---------------
 * Author: Ondřej Pavlica
 * Email:  xpavlica@fi.muni.cz
 *
 * Please do NOT contact authors directly, use Discussions in IS MU instead.
 * Otherwise, you might not get an answer.
 *
 * ----------------------------------------------------------------------------
 *
 * A word enclosed in dashes (e.g. -example-) denotes a function parameter.
 *
 * Implement function array_2D, which returns a pointer to a 2D array of
 * members sized -size- each. The array will be of shape -rows-x-columns-,
 * so that address of item at coordinates row_index, col_index can be accessed
 * with *(array[row_index] + col_index*size). This means, firstly allocate
 * space for rows, then for columns.
 *
 * Allocate "extra" row holding a NULL pointer to mark the end of array.
 *
 * The function returns NULL if an error occurs.
 *
 * You can pass "-rows- -cols- -size-" to built binary via standard input
 * if you want to do your own testing.
 *
 * Finally, implement free_2D function to free the space previously allocated
 * for array. Use the fact that there is NULL after the last row.
 *
 * Hint: calloc() might come in handy in your solution.
 */

void **array_2D(size_t size, size_t rows, size_t columns)
{
    int num_of_arrays = 0;
    void **array = (void**)malloc((rows + 1) * sizeof(void*));
    if (array == NULL){
        return NULL;
    }
    array[rows] = NULL;

    for (int i = 0; i < rows; i++){
        array[i] = (void*)malloc(columns * size);
        if (array[i] == NULL){
            for (int j = 0; j < num_of_arrays; j++){
                free(array[j]);
                array[j] = NULL;
            }
            free(array);
            array = NULL;
            return NULL;
        }
        num_of_arrays++;
    }
    return array;
}

/*
 * Free for 2D array obtained by array2D.
 */
void free_2D(void **data)
{
    int i = 0;
    while (data[i] != NULL){
        free(data[i]);
        data[i] = NULL;
        i++;
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
