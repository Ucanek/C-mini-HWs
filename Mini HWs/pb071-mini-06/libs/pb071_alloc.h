#ifndef MINI06_PB071_ALLOC_H
#define MINI06_PB071_ALLOC_H

#include <stdlib.h>

void *pb071_malloc(size_t size);
void *pb071_calloc(size_t nmemb, size_t size);
void *pb071_realloc(void *original_uptr, size_t nmemb);
void pb071_free(void *uptr);

struct pb071_allocator_state;
struct pb071_allocator_state *pb071_info_state(void);
size_t pb071_info_allocated(void *uptr);

void pb071_info_save(void);
void pb071_info_load(void);
void pb071_alloc_init(void);
void pb071_alloc_destroy(void);

#define PB071_ALLOC_UNLIMITED ((size_t) -1)

struct pb071_allocator_state
{
    size_t max_bytes_allocable;
    size_t already_allocated_monotonic;
    size_t already_allocated;
};


#endif //MINI06_PB071_ALLOC_H
