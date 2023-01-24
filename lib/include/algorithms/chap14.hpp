#ifndef CHAP_14_H
#define CHAP_14_H
#include <cmath>
//#include <algorithm>
#include "chap2.hpp"

namespace chap14
{
    /**
     * @brief recursive method to compute the optimal revenue for a rod of size n (n <= vector size)
     * 
     * @param prices vector of prices for each cut i = 1..vector_size
     * @param n max rod size to consider
     * 
     * @return int
     */
    int CutRod(std::vector<int> prices, int n);

    /**
     * @brief memoized version of the recursive cutrod method
     * 
     * @param prices vector of prices for each cut i = 1..vector_size
     * @param n max rod size to consider
     * @return int 
     */
    int MemoizedCutRod(std::vector<int> prices, int n);

    /**
     * @brief auxiliary function for the memoized cutrod function performing the recursion part
     * 
     * @param prices vector of prices for each cut i = 1..vector_size
     * @param n max rod size to consider
     * @param revenues refeence passed vector of revenues that gets checked before computing the revenues
     * @return int 
     */
    int MemoizedCutRodAux(std::vector<int> prices, int n, std::vector<int>& revenues);
}
#endif