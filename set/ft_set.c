#include "ft_set.h"

t_set setInit(size_t typeSize, int (*_cmp)(void*, void*), void (*_free)(void*))
{
	t_set set;
	set.tree = rbInit(typeSize,_cmp, _free);
	return set;
}

void setInsert(t_set* set, void* val)
{
	rbInsert(&set->tree, val);
}

void setErase(t_set* set, void* val)
{
	rbDeleteVal(&set->tree, val);
}
void setEraseIt(t_set* set, setIterator it)
{
	rbDelete(&set->tree, it);
}
void setClear(t_set* set)
{
	rbClear(&set->tree);
}
void setFree(t_set* set)
{
	rbFree(&set->tree);
}
size_t setSize(t_set* set)
{
	return set->tree._size;
}
void *setFind(t_set* set, void* val)
{
	nodePtr node = rbFind(&set->tree, val);
	if (node == set->tree._Nnull)
		return NULL;
	return node->_val;
}

setIterator setBegin(t_set* set)
{
	return nodeMin(set->tree._root, set->tree._Nnull);
}

setIterator setEnd(t_set* set)
{
	return set->tree._Nnull;
}

setIterator setNext(t_set* set, setIterator it)
{
	return nodeIncrement(it, set->tree._Nnull);
}

setIterator setPrev(t_set* set, setIterator it)
{
	return nodeDecrement(it, set->tree._Nnull);
}