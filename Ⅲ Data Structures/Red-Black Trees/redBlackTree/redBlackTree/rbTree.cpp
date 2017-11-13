#include "rbTree.h"


template<typename T>
rbTree<T>::rbTree()
{
	nil_ = new node<T>(NIL);
	root_ = nil_;
	/*root_ = new node<T>(BLACK);
	root_->setParent(nil_);
	root_->setLeft(nil_);
	root_->setRight(nil_);*/
}

template<typename T>
rbTree<T>::~rbTree()
{
}

template<typename T>
void rbTree<T>::rbInsert(pNode z)
{
	pNode y = nil_;
	pNode x = root_;
	// go through
	while (x != nil_)
	{
		y = x;
		if (z->key() < x->key())
		{
			x = x->left();
		}
		else
		{
			x = x->right();
		}
	}
	//z->setParent(y);
	// if no data in rbTree
	if (y == nil_))
	{
		root_ = z;
	}
	else if (z->key() < y->key())
	{
		y->setLeft(z);
	}
	else
	{
		y->setRight(z);
	}
	z->setParent(y);
	z->setLeft(nil_);
	z->setRight(nil_);
	z->setColor(RED);
	rbInsertFixup(z);
}

template<typename T>
void rbTree<T>::rbDelete(pNode z)
{
	pNode y = z;
	pNode x = nullptr;
	node<T>::iro yOriginColor = y->color();
	if (z->left() == nil_)
	{
		x = z->right();
		rbTransplant(z, z->right());
	}
	else if (z->right() == nil_)
	{
		x = z->left();
		rbTransplant(z, z->left());
	}
	else
	{
		y = treeMinimum(z->right());
		yOriginColor = y->color();
		x = y->right();
		if (y->parent() == z)
		{
			x->setParent(y);
		}
		else
		{
			rbTransplant(y, y->right());
			y->setRight(z->right);
			y->right()->setParent(y);
		}
		rbTransplant(z, y);
		y->setLeft(z->left());
		y->left()->setParent(y);
		y->setColor(z->color());
	}
	if (yOriginColor == BLACK)
	{
		rbDeleteFixup(x);
	}
}

template<typename T>
void rbTree<T>::leftRotate(pNode x)
{
	/*set right node of x*/
	pNode y(x->right());
	x->setRight(y->left());

	/*set parent of y's left node*/
	if (y->left()->color() != NIL)
	{
		y->left()->setParent(x);
	}

	/*set parent node of y*/
	y->setParent(x->parent());
	
	/*set x's parent left or right node*/
	if (x->parent()->color() == NIL)
	{
		root_ = y;
	}
	else if (x == x->pareant()->left())
	{
		x->parent()->setLeft(y);
	}
	else
	{
		x->parent()->setRight(y);
	}

	y->setLeft(x);
	x->setParent(y);
}

template<typename T>
void rbTree<T>::rightRotate(pNode y)
{
	/*set left node of y*/
	pNode x(y->left());
	y->setLeft(x->right());

	/*set parent node of x's right node */
	if (x->right()->color() != NIL)
	{
		x->right()->setParent(y);
	}

	/*set parent node of x*/
	x->setParent(y->parent());
	
	/*set y's parent left or right node*/
	if (y->parent()->color() == NIL)
	{
		root_ = x;
	}
	else if (y == y->parent()->left())
	{
		y->parent()->setLeft(x);
	}
	else
	{
		y->parent()->setRight(x);
	}

	x->setRight(y);
	y->setParent(x);
}

template<typename T>
void rbTree<T>::rbInsertFixup(pNode z)
{
	while (z->parent()->color() == RED)
	{
		/*如果该节点在一个子树的左枝*/
		if (z->parent() == z->parent()->parent()->left())
		{
			/*取得叔节点*/
			pNode y = z->parent()->parent()->right();
			/*case 1: z和父节点都是红色，叔节点也是红色*/
			if (y->color() == RED)
			{
				z->parent()->setColor(BLACK);
				y->setColor(BLACK);
				z->parent()->parent()->setColor(RED);
				z = z->parent()->parent();
			}
			/*case 2：z和父节点都是红色，叔节点是黑色，z为右孩子*/
			else if (z == z->parent()->right())
			{
				z = z->parent();
				leftRotate(z);
			}
			/*case 3：z和父节点都是红色，叔节点是黑色，z为左孩子*/
			z->parent()->setColor(BLACK);
			z->parent()->parent()->setColor(RED);
			rightRotate(z);
		}
		/*如果该节点在一个子树的右枝*/
		else
		{
			pNode y = z->parent()->parent()->left();
			/*case 1*/
			if (y->color() == RED)
			{
				z->parent()->setColor(BLACK);
				y->setColor(BLACK);
				z->parent()->parent()->setColor(RED);
				z = z->parent()->parent();
			}
			/*case 2*/
			else if (z == z->parent()->left())
			{
				z = z->parent();
				rightRotate(z);
			}
			/*case 3*/
			z->parent()->setColor(BLACK);
			z->parent()->parent()->setColor(RED);
			leftRotate(z);
		}
	}
	root_->setColor(BLACK);
}

template<typename T>
void rbTree<T>::rbTransplant(pNode u, pNode v)
{
	if (u->parent() == nil_)
	{
		root_ = v;
	}
	else if (u == u->parent()->left())
	{
		u->parent()->setLeft(v);
	}
	else
	{
		u->parent()->setRight(v);
	}
	v->setParent(u->parent());
}

template<typename T>
void rbTree<T>::rbDeleteFixup(pNode x)
{
	while (x != root_ && x->color() == BLACK)
	{
		if (x == x->parent()->left())
		{
			pNode w = x->parent()->right();
			if (w->color() == RED)
			{
				w->setColor(BLACK);
				x->parent()->setColor(RED);
				leftRotate(x->parent());
				w = x->parent()->right();
			}
			if (w->left()->color() == BLACK && w->right()->color() == BLACK)
			{
				w->setColor(RED);
				x = x->parent();
			}
			else if (w->right()->color() == BLACK)
			{
				w->left()->setColor(BLACK);
				w->setColor(RED);
				rightRotate(w);
				w = x->parent()->right();
			}
			w->setColor(x->parent()->color());
			x->parent()->setColor(BLACK);
			W->right()->setColor(BLACK);
			leftRotate(x->parent());
			x = root_;
		}
		else
		{
			pNode w = x->parent()->left();
			if (w->color() == RED)
			{
				w->setColor(BLACK);
				x->parent()->setColor(RED);
				rightRotate(x->parent());
				w = x->parent()->left();
			}
			if (w->right()->color() == BLACK && w->left()->color() == BLACK)
			{
				w->setColor(RED);
				x = x->parent();
			}
			else if (w->left()->color() == BLACK)
			{
				w->right()->setColor(BLACK);
				w->setColor(RED);
				leftRotate(w);
				w = x->parent()->left();
			}
			w->setColor(x->parent()->color());
			x->parent()->setColor(BLACK);
			W->left()->setColor(BLACK);
			rightRotate(x->parent());
			x = root_;
		}
	}
	x->setColor(BLACK);
}
