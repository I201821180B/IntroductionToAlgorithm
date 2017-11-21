#ifndef _MATRIX_H_
#define _MATRIX_H_

#define DISABLE_COPY_AND_ASSIGN(className) \
	className(const className&) = delete; \
	className& operator=(const className&) = delete

#include <vector>


using std::vector;

template<typename T>
class matrix
{
public:
	matrix(const size_t _row, const size_t _col);
	//~matrix();
	size_t row_;
	size_t col_;
	vector<vector<T>> m_;

	DISABLE_COPY_AND_ASSIGN(matrix);
};

#endif // !_MATRIX_H_



