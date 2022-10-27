#include "redBlackTree.h"

nodePtr nodeInit(void *val, nodePtr parent, size_t typeSize,nodePtr Nnull)
{
	nodePtr node = ft_calloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->_val = ft_calloc(typeSize);
	if (!node->_val)
	{
		free(node);
		return (NULL);
	}
	ft_memcpy(node->_val, val, typeSize);
	node->_parent = parent;
	node->_left = node->_right = Nnull;
	node->_color = RED;
	return (node);
}

nodePtr nodeIncrement(nodePtr x, nodePtr Nnull)
{
	if (x == Nnull)
		return (Nnull->_right);
	if (x->_right != Nnull)
	{
		x = x->_right;
		while (x->_left != Nnull)
			x = x->_left;
	}
	else
	{
		nodePtr y = x->_parent;
		while (x == y->_right)
		{
			x = y;
			y = y->_parent;
		}
		if (x->_right != y)
			x = y;
	}
	return x;
}

nodePtr nodeDecrement(nodePtr x, nodePtr Nnull)
{
	if (x == Nnull)
		return (Nnull->_right);
	if (x->_color == RED && x->_parent->_parent == x)
		x = x->_right;
	else if (x->_left != Nnull)
	{
		nodePtr y = x->_left;
		while (y->_right != Nnull)
			y = y->_right;
		x = y;
	}
	else
	{
		nodePtr y = x->_parent;
		while (x == y->_left)
		{
			x = y;
			y = y->_parent;
		}
		x = y;
	}
	return x;
}

nodePtr nodeMax(nodePtr node, nodePtr Nnull)
{
	if (node == Nnull)
		return (Nnull);
	while (node->_right != Nnull)
		node = node->_right;
	return node;
}

nodePtr nodeMin(nodePtr node, nodePtr Nnull)
{
	if(node == Nnull)
		return Nnull;
	while (node->_left != Nnull)
		node = node->_left;
	return node;
}

t_redBlackTree rbInit(size_t typeSize, int (*_cmp)(void*, void*), void (*_free)(void*))
{
	t_redBlackTree tree;
	tree._Nnull = ft_calloc(sizeof(t_node));
	tree._Nnull->_left  = tree._Nnull->_parent = tree._Nnull->_val = NULL;
	tree._Nnull->_right = tree._Nnull;
	tree._Nnull->_color = BLACK;
	tree._root = tree._Nnull;
	tree._size = 0;
	tree._typeSize = typeSize;
	tree._free = _free;
	tree._cmp = _cmp;
	return tree;
}
void rbClearhelper(t_redBlackTree *tree, nodePtr node)
{
	if (node == tree->_Nnull)
		return;
	rbClearhelper(tree, node->_left);
	rbClearhelper(tree, node->_right);
	if (tree->_free)
		tree->_free(node->_val);
	else
		free(node->_val);
	node->_left =  node->_parent = node->_right = node->_val = NULL;
	free(node);
	--tree->_size;

}
void rbClear(t_redBlackTree *tree)
{
	rbClearhelper(tree, tree->_root);
	tree->_root = tree->_Nnull;
}

void rbFree(t_redBlackTree *tree)
{
	rbClear(tree);
	free(tree->_Nnull);
	tree->_Nnull = NULL;
}
void rbRightRotate(t_redBlackTree *tree, nodePtr x)
{
	nodePtr y = x->_left;
	x->_left = y->_right;
	if (y->_right != tree->_Nnull)
		y->_right->_parent = x;
	y->_parent = x->_parent;
	if (x->_parent == tree->_Nnull)
		tree->_root = y;
	else if (x == x->_parent->_right)
		x->_parent->_right = y;
	else
		x->_parent->_left = y;
	y->_right = x;
	x->_parent = y;
}

void rbLeftRotate(t_redBlackTree *tree, nodePtr x)
{
	nodePtr y = x->_right;
	x->_right = y->_left;
	if (y->_left != tree->_Nnull)
		y->_left->_parent = x;
	y->_parent = x->_parent;
	if (x->_parent == tree->_Nnull)
		tree->_root = y;
	else if (x == x->_parent->_left)
		x->_parent->_left = y;
	else
		x->_parent->_right = y;
	y->_left = x;
	x->_parent = y;
}

void rbTransplant(t_redBlackTree *tree, nodePtr x, nodePtr y)
{
	if (x == tree->_root)
		tree->_root = y;
	else if(x == x->_parent->_left)
		x->_parent->_left = y;
	else
		x->_parent->_right = y;
	y->_parent = x->_parent;
}

nodePtr rbFind(t_redBlackTree *tree, void *val)
{
	nodePtr x = tree->_root;
	while (x != tree->_Nnull)
	{
		if (tree->_cmp(val, x->_val))
			x = x->_left;
		else if (tree->_cmp(x->_val, val))
			x = x->_right;
		else
			return (x);
	}
	return (tree->_Nnull);
}

void rbInsertFix(t_redBlackTree *tree, nodePtr newnode)
{
	while (newnode->_parent != tree->_Nnull && newnode->_parent->_color == RED)
	{
		nodePtr x = tree->_Nnull;
		if (newnode->_parent == newnode->_parent->_parent->_right)
		{
			x = newnode->_parent->_parent->_left;
			if (x->_color == RED)
			{
				x->_color = BLACK;
				newnode->_parent->_color = BLACK;
				newnode->_parent->_parent->_color = RED;
				newnode = newnode->_parent->_parent;
			}
			else
			{
				if(newnode == newnode->_parent->_left)
				{
					newnode = newnode->_parent;
					rbRightRotate(tree, newnode);
				}
				newnode->_parent->_color = BLACK;
				newnode->_parent->_parent->_color = RED;
				rbLeftRotate(tree, newnode->_parent->_parent);
			}
		}
		else
		{
			x = newnode->_parent->_parent->_right;
			if(x->_color == RED)
			{
				x->_color = BLACK;
				newnode->_parent->_color = BLACK;
				newnode->_parent->_parent->_color = RED;
				newnode = newnode->_parent->_parent;
			}
			else
			{
				if(newnode == newnode->_parent->_right)
				{
					newnode = newnode->_parent;
					rbLeftRotate(tree, newnode);
				}
				newnode->_parent->_color = BLACK;
				newnode->_parent->_parent->_color = RED;
				rbRightRotate(tree, newnode->_parent->_parent);
			}
		}
	}
	tree->_root->_color = BLACK;
}

void rbInsert(t_redBlackTree *tree, void *val)
{
	nodePtr x = tree->_root;
	nodePtr y = tree->_Nnull;
	
	while (x != tree->_Nnull)
	{
		y = x;
		if (tree->_cmp(val, x->_val))
			x = x->_left;
		else if (tree->_cmp(x->_val, val))
			x = x->_right;
		else
			return;
	}
	nodePtr newnode = nodeInit(val,y, tree->_typeSize, tree->_Nnull);
	if (y == tree->_Nnull)
		tree->_root = newnode;
	else if (tree->_cmp(newnode->_val, y->_val))
		y->_left = newnode;
	else
		y->_right = newnode;
	++tree->_size;
	if (newnode->_parent == tree->_Nnull)
		newnode->_color = BLACK;
	else if(newnode->_parent->_parent == tree->_Nnull)
		;
	else
		rbInsertFix(tree, newnode);
	if (tree->_Nnull->_right == tree->_Nnull)
		tree->_Nnull->_right = nodeMax(tree->_root ,tree->_Nnull);
	else
		tree->_Nnull->_right = nodeMax(tree->_Nnull->_right ,tree->_Nnull);
	
}

void rbDeleteFix(t_redBlackTree *tree, nodePtr x)
{
	while (x != tree->_root && x->_color == BLACK)
	{
		if (x == x->_parent->_left)
		{
			nodePtr w = x->_parent->_right;
			if (w->_color == RED)
			{
				w->_color = BLACK;
				x->_parent->_color = RED;
				rbLeftRotate(tree, x->_parent);
				w = x->_parent->_right;
			}
			if (w->_left->_color == BLACK && w->_right->_color == BLACK)
			{
				w->_color = RED;
				x = x->_parent;
			}
			else
			{
				if (w->_right->_color == BLACK)
				{
					w->_left->_color = BLACK;
					w->_color = RED;
					rbRightRotate(tree, w);
					w = x->_parent->_right;
				}
				w->_color = x->_parent->_color;
				x->_parent->_color = BLACK;
				w->_right->_color = BLACK;
				rbLeftRotate(tree, x->_parent);
				x = tree->_root;
			}
		}
		else
		{
			nodePtr w = x->_parent->_left;
			if (w->_color == RED)
			{
				w->_color = BLACK;
				x->_parent->_color = RED;
				rbRightRotate(tree, x->_parent);
				w = x->_parent->_left;
			}
			if (w->_left->_color == BLACK && w->_right->_color == BLACK)
			{
				w->_color = RED;
				x = x->_parent;
			}
			else
			{
				if (w->_left->_color == BLACK)
				{
					w->_right->_color = BLACK;
					w->_color = RED;
					rbLeftRotate(tree, w);
					w = x->_parent->_left;
				}
				w->_color = x->_parent->_color;
				x->_parent->_color = BLACK;
				w->_left->_color = BLACK;
				rbRightRotate(tree, x->_parent);
				x = tree->_root;
			}
		}
	}
	x->_color = BLACK;;
}

void rbDelete(t_redBlackTree *tree, nodePtr del)
{
	nodePtr x;
	nodePtr y = del;
	int color = del->_color;
	if (del == tree->_Nnull->_right)
	{
		if (tree->_size == 1)
			tree->_Nnull->_right = tree->_Nnull;
		else 
			tree->_Nnull->_right = nodeDecrement(del, tree->_Nnull);
	}
	if (del->_left == tree->_Nnull)
	{
		x = del->_right;
		rbTransplant(tree, del, del->_right);
	}
	else if (del->_right == tree->_Nnull)
	{
		x = del->_left;
		rbTransplant(tree, del, del->_left);
	}
	else
	{
		y = nodeMin(del->_right, tree->_Nnull);
		color = y->_color;
		x = y->_right;
		if (y->_parent == del)
			x->_parent = y;
		else
		{
			rbTransplant(tree, y, y->_right);
			y->_right = del->_right;
			y->_right->_parent = y;
		}
		rbTransplant(tree, del, y);
		y->_left = del->_left;
		y->_left->_parent = y;
		y->_color = del->_color;
	}
	if (tree->_free)
		tree->_free(del->_val);
	else
		free(del->_val);
	free(del);
	--tree->_size;
	if (color == BLACK)
		rbDeleteFix(tree, x);
	tree->_Nnull->_parent = tree->_Nnull->_left = tree->_Nnull;
}

void rbDeleteVal(t_redBlackTree *tree, void *val)
{
	nodePtr del = rbFind(tree, val);
	if (del == tree->_Nnull)
		return;
	rbDelete(tree, del);
}