#ifndef _CUTROD_H_
#define _CUTROD_H_

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using std::vector;
using std::numeric_limits;
using std::max;
using std::cout;
using std::endl;

size_t memorizedCutRod(const vector<int>& _price, const size_t _length);
size_t memorizedCutRodAux(const vector<int>& _price, const size_t _length, vector<int>& r);
size_t bottomUpCutRod(const vector<int>& _price, const size_t _length);
void extendedBottomUpCutRod(const vector<int>& _price, const size_t _length, vector<int>& _optimal, vector<int>& _s);
void printCutRodSolution(const vector<int>& _price, const size_t _length);
#endif // !_CURROD_H_
