#include "../include/algorithms/chap14.hpp"
#include <stdexcept>

namespace chap14
{
    int CutRod(std::vector<int> prices, int n)
    {
        if(n == 0)
        {
            return 0;
        }
        int revenue = prices[n - 1];
        for(int i = n - 1; i >= 0; i--)
        {
            revenue = std::max(revenue, prices[n - i - 1] + CutRod(prices, i));
        }
        return revenue;
    }

    int MemoizedCutRodAux(std::vector<int> prices, int n, std::vector<int>& revenues)
    {
        if(revenues[n - 1] >= 0)
        {
            return revenues[n - 1];
        }
        int revenue = -1;
        if(n == 0)
        {
            revenue = 0;
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                revenue = std::max(revenue, prices[i] + MemoizedCutRodAux(prices, n - i - 1, revenues));
            }
        }
        revenues[n] = revenue;
        return revenue;
    }

    int MemoizedCutRod(std::vector<int> prices, int n)
    {
        std::vector<int> revenues(n, -1);
        return MemoizedCutRodAux(prices, n, revenues);
    }
}