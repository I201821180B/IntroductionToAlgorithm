#include <iostream>
#include <vector>
#include <string>
//#include <cstdint>
#include <type_traits>

#include "optimalBinarySearchTree.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

// 判断一个类型是否为vector类模板
// 方案1不行
//template <typename T, typename U>
//using decay_equiv = std::is_same<typename std::decay<T>::type, U>::type;

// 方案2
template<typename Test, template<typename...> class Ref>
struct is_specialization : std::false_type {};

template<template<typename...> class Ref, typename... Args>
struct is_specialization<Ref<Args...>, Ref> : std::true_type {};

// 方案3
//template<typename T> struct is_vector : public std::false_type {};
//
//template<typename T, typename A>
//struct is_vector<std::vector<T, A>> : public std::true_type {};

template<typename T>
void print(T& _i, typename std::enable_if<
								!is_specialization<std::remove_const_t<T>, std::vector>::value
							>::type* = nullptr)//!decay_equiv<T, vector<int>>::value
{
	cout << _i << "\t\t";
}

template<typename T>
void print(T& _v, typename std::enable_if<
								is_specialization<std::remove_const_t<T>, std::vector>::value
							>::type* = nullptr)//decay_equiv<T, vector<int>>::value
{
	for (const auto& item : _v)
	{
		print(item);
	}
	cout << endl;
}



int main()
{
	vector<float> p{ 0.15f, 0.1f, 0.05f, 0.1f, 0.2f };
	vector<float> q{ 0.05f, 0.1f, 0.05f, 0.05f, 0.05f, 0.1f };

	vector<vector<float>> e;
	vector<vector<size_t>> r;

	/*cout << ((std::is_same<
		std::vector<int>, std::vector<string>
	>::value) ? "deep" : "dark");*/

	//vector<vector<float>> test = { {0.1f,0.1f,0.1f},{0.2f,0.2f,0.2f},{0.3f,0.3f,0.3f} };

	/*int a = 3;
	print(a);
	print(p);
	print(test);*/

	optimalBstRe(p, q, p.size(), e, r);

	print(e);
	print(r);

}