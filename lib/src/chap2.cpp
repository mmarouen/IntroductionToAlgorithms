#include "../include/algorithms/chap2.hpp"
#include <stdexcept>
#include <iomanip>
#include <sstream>

namespace chap2
{

    std::string DisplayVector(std::vector<float> vec, int max_index)
    {
        std::string msg;
        std::stringstream stream;
        for(int j = 0; j < max_index; j++)
        {
            stream << std::fixed << std::setprecision(2) << vec[j];
            msg += stream.str() + " ";
            stream.str("");
        }
        return msg;
    }

    void InsertionSort(std::vector<float>& values_)
    {
        int n = values_.size();
        if(n == 0)
        {
            throw(std::runtime_error("Vector is empty"));
        }
        if(n > 1)
        {
            for(int i = 1; i < n; i++)
            {
                float val = values_[i];
                for(int j = i - 1; j >= 0; j--)
                {
                    if(values_[j] < val)
                    {
                        values_[j + 1] = val;
                        break;
                    }
                    values_[j + 1] = values_[j];
                    if(j == 0)
                    {
                        values_[0] = val;
                        break;
                    }
                }
            }
        }
    }

    void Merge(std::vector<float>& values_list, int begin, int mid, int end)
    {
        std::vector<float> left;
        left.insert(left.begin(), values_list.begin() + begin, values_list.begin() + mid);
        std::vector<float> right;
        right.insert(right.begin(), values_list.begin() + mid, values_list.begin() + end);
        std::vector<float> merged;
        std::vector<float> base(left.begin(), left.end());
        std::vector<float> competing(right.begin(), right.end());
        if(right.size() < left.size())
        {
            base = right;
            competing = left;
        }
        for(int i = 0; i < base.size(); i++)
        {
            float val = base[i];
            bool interrupted = false;
            while(competing.size() > 0)
            {
                if(competing[0] > val)
                {
                    interrupted = true;
                    merged.push_back(val);
                    break;
                }
                merged.push_back(competing[0]);
                competing.erase(competing.begin());
            }
            if(!interrupted)
            {
                merged.push_back(val);
            }
        }
        merged.insert(merged.end(), competing.begin(), competing.end());
        std::copy(merged.begin(), merged.end(), values_list.begin() + begin);
    }

    void MergeSort(std::vector<float>& values_list, int begin, int end)
    {
        if(begin >= end)
        {
            return;
        }
        int mid = (begin + end) / 2;
        MergeSort(values_list, begin, mid);
        if(mid == begin)
        {
            MergeSort(values_list, mid + 1, end);
        }
        else
        {
            MergeSort(values_list, mid, end);
        }
        Merge(values_list, begin, mid, end);
    }
}