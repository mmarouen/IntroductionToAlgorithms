#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include "algorithms/chap20.hpp"

int main(int argc, char** argv)
{
    // producing graph depicted in fig 20.1
    std::vector<int> vertices(5);
    std::iota(std::begin(vertices), std::end(vertices), 1);
    int root_node = 5;
    std::vector<Edge> edges_vector{
        {1, 2}, {1, 5}, {2, 5}, {2, 4}, {2, 3},
        {4, 5}, {4, 3}
    };
    Graph graph(edges_vector, vertices);
    std::string msg = chap20::PrintGraph(&graph);
    std::cout << msg << std::endl;
    chap20::BreadthFirstSearch bfs(&graph, root_node);
    std::cout << bfs.PrintPath() << std::endl;
    return 0;
}