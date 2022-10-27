#ifndef __REDBLACKTREE_H__
#define __REDBLACKTREE_H__

#include "../libft/libft.h"
#define RED 0
#define BLACK 1

typedef struct s_node
{
	void *_val;
	struct s_node* _right;
	struct s_node* _left;
	struct s_node* _parent;
	int _color;
}t_node;

typedef t_node* nodePtr;

typedef struct s_redBlackTree
{
	nodePtr _root;
	nodePtr _Nnull;
	size_t _size;
	size_t _typeSize;
	void (*_free)(void*);
	int (*_cmp)(void*, void*);
}t_redBlackTree;

nodePtr nodeInit(void *val, nodePtr parent, size_t typeSize, nodePtr Nnull);
nodePtr nodeIncrement(nodePtr node, nodePtr Nnull);
nodePtr nodeDecrement(nodePtr node, nodePtr Nnull);
nodePtr nodeMax(nodePtr node, nodePtr Nnull);
nodePtr nodeMin(nodePtr node, nodePtr Nnull);

t_redBlackTree rbInit(size_t typeSize,int (*_cmp)(void*, void*), void (*_free)(void*));
void rbInsert(t_redBlackTree *tree, void *val);
void rbDelete(t_redBlackTree *tree, nodePtr del);
void rbDeleteVal(t_redBlackTree *tree, void *val);
void rbClear(t_redBlackTree *tree);
void rbFree(t_redBlackTree *tree);
void rbInsertFix(t_redBlackTree *tree, nodePtr node);
void rbDeleteFix(t_redBlackTree *tree, nodePtr node);
void rbLeftRotate(t_redBlackTree *tree, nodePtr node);
void rbRightRotate(t_redBlackTree *tree, nodePtr node);
void rbTransplant(t_redBlackTree *tree, nodePtr x, nodePtr y);
nodePtr rbFind(t_redBlackTree *tree, void *val);
#endif