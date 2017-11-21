#ifndef _MATRIX_CHAIN_MULTIPLICATION_H_
#define _MATRIX_CHAIN_MULTIPLICATION_H_

#include "matrix.h"

#include <vector>

using std::vector;

void matrixMultiply(const vector<int>& _a, const vector<int>& _b, vector<int>& _c);
void matrixChainOrder(const vector<int>& _p, vector<vector<int>>& _m, vector<vector<int>>& _s);
void printOptimalParens(const vector<vector<int>>& _s, size_t _i, size_t _j);

#endif // !_MATRIX_CHAIN_MULTIPLICATION_H_

