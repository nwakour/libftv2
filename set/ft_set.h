#ifndef __SET_H__
#define __SET_H__

#include "redBlackTree.h"

typedef struct s_set
{
	t_redBlackTree tree;
}t_set;
typedef nodePtr setIterator;

t_set setInit(size_t typeSize, int (*_cmp)(void*, void*), void (*_free)(void*));
void setInsert(t_set* set, void* val);
void setErase(t_set* set, void* val);
void setEraseIt(t_set* set, setIterator it);
void setClear(t_set* set);
void setFree(t_set* set);
size_t setSize(t_set* set);
void *setFind(t_set* set, void* val);
setIterator setBegin(t_set* set);
setIterator setEnd(t_set* set);
setIterator setNext(t_set* set, setIterator it);
setIterator setPrev(t_set* set, setIterator it);
#endif