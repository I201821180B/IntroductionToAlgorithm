#include "matrix.h"


template<typename T>
matrix<T>::matrix(const size_t row, const size_t col)
    : row_(row), col_(col),m_(row, vector<T>(col, 0))
{
}

template<typename T>
matrix<T>::matrix(const vector<T>& v, const size_t row, const size_t col)
    : matrix(row, col)
{
    assert(v.size() >= row*col);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            m_[i][j] = v[i*col + j];
        }
    }
}

// 移动构造函数
template<typename T>
matrix<T>::matrix(matrix<T>&& mx)
    : row_(mx.row_), col_(mx.col_)
{
    cout << "move ctor" << endl;
    m_ = std::move(mx.m_);
}

// const对象
template<typename T>
const vector<T>& matrix<T>::operator[](const size_t idx) const
{
    return m_[idx];
}


// 移动赋值函数
template<typename T>
matrix<T>& matrix<T>::operator=(matrix<T>&& mx)
{
    cout << "move operator" << endl;
    row_ = mx.row_;
    col_ = mx.col_;
    m_ = std::move(mx.m_);
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