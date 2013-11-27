#include <libgen.h> // for basename

#define off_t           loff_t

#ifndef MAX
#define MAX(x,y)        ((x) > (y) ? (x) : (y))
#endif

#ifndef MIN
#define MIN(x,y)        ((x) < (y) ? (x) : (y))
#endif

/* workaround for stpcpy */
static inline char *stpcpy(char *dst, const char *src)
{
    while (*src) {
        *dst++ = *src++;
    }
    // Need to copy the NULL terminator
    *dst = *src;
    return dst;
}

/* _mempcpy and mempcpy */
#ifndef __mempcpy
#define __mempcpy(dest, src, n)  mempcpy(dest, src, n)
#endif

#ifndef mempcpy
#include <string.h>

static inline void *mempcpy(void *dest, const void *src, size_t n)
{
    char *ptr = memcpy(dest, src, n);
    return ptr + n;
}
#endif

/* rawmemchr */
static inline void *rawmemchr(const void *s, int c)
{
    const unsigned char *ptr = s;
    while (1) {
        if (*ptr == c) return (void *) ptr;
        ptr++;
    }
}

/* workaround for canonicalize_file_name */
#define canonicalize_file_name(path) realpath(path, NULL)

/* workaround for open64 */
#define open64(path, flags)     open(path, ((flags) | O_LARGEFILE))
