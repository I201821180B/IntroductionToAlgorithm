#include "node.h"


//template<typename T>
//node<T>::node(iro _color, T key)
//	: color_(_color), key_(key)
//{
//}
//
//template<typename T>
//node<T>::node(iro _color)
//	: color_(_color)
//{
//}

//template<typename T>
//void node<T>::setColor(iro _color)
//{
//	this->color_ = _color;
//}

template<typename T>
node<T>::node(T key)
    : key_(key), left_(nullptr), right_(nullptr), parent_(nullptr)
{
    std::cout << "node constructor" << std::endl;
}

template<typename T>
node<T>::~node()
{
//	//if (std::is_pointer<T>::value)
//	//{
//		//delete key_;
//		
//		std::unique_ptr<
//			typename std::enable_if<
//				std::is_pointer<T>::value, typename std::remove_pointer<T>::type
//			>::type
//		> upkey(key_);
//	//}
}

//template<typename T>
//node<T>::node(const node<T>& _node)
//{
//	key_ = _node.key();
//	left_ = _node.left();
//	right_ = _node.right();
//	parent_ = _node.parent();
//	std::cout << "node copy constructor" << std::endl;
//
//}

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

//template<typename T> 
//class node<T*> {
//	using key_value = T*;
//	~node()
//	{
//		delete key_;
//	}
//};

template class node<int>;
template class node<std::string>;
template class node<std::shared_ptr<std::string>>;



