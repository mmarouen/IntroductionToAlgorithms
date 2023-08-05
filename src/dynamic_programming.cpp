#include <iostream>
#include <algorithms/chap14.hpp>

int main(int argc, char** argv)
{
    // cutrod problem
    std::cout << "######################" << std::endl;
    std::cout << "Cut Rod" << std::endl;
    std::vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int cut_size = 10;
    std::vector<std::vector<int>> pieces;
    try
    {
        int revenue_ = chap14::MemoizedCutRod(prices, cut_size, pieces);
        std::cout << "best cutrod for size " << cut_size << ": " << revenue_ << std::endl;
        std::cout << "first pieces to cut for each size:\n";
        for(int i = 0; i < pieces.size(); i++)
        {
            std::cout << "--n = " << i + 1 << ": ";
            for(int j = 0; j < pieces[i].size(); j++)
            {
                std::cout << pieces[i][j] << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // longest common sequence

    std::cout << "######################" << std::endl;
    std::cout << "Longest common sequence" << std::endl;
    std::vector<std::string> sequence_x{"A", "B", "C", "B", "D", "A", "B"};
    std::vector<std::string> sequence_y{"B", "D", "C", "A", "B", "A"};
    std::vector<std::vector<int>> lcs, paths;
    chap14::LCS(sequence_x, sequence_y);
    try
    {
        chap14::LongestCommonSequence(sequence_x, sequence_y, lcs, paths);
        std::cout << "longest sequence " << lcs[sequence_x.size()][sequence_y.size()] << std::endl;
        std::vector<std::string> lcs_sequence = chap14::DisplayLCS(lcs, paths, sequence_x);
        std::cout << "lcs sequence length " << lcs_sequence.size() << std::endl;
        for(std::string s : lcs_sequence)
        {
            std::cout << s << ", ";
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	return 0;
}