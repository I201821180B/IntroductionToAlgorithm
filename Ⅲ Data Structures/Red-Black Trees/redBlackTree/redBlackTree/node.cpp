#include "node.h"


template<typename T>
node<T>::node()
	: left_(nullptr), right_(nullptr), parent_(nullptr)
{
} 

template<typename T>
node<T>::node(COLOR _color)
	: node()/*, color_(_color)*/
{
	color_ = _color;
}

template<typename T>
node<T>::node(T _key)
	: node()/*, key_(_key)*/
{
	key_ = _key;
	//color_ = RED;
	std::cout << "node constructor" << std::endl;
}

/*不能调用委托构造函数之后，再初始化别的变量*/
template<typename T>
node<T>::node(COLOR _color, T _key)
	: node()/*, color_(_color), key_(_key)*/
{
	color_ = _color;
	key_ = _key;
}

template<typename T>
void node<T>::setColor(COLOR _color)
{
	this->color_ = _color;
}

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