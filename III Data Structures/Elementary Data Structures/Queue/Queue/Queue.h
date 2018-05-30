#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "LinkedList.h"

#include <initializer_list>
#include <cstdint>

using std::initializer_list;
using std::int32_t;

template<typename T>
class queue
{
public:
    queue();
    queue(initializer_list<T> il);
    //~queue();
    bool isEmpty();
    void enqueue(T x);
    T dequeue();
    uint32_t size();
    void print();
private:
    linkedList<T> q;
    //int32_t size;
};

#endif