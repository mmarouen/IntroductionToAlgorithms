#include "../include/algorithms/chap14.hpp"
#include <stdexcept>

namespace chap14
{
    int CutRod(std::vector<int> prices, std::vector<int>& revenues, int n, std::vector<int>& pieces)
    {
        if(n == 0)
        {
            revenues[0] = 0;
            pieces[0] = -1;
            return 0;
        }
        int revenue = -1;
        int optimal_index = -10;
        for(int i = 0; i < n; i++)
        {
            int revenue_i;
            if(revenues[i] < 0)
            {
                revenue_i = prices[n - 1 - i] + CutRod(prices, revenues, i, pieces);
            }
            else
            {
                revenue_i = prices[n - 1 - i] + revenues[i];
            }
            if(revenue_i > revenue)
            {
                revenue = revenue_i;
                pieces[n] = n - i;
            }
        }
        if(n < prices.size())
        {
            revenues[n] = revenue;
        }
        return revenue;
    }

    int MemoizedCutRod(std::vector<int> prices, int max_cut_size, std::vector<int>& pieces)
    {
        int n = max_cut_size;
        if(max_cut_size > prices.size())
        {
            n = prices.size();
        }
        if(max_cut_size == 0)
        {
            throw(std::runtime_error("Received a 0 max cut size. Minimum accepted size is 1"));
        }
        std::vector<int> revenues(n, -1);
        pieces.resize(n + 1, -1);
        return CutRod(prices, revenues, n, pieces);
    }

    void LongestCommonSequence(std::vector<std::string> sequence_x, std::vector<std::string> sequence_y, std::vector<std::vector<int>>& lcs)
    {
        int m = sequence_x.size() + 1;
        int n = sequence_y.size() + 1;
        if(m * n == 0)
        {
            throw(std::runtime_error("Sequences must contain at least one string each"));
        }
        lcs.resize(m, std::vector<int>(n));
        std::vector<std::vector<std::string>> paths;
        paths.resize(m, std::vector<std::string>(n));
        for(int i = 0; i < m; i++)
        {
            lcs[i][0] = 0;
        }
        for(int j = 0; j < n; j++)
        {
            lcs[0][j] = 0;
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(sequence_x[i - 1] == sequence_y[j - 1])
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else if(lcs[i - 1][j] > lcs[i][j - 1])
                {
                    lcs[i][j] = lcs[i - 1][j];
                }
                else
                {
                    lcs[i][j] = lcs[i][j - 1];
                }
            }
        }
    }

}