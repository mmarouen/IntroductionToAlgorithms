#include <iostream>
#include <random>
#include <iomanip>
#include "algorithms/chap2.hpp"

int main(int argc, char** argv)
{
    bool merge_only = false;
    bool insertion_sort = true;
    bool merge_sort = false;
    bool all = false;
    std::vector<std::string> all_args;
    std::string msg = "Usage: ./sorter [merge | insertion_sort | merge_sort | -help | --h | help]";
    msg += "\n- insertion_sort         (default setup) runs the insertion sort algorithm on a predefined vector";
    msg += "\n- merge_sort             runs the merge sort algorithm on a predefined vector";
    msg += "\n- merge                  runs the merge algorithm on a predefined vector";
    msg += "\n- all                    runs insertion sort and merge sort on a randomly generated vector and times execution for each";
    msg += "\n- help | --h | -help     displays this message";
    if (argc > 1)
    {
        all_args.assign(argv + 1, argv + argc);
        merge_only = all_args[0] == "merge";
        insertion_sort = all_args[0] == "insertion_sort";
        merge_sort = all_args[0] == "merge_sort";
        all = all_args[0] == "all";
    }
    if(insertion_sort)
    {
        std::vector<float> input_vec{100, 65, 34, 12, 9, -3};
        std::vector<float> left, right;
        int split_ind = 2;
        left.insert(left.begin(), input_vec.begin(), input_vec.begin() + split_ind);
        right.insert(right.begin(), input_vec.begin() + split_ind, input_vec.begin() + input_vec.size());
        std::cout << "left " << chap2::DisplayVector(left, left.size()) << std::endl;
        std::cout << "right " << chap2::DisplayVector(right, right.size()) << std::endl;
        try
        {
            std::cout << "display unsorted vector " << chap2::DisplayVector(input_vec, input_vec.size()) << std::endl;
            chap2::InsertionSort(input_vec);
            std::cout << "display sorted vector " << chap2::DisplayVector(input_vec, input_vec.size()) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else if(merge_only)
    {
        std::vector<float> input_vec{45, 67, 80, 110, -5, 50, 200};
        std::cout << "display unsorted vector " << chap2::DisplayVector(input_vec, input_vec.size()) << std::endl;
        chap2::Merge(input_vec, 0, 4, 7);
        std::cout << "display sorted vector " << chap2::DisplayVector(input_vec, input_vec.size()) << std::endl;
    }
    else if(merge_sort)
    {
        std::vector<float> input_vec{45, 31, 67, 80, -65, 110, -5, 50, 200};
        std::cout << "display unsorted vector " << chap2::DisplayVector(input_vec, input_vec.size()) << std::endl;
        chap2::MergeSort(input_vec, 0, 7);
        std::cout << "display sorted vector " << chap2::DisplayVector(input_vec, input_vec.size()) << std::endl;
    }
    else if(all)
    {
        std::vector<float> input_vec;
        int vec_size = 10000;
        for(int i = 0; i < vec_size; i++)
        {
            float rand = std::rand() % 1000000;
            input_vec.push_back(rand);
        }
        std::vector<float> first_vector, second_vector;
        first_vector = input_vec;
        second_vector = input_vec;
        std::string msg = "- Insertion sort:\n";
        clock_t begin_time = clock();
        chap2::InsertionSort(first_vector);
        msg += "-runtime " + std::to_string(float(clock() - begin_time) / CLOCKS_PER_SEC) +  "s\n";
        msg += "- Merge sort:\n";
        begin_time = clock();
        chap2::MergeSort(second_vector, 0, vec_size);
        msg += "-runtime " + std::to_string(float(clock() - begin_time) / CLOCKS_PER_SEC) +  "s";
        std::cout << std::setprecision(0);
        std::cout << msg << std::endl;
    }
    else
    {
        std::cout << msg << std::endl;
    }
	return 0;
}