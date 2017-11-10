#include "rbTree.h"


template<typename T>
rbTree<T>::rbTree()
{
	NIL = make_shared<node<T>>(node<T>::iro::NIL);
}

template<typename T>
rbTree<T>::~rbTree()
{
}

template<typename T>
void rbTree<T>::rbInsert(shared_ptr<node<T>>& z)
{
	
}

template<typename T>
void rbTree<T>::leftRotate(shared_ptr<node<T>>& x)
{
	/*set right node of x*/
	shared_ptr<node<T>> y(x->right());
	x->setRight(y->left());

	/*set parent of y's left node*/
	if (y->left()->color() != node<T>::iro::NIL)
	{
		y->left()->setParent(x);
	}

	/*set parent node of y*/
	y->setParent(x->parent());
	
	/*set x's parent left or right node*/
	if (x->parent()->color() == node<T>::iro::NIL)
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
void rbTree<T>::rightRotate(shared_ptr<node<T>>& y)
{
	/*set left node of y*/
	shared_ptr<node<T>> x(y->left());
	y->setLeft(x->right());

	/*set parent node of x's right node */
	if (x->right()->color() != node<T>::iro::NIL)
	{
		x->right()->setParent(y);
	}

	/*set parent node of x*/
	x->setParent(y->parent());
	
	/*set y's parent left or right node*/
	if (y->parent()->color() == node<T>::iro::NIL)
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
void rbTree<T>::rbInsertFixup(shared_ptr<node<T>>& z)
{
}
