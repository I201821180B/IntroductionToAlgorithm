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
void rbTree<T>::rbInsert(pNode _z)
{
	pNode y = nil_;
	pNode x = root_;
	// go through
	while (x != nil_)
	{
		y = x;
		if (_z->key() < x->key())
		{
			x = x->left();
		}
		else
		{
			x = x->right();
		}
	}
	//_z->setParent(y);
	// if no data in rbTree
	if (y == nil_))
	{
		root_ = _z;
	}
	else if (_z->key() < y->key())
	{
		y->setLeft(_z);
	}
	else
	{
		y->setRight(_z);
	}
	_z->setParent(y);
	_z->setLeft(nil_);
	_z->setRight(nil_);
	_z->setColor(RED);
	rbInsertFixup(_z);
}

template<typename T>
void rbTree<T>::rbDelete(pNode _z)
{
	pNode y = _z;
	pNode x = nullptr;
	node<T>::iro yOriginColor = y->color();
	if (_z->left() == nil_)
	{
		x = _z->right();
		rbTransplant(_z, _z->right());
	}
	else if (_z->right() == nil_)
	{
		x = _z->left();
		rbTransplant(_z, _z->left());
	}
	else
	{
		y = treeMinimum(_z->right());
		yOriginColor = y->color();
		x = y->right();
		if (y->parent() == _z)
		{
			x->setParent(y);
		}
		else
		{
			rbTransplant(y, y->right());
			y->setRight(_z->right);
			y->right()->setParent(y);
		}
		rbTransplant(_z, y);
		y->setLeft(_z->left());
		y->left()->setParent(y);
		y->setColor(_z->color());
	}
	if (yOriginColor == BLACK)
	{
		rbDeleteFixup(x);
	}
}

template<typename T>
void rbTree<T>::leftRotate(pNode _x)
{
	/*set right node of _x*/
	pNode y(_x->right());
	_x->setRight(y->left());

	/*set parent of y's left node*/
	if (y->left()->color() != NIL)
	{
		y->left()->setParent(_x);
	}

	/*set parent node of y*/
	y->setParent(_x->parent());
	
	/*set _x's parent left or right node*/
	if (_x->parent()->color() == NIL)
	{
		root_ = y;
	}
	else if (_x == _x->pareant()->left())
	{
		_x->parent()->setLeft(y);
	}
	else
	{
		_x->parent()->setRight(y);
	}

	y->setLeft(_x);
	_x->setParent(y);
}

template<typename T>
void rbTree<T>::rightRotate(pNode _y)
{
	/*set left node of _y*/
	pNode x(_y->left());
	_y->setLeft(x->right());

	/*set parent node of x's right node */
	if (x->right()->color() != NIL)
	{
		x->right()->setParent(_y);
	}

	/*set parent node of x*/
	x->setParent(_y->parent());
	
	/*set _y's parent left or right node*/
	if (_y->parent()->color() == NIL)
	{
		root_ = x;
	}
	else if (_y == _y->parent()->left())
	{
		_y->parent()->setLeft(x);
	}
	else
	{
		_y->parent()->setRight(x);
	}

	x->setRight(_y);
	_y->setParent(x);
}

template<typename T>
void rbTree<T>::rbInsertFixup(pNode _z)
{
	while (_z->parent()->color() == RED)
	{
		/*如果该节点在一个子树的左枝*/
		if (_z->parent() == _z->parent()->parent()->left())
		{
			/*取得叔节点*/
			pNode y = _z->parent()->parent()->right();
			/*case 1: _z和父节点都是红色，叔节点也是红色*/
			if (y->color() == RED)
			{
				_z->parent()->setColor(BLACK);
				y->setColor(BLACK);
				_z->parent()->parent()->setColor(RED);
				_z = _z->parent()->parent();
			}
			/*case 2：_z和父节点都是红色，叔节点是黑色，_z为右孩子*/
			else if (_z == _z->parent()->right())
			{
				_z = _z->parent();
				leftRotate(_z);
			}
			/*case 3：_z和父节点都是红色，叔节点是黑色，_z为左孩子*/
			_z->parent()->setColor(BLACK);
			_z->parent()->parent()->setColor(RED);
			rightRotate(_z);
		}
		/*如果该节点在一个子树的右枝*/
		else
		{
			pNode y = _z->parent()->parent()->left();
			/*case 1*/
			if (y->color() == RED)
			{
				_z->parent()->setColor(BLACK);
				y->setColor(BLACK);
				_z->parent()->parent()->setColor(RED);
				_z = _z->parent()->parent();
			}
			/*case 2*/
			else if (_z == _z->parent()->left())
			{
				_z = _z->parent();
				rightRotate(_z);
			}
			/*case 3*/
			_z->parent()->setColor(BLACK);
			_z->parent()->parent()->setColor(RED);
			leftRotate(_z);
		}
	}
	root_->setColor(BLACK);
}

template<typename T>
void rbTree<T>::rbTransplant(pNode _u, pNode _v)
{
	if (_u->parent() == nil_)
	{
		root_ = _v;
	}
	else if (_u == _u->parent()->left())
	{
		_u->parent()->setLeft(_v);
	}
	else
	{
		_u->parent()->setRight(_v);
	}
	_v->setParent(_u->parent());
}

template<typename T>
void rbTree<T>::rbDeleteFixup(pNode _x)
{
	while (_x != root_ && _x->color() == BLACK)
	{
		if (_x == _x->parent()->left())
		{
			pNode w = _x->parent()->right();
			if (w->color() == RED)
			{
				w->setColor(BLACK);
				_x->parent()->setColor(RED);
				leftRotate(_x->parent());
				w = _x->parent()->right();
			}
			if (w->left()->color() == BLACK && w->right()->color() == BLACK)
			{
				w->setColor(RED);
				_x = _x->parent();
			}
			else if (w->right()->color() == BLACK)
			{
				w->left()->setColor(BLACK);
				w->setColor(RED);
				rightRotate(w);
				w = _x->parent()->right();
			}
			w->setColor(_x->parent()->color());
			_x->parent()->setColor(BLACK);
			W->right()->setColor(BLACK);
			leftRotate(_x->parent());
			_x = root_;
		}
		else
		{
			pNode w = _x->parent()->left();
			if (w->color() == RED)
			{
				w->setColor(BLACK);
				_x->parent()->setColor(RED);
				rightRotate(_x->parent());
				w = _x->parent()->left();
			}
			if (w->right()->color() == BLACK && w->left()->color() == BLACK)
			{
				w->setColor(RED);
				_x = _x->parent();
			}
			else if (w->left()->color() == BLACK)
			{
				w->right()->setColor(BLACK);
				w->setColor(RED);
				leftRotate(w);
				w = _x->parent()->left();
			}
			w->setColor(_x->parent()->color());
			_x->parent()->setColor(BLACK);
			W->left()->setColor(BLACK);
			rightRotate(_x->parent());
			_x = root_;
		}
	}
	_x->setColor(BLACK);
}
