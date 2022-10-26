#include "ft_string.h"

t_string stringInit()
{
	t_string new;
	new._cap = new._end = new._start = NULL;
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
void stringFree(t_string *string)
{
	stringClear(string);
	free(string->_start);
	string->_cap = string->_end = string->_start = NULL;
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

t_string stringNew(const char *str)
{
	t_string new;
	new._cap = new._end = new._start = NULL;
	stringAppendCString(&new, str);
	return (new);
}
t_string stringCopy(t_string *string)
{
	t_string new;
	stringAppendCString(&new, string->_start);
	return (new);
}
void stringPrintErr(const t_string *string)
{
	ft_putstr_fd(string->_start, 2);
}

stringIterator stringBegin(const t_string *string)
{
	return (string->_start);
}

stringIterator stringEnd(const t_string *string)
{
	return (string->_end);
}

stringIterator stringFindChar(const t_string *string, size_t start, const char c)
{
	if (start > stringSize(string))
		return (string->_end);
	stringIterator ptr = string->_start + start;
	while (ptr < string->_end)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (string->_end);
}

stringIterator stringRevFindChar(const t_string *string, size_t start, const char c)
{
	if (start > stringSize(string))
		return (string->_end);
	stringIterator ptr = string->_start + start;
	while (ptr >= string->_start)
	{
		if (*ptr == c)
			return (ptr);
		ptr--;
	}
	return (string->_end);
}

int stringComString(const t_string *s1, const t_string *s2)
{
	return (ft_strcmp(s1->_start, s2->_start));
}

int stringComCString(const t_string *s1, const char *s2)
{
	return (ft_strcmp(s1->_start, s2));
}

void _freeString(void *string)
{
	stringFree((t_string *)string);
}

int _findString(const void *string, const void *string2)
{
	return (stringComString((const t_string *)string, (const t_string *)string2));
}

int _findCString(const void *string, const void *data)
{
	return (stringComCString((const t_string *)string, (const char *)data));
}