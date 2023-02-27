#include <iostream>
#include <algorithms/chap14.hpp>

int main(int argc, char** argv)
{
    // cutrod problem
    std::vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int cut_size = 10;
    std::vector<int> pieces;
    try
    {
        int revenue_ = chap14::MemoizedCutRod(prices, cut_size, pieces);
        std::cout << "best cutrod for size " << cut_size << ": " << revenue_ << std::endl;
        std::cout << "first pieces to cut for each size:\n";
        for(int i = 0; i < pieces.size(); i++)
        {
            std::cout << pieces[i] << ", ";
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // longest common sequence
    std::vector<std::string> sequence_x{"A", "B", "C", "B", "D", "A", "B"};
    std::vector<std::string> sequence_y{"B", "D", "C", "A", "B", "A"};
    std::vector<std::vector<int>> lcs;
    try
    {
        chap14::LongestCommonSequence(sequence_x, sequence_y, lcs);
        std::cout << "longest sequence " << lcs[sequence_x.size()][sequence_y.size()] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
	return 0;
}