#include "Queue.h"

#include <string>

using std::string;

template<typename T>
queue<T>::queue()
{
}

template<typename T>
queue<T>::~queue()
{
}

template<typename T>
queue<T>::queue(initializer_list<T> il)
{

}

template class queue<int>;
template class queue<string>;