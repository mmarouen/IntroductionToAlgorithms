#ifndef CHAP_14_H
#define CHAP_14_H
#include <cmath>
//#include <algorithm>
#include "chap2.hpp"
#include <stdexcept>

namespace chap14
{
    /**
     * @brief recursive method to compute the optimal revenue for a rod of size n (n <= vector size)
     * 
     * @param prices vector of prices for each cut i = 1..vector_size
     * @param revenues vector of revenues computed sofar, get appended with every call to the function
     * @param n max rod size to consider
     * @param pieces list of pieces composing the maximal revenue cut
     * 
     * @return int
     */
    int CutRod(std::vector<int> prices, std::vector<int>& revenues, int n, std::vector<int>& pieces);

    /**
     * @brief memoized version of the recursive cutrod method.
     * The method also returns the pirces and quantities to cut
     * 
     * @param prices vector of prices for each cut i = 1..vector_size
     * @param max_cut_size max rod size to consider
     * @param pieces list of pieces index to use
     * @return int 
     */
    int MemoizedCutRod(std::vector<int> prices, int max_cut_size, std::vector<int>& pieces);

    void LongestCommonSequence(std::vector<std::string> sequence_x, std::vector<std::string> sequence_y, std::vector<std::vector<int>>& lcs);
}
#endif