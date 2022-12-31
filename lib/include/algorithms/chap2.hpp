#ifndef CHAP_2_H
#define CHAP_2_H
#include <vector>
#include <iostream>
#include <algorithm> // for std::copy

namespace chap2
{

    std::string DisplayVector(std::vector<float> vec, int max_index);

    /**
     * @brief Insertion sort algorithm
     * 
     * @param values_list vector of floats to srot
     * @return void 
     */
    void InsertionSort(std::vector<float>& values_list);

    /**
     * @brief divide and conquer based algorithm
     * 
     * @param values_list input vector
     * @param begin first index to split from
     * @param end last index to split to
     */
    void MergeSort(std::vector<float>& values_list, int begin, int end);

    /**
     * @brief merge part of the merge sort algorithm
     * 
     * @param values_list input vector
     * @param begin first index to split from
     * @param end last index to split to
     */
    void Merge(std::vector<float>& values_list, int begin, int mid, int end);
}

#endif