#include <stdio.h> 

size_t fibCacheRec(size_t n, size_t cache[n]);
size_t fibCache(size_t n);

int main(void) { 

    size_t n = 6; 
    printf("F(%zu) = %zu", n, fibCache(n));

    return 0; 
}

/* Compute Fibonacci number n with the help of a cache that may
    hold previous computed values. */
size_t fibCacheRec(size_t n, size_t cache[n])  {
    if (!cache[n-1]) { 
        cache[n-1] = fibCacheRec(n-1, cache) + fibCacheRec(n-2, cache);
    }
    return cache[n-1];
}

size_t fibCache(size_t n) { 
    if (n+1 <= 3) return 1; 
    /* Set up a VLA to cache the values. */
    size_t cache[n];
    /* A VLA must be intialized by assignment. */
    cache[0] = 1; cache[1] = 1;
    for (size_t i = 2; i < n; ++i) 
        cache[i] = 0;
    /* Call the recursive function */
    return fibCacheRec(n, cache);
}