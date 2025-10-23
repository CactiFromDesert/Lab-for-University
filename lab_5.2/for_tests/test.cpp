#include <gtest/gtest.h>

#include "../matrix.hpp"
#include "../utilits.hpp"

TEST(MatrixTest, OperatorMultEqTest1)
{
    Matrix<int> mat(5, 5, 5);
    mat *= 5;
    
    for(size_t i = 0; i < mat.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat.get_columns(); ++j)
        {
            EXPECT_EQ(mat.get_elem(i, j), 25);
        }
    }
    
}

TEST(MatrixTest, OperatorPlusTest2)
{
    Matrix<int> mat(5, 5, 5);
    Matrix<int> mat2(5, 5, 4);
    Matrix<int> mat3 = mat + mat2;
    
    for(size_t i = 0; i < mat3.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat3.get_columns(); ++j)
        {
            EXPECT_EQ(mat3.get_elem(i, j), 9);
        }
    }
    
}

TEST(MatrixTest, OperatorMultTest1)
{
    Matrix<int> mat(5, 5, 5);
    Matrix<int> mat4 = mat * 5;
    
    for(size_t i = 0; i < mat4.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat4.get_columns(); ++j)
        {
            EXPECT_EQ(mat4.get_elem(i, j), 25);
        }
    }
    
}

TEST(MatrixTest, OperatorMultTest2)
{
    Matrix<int> mat(2, 2, 5);
    Matrix<int> mat2(2, 2, 4);
    Matrix<int> mat4 = mat * mat2;
    
    for(size_t i = 0; i < mat4.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat4.get_columns(); ++j)
        {
            EXPECT_EQ(mat4.get_elem(i, j), 40);
        }
    }
    
}

TEST(MatrixTest, OperatorEmptyTest)
{
    Matrix<int> mat;
    Matrix<int> mat2(5, 5, 4);
    
    EXPECT_EQ(mat.empty(), 1);
    EXPECT_EQ(mat2.empty(), 0);

    mat = mat2;

    EXPECT_EQ(mat.empty(), 0);
}

TEST(MatrixTest, OperatorSwapTest2)
{
    Matrix<int> mat(2, 2, 5);
    Matrix<int> mat2(2, 2, 4);
    
    for(size_t i = 0; i < mat.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat.get_columns(); ++j)
        {
            EXPECT_EQ(mat.get_elem(i, j), 5);
        }
    }
    for(size_t i = 0; i < mat2.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat2.get_columns(); ++j)
        {
            EXPECT_EQ(mat2.get_elem(i, j), 4);
        }
    }

    mat.swap(mat2);

    for(size_t i = 0; i < mat.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat.get_columns(); ++j)
        {
            EXPECT_EQ(mat.get_elem(i, j), 4);
        }
    }
    for(size_t i = 0; i < mat2.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat2.get_columns(); ++j)
        {
            EXPECT_EQ(mat2.get_elem(i, j), 5);
        }
    }
    
}

TEST(MatrixTest, OperatorInTest2)
{
    Matrix<int> mat2(2, 7, 5);
    
    EXPECT_EQ(mat2.get_columns(), 7);
    EXPECT_EQ(mat2.get_rows(), 2);
    
}

TEST(MatrixTest, OperatorTraceTest2)
{
    Matrix<int> mat1(4, 4, 5);
    EXPECT_EQ(mat1.trace(), 20);

    Matrix<int> mat2(2, 2, 5);
    EXPECT_EQ(mat2.trace(), 10);

    Matrix<int> mat3(5, 5, 7);
    EXPECT_EQ(mat3.trace(), 35);
}

TEST(MatrixTest, OperatorClonTest2)
{
    Matrix<int> mat(2, 2, 5);
    Matrix<int> mat2(2, 2, 4);
    Matrix<int> mat3(mat);
    Matrix<int> mat4(mat2);

    for(size_t i = 0; i < mat3.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat3.get_columns(); ++j)
        {
            EXPECT_EQ(mat3.get_elem(i, j), 5);
        }
    }
    
    for(size_t i = 0; i < mat4.get_rows(); ++i)
    {
        for(size_t j = 0; j < mat4.get_columns(); ++j)
        {
            EXPECT_EQ(mat4.get_elem(i, j), 4);
        }
    }
    
}
