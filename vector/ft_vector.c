#include "ft_vector.h"

t_vector vectorInit(size_t typeSize, void (*_free)(void *))
{
	t_vector new;
	new._start = new._end = new._cap = NULL;
	new._typeSize = typeSize;
	new._free = _free;
	return (new);
}

void vectorReserve(t_vector *vector, size_t n)
{
	size_t size = vectorSize(vector);
	size_t cap = vectorCapacity(vector);
	if (cap >= n)
		return;
	void *new = malloc(n * vector->_typeSize);
	if (new == NULL)
		return;
	ft_memcpy(new, vector->_start, size * vector->_typeSize);
	free(vector->_start);
	vector->_start = new;
	vector->_end = new + size * vector->_typeSize;
	vector->_cap = new + n * vector->_typeSize;
}
t_vector vectorCopy(const t_vector *src)
{
	t_vector new;
	new._typeSize = src->_typeSize;
	new._free = src->_free;
	size_t size = vectorSize(src);
	vectorReserve(&new, size);
	ft_memcpy(new._start, src->_start, size * src->_typeSize);
	return (new);
}
vectorIterator vectorNext(const t_vector *vector, vectorIterator it)
{
	return (it + vector->_typeSize);
}
t_vector vectorCopyDeep(const t_vector *src, void *(*_copy)(void *))
{
	t_vector new;
	new._typeSize = src->_typeSize;
	new._free = src->_free;
	size_t size = vectorSize(src);
	vectorReserve(&new, size);
	for (vectorIterator it = vectorBegin(src); vectorIsEnd(src, it) != 0; it = vectorNext(src, it))
	{
		void *data = _copy(it);
		vectorPushBack(&new, data);
		free(data);
	}
	return (new);
}
size_t vectorSize(const t_vector *vector)
{
	return ((vector->_end - vector->_start) / vector->_typeSize);
}

size_t vectorCapacity(const t_vector *vector)
{
	return ((vector->_cap - vector->_start) / vector->_typeSize);
}

void vectorClear(t_vector *vector)
{
	if (vector->_free != NULL)
	{
		for (vectorIterator it = vectorBegin(vector); !vectorIsEnd(vector, it); it = vectorNext(vector, it))
			vector->_free(it);
	}
	vector->_end = vector->_start;
}
void vectorFree(t_vector *vector)
{
	if (vector == NULL)
		return;
	vectorClear(vector);
	free(vector->_start);
	vector->_start = vector->_end = vector->_cap = NULL;
}
void vectorPushBack(t_vector *vector, const void *data)
{
	size_t size = vectorSize(vector);
	size_t cap = vectorCapacity(vector);
	if (cap == 0)
		vectorReserve(vector, 1);
	else if (size == cap)
		vectorReserve(vector, cap * 2);
	ft_memcpy(vector->_end, data, vector->_typeSize);
	vector->_end += vector->_typeSize;
}

void vectorPushFront(t_vector *vector, const void *data)
{
	size_t size = vectorSize(vector);
	size_t cap = vectorCapacity(vector);
	if (cap == 0)
		vectorReserve(vector, 1);
	else if (size == cap)
		vectorReserve(vector, cap * 2);
	ft_memmove(vector->_start + vector->_typeSize, vector->_start, size * vector->_typeSize);
	ft_memcpy(vector->_start, data, vector->_typeSize);
	vector->_end += vector->_typeSize;
}

void vectorPopBack(t_vector *vector)
{
	if (vectorSize(vector) == 0)
		return;
	vector->_end -= vector->_typeSize;
	if (vector->_free != NULL)
		vector->_free(vector->_end);
}

void vectorPopFront(t_vector *vector)
{
	if (vectorSize(vector) == 0)
		return;
	if (vector->_free != NULL)
		vector->_free(vector->_start);
	ft_memmove(vector->_start, vector->_start + vector->_typeSize, vectorSize(vector) * vector->_typeSize);
	vector->_end -= vector->_typeSize;
}

void vectorInsert(t_vector *vector, size_t index, const void *data)
{
	size_t size = vectorSize(vector);
	size_t cap = vectorCapacity(vector);
	if (cap == 0)
		vectorReserve(vector, 1);
	else if (size == cap)
		vectorReserve(vector, cap * 2);
	ft_memmove(vector->_start + (index + 1) * vector->_typeSize, vector->_start + index * vector->_typeSize, (size - index) * vector->_typeSize);
	ft_memcpy(vector->_start + index * vector->_typeSize, data, vector->_typeSize);
	vector->_end += vector->_typeSize;
}

void vectorInsertIt(t_vector *vector, vectorIterator it, const void *data)
{
	size_t size = vectorSize(vector);
	size_t cap = vectorCapacity(vector);
	size_t index = (it - vector->_start) / vector->_typeSize;
	if (cap == 0)
		vectorReserve(vector, 1);
	else if (size == cap)
		vectorReserve(vector, cap * 2);
	ft_memmove(vector->_start + (index + 1) * vector->_typeSize, vector->_start + index * vector->_typeSize, (size - index) * vector->_typeSize);
	ft_memcpy(vector->_start + index * vector->_typeSize, data, vector->_typeSize);
	vector->_end += vector->_typeSize;
}

void vectorErase(t_vector *vector, size_t index)
{
	size_t size = vectorSize(vector);
	if (vector->_free != NULL)
		vector->_free(vector->_start + index * vector->_typeSize);
	ft_memmove(vector->_start + index * vector->_typeSize, vector->_start + (index + 1) * vector->_typeSize, (size - index - 1) * vector->_typeSize);
	vector->_end -= vector->_typeSize;
}

void vectorEraseIt(t_vector *vector, vectorIterator it)
{
	size_t size = vectorSize(vector);
	size_t index = (it - vector->_start) / vector->_typeSize;
	if (vector->_free != NULL)
		vector->_free(vector->_start + index * vector->_typeSize);
	ft_memmove(vector->_start + index * vector->_typeSize, vector->_start + (index + 1) * vector->_typeSize, (size - index - 1) * vector->_typeSize);
	vector->_end -= vector->_typeSize;
}

void vectorEraseRange(t_vector *vector, size_t first, size_t last)
{
	size_t size = vectorSize(vector);
	if (vector->_free != NULL)
	{
		for (size_t i = first; i < last; i++)
			vector->_free(vector->_start + i * vector->_typeSize);
	}
	ft_memmove(vector->_start + first * vector->_typeSize, vector->_start + last * vector->_typeSize, (size - last) * vector->_typeSize);
	vector->_end -= (last - first) * vector->_typeSize;
}

void vectorEraseRangeIt(t_vector *vector, vectorIterator first, vectorIterator last)
{
	size_t size = vectorSize(vector);
	size_t firstIndex = (first - vector->_start) / vector->_typeSize;
	size_t lastIndex = (last - vector->_start) / vector->_typeSize;
	if (vector->_free != NULL)
	{
		for (size_t i = firstIndex; i < lastIndex; i++)
			vector->_free(vector->_start + i * vector->_typeSize);
	}
	ft_memmove(vector->_start + firstIndex * vector->_typeSize, vector->_start + lastIndex * vector->_typeSize, (size - lastIndex) * vector->_typeSize);
	vector->_end -= (lastIndex - firstIndex) * vector->_typeSize;
}

vectorIterator vectorBegin(const t_vector *vector)
{
	return (vector->_start);
}

vectorIterator vectorEnd(const t_vector *vector)
{
	return (vector->_end);
}

int vectorIsEnd(const t_vector *vector, vectorIterator it)
{
	return (it == vector->_end);
}

vectorIterator vectorFind(const t_vector *vector, const void *data, int (*cmp)(const void *, const void *))
{
	size_t size = vectorSize(vector);
	for (size_t i = 0; i < size; i++)
	{
		if (cmp(vector->_start + i * vector->_typeSize, data) == 0)
			return (vector->_start + i * vector->_typeSize);
	}
	return (vector->_end);
}

vectorIterator vectorAt(const t_vector *vector, size_t index)
{
	size_t size = vectorSize(vector);
	if (index >= size)
		return (vector->_end);
	return (vector->_start + index * vector->_typeSize);
}