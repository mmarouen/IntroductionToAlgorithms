#include <iostream>
#include <random>
#include "algorithms/chap4.hpp"
#include "algorithms/chap2.hpp"

int main(int argc, char** argv)
{
    int n_cols = 8;
    int n_rows = 8;
    std::vector<float> values;
    matrix A, B, C, C_;

    // fillup matrix A from vector
    for(int i = 0; i < n_cols * n_rows; i++)
    {
        float rand = std::rand() % 10;
        values.push_back(rand);
    }
    try
    {
        A = chap4::SerializeMatrix(values, n_cols, n_rows);
        std::cout << "Matrix A \n" << chap4::DisplayMatrix(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // fillup matrix B from vector
    values.clear();
    for(int i = 0; i < n_cols * n_rows; i++)
    {
        float rand = std::rand() % 10;
        values.push_back(rand);
    }
    try
    {
        B = chap4::SerializeMatrix(values, n_rows, n_cols);
        std::cout << "Matrix B \n" << chap4::DisplayMatrix(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // classical multiplication C = A * B
    try
    {
        chap4::MatrixMultiply(A, B, C);
        std::cout << "Matrix C (classical multiplication) \n" << chap4::DisplayMatrix(C);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // recursive multiplication C = A * B
    for(int i = 0; i < n_cols; i++)
    {
        std::vector<float> zeroes(n_cols, 0.0);
        C_.push_back(zeroes);
    }
    try
    {
        MatrixPoint point_a, point_b;
        chap4::MatrixMultiplyRecursive(&A, &B, &C_, n_cols, point_a, point_b);
        std::cout << "Matrix C (recursive multiplication) \n" << chap4::DisplayMatrix(C_);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
	return 0;
}