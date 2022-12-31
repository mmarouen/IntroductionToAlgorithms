#include "../include/algorithms/chap4.hpp"
#include <stdexcept>

namespace chap4
{
    std::string DisplayMatrix(matrix A)
    {
        std::string msg = "";
        int n_rows = A.size();
        int n_cols = A[0].size();
        std::stringstream stream;
        if(isEmpty(A))
        {
            throw(std::runtime_error("Matrix is empty"));
        }
        for(int i = 0; i < n_rows; i++)
        {
            for(int j = 0; j < n_cols; j++)
            {
                stream << std::fixed << std::setprecision(2) << A[i][j];
                msg += stream.str() + " ";
                stream.str("");
            }
            msg += "\n";
        }
        return msg;
    }

    matrix SerializeMatrix(std::vector<float> values, int n_cols, int n_rows)
    {
        int n_values = values.size();
        if(n_values == 0)
        {
            throw(std::runtime_error("Empty input"));
        }
        if(n_cols * n_rows != n_values)
        {
            throw(std::runtime_error("Input size must be exactly n_cols x n_rows"));
        }
        matrix result;
        result.resize(n_rows, std::vector<float>(n_cols));
        for(int i = 0; i < n_rows; i++)
        {
            for(int j = 0; j < n_cols; j++)
            {
                result[i][j] = values[j + i * n_cols];
            }
        }
        return result;
    }

    void MatrixMultiply(matrix& A, matrix& B, matrix& C)
    {
        int n_rows_a = A.size();
        int n_cols_a = A[0].size();
        int n_rows_b = B.size();
        int n_cols_b = B[0].size();
        if(isEmpty(A))
        {
            throw(std::runtime_error("Matrix A is empty"));
        }
        if(isEmpty(B))
        {
            throw(std::runtime_error("Matrix B is empty"));
        }
        if(n_cols_a != n_rows_b)
        {
            throw(std::runtime_error("Matrix sizes are not compatible"));
        }
        C.resize(n_rows_a, std::vector<float>(n_cols_b));
        for(int i = 0; i < n_rows_a; i ++)
        {
            for(int j = 0; j < n_cols_b; j++)
            {
                C[i][j] = 0;
                for(int k = 0; k < n_cols_a; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    void MatrixMultiplyRecursive(matrix* A_ptr, matrix* B_ptr, matrix* C_ptr, int size, MatrixPoint& point_a, MatrixPoint& point_b)
    {
        if(!isSquare(*A_ptr))
        {
            throw(std::runtime_error("Matrix A is not square"));
        }
        if(!isSquare(*B_ptr))
        {
            throw(std::runtime_error("Matrix B is not square"));
        }
        if(A_ptr->size() != B_ptr->size())
        {
            throw(std::runtime_error("Input matrices do not have the same size"));
        }
        if(A_ptr->size() != B_ptr->size())
        {
            throw(std::runtime_error("Input matrices do not have the same size"));
        }
        if(!isPowerOf2(A_ptr->size()))
        {
            throw(std::runtime_error("Input size can only be a power of 2"));
        }
        if(size == 1)
        {
            C_ptr->at(point_a.row)[point_b.col] += A_ptr->at(point_a.row)[point_a.col] * B_ptr->at(point_b.row)[point_b.col];
            return;
        }
        int size_ = size / 2;
        MatrixMultiplyRecursive(A_ptr, B_ptr, C_ptr, size_, point_a, point_b); // A11, B11
        MatrixPoint point_b_ = point_b;
        MatrixPoint point_a_ = point_a;
        point_b_.col += size_;
        MatrixMultiplyRecursive(A_ptr, B_ptr, C_ptr, size_, point_a, point_b_); // A11, B12
        point_a_.row += size_;
        MatrixMultiplyRecursive(A_ptr, B_ptr, C_ptr, size_, point_a_, point_b); // A21, B11
        MatrixMultiplyRecursive(A_ptr, B_ptr, C_ptr, size_, point_a_, point_b_); // A21, B12
        point_a_.row = point_a.row;
        point_a_.col = point_a.col + size_;
        point_b_.row = point_b.row + size_;
        point_b_.col = point_b.col;
        MatrixMultiplyRecursive(A_ptr, B_ptr, C_ptr, size_, point_a_, point_b_); // A12, B21
        point_b_.col += size_;
        MatrixMultiplyRecursive(A_ptr, B_ptr, C_ptr, size_, point_a_, point_b_); // A12, B22
        point_a_.row += size_;
        MatrixMultiplyRecursive(A_ptr, B_ptr, C_ptr, size_, point_a_, point_b_); // A22, B22
        point_b_.col -= size_;
        MatrixMultiplyRecursive(A_ptr, B_ptr, C_ptr, size_, point_a_, point_b_); // A22, B21
    }
}