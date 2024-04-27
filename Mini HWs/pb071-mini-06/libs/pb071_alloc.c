#include <string.h>
#include <stdio.h>
#include "pb071_alloc.h"

static struct pb071_allocator_state *alloc_status;
static struct pb071_allocator_state saved_state;

static void *pb071_info_realptr(void *uptr)
{
    return (char *) uptr - sizeof(size_t);
}

static void *pb071_info_userptr(void *rptr)
{
    return (char *) rptr + sizeof(size_t);
}

static void pb071_info_set_allocated(void *uptr, size_t allocated)
{
    (*(size_t *) pb071_info_realptr(uptr)) = allocated;
}

static size_t pb071_info_req(size_t length)
{
    return sizeof(size_t) + length;
}

size_t pb071_info_allocated(void *uptr)
{
    return *(size_t *) pb071_info_realptr(uptr);
}

void *pb071_malloc(size_t size)
{
    if (alloc_status == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        return NULL;
    }

    if ((alloc_status->already_allocated + size) > alloc_status->max_bytes_allocable) {
        return NULL;
    }

    void *rptr = malloc(pb071_info_req(size));

    if (rptr == NULL) {
        return NULL;
    }

    void *uptr = pb071_info_userptr(rptr);

    pb071_info_set_allocated(uptr, size);
    alloc_status->already_allocated += size;
    alloc_status->already_allocated_monotonic += size;

    return uptr;
}

void *pb071_calloc(size_t nmemb, size_t size)
{
    if (alloc_status == NULL) {
        return calloc(nmemb, size);
    }

    if (size == 0) {
        return NULL;
    }

    void *uptr = pb071_malloc(nmemb * size);

    if (uptr == NULL) {
        return NULL;
    }

    memset(uptr, 0, nmemb * size);

    return uptr;
}

void *pb071_realloc(void *original_uptr, size_t nmemb)
{
    if (alloc_status == NULL) {
        return realloc(original_uptr, nmemb);
    }

    if (original_uptr == NULL) {
        return pb071_malloc(nmemb);
    }

    size_t original = pb071_info_allocated(original_uptr);

    if (alloc_status->already_allocated - original + nmemb > alloc_status->max_bytes_allocable) {
        return NULL;
    }

    void *original_rptr = pb071_info_realptr(original_uptr);

    void *new_rptr = realloc(original_rptr, pb071_info_req(nmemb));
    if (new_rptr == NULL) {
        return NULL;
    }

    void *new_uptr = pb071_info_userptr(new_rptr);
    pb071_info_set_allocated(new_uptr, nmemb);

    alloc_status->already_allocated -= original;
    alloc_status->already_allocated += nmemb;
    alloc_status->already_allocated_monotonic -= original;
    alloc_status->already_allocated_monotonic += nmemb;

    return new_uptr;
}

void pb071_free(void *uptr)
{
    if (alloc_status == NULL) {
        free(uptr);
        return;
    }

    void *rptr = pb071_info_realptr(uptr);

    size_t original_size = pb071_info_allocated(uptr);
    alloc_status->already_allocated -= original_size;

    free(rptr);
}

void pb071_alloc_destroy(void)
{
    if (alloc_status != NULL) {
        free(alloc_status);
    }
    alloc_status = NULL;
}

void pb071_alloc_init(void)
{
    alloc_status = malloc(sizeof(*alloc_status));
    memset(alloc_status, 0, sizeof(*alloc_status));

    if (atexit(pb071_alloc_destroy) != 0) {
        fprintf(stderr, "atexit for allocator failed, report this to task author\n");
    }
}

struct pb071_allocator_state *pb071_info_state(void)
{
    return alloc_status;
}

void pb071_info_save(void)
{
    if (alloc_status == NULL) {
        return;
    }
    saved_state = *alloc_status;
}

void pb071_info_load(void)
{
    if (alloc_status == NULL) {
        return;
    }
    *alloc_status = saved_state;
}

