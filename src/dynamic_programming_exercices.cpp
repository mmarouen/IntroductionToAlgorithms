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
    std::cout << "##### Exercice 14.1 Longest palindrome problem ######" << std::endl;
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
    std::cout << "##### Exercice 14.2 Bitonic path problem ######" << std::endl;
    std::vector<std::pair<int, int>> list_of_points{{-2, 3}, {-1, -3}, {0, 0}, {3, 1}, {4, -2}, {5, 2}, {6, -1}};
    float path = chap14::BitonicWay(list_of_points);
    std::cout << "Shrotest bitonic path " << path << std::endl;

    /**
     * @brief exercice 14.7a Viterbi algorithm based on the graph produced in figure 20.2
     * 
     */
    std::cout << std::endl;
    std::cout << "##################################################" << std::endl;
    std::cout << "##### Exercice 14.7 Viterbi algorithm Exercice 14.7-a ######" << std::endl;
    int n_nodes = 6;
    int n_edges = 8;
    std::vector<int> vertices(n_nodes);
    std::iota(std::begin(vertices), std::end(vertices), 1);
    std::vector<float> sounds(n_edges);
    for(int i = 0; i < n_edges; i++)
    {
        sounds[i] = (float)(rand() % 1000);
    }
    std::cout << "Printing sounds:" << std::endl;
    for(float sound : sounds)
    {
        std::cout << sound << " ";
    }
    std::cout << std::endl;
    std::vector<Edge> edges_vector{
        {1, 2, sounds[0]}, {1, 4, sounds[1]}, {2, 5, sounds[2]},
        {3, 6, sounds[3]}, {3, 5, sounds[4]}, {4, 2, sounds[5]},
        {5, 4, sounds[6]}, {6, 6, sounds[7]}
    };
    Graph graph(edges_vector, vertices, true);
    std::cout << graph.PrintGraph(); // check graph in accordance with plot
    int root_node = 1;
    std::cout << "##### Existing path ######" << std::endl;
    std::vector<float> existing_path{sounds[0], sounds[2], sounds[6]};
    std::cout << chap14::PrintPath(chap14::ViterbiPath(&graph, root_node, existing_path));
    std::cout << "##### None existing path ######" << std::endl;
    std::vector<float> non_existing_path{sounds[0], sounds[2], sounds[6] + 1};
    std::cout << chap14::PrintPath(chap14::ViterbiPath(&graph, root_node, non_existing_path));

    /**
     * @brief exercice 14.7b Viterbi algorithm based on the graph produced in figure 20.2
     * 
     */
    std::cout << std::endl;
    std::cout << "##################################################" << std::endl;
    std::cout << "##### Viterbi algorithm Exercice 14.7-a ######" << std::endl;

    /**
     * @brief exercice 14.10 Planning an investment strategy
     * 
     */
    std::cout << std::endl;
    std::cout << "##################################################" << std::endl;
    std::cout << "##### Exercice 14.10 Planning an investment strategy ######" << std::endl;
    std::cout << "Please check chap14 solutions pdf file"

	return 0;
}
