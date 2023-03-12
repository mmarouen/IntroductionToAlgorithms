#include <iostream>
#include <numeric>
#include "algorithms/chap15.hpp"

int main(int argc, char** argv)
{

    std::cout << "####################" << std::endl;
    std::cout << "Optimal activity selection" << std::endl;
    std::vector<chap15::Activity> activities{{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}, {6, 10}, {7, 11}, {8, 12}, {2, 14}, {12, 16}};
    std::vector<int> optimal_activities = chap15::ActivitySelectionDP(activities);
    std::cout << "optimal activities:\n";
    for(int activity_index : optimal_activities)
    {
        std::cout << "a_" << activity_index << " ";
    }
    std::cout << std::endl;

    std::cout << "####################" << std::endl;
    std::cout << "01 Knapsack using DP" << std::endl;
    std::vector<chap15::Item> items{{1, 10, 60}, {2, 20, 100}, {3, 30, 120}};
    int total_weight = 50;
    std::cout << "items available:\n";
    for(chap15::Item item : items)
    {
        std::cout << "weight " << item.weight << ", value " << item.value << std::endl;
    }
    std::vector<chap15::Item> result = chap15::KnapsackProblem01(items, total_weight);

    return 0;
}