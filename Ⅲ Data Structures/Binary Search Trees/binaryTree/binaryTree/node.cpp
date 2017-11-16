#include "node.h"


//template<typename T>
//node<T>::node(iro _color, T _key)
//	: color_(_color), key_(_key)
//{
//}
//
//template<typename T>
//node<T>::node(iro _color)
//	: color_(_color)
//{
//}

//template<typename T>
//void node<T>::setColor(iro _color)
//{
//	this->color_ = _color;
//}

template<typename T>
node<T>::node(T _key)
	: key_(_key), left_(nullptr), right_(nullptr), parent_(nullptr)
{
	std::cout << "node constructor" << std::endl;
}

//template<typename T>
//node<T>::node(const node<T>& _node)
//{
//	key_ = _node.key();
//	left_ = _node.left();
//	right_ = _node.right();
//	parent_ = _node.parent();
//	std::cout << "node copy constructor" << std::endl;
//
//}

template<typename T>
void node<T>::setKey(T _key)
{
	this->key_ = _key;
}

template<typename T>
void node<T>::setLeft(pNode _newleft)
{
	this->left_ = _newleft;
}

template<typename T>
void node<T>::setRight(pNode _newright)
{
	this->right_ = _newright;
}

template<typename T>
void node<T>::setParent(pNode _newparent)
{
	this->parent_ = _newparent;
}


template class node<int>;
template class node<std::string>;



