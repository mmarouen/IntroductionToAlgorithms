#include "algorithms/chap14.hpp"
#include <stdexcept>

namespace chap14
{
    int CutRod(std::vector<int> prices, std::vector<int>& revenues, int n, std::vector<std::vector<int>>& pieces)
    {
        if(n == 0)
        {
            revenues[0] = 0;
            return 0;
        }
        if(n == 1)
        {
            revenues[1] = prices[0];
            pieces[0].push_back(1);
            return prices[0];
        }
        int revenue = -1;
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
                revenues[n] = revenue;
                std::vector<int> best_indices;
                if(i == 0)
                {
                    best_indices.push_back(n - i);
                }
                else
                {
                    best_indices = pieces[i - 1];
                    best_indices.push_back(n - i);
                }
                pieces[n - 1] = best_indices;
            }
        }
        return revenue;
    }

    int MemoizedCutRod(std::vector<int> prices, int max_cut_size, std::vector<std::vector<int>>& pieces)
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
        std::vector<int> revenues(n + 1, -1);
        pieces.resize(n, std::vector<int>(0));
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

    void LCS(std::vector<std::string> x_, std::vector<std::string> y_)
    {
        int m = x_.size() + 1;
        int n = y_.size() + 1;
        std::vector<std::vector<int>> lcs(m, std::vector<int>(n));

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(x_[i - 1] == y_[j - 1])
                {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                }
                else
                {
                    lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        std::cout << "printing lcs matrix" << std::endl;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                std::cout << lcs[i][j] << " ";
            }
            std::cout << std::endl;
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
        float path = 10000;
        std::string nodes_list_one_way;
        if(n_points < 4)
        {
            nodes_list_one_way = "0 - 1 - 2";
            std::cout << "nodes list one way " << nodes_list_one_way;
            path = distanceTwoPoints(input_points[0], input_points[1])
                 + distanceTwoPoints(input_points[2], input_points[1])
                 + distanceTwoPoints(input_points[2], input_points[0]);
                 return path;
        }
        std::pair<int, int> endpoint = input_points.back();   
        std::pair<int, int> rootpoint = input_points[0];   
        std::vector<int> one_way_path{0, 1};
        int left_endpoint = 2;
        int right_endpoint = 1;
        path = distanceTwoPoints(input_points[0], input_points[1]) + distanceTwoPoints(input_points[0], input_points[2]);
        // 2 leftmost points belong to the path
        // additionally, the 3rd leftmost point belongs to the return way
        // we also know that the last point and the one before it belongs to the path
        // this means we can start searching from the 4th point onwards till the before last point
        for(int i = 3; i < n_points - 2; i++)
        {
            if(i <= right_endpoint)
            {
                continue;
            }
            std::pair<int, int> current_endpoint = input_points[right_endpoint];
            std::pair<int, int> current_l_endpoint = input_points[left_endpoint];
            float current_cost = 1000;
            int next_right_endpoint = -1;
            int next_left_endpoint = -1;
            for(int j = i; j < n_points - 1; j++)
            {
                int j_left_endpoint = left_endpoint;
                if(j > right_endpoint + 1 && j - 1 != left_endpoint)
                {
                    j_left_endpoint = j - 1;
                }
                float cost_j = path + distanceTwoPoints(input_points[j], current_endpoint);
                cost_j += distanceTwoPoints(input_points[j_left_endpoint], current_l_endpoint);
                cost_j += distanceTwoPoints(input_points[j], endpoint) + distanceTwoPoints(input_points[j_left_endpoint], endpoint);
                if(cost_j < current_cost)
                {
                    next_right_endpoint = j;
                    current_cost = cost_j;
                    next_left_endpoint = j_left_endpoint;
                }
            }
            left_endpoint = next_left_endpoint;
            right_endpoint = next_right_endpoint;
            one_way_path.push_back(next_right_endpoint);
            path += distanceTwoPoints(current_endpoint, input_points[right_endpoint]);
            path += distanceTwoPoints(current_l_endpoint, input_points[left_endpoint]);
        }
        one_way_path.push_back(n_points - 1);
        path += distanceTwoPoints(input_points[one_way_path.back()], endpoint);
        std::cout << "display the one way path " << std::endl;
        for(int i = 0; i < one_way_path.size(); i++)
        {
            std::pair<int, int> current_pt = input_points[one_way_path[i]];
            std::cout << one_way_path[i] << ": (" << current_pt.first << ", " << current_pt.second << ") --> ";
        }
        std::cout << std::endl;
        // compute total path
        path = 0;
        std::pair<int, int> left_end = input_points[0];
        std::pair<int, int> right_end = input_points[0];
        for(int i = 1; i < n_points; i++)
        {
            if(i == n_points - 1)
            {
                path += distanceTwoPoints(left_end, input_points[i]) + distanceTwoPoints(right_end, input_points[i]);
            }
            else if(std::find(one_way_path.begin(), one_way_path.end(), i) == one_way_path.end())
            {
                path += distanceTwoPoints(left_end, input_points[i]);
                left_end = input_points[i];
            }
            else
            {
                path += distanceTwoPoints(right_end, input_points[i]);
                right_end = input_points[i];
            }
        }
        return path;
    }

    bool findVertex(int& next_vertex_ind, Vertex* current_vertex, Graph* graph, float sound)
    {
        bool result = false;
        if(current_vertex->edge_value == sound)
        {
            next_vertex_ind = current_vertex->next->value;
            result = true;
        }
        else
        {
            Vertex* next_vertex = new Vertex;
            next_vertex = current_vertex->next;
            while(next_vertex)
            {
                if(next_vertex->edge_value == sound)
                {
                    result = true;
                    next_vertex_ind = next_vertex->next->value;
                    break;
                }
                else
                {
                    next_vertex = next_vertex->next;
                }
            }
        }
        return result;
    }

    std::vector<int> ViterbiPath(Graph* graph, int root_node, std::vector<float> sequence_sounds)
    {
        std::cout << "Vector to find:" << std::endl;
        for(float sound : sequence_sounds)
        {
            std::cout << sound << " ";
        }
        std::cout << std::endl;
        std::vector<int> queue;
        int i = 0;
        Vertex* current_vertex = graph->getVertex(root_node);
        float current_sound = sequence_sounds[i];
        int next_vertex_ind = -1;
        bool found_path = true;
        while(queue.size() < sequence_sounds.size())
        {
            bool res = findVertex(next_vertex_ind, current_vertex, graph, sequence_sounds[i]);
            if(res)
            {
                queue.push_back(current_vertex->value);
                current_vertex = graph->getVertex(next_vertex_ind);
                i += 1;
            }
            else
            {
                found_path = false;
                queue.clear();
                break;
            }
        }
        if(next_vertex_ind > -1 && found_path)
        {
            queue.push_back(next_vertex_ind);
        }
       return queue;
    }

}