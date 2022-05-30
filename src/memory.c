#include "common.h"
#include "memory.h"

void* reallocate(void* ptr, size_t old_size, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    // 1. when old_size is zero, realloc() is equivalent to calling malloc().
    // 2. if the new size is smaller than the existing block of memory, it
    // simply updates the size of the block and returns the same pointer you
    // gave it
    // 3. if there isn’t room to grow the block, realloc() instead allocates a
    // new block of memory of the desired size, copies over the old bytes, frees
    // the old block, and then returns a pointer to the new block
    void* result = realloc(ptr, new_size);
    if (result == NULL) {
        printf("reallocate failed for %p with new size %d\n", ptr, new_size);
        exit(1);
    }
    // printf("reallocated %p as %p from %d to %d\n", ptr, result, old_size,
    //        new_size);
    return result;
}