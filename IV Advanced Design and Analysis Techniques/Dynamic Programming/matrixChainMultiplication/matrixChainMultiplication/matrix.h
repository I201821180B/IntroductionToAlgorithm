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
    matrix(const size_t row, const size_t col);
    matrix(const vector<T>& v, const size_t row, const size_t col);
    matrix(matrix<T>&& m);
    //~matrix();
    
    matrix<T>& operator=(matrix<T>&& m);
    vector<T>& operator[](const size_t idx);
    const vector<T>& operator[](const size_t idx) const;

    void print();

    size_t row_;
    size_t col_;
    vector<vector<T>> m_;

    DISABLE_COPY_AND_ASSIGN(matrix);
};

#endif // !_MATRIX_H_



