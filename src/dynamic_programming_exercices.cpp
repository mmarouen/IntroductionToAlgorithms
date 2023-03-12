#include <iostream>
#include <algorithms/chap14.hpp>

int main(int argc, char** argv)
{
    /**
     * @brief exercice 14.1: longest palindrome in a given word
     * a list of words is provided and tested in sequence
     * 
     */
    std::cout << "##################################################" << std::endl;
    std::cout << "##### Longest palindrome problem ######" << std::endl;
    std::vector<std::vector<std::string>> list_of_words;
    std::vector<std::string> word_1{"T", "H", "E", "A", "T", "E", "R"};
    std::vector<std::string> word_2{"C", "I", "V", "I", "C"};
    std::vector<std::string> word_3{"R", "A", "C", "E", "C", "A", "R"};
    std::vector<std::string> word_4{"C", "H", "A", "R", "A", "C", "T", "E", "R"};
    list_of_words.push_back(word_1);
    list_of_words.push_back(word_2);
    list_of_words.push_back(word_3);
    list_of_words.push_back(word_4);
    for(std::vector<std::string> word : list_of_words)
    {
        std::vector<std::string> longest_palendrome = chap14::LongestPalendromeSequence(word);
        std::cout << "Longest palindrome in ";
        for(std::string s : word)
        {
            std::cout << s;
        }
        std::cout << ":" << std::endl;
        for(std::string s : longest_palendrome)
        {
            std::cout << s << ", ";
        }
        std::cout << std::endl;
    }

    /**
     * @brief exercice 14.2: shortest bitonic tour
     * We assume that the given points:
     * - have integer coordinates
     * - are sorted in increasing order w.r.t. x-axis
     */
    std::cout << std::endl;
    std::cout << "##################################################" << std::endl;
    std::cout << "##### Bitonic path problem ######" << std::endl;
    std::vector<std::pair<int, int>> list_of_points{{-2, 3}, {-1, -3}, {0, 0}, {3, 1}, {4, -2}, {5, 2}, {6, -1}};
    std::cout << "shrotest path " << chap14::BitonicWay(list_of_points) << std::endl;

	return 0;
}
