#include "rbTree.h"


template<typename T>
rbTree<T>::rbTree()
{
	nil_ = new node<T>(node<T>::NIL);
	root_ = nil_;
	/*root_ = new node<T>(node<T>::BLACK);
	root_->setParent(nil_);
	root_->setLeft(nil_);
	root_->setRight(nil_);*/
}

template<typename T>
rbTree<T>::~rbTree()
{
}

template<typename T>
void rbTree<T>::rbInsert(node<T>* z)
{
	node<T>* y = nil_;
	node<T>* x = root_;
	// go through
	while (x.get() != nil_.get())
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
	if (y.get() == nil_.get())
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
	z->setColor(node<T>::RED);
	rbInsertFixup(z);
}

template<typename T>
void rbTree<T>::leftRotate(node<T>* x)
{
	/*set right node of x*/
	node<T>* y(x->right());
	x->setRight(y->left());

	/*set parent of y's left node*/
	if (y->left()->color() != node<T>::NIL)
	{
		y->left()->setParent(x);
	}

	/*set parent node of y*/
	y->setParent(x->parent());
	
	/*set x's parent left or right node*/
	if (x->parent()->color() == node<T>::NIL)
	{
		root_ = y;
	}
	else if (x.get() == x->pareant()->left().get())
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
void rbTree<T>::rightRotate(node<T>* y)
{
	/*set left node of y*/
	node<T>* x(y->left());
	y->setLeft(x->right());

	/*set parent node of x's right node */
	if (x->right()->color() != node<T>::NIL)
	{
		x->right()->setParent(y);
	}

	/*set parent node of x*/
	x->setParent(y->parent());
	
	/*set y's parent left or right node*/
	if (y->parent()->color() == node<T>::NIL)
	{
		root_ = x;
	}
	else if (y.get() == y->parent()->left().get())
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
void rbTree<T>::rbInsertFixup(node<T>* z)
{
	while (z->parent()->color() == node<T>::RED)
	{
		/*如果该节点在一个子树的左枝*/
		if (z->parent() == z->parent()->parent()->left())
		{
			/*取得叔节点*/
			node<T>* y = z->parent()->parent()->right();
			/*case 1: z和父节点都是红色，叔节点也是红色*/
			if (y->color() == node<T>::RED)
			{
				z->parent()->setColor(node<T>::BLACK);
				y->setColor(node<T>::BLACK);
				z->parent()->parent()->setColor(node<T>::RED);
				z = z->parent()->parent();
			}
			/*case 2：z和父节点都是红色，叔节点是黑色，z为右孩子*/
			else if (z == z->parent()->right())
			{
				z = z->parent();
				leftRotate(z);
			}
			/*case 3：旋转之后两边不平衡*/
			z->parent()->setColor(node<T>::BLACK);
			z->parent()->parent()->setColor(node<T>::RED);
			rightRotate(z);
		}
		/*如果该节点在一个子树的右枝*/
		else
		{
			node<T>* y = z->parent()->parent()->left();
			/*case 1*/
			if (y->color() == node<T>::RED)
			{
				z->parent()->setColor(node<T>::BLACK);
				y->setColor(node<T>::BLACK);
				z->parent()->parent()->setColor(node<T>::RED);
				z = z->parent()->parent();
			}
			/*case 2*/
			else if (z == z->parent()->left())
			{
				z = z->parent();
				rightRotate(z);
			}
			/*case 3*/
			z->parent()->setColor(node<T>::BLACK);
			z->parent()->parent()->setColor(node<T>::RED);
			leftRotate(z);
		}
	}
	root_->setColor(node<T>::BLACK);
}
