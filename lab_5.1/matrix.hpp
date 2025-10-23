#pragma once

#include <iostream>
#include <limits>

#include "utilits.hpp"

template <typename T>
class Matrix
{
    public:
        Matrix() noexcept: rows_(0), column_(0), array_(nullptr) {}

        Matrix(size_t rows, size_t column, T value = T{}): rows_(rows), column_(column), array_(new T[rows * column]) 
        {
            std::fill_n(array_, rows * column, value);
        }

        Matrix(const Matrix& mat): rows_(mat.rows_), column_(mat.column_), array_(new T[mat.rows_ * mat.column_])
        {
            std::copy(mat.array_, mat.array_ + mat.rows_ * mat.column_, array_);
        }

        Matrix& input(size_t rows, size_t column, const T* arr)
        {
            std::copy(arr, arr + rows * column, array_);
            return *this;
        }

        Matrix& input()
        {
            if(!array_)
                return *this;
            for(size_t i = 0; i < rows_; ++i)
            {
                for(size_t j = 0; j < column_; ++j)
                {
                    array_[i * column_ + j] = get_num<T>();
                }
            }
            return *this;
        }

        T trace() const noexcept
        {
            T sum = 0;
            for(size_t i = 0; i < rows_; ++i)
            {
                for(size_t j = 0; j < column_; ++j)
                {
                    if(i == j)
                    {
                        //sum += array_.data()[i * column_ + j];
                        sum += array_[i * column_ + j];
                    }
                    //x << mat.data()[i * mat.get_columns() + j] << ' ';
                }
            }
            return sum;
        }

        Matrix& det() const;// метод гауса !!!!!!!!!!!!!!

        size_t get_columns() const noexcept
        {
            return column_;
        }

        size_t get_rows() const noexcept
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

        T* data() noexcept
        {
            return array_;
        }

        const T* data() const noexcept
        {
            return array_;
        }

        void swap(Matrix& mat) noexcept
        {
            std::swap(rows_, mat.rows_);
            std::swap(column_, mat.column_);
            std::swap(array_, mat.array_);
        }

        Matrix& operator=(const Matrix& mat)
        {
            Matrix mat_copy = mat;
            swap(mat_copy);
            return *this;
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

        void operator*=(const T& other)  noexcept
        {
            for (size_t i = 0; i < rows_; ++i) 
            {
                for (size_t j = 0; j < column_; ++j) 
                {
                    array_[i * column_ + j] *= other;
                }
            }
        }

        Matrix operator*(const T& other) const
        {
            Matrix result(rows_, column_);
            for (size_t i = 0; i < rows_; ++i) 
            {
                for (size_t j = 0; j < column_; ++j) 
                {
                    result.array_[i * column_ + j] = array_[i * column_ + j] * other;
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

        bool empty() const noexcept
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