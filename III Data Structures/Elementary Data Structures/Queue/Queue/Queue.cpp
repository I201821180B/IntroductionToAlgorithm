#include "Queue.h"

#include <string>

using std::string;

template<typename T>
queue<T>::queue()
    : q() 
{
}

template<typename T>
queue<T>::queue(initializer_list<T> il)
    : q(il)
{
}

//template<typename T>
//queue<T>::~queue()
//{
//}

template<typename T>
bool queue<T>::isEmpty()
{
    return !(q.size());
}

template<typename T>
void queue<T>::enqueue(T x)
{
    q.insert(x);
}

template<typename T>
T queue<T>::dequeue()
{
    node<T>* t = q.locate(q.size() - 1);
    T res = t->data;
    q.removeNode(t);
    return res;
}

template<typename T>
uint32_t queue<T>::size()
{
    return q.size();
}

template<typename T>
void queue<T>::print()
{
    q.print();
}


template class queue<int>;
template class queue<string>;