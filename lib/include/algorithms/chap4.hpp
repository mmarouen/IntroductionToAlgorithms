#ifndef CHAP_4_H
#define CHAP_4_H
#include <vector>
#include <iostream>
#include <algorithm> // for std::copy
#include <iomanip>
#include <sstream>
#include <cmath>

typedef std::vector<std::vector<float>> matrix;

struct MatrixPoint {
    int col=0;
    int row=0;
};


namespace chap4
{
    /**
     * @brief checks whether input matrix contains empty rows or columns
     * 
     * @param A input matrix
     * @return true 
     * @return false 
     */
    bool inline isEmpty(matrix A){return A.size() == 0 || A[0].size() == 0;};

    /**
     * @brief checks whether input matrix is square
     * 
     * @param A input matrix
     * @return true 
     * @return false 
     */
    bool inline isSquare(matrix A){return A.size() == A[0].size();};

    /**
     * @brief check whether input is a power of 2
     * 
     * @param i integer to analyse
     * @return true 
     * @return false 
     */
    bool inline isPowerOf2(int i){return ceil(log2(i)) == floor(log2(i));};

    /**
     * @brief serializing a vector into a row based (filled horizontally) matrix.
     * 
     * @param values input vector of values
     * @param n_cols number of columns
     * @param n_rows number of rows
     * @return matrix 
     */
    matrix SerializeMatrix(std::vector<float> values, int n_cols, int n_rows);

    /**
     * @brief string display of a matrix
     * 
     * @param A matrix to display
     * @return std::string 
     */
    std::string DisplayMatrix(matrix A);

    /**
     * @brief classical matrix multiplication of 2 NxN matrices: C = A * B
     * 
     * @param A left matrix on the product
     * @param B right matrix on the product
     * @param C resulting matrix
     */
    void MatrixMultiply(matrix& A, matrix& B, matrix& C);


    /**
     * @brief recusrively multiplies 2 NxN matrices: C = A * B
     * 
     * @param A_ptr pointer to the left matrix
     * @param B_ptr pointer to the right matrix
     * @param C_ptr pointer to the resultant matrix
     * @param size size of the matrix block to consider
     * @param point_a starting point for matrix A
     * @param point_b starting point for matrix B
     */
    void MatrixMultiplyRecursive(matrix* A_ptr, matrix* B_ptr, matrix* C_ptr, int size, MatrixPoint& point_a, MatrixPoint& point_b);

}

#endif