#include "node.h"

#include <string>

using std::string;

template<typename T>
node<T>::node(const T & t) 
	: data(t)
{
}

//template<typename T>
//node<T>::~node()
//{
//	
//}

template struct node<int>;
template struct node<string>;