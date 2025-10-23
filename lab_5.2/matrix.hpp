#pragma once

#include <iostream>
#include <algorithm>
#include <optional>
#include <vector>
#include <limits>

#include "utilits.hpp"

template <typename T>
class Matrix
{
    public:
        Matrix(): rows_(0), column_(0), array_(nullptr) {}

        Matrix(size_t rows, size_t column, T value = T{}): rows_(rows), column_(column), array_(new T[rows * column]) 
        {
            std::fill_n(array_, rows * column, value);
        }

        Matrix(size_t rows, size_t column, const T* arr): rows_(rows), column_(column), array_(new T[rows * column]) 
        {
            std::copy(arr, arr + rows * column, array_);
        }

        Matrix& input()
        {
            if(!array_)
                return *this;
            std::cout << ' ! ';
            for(size_t i = 0; i < rows_; ++i)
            {
                for(size_t j = 0; j < column_; ++j)
                {
                    array_[i * column_ + j] = get_num<T>();
                }
            }
            return *this;
        }

        Matrix& input(size_t rows, size_t column, const T* arr)
        {
            std::copy(arr, arr + rows * column, array_);
            return *this;
        }

        size_t get_columns() const
        {
            return column_;
        }

        size_t get_rows() const //ноуэксепт!!!!!!!!!!!!!!!
        {
            return rows_;
        }

        T get_elem(size_t i, size_t j) const
        {
            if(i >= rows_ || j >= column_)
                throw std::out_of_range("Invalid index");
            return array_[i * column_ + j];
        }

        T& get_elem(size_t i, size_t j) 
        {
            if(i >= rows_ || j >= column_)
                throw std::out_of_range("Invalid index");
            return array_[i * column_ + j];
        }// заменим на кв скобки

        T* data()
        {
            return array_;
        }

        const T* data() const
        {
            return array_;
        }

        Matrix operator*(const Matrix& mat2) const
        {
            if(rows_ != mat2.column_)
                throw std::invalid_argument("Matrix dimensions incompatible for multiplication");
            Matrix result(rows_, mat2.column_);
            for (size_t i = 0; i < rows_; ++i) 
            {
                for (size_t j = 0; j < mat2.column_; ++j) 
                {
                    T sum = 0;
                    for (size_t k = 0; k < column_; ++k) 
                    {
                        sum += get_elem(i, k) * mat2.get_elem(k, j);
                    }
                    result.get_elem(i, j) = sum;
                }
            }
            return result;
        }

        void operator*=(T other) 
        {
            for (size_t i = 0; i < rows_; ++i) 
            {
                for (size_t j = 0; j < column_; ++j) 
                {
                    get_elem(i, j) *= other;
                }
            }
        }

        Matrix operator*(T other) const
        {
            Matrix result(rows_, column_);
            for (size_t i = 0; i < rows_; ++i) 
            {
                for (size_t j = 0; j < column_; ++j) 
                {
                    result.get_elem(i, j) = get_elem(i, j) * other;
                }
            }
            return result;
        }

        Matrix operator+(const Matrix& mat2) const
        {
            if(rows_ != mat2.rows_ || column_ != mat2.column_)
                throw std::invalid_argument("Matrix must match for addition");
            Matrix result(rows_, column_);
            for(size_t i = 0; i < rows_ * column_; ++i)
            {
                result.array_[i] = array_[i] + mat2.array_[i];
            }
            return result;
        }

        bool empty() const
        {
            return !array_;    
        }

        ~Matrix()
        {
            delete[] array_;
        } 
    
    private:
        size_t rows_;
        size_t column_;
        T* array_;
};


/*
1 2 3
4 5 6
7 8 9//012345678
*/   //123456789

template <typename T>
std::ostream& operator<<(std::ostream& x, const Matrix<T>& mat)
{
    for(size_t i = 0; i < mat.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat.get_columns(); ++j)
        {
            x << mat.data()[i * mat.get_columns() + j] << ' ';
        }
        x << '\n';
    }
    return x;
}