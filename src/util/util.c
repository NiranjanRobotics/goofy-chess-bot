#include "util.h"

void *safe_malloc(size_t size)
{
    void *allocated = malloc(size);

    if (!allocated)
    {
        fprintf(stderr, "[ERROR] Failed to allocate %zu bytes safely.\n", size);
        exit(1);
    }

    return allocated;
}
