#ifndef _MATRIX_H_
#define _MATRIX_H_

#define DISABLE_COPY_AND_ASSIGN(className) \
	className(const className&) = delete; \
	className& operator=(const className&) = delete

#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

using std::vector;
using std::cout;
using std::endl;

template<typename T>
class matrix
{
public:
	matrix(const size_t _row, const size_t _col);
	matrix(const vector<T>& _v, const size_t _row, const size_t _col);
	matrix(matrix<T>&& _m);
	//~matrix();
	
	matrix<T>& operator=(matrix<T>&& _m);
	vector<T>& operator[](const size_t idx);
	const vector<T>& operator[](const size_t idx) const;

	void print();

	size_t row_;
	size_t col_;
	vector<vector<T>> m_;

	DISABLE_COPY_AND_ASSIGN(matrix);
};

#endif // !_MATRIX_H_



