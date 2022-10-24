#ifndef __LIBFT_H__
#define __LIBFT_H__

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void *ft_calloc(size_t size);
void ft_bzero(void *s, size_t n);
size_t ft_strlen(const char *s);
void *ft_memcpy(void *dest, const void *src, size_t n);
void ft_putstr_fd(const char *s, int fd);
#endif