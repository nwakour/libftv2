#ifndef __STRING_H__
#define __STRING_H__

#include "../libft/libft.h"

typedef char* stringIterator;

typedef struct s_string
{
	stringIterator _start;
	stringIterator _end;
	stringIterator _cap;
} t_string;

t_string stringInit();
t_string stringNew(const char *str);
t_string stringCopy(t_string *string);
void stringReserve(t_string *string, size_t n);
void stringClear(t_string *string);
void stringFree(t_string *string);
void stringAppendCString(t_string *dest, const char *src);
void stringAppendString(t_string *dest, const t_string *src);
size_t stringSize(const t_string *string);
size_t stringCapacity(const t_string *string);
stringIterator stringBegin(const t_string *string);
stringIterator stringEnd(const t_string *string);
void stringPrint(const t_string *string);
void stringPrintErr(const t_string *string);
stringIterator stringFindChar(const t_string *string, size_t start, const char c);
stringIterator stringRevFindChar(const t_string *string, size_t start, const char c);
int stringComString(const t_string *s1, const t_string *s2);
int stringComCString(const t_string *s1, const char *s2);
void _freeString(void *string);
int _findString(const void *string, const void *string2);
int _findCString(const void *string, const void *data);
#endif