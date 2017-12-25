#ifndef _NODE_H_
#define _NODE_H_

#include "basic.h"

#include <iostream>
#include <string>
#include <type_traits>
#include <memory>

using COLOR = bool;
const COLOR RED = false;
const COLOR BLACK = true;

template<typename T>
class node
{
public:
    using pNode = node<T>*;
    
    node();
    node(COLOR color, T key);
    explicit node(COLOR color);
    explicit node(T key);
    //~node();

    COLOR color() { return color_; }
    void setColor(COLOR color);
    T key() { return key_; }
    void setKey(T key);

    pNode left() { return left_; }
    pNode right() { return right_; }
    pNode parent() { return parent_; }
    void setLeft(pNode newleft);
    void setRight(pNode newright);
    void setParent(pNode newparent);
private:
    COLOR color_;
    T key_;
    pNode left_;
    pNode right_;
    pNode parent_;
    DISABLE_COPY_AND_ASSIGN(node);
};


#endif


