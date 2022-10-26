#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "../libft/libft.h"

typedef void* vectorIterator;
typedef struct s_vector
{
	vectorIterator _start;
	vectorIterator _end;
	vectorIterator _cap;
	size_t _typeSize;
	void (*_free)(void *);
} t_vector;

t_vector vectorInit(size_t typeSize, void (*_free)(void*));
t_vector vectorCopy(const t_vector *src);
t_vector vectorCopyDeep(const t_vector *src, void *(*_copy)(void*));
void vectorReserve(t_vector *vector, size_t size);
void vectorClear(t_vector *vector);
void vectorFree(t_vector *vector);
void vectorPushBack(t_vector *vector, const void *data);
void vectorPushFront(t_vector *vector, const void *data);
void vectorPopBack(t_vector *vector);
void vectorPopFront(t_vector *vector);
void vectorInsert(t_vector *vector, size_t index, const void *data);
void vectorInsertIt(t_vector *vector, vectorIterator it,const void *data);
void vectorErase(t_vector *vector, size_t index);
void vectorEraseIt(t_vector *vector, vectorIterator it);
void vectorEraseRange(t_vector *vector, size_t index, size_t count);
void vectorEraseRangeIt(t_vector *vector, vectorIterator first, vectorIterator last);
size_t vectorSize(const t_vector *vector);
size_t vectorCapacity(const t_vector *vector);
vectorIterator vectorBegin(const t_vector *vector);
vectorIterator vectorEnd(const t_vector *vector);
int vectorIsEnd(const t_vector *vector, const vectorIterator it);
vectorIterator vectorFind(const t_vector *vector, const void *data, int (*cmp)(const void*, const void*));
vectorIterator vectorNext(const t_vector *vector, vectorIterator it);
vectorIterator vectorAt(const t_vector *vector, size_t index);
#endif