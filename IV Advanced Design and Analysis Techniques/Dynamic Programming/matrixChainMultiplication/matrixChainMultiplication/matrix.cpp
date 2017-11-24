#include "matrix.h"


template<typename T>
matrix<T>::matrix(const size_t _row, const size_t _col)
	: row_(_row), col_(_col),m_(_row, vector<T>(_col, 0))
{
}

template<typename T>
matrix<T>::matrix(const vector<T>& _v, const size_t _row, const size_t _col)
	: matrix(_row, _col)
{
	assert(_v.size() >= _row*_col);
	for (int i = 0; i < _row; ++i)
	{
		for (int j = 0; j < _col; ++j)
		{
			m_[i][j] = _v[i*_col + j];
		}
	}
}

// 移动构造函数
template<typename T>
matrix<T>::matrix(matrix<T>&& _mx)
	: row_(_mx.row_), col_(_mx.col_)
{
	cout << "move ctor" << endl;
	m_ = std::move(_mx.m_);
}

// const对象
template<typename T>
const vector<T>& matrix<T>::operator[](const size_t idx) const
{
	return m_[idx];
}


// 移动赋值函数
template<typename T>
matrix<T>& matrix<T>::operator=(matrix<T>&& _mx)
{
	cout << "move operator" << endl;
	row_ = _mx.row_;
	col_ = _mx.col_;
	m_ = std::move(_mx.m_);
	return *this;
}

// 非const对象
template<typename T>
vector<T>& matrix<T>::operator[](const size_t idx)
{
	
	return m_[idx];
}

template<typename T>
void matrix<T>::print()
{
	cout << endl;
	for (size_t i = 0; i < row_; ++i)
	{
		for (int j = 0; j < col_; ++j)
		{
			cout << m_[i][j] << " ";
		}
		cout << endl;
	}
}


//matrix::~matrix()
//{
//}

template class matrix<int>;
template class matrix<float>;