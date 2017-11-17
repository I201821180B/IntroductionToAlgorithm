#include "rbTree.h"


template<typename T>
rbTree<T>::rbTree()
{
	nil_ = new node<T>(BLACK);
	nil_->setParent(nil_);
	nil_->setLeft(nil_);
	nil_->setRight(nil_);
	root_ = nil_;
	//root_ = nil_;
	/*root_ = new node<T>(BLACK);
	root_->setParent(nil_);
	root_->setLeft(nil_);
	root_->setRight(nil_);*/
}

template<typename T>
rbTree<T>::rbTree(std::initializer_list<T> _il)
	: rbTree()
{
	for (const T& item : _il)
	{
		//pNode newNode = new node<T>(item);//, nil_
		//rbInsert(newNode);
		insert(item);
	}
}

template<typename T>
rbTree<T>::rbTree(std::vector<T>& _v)
	: rbTree()
{
	for (const T& item : _v)
	{
		//pNode newNode = new node<T>(item);//, nil_
		//rbInsert(newNode);
		insert(item);
	}
}

template<typename T>
rbTree<T>::~rbTree()
{
	rbFree(root_);
	delete nil_;
}

template<typename T>
void rbTree<T>::preOrderTreeWalk(pNode _x)
{
	/*前序遍历*/
	if (_x != nil_)
	{
		std::cout << _x->key() << " ";
		preOrderTreeWalk(_x->left());
		preOrderTreeWalk(_x->right());
	}
}

template<typename T>
void rbTree<T>::inOrderTreeWalk(pNode _x)
{
	/*中序遍历*/
	if (_x != nil_)
	{
		inOrderTreeWalk(_x->left());
		std::cout << _x->key() << " ";
		inOrderTreeWalk(_x->right());
	}
}

template<typename T>
void rbTree<T>::postOrderTreeWalk(pNode _x)
{
	/*后序遍历*/
	if (_x != nil_)
	{
		postOrderTreeWalk(_x->left());
		postOrderTreeWalk(_x->right());
		std::cout << _x->key() << " ";
	}
}

template<typename T>
void rbTree<T>::print()
{
	inOrderTreeWalk(root_);
	std::cout << std::endl;
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::treeSearch(pNode _x, T _key)
{
	/*查找，用递归*/
	if (_x == nil_ || _key == _x->key())
	{
		return _x;
	}
	if (_key < _x->key())
	{
		return treeSearch(_x->left(), _key);
	}
	else
	{
		return treeSearch(_x->right(), _key);
	}
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::iterativeTreeSearch(pNode _x, T _key)
{
	/*查找，用循环代替递归，效率高*/
	while (_x != nil_ && _key != _x->key())
	{
		if (_key < _x->key())
		{
			_x = _x->left();
		}
		else
		{
			_x = _x->right();
		}
	}
	return _x;
}

template<typename T>
T rbTree<T>::search(T _key)
{
	pNode res = iterativeTreeSearch(root_, _key);
	return res->key();
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::treeMinimum(pNode _x)
{
	/*遍历到最左边的一个点*/
	while (_x->left() != nil_)
	{
		_x = _x->left();
	}
	return _x;
}

template<typename T>
T rbTree<T>::min()
{
	pNode res = treeMinimum(root_);
	return res->key();
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::treeMaximum(pNode _x)
{
	/*遍历到最右边的一个点*/
	while (_x->right() != nil_)
	{
		_x = _x->right();
	}
	return _x;
}

template<typename T>
T rbTree<T>::max()
{
	pNode res = treeMaximum(root_);
	return res->key();
}

template<typename T>
T rbTree<T>::successor(T _key)
{
	pNode res = iterativeTreeSearch(root_, _key);
	pNode suc = rbSuccessor(res);
	return suc->key();
}

template<typename T>
T rbTree<T>::preSuccessor(T _key)
{
	pNode res = iterativeTreeSearch(root_, _key);
	pNode preSuc = rbPreSuccessor(res);
	return preSuc->key();
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::rbSuccessor(pNode _x)
{
	/*当前节点有右子节点，沿着右边找后继*/
	if (_x->right() != nil_)
	{
		return treeMinimum(_x->right());
	}
	/*当前节点没有右子节点，沿着父节点的右边向上找后继*/
	pNode y = _x->parent();
	while (y != nil_ && _x == y->right())
	{
		_x = y;
		y = y->parent();
	}
	return y;
}

template<typename T>
typename rbTree<T>::pNode rbTree<T>::rbPreSuccessor(pNode _x)
{
	/*当前节点有左子节点，沿着左边找前驱*/
	if (_x->left() != nil_)
	{
		return treeMaximum(_x->left());
	}
	pNode y = _x->parent();
	while (y != nil_ && _x == y->left())
	{
		_x = y;
		y = y->parent();
	}
	return y;
}

template<typename T>
void rbTree<T>::rbInsert(pNode _z)
{
	pNode y = nil_;
	pNode x = root_;
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
	_z->setParent(y);
	// if no data in rbTree
	if (y == nil_)
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
	//_z->setParent(y);
	_z->setLeft(nil_);
	_z->setRight(nil_);
	_z->setColor(RED);
	rbInsertFixup(_z);
}

template<typename T>
void rbTree<T>::insert(T _key)
{
	pNode newNode = new node<T>(_key);
	rbInsert(newNode);
}

template<typename T>
void rbTree<T>::rbDelete(pNode _z)
{
	pNode y = _z;
	pNode x = nil_;
	COLOR yOriginColor = y->color();
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
			y->setRight(_z->right());
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
	delete _z;
}

template<typename T>
void rbTree<T>::remove(T _key)
{
	pNode res = iterativeTreeSearch(root_, _key);
	rbDelete(res);
}

template<typename T>
void rbTree<T>::leftRotate(pNode _x)
{
	/*set right node of _x*/
	pNode y = _x->right();
	_x->setRight(y->left());

	/*set parent of y's left node*/
	if (y->left() != nil_)
	{
		y->left()->setParent(_x);
	}

	/*set parent node of y*/
	y->setParent(_x->parent());

	/*set _x's parent left or right node*/
	if (_x->parent() == nil_)
	{
		root_ = y;
	}
	else if (_x == _x->parent()->left())
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
	pNode x = _y->left();
	_y->setLeft(x->right());

	/*set parent node of x's right node */
	if (x->right() != nil_)
	{
		x->right()->setParent(_y);
	}

	/*set parent node of x*/
	x->setParent(_y->parent());

	/*set _y's parent left or right node*/
	if (_y->parent() == nil_)
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
			else
			{
				/*case 2：_z和父节点都是红色，叔节点是黑色，_z为右孩子*/
				if (_z == _z->parent()->right())
				{
					_z = _z->parent();
					leftRotate(_z);
				}
				/*case 3：_z和父节点都是红色，叔节点是黑色，_z为左孩子*/
				_z->parent()->setColor(BLACK);
				_z->parent()->parent()->setColor(RED);
				rightRotate(_z->parent()->parent());//
			}
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
			
			else 
			{
				/*case 2*/
				if (_z == _z->parent()->left())
				{
					_z = _z->parent();
					rightRotate(_z);
				}
				/*case 3*/
				_z->parent()->setColor(BLACK);
				_z->parent()->parent()->setColor(RED);
				leftRotate(_z->parent()->parent());//
			}
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
			w->right()->setColor(BLACK);
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
			w->left()->setColor(BLACK);
			rightRotate(_x->parent());
			_x = root_;
		}
	}
	_x->setColor(BLACK);
}

template<typename T>
void rbTree<T>::rbFree(pNode _x)
{
	if (_x != nil_)
	{
		rbFree(_x->left());
		rbFree(_x->right());
		delete _x;
		_x = nullptr;
		return;
	}
}


template class rbTree<int>;
template class rbTree<std::string>;