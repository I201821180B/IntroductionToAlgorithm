#include "Stack.h"

template<typename T>
inline stack<T>::stack()
	: size(0), top(0)
{
}

template<typename T>
stack<T>::stack(initializer_list<T> il)
{
	for (const auto& item : il)
	{
		node<T>* newnode = node<T>(item);
		s.insert(newnode);
	}
}

template<typename T>
stack<T>::~stack()
{
	
}

template<typename T>
bool stack<T>::stackEmpty()
{
	return false;
}

template<typename T>
bool stack<T>::push()
{
	return false;
}

template<typename T>
T stack<T>::pop()
{
	return T();
}

template class stack<int>;
template class stack<string>;