#ifndef _VECTOROPERATION_H_
#define _VECTOROPERATION_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <functional>

using namespace std;

void getRandomVector(vector<int>& v, size_t size, int from, int to);

template<typename T> 
void printVector(vector<T>& v);

// 模板显示实例化，否则模板的声明与实现不能分开

template void printVector<int>(vector<int>& v);

#endif
