#include "../include/algorithms/chap15.hpp"

namespace chap15
{

    std::vector<int> ActivitySelectionDP(std::vector<Activity> activities)
    {
        std::vector<int> optimal_activities_index{1};
        int current_f = activities[0].f;
        for(int i = 1; i < activities.size(); i++)
        {
            if(activities[i].s >= current_f)
            {
                optimal_activities_index.push_back(i + 1);
                current_f = activities[i].f;
            }
        }
        return optimal_activities_index;
    }

    Sack KnapsackProblemAux(int n, std::vector<int>& values, std::vector<Item> items)
    {
        Sack sack;
        if(n == 0)
        {
            int value = 0;
            int index = -1;
            Item item_;
            for(int i = 0; i < items.size(); i++)
            {
                Item item = items[i];
                if(item.weight > 1)
                {
                    break;
                }
                if(item.value > value)
                {
                    value = item.value;
                    index = i;
                    item_ = item;
                }
            }
            sack.value = value;
            sack.weight = 1;
            if(value > 0)
            {
                sack.items.push_back(item_);
            }
            values[0] = value;
            return sack;
        }
        int value_n = 0;
        int n_items = items.size();
        int value_n_i = 0;
        int n_i = -1;
        std::vector<Item> items_vector;
        for(int i = 0; i < n; i++)
        {
            int value_n_tmp = 0;
            std::vector<Item> selected_items;
            if(values[i] < 0)
            {
                Sack previous_sack = KnapsackProblemAux(i, values, items);
                selected_items = previous_sack.items;
                value_n_tmp = previous_sack.value;
            }
            else
            {
                value_n_tmp = values[i];
            }
            int value_n_i_tmp = 0;
            int n_i_tmp = -1;
            int j = n_items - 1;
            while(items[j].weight >= n - i)
            {
                auto it = std::find_if(
                    selected_items.begin(),
                    selected_items.end(),
                    [&](const Item& item__){return item__ == items[j];});
                bool not_used_item = it == selected_items.end();
                if(items[j].weight == n - i && items[j].value > value_n_i && not_used_item)
                {
                    value_n_i_tmp = items[j].value;
                    n_i_tmp = j;
                }
                j -= 1;
            }
            value_n_tmp += value_n_i_tmp;
            if(value_n_tmp > value_n)
            {
                value_n = value_n_tmp;
                if(n_i_tmp >= 0)
                {
                    value_n_i = value_n_i_tmp;
                    n_i = n_i_tmp;
                }
            }
        }
        if(n_i > 0)
        {
            items_vector.push_back(items[n_i]);
        }
        sack.value = value_n;
        sack.weight = n;
        sack.items = items_vector;
        values[n] = value_n;
        return sack;
    }

    std::vector<Item> KnapsackProblem01(std::vector<Item> items, int total_weight)
    {
        std::vector<int> values(total_weight + 1, -1);
        KnapsackProblemAux(total_weight, values, items);
        std::cout << "Optimal values for each weight:\n";
        for(int i = 0; i < values.size(); i++)
        {
            if(i % 10 == 0)
            {
                std::cout << "weight " << i << ", value " << values[i] << std::endl;
            }
        }
        return items;
    }

}