/**
 * 1. 所有指针为空或不为空的判断，全部写成if(!p)或if(p)的形式，不和nullptr做比较
 * 2. nullptr是为了完美转发和重载匹配用的
 */

#include "binaryTree.h"


template<typename T>
binaryTree<T>::binaryTree()
{
	root_ = nullptr;
}

template<typename T>
binaryTree<T>::binaryTree(std::initializer_list<T> il)
	: binaryTree()
{
	for (const T& item : il)
	{
		pNode newNode = new node<T>(item);
		treeInsert(newNode);
	}
}

template<typename T>
binaryTree<T>::binaryTree(std::vector<T>& v)
	: binaryTree()
{
	for (const T& item : v)
	{
		//std::cout << item << std::endl;
		pNode newNode = new node<T>(item);
		treeInsert(newNode);
	}
}

template<typename T>
binaryTree<T>::~binaryTree()
{
	treeFree(root_);
	//_CrtDumpMemoryLeaks();
}

template<typename T>
void binaryTree<T>::inorderTreeWalk(pNode _x)
{
	/*中序遍历*/
	if (_x)
	{
		inorderTreeWalk(_x->left());
		std::cout << _x->key() << " ";
		inorderTreeWalk(_x->right());
	}
}

template<typename T>
void binaryTree<T>::print()
{
	inorderTreeWalk(root_);
	std::cout << std::endl;
}

/**
 * 1. 类模板的成员函数的返回值是类型别名时，需要使用typename class<T>::alias这种形式
 * 2. 涉及到一个在 template（模板）中的 nested dependent type name（嵌套依赖类型名）
 *    的任何时候，你必须把单词 typename 放在紧挨着它的前面
 * 3. 这样才能告诉编译器把它当作一个类型来处理，否则会被当成是别的标识符
 */
template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeSearch(pNode _x, T _key)
{
	/*查找，用递归*/
	if (!_x || _key == _x->key())
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
typename binaryTree<T>::pNode binaryTree<T>::iterativeTreeSearch(pNode _x, T _key)
{
	/*查找，用循环代替递归，效率高*/
	while (_x && _key != _x->key())
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
typename binaryTree<T>::pNode binaryTree<T>::search(T _key)
{
	
	return iterativeTreeSearch(root_, _key);
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeMinimum(pNode _x)
{
	/*遍历到最左边的一个点*/
	while (_x->left())
	{
		_x = _x->left();
	}
	return _x;
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::min()
{
	return treeMinimum(root_);
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeMaximum(pNode _x)
{
	/*遍历到最右边的一个点*/
	while (_x->right())
	{
		_x = _x->right();
	}
	return _x;
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::max()
{
	return treeMaximum(root_);
}

template<typename T>
typename binaryTree<T>::pNode binaryTree<T>::treeSuccessor(pNode _x)
{
	/*当前节点有右子节点，沿着右边找后继*/
	if (_x->right())
	{
		return treeMinimum(_x->right());
	}
	/*当前节点没有右子节点，沿着父节点的右边向上找后继*/
	pNode y = _x->parent();
	while (y && _x == y->right())
	{
		_x = y;
		y = y->parent();
	}
	return y;
}

template<typename T>
void binaryTree<T>::treeInsert(pNode _z)
{
	pNode y = nullptr;
	pNode x = root_;
	while (x)
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
	if (!y)
	{
		/*树为空*/
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
}

template<typename T>
void binaryTree<T>::transplant(pNode _u, pNode _v)
{
	if (!(_u->parent()))
	{
		root_ = _u;
	}
	else if (_u == _u->parent()->left())
	{
		_u->parent()->setLeft(_v);
	}
	else
	{
		_u->parent()->setRight(_v);
	}
	if (_v != nullptr)
	{
		_v->setParent(_u->parent());
	}
}

template<typename T>
void binaryTree<T>::treeDelete(pNode _z)
{
	if (!(_z->left()))
	{
		transplant(_z, _z->right());
	}
	else if (!(_z->right()))
	{
		transplant(_z, _z->left());
	}
	else
	{
		/*用y换_z*/
		pNode y = treeMinimum(_z);
		if (y->parent() != _z)
		{
			transplant(y, y->right());
			y->setRight(_z->right());
			y->right()->setParent(y);
		}
		transplant(_z, y);
		y->setLeft(_z->left());
		y->left()->setParent(y);
	}
}

template<typename T>
void binaryTree<T>::treeFree(pNode _x)
{
	if (_x)
	{
		treeFree(_x->left());
		treeFree(_x->right());
		delete _x;
		_x = nullptr;
		return;
	}
}

template class binaryTree<int>;
template class binaryTree<std::string>;


