#ifndef CHAP_15_H
#define CHAP_15_H
#include <cmath>
#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <algorithm>

namespace chap15
{

    /**
     * @brief activity definition selection problem
     * 
     */
    struct Activity{
        int s;
        int f;
    };

    /**
     * @brief Dynamic programming version of the activity selection problem.
     * 
     * @param activities list of activities sorted by finish time in increasing order
     * @note if 2 activities have the same finish time, we ignore the one starting earlier since its an obvious choice to eliminate 
     */
    std::vector<int> ActivitySelectionDP(std::vector<Activity> activities);

    /**
     * @brief item definition for the knapsack problem
     * 
     */
    struct Item{
        int id;
        int weight;
        int value;
        bool operator==(const Item& item_2) const
        {
            return id == item_2.id;
        }
    };

    struct Sack{
        int value;
        int weight;
        std::vector<Item> items;
    };

    /**
     * @brief fractional knpasack problem
     * 
     * @param items list of items that can be packed
     * @param total_weight total knapsack weight
     * @return std::vector<Item> 
     */
    std::vector<Item> KnapsackProblemFraction(std::vector<Item> items, int total_weight);

    /**
     * @brief 0-1 knpasack problem where each item is supposed available only once
     * 
     * @param items list of items that can be packed
     * @param total_weight total knapsack weight
     * @return std::vector<Item> 
     */
    std::vector<Item> KnapsackProblem01(std::vector<Item> items, int total_weight);

    /**
     * @brief computes the optimal value for the given sack size
     * 
     * @param n current size of the sack
     * @param values values vector
     * @param items input items containing weight and values
     * @param items_ output items to include
     * @return Sack 
     */
    Sack KnapsackProblemAux(int n, std::vector<int>& values, std::vector<Item> items);


}
#endif