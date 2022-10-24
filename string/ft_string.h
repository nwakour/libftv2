#ifndef __STRING_H__
#define __STRING_H__

#include "../libft/libft.h"

typedef struct s_string t_string;

t_string *stringInit();
t_string *stringNew(const char *str);
t_string *stringCopy(t_string *string);
void stringReserve(t_string *string, size_t n);
void stringClear(t_string *string);
void stringFree(t_string **string);
void stringAppendCString(t_string *dest, const char *src);
void stringAppendString(t_string *dest, const t_string *src);
size_t stringSize(const t_string *string);
size_t stringCapacity(const t_string *string);
const char *stringGetStr(const t_string *string);
char *stringGetnStr(const t_string *string, size_t n);
char *stringBegin(const t_string *string);
char *stringEnd(const t_string *string);
void stringPrint(const t_string *string);
void stringPrintErr(const t_string *string);
size_t stringFindChar(const t_string *string, const char c);

#endif