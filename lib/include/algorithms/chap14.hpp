#ifndef CHAP_14_H
#define CHAP_14_H
#include <cmath>
//#include <algorithm>
#include "chap2.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <numeric>
#include <map>

namespace chap14
{

    enum Direction {
        TopLeft=0,
        Top=1,
        Left=2
    };
    
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

    void LongestCommonSequence(std::vector<std::string> sequence_x, std::vector<std::string> sequence_y, std::vector<std::vector<int>>& lcs, std::vector<std::vector<int>>& paths);
    std::vector<std::string> DisplayLCS(std::vector<std::vector<int>> lcs, std::vector<std::vector<int>> paths, std::vector<std::string> sequence_x);

    /**
     * @brief Exercice 14.2
     * 
     */
    std::vector<std::string> LongestPalendromeSequence(std::vector<std::string> word);

    /**
     * @brief Exercice 14.3 utility function to compute distance between 2 points (assumed to have integer coordinates)
     * 
     * @param pt_1 first point
     * @param pt_2 second point
     * @return float 
     */
    inline float distanceTwoPoints(std::pair<int, int> pt_1, std::pair<int, int> pt_2)
    {
        return sqrt((pt_1.first - pt_2.first) * (pt_1.first - pt_2.first) + (pt_1.second - pt_2.second) * (pt_1.second - pt_2.second));
    }

    struct BitonicNode
    {
        int tail;
        float path;
        float cost_value;
        BitonicNode()
        {
            tail = -1;
            path = 10000;
            cost_value = 10000;
        };
        BitonicNode(int tail_, float path_, float cost_): tail(tail_), path(path_), cost_value(cost_) {};
    };
    

    /**
     * @brief computes the bitonic way through the points.
     * Lets suppose that n is the number of points:
     * - Root node (leftmost) has id 0
     * - Next node id: 1
     * - ...
     * - End node id: n-1
     * The vector contains node id in sequence 
     * 
     * @param input_points 
     * @return float
     */
    float BitonicWay(std::vector<std::pair<int, int>> input_points);
}
#endif