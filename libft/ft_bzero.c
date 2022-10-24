#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    char *ptr = s;
    while (n--)
        *ptr++ = 0;
}