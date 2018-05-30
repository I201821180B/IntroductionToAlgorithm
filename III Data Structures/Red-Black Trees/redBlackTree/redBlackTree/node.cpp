#include "node.h"


template<typename T>
node<T>::node()
    : left_(nullptr), right_(nullptr), parent_(nullptr)
{
} 

template<typename T>
node<T>::node(COLOR color)
    : node()/*, color_(color)*/
{
    color_ = color;
}

template<typename T>
node<T>::node(T key)
    : node()/*, key_(key)*/
{
    key_ = key;
    //color_ = RED;
    std::cout << "node constructor" << std::endl;
}

//template<typename T>
//node<T>::~node()
//{
//	if (std::is_pointer<T>::value)
//	{
//		delete key_;
//	}
//}

/*不能调用委托构造函数之后，再初始化别的变量*/
template<typename T>
node<T>::node(COLOR color, T key)
    : node()/*, color_(color), key_(key)*/
{
    color_ = color;
    key_ = key;
}


template<typename T>
void node<T>::setColor(COLOR color)
{
    this->color_ = color;
}

template<typename T>
void node<T>::setKey(T key)
{
    this->key_ = key;
}

template<typename T>
void node<T>::setLeft(pNode newleft)
{
    this->left_ = newleft;
}

template<typename T>
void node<T>::setRight(pNode newright)
{
    this->right_ = newright;
}

template<typename T>
void node<T>::setParent(pNode newparent)
{
    this->parent_ = newparent;
}


template class node<int>;
template class node<std::string>;
template class node<std::shared_ptr<std::string>>;