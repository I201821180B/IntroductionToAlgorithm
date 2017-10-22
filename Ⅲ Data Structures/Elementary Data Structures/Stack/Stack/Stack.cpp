#include "Stack.h"

template<typename T>
inline stack<T>::stack()
	: s()
{
}

template<typename T>
stack<T>::stack(initializer_list<T> il)
	: s(il)
{
}

/*
template<typename T>
stack<T>::~stack()
{
	
}
*/

template<typename T>
bool stack<T>::isEmpty()
{
	return !(s.size());
}

template<typename T>
bool stack<T>::push(T x)
{
	return s.insert(x);
}

template<typename T>
T stack<T>::pop()
{
	node<T>* temp = s[s.size()-1];
	T res = temp->data;
	return res;
}

template<typename T>
uint32_t stack<T>::size()
{
	return s.size();
}

template class stack<int>;
template class stack<string>;