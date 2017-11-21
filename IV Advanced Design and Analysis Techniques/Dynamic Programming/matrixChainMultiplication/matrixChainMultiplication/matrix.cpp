#include "matrix.h"


template<typename T>
matrix<T>::matrix(const size_t _row, const size_t _col)
	: row_(_row), col_(_col),m_(_row, vector<T>(_col))
{
}



//matrix::~matrix()
//{
//}

template class matrix<int>;
template class matrix<float>;