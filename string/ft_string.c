#include "ft_string.h"

typedef struct s_string
{
	char *_start;
	char *_end;
	char *_cap;
} t_string;

t_string *stringInit()
{
	t_string *new = ft_calloc(sizeof(t_string));
	if (new == NULL)
		return (NULL);
	return (new);
}

size_t stringSize(const t_string *string)
{
	return (string->_end - string->_start);
}

size_t stringCapacity(const t_string *string)
{
	return (string->_cap - string->_start);
}

const char *stringGetStr(const t_string *string)
{
	return (string->_start);
}
void stringClear(t_string *string)
{
	string->_end = string->_start;
	string->_end[0] = '\0';
}
void stringReserve(t_string *string, size_t n)
{
	size_t size = stringSize(string);
	size_t cap = stringCapacity(string);
	if (cap >= n)
		return;
	char *new = malloc(n);
	if (new == NULL)
		return;
	ft_memcpy(new, string->_start, size);
	free(string->_start);
	string->_start = new;
	string->_end = new + size;
	string->_cap = new + n;
}
void stringFree(t_string **string)
{
	if (string == NULL || *string == NULL)
		return;
	free((*string)->_start);
	(*string)->_start = (*string)->_end = (*string)->_cap = NULL;
	free(*string);
	*string = NULL;
}

void stringAppendCString(t_string *dest, const char *src)
{
	size_t size = stringSize(dest);
	size_t cap = stringCapacity(dest);
	size_t len = ft_strlen(src);
	if (len < cap - size)
	{
		ft_memcpy(dest->_end, src, len);
		dest->_end += len;
		dest->_end[0] = '\0';
	}
	else
	{
		size = size + len + 1;
		if (size > cap * 2)
			cap = size;
		else
			cap *= 2;
		stringReserve(dest, cap);
		ft_memcpy(dest->_end, src, len);
		dest->_end += len;
		dest->_end[0] = '\0';
	}
}

void stringAppendString(t_string *dest, const t_string *src)
{
	stringAppendCString(dest, src->_start);
}

void stringPrint(const t_string *string)
{
	ft_putstr_fd(string->_start, 1);
}

void stringPrintErr(const t_string *string)
{
	ft_putstr_fd(string->_start, 2);
}

char *stringGetnStr(const t_string *string, size_t n)
{
	if (n > stringSize(string))
		return (NULL);
	return (string->_start + n);
}

char *stringBegin(const t_string *string)
{
	return (string->_start);
}

char *stringEnd(const t_string *string)
{
	return (string->_end);
}