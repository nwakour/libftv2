#include "libft.h"

void *ft_calloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (ptr == NULL)
        return (NULL);
    ft_bzero(ptr, size);
    return (ptr);
}