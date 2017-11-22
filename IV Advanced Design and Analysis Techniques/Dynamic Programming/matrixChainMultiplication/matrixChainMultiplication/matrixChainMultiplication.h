#ifndef _MATRIX_CHAIN_MULTIPLICATION_H_
#define _MATRIX_CHAIN_MULTIPLICATION_H_

#include "matrix.h"

#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

using std::vector;
using std::cerr;
using std::endl;

matrix<int> matrixMultiply(const matrix<int>& _a, const matrix<int>& _b);
void matrixChainOrder(const vector<int>& _p, vector<vector<int>>& _m, vector<vector<int>>& _s);
void printOptimalParens(const vector<vector<int>>& _s, size_t _i, size_t _j);

#endif // !_MATRIX_CHAIN_MULTIPLICATION_H_

