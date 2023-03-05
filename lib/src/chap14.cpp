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

    void LongestCommonSequence(std::vector<std::string> sequence_x, std::vector<std::string> sequence_y, std::vector<std::vector<int>>& lcs, std::vector<std::vector<int>>& paths)
    {
        int m = sequence_x.size() + 1;
        int n = sequence_y.size() + 1;
        if(m * n == 0)
        {
            throw(std::runtime_error("Sequences must contain at least one string each"));
        }
        lcs.resize(m, std::vector<int>(n));
        paths.resize(m, std::vector<int>(n));
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
                    paths[i][j] = Direction::TopLeft;
                }
                else if(lcs[i - 1][j] > lcs[i][j - 1])
                {
                    lcs[i][j] = lcs[i - 1][j];
                    paths[i][j] = Direction::Top;
                }
                else
                {
                    lcs[i][j] = lcs[i][j - 1];
                    paths[i][j] = Direction::Left;
                }
            }
        }
    }

    std::vector<std::string> DisplayLCS(std::vector<std::vector<int>> lcs, std::vector<std::vector<int>> paths, std::vector<std::string> sequence_x)
    {
        int m = lcs.size();
        int n = lcs[0].size();
        std::vector<std::string> lcs_sequence;
        int i = m - 1;
        int j = n - 1;
        while(i > 0 && j > 0 && lcs[i][j] != 0)
        {
            std::string value;
            int next_i, next_j;
            if(paths[i][j] == Direction::TopLeft)
            {
                next_i = i - 1;
                next_j = j - 1;
            }
            else if(paths[i][j] == Direction::Top)
            {
                next_i = i - 1;
                next_j = j;
            }
            else
            {
                next_i = i;
                next_j = j - 1;
            }
            if(lcs[i][j] > lcs[next_i][next_j])
            {
                lcs_sequence.insert(lcs_sequence.begin(), sequence_x[i - 1]);
            }
            i = next_i;
            j = next_j;

        }
        return lcs_sequence;
    }

    std::vector<std::string> LongestPalendromeSequence(std::vector<std::string> word)
    {
        std::vector<std::string> reversed_word;
        for(int i = word.size() - 1; i >= 0; i--)
        {
            reversed_word.push_back(word[i]);
        }
        std::vector<std::vector<int>> lcs, paths;
        LongestCommonSequence(word, reversed_word, lcs, paths);
        return DisplayLCS(lcs, paths, word);
    }

    float BitonicWay(std::vector<std::pair<int, int>> input_points)
    {
        int n_points = input_points.size();
        float path = 10;
        if(n_points < 4)
        {
            //
        }
        else
        {
            std::map<int, BitonicNode> cost;
            float path_value = distanceTwoPoints(input_points[0], input_points[1]) + distanceTwoPoints(input_points[2], input_points[1]);
            float cost_value = path_value + distanceTwoPoints(input_points[n_points - 1], input_points[2]) + distanceTwoPoints(input_points[n_points - 1], input_points[0]);
            cost[0] = {2, path_value, cost_value};
            path_value = distanceTwoPoints(input_points[0], input_points[1]) + distanceTwoPoints(input_points[2], input_points[0]);
            cost_value = path_value + distanceTwoPoints(input_points[n_points - 1], input_points[2]) + distanceTwoPoints(input_points[n_points - 1], input_points[1]);
            cost[2] = {1, path_value, cost_value};
            for(int i = 3; i < n_points - 1; i++)
            {
                float cost_i = 100000;
                int tail_i = -1;
                float path_i = 1000;
                for(int j = 0; j < i; j++)
                {
                    if(j != 1)
                    {
                        float path_i_ = cost[j].path + distanceTwoPoints(input_points[i], input_points[j]);
                        int tail_i_ = cost[j].tail;
                        float cost_i_ = path_i_ + distanceTwoPoints(input_points[n_points - 1], input_points[tail_i_]) + distanceTwoPoints(input_points[n_points - 1], input_points[i]);
                        if(j != i - 1)
                        {
                            path_i_ += distanceTwoPoints(input_points[cost[j].tail], input_points[i - 1]);
                            cost_i_ = path_i_ + distanceTwoPoints(input_points[n_points - 1], input_points[i - 1]) + distanceTwoPoints(input_points[n_points - 1], input_points[i]);
                            tail_i_ = i - 1;
                        }
                        if(cost_i_ < cost_i)
                        {
                            cost_i = cost_i_;
                            tail_i = tail_i_;
                            path_i = path_i_;
                        }
                        cost[j].path += distanceTwoPoints(input_points[i], input_points[cost[j].tail]);
                        cost[j].cost_value = distanceTwoPoints(input_points[n_points - 1], input_points[i]) + distanceTwoPoints(input_points[n_points - 1], input_points[j]);
                        cost[j].tail = i;
                    }
                }
                cost[i] = {tail_i, path_i, cost_i};
            }
            float minimal_path = 10000;
            for (auto &[key, value]: cost)
            {
                float loop_closure = distanceTwoPoints(input_points[n_points - 1], input_points[cost[key].tail]) + distanceTwoPoints(input_points[n_points - 1], input_points[key]);
                float path_ = cost[key].path + loop_closure;
                if(path_ < minimal_path)
                {
                    minimal_path = path_;
                }
                cost[key] = {n_points - 1, path_, loop_closure};
            }
            path = minimal_path;
        }
        return path;
    }

}