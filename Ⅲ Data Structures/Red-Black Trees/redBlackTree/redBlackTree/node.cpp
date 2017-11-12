#include "node.h"



template<typename T>
node<T>::node(iro _color, T _key)
	: color_(_color), key_(_key)
{
}

template<typename T>
node<T>::node(iro _color)
	: color_(_color)
{
}

template<typename T>
void node<T>::setColor(iro _color)
{
	this->color_ = _color;
}

template<typename T>
void node<T>::setKey(T _key)
{
	this->key_ = _key;
}

template<typename T>
void node<T>::setLeft(node<T>* _newleft)
{
	this->left_ = _newleft;
}

template<typename T>
void node<T>::setRight(node<T>* _newright)
{
	this->right_ = _newright;
}

template<typename T>
void node<T>::setParent(node<T>* _newparent)
{
	this->parent_ = _newparent;
}


template class node<int>;
template class node<string>;