#pragma once

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <numeric>

#include "utilits.hpp"

template <typename T>
class Matrix
{
public:
    Matrix() = default;

    explicit Matrix(size_t size): size_(size), main_diag_(size, T(0)),
          upper_diag_(size > 1 ? size - 1 : 0, T(0)),
          lower_diag_(size > 1 ? size - 1 : 0, T(0)) {}

    Matrix& input()
    {
        std::cout << "Enter size: \n";
        size_ = get_num<size_t>();
        main_diag_.resize(size_);
        lower_diag_.resize(size_ - 1);
        upper_diag_.resize(size_ - 1);
        std::cout << "Enter elems to main diag: \n";
        for(size_t i = 0; i < size_; ++i)
        {
            main_diag_[i] = get_num<T>();
        }
        if(size_ > 1)
        {
            std::cout << "Enter elems to upper diag: \n";
            for(size_t i = 0; i < size_ - 1; ++i)
                upper_diag_[i] = get_num<T>();
            std::cout << "Enter elems to lower diag: \n";
            for(size_t i = 0; i < size_ - 1; ++i)
                lower_diag_[i] = get_num<T>();
        }
    }

    T trace() const noexcept
    {
        return std::accumulate(main_diag_.begin(), main_diag_.end(), T(0));
    }

    size_t get_columns() const noexcept
    {
        return size_;
    }

    size_t get_rows() const noexcept
    {
        return size_;
    }

    void swap(Matrix& mat) noexcept
    {
        std::swap(size_, mat.size_);
        std::swap(main_diag_, mat.main_diag_);
        std::swap(lower_diag_, mat.lower_diag_);
        std::swap(upper_diag_, mat.upper_diag_);
    }

    T& get_elem(size_t ind_x, size_t ind_y)
    {
        if (ind_x >= size_ || ind_y >= size_) 
            throw std::out_of_range("Index out of range");
        if(ind_x == ind_y)
            return main_diag_[ind_x];
        else if(ind_y == ind_x + 1)
            return upper_diag_[ind_x];
        else if(ind_x == ind_y + 1)
            return lower_diag_[ind_y];
        else
            throw std::invalid_argument("Accessing zero element in tridiagonal matrix");
    }

    const T& get_elem(size_t ind_x, size_t ind_y) const
    {
        if (ind_x >= size_ || ind_y >= size_) 
            throw std::out_of_range("Index out of range");
        if(ind_x == ind_y)
            return main_diag_[ind_x];
        else if(ind_y == ind_x + 1)
            return upper_diag_[ind_x];
        else if(ind_x == ind_y + 1)
            return lower_diag_[ind_y];
        else
            return T(0);
    }

    /*Matrix operator*(const Matrix& mat2) const//!!!!!
    {
        if(rows_ != mat2.size_)
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

    void operator*=(const T& other)  noexcept//!!!
    {
        for (size_t i = 0; i < rows_; ++i) 
        {
            for (size_t j = 0; j < column_; ++j) 
            {
                array_[i * column_ + j] *= other;
            }
        }
    }*/

    Matrix& operator+=(const T& other) noexcept
    {
        if (size_ != other.size_) 
            throw std::invalid_argument("Matrix sizes must be equal for addition");
        
        std::transform(main_diag_.begin(), main_diag_.end(), 
                      other.main_diag_.begin(), main_diag_.begin(), std::plus<T>());
        std::transform(lower_diag_.begin(), lower_diag_.end(), 
                    other.lower_diag_.begin(), lower_diag_.begin(), std::plus<T>());
        std::transform(upper_diag_.begin(), upper_diag_.end(), 
                    other.upper_diag_.begin(), upper_diag_.begin(), std::plus<T>());
        return *this;
    }

    Matrix& operator-=(const Matrix& other) noexcept
    {
        if (size_ != other.size_) 
            throw std::invalid_argument("Matrix sizes must be equal for addition");
        
        std::transform(main_diag_.begin(), main_diag_.end(), 
                    other.main_diag_.begin(), main_diag_.begin(), std::minus<T>());
        std::transform(lower_diag_.begin(), lower_diag_.end(), 
                    other.lower_diag_.begin(), lower_diag_.begin(), std::minus<T>());
        std::transform(upper_diag_.begin(), upper_diag_.end(), 
                    other.upper_diag_.begin(), upper_diag_.begin(), std::minus<T>());
        return *this;
    }

    Matrix operator+(const Matrix& mat2) const
    {
        if (size_ != other.size_) 
            throw std::invalid_argument("Matrix sizes must be equal for addition");
        Matrix result(size_);
        for(size_t i = 0; i < size_; ++i)
            result.main_diag_[i] = main_diag_[i] + mat2.main_diag_[i];
        for(size_t i = 0; i < size_ - 1; ++i)
        {
            result.lower_diag_[i] = lower_diag_[i] + mat2.lower_diag_[i];
            result.upper_diag_[i] = upper_diag_[i] + mat2.upper_diag_[i];
        }
        return result;
    }

    Matrix operator-(const Matrix& mat2) const
    {
        if (size_ != other.size_) 
            throw std::invalid_argument("Matrix sizes must be equal for addition");
        Matrix result(size_);
        for(size_t i = 0; i < size_; ++i)
            result.main_diag_[i] = main_diag_[i] - mat2.main_diag_[i];
        for(size_t i = 0; i < size_ - 1; ++i)
        {
            result.lower_diag_[i] = lower_diag_[i] - mat2.lower_diag_[i];
            result.upper_diag_[i] = upper_diag_[i] - mat2.upper_diag_[i];
        }
        return result;
    }

    Matrix operator*(const Matrix& mat2) const
    {
        if (size_ != other.size_) 
            throw std::invalid_argument("Matrix sizes must be equal for addition");
        Matrix result(size_);
        for(size_t i = 0; i < size_; ++i)
            result.main_diag_[i] = main_diag_[i] * mat2.main_diag_[i];
        for(size_t i = 0; i < size_ - 1; ++i)
        {
            result.lower_diag_[i] = lower_diag_[i] * mat2.lower_diag_[i];
            result.upper_diag_[i] = upper_diag_[i] * mat2.upper_diag_[i];
        }
        return result;
    }

    bool empty() const noexcept
    {
        return !size_;    
    }

private:
    size_t size_;
    std::vector<T> main_diag_;
    std::vector<T> lower_diag_;
    std::vector<T> upper_diag_;
};


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

template <typename T>
std::istream& operator>>(std::istream& x, const Matrix<T>& mat)
{
    mat.input();
    return x;
}