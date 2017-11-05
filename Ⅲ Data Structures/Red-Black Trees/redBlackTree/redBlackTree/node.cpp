#include "node.h"



template<typename T>
inline node<T>::node(iro _color, T _key)
	: color_(_color), key_(_key)
{
}


template class node<int>;
template class node<string>;