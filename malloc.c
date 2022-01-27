#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

void *malloc(size_t size) {
    static void* (*real_malloc)(size_t) = NULL;
    static size_t total_alloc;
    total_alloc += size;

    if (!real_malloc)
        real_malloc = dlsym(RTLD_NEXT, "malloc");

    fprintf(stderr, "Total bytes allocated so far: %lu\n", total_alloc);
    return real_malloc(size);
}
