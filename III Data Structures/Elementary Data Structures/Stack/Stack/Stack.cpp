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
void stack<T>::push(T x)
{
    return s.insert(x);
}

template<typename T>
T stack<T>::pop()
{
    node<T>* n = s.locate(0);
    T res = n->data;
    s.removeNode(n);
    return res;
}

template<typename T>
uint32_t stack<T>::size()
{
    return s.size();
}

template<typename T>
void stack<T>::print()
{
    s.print();
}

template class stack<int>;
template class stack<string>;