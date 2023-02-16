#include <iostream>
#include <iomanip>
#include <map>
#include "algorithms/chap20.hpp"

int main(int argc, char** argv)
{
    // producing graph depicted in fig 20.1
    int vertices = 5;
    std::vector<Edge> edges_vector{
        {1,2}, {1,5}, {2,5}, {2,4}, {2,3}
    };
    Graph graph(edges_vector, vertices);
    std::cout << "printing graph\n";    
    for (int i = 0; i < vertices; i++)
    {
        std::cout << chap20::PrintVertex(graph.adjacency_list_[i]) << std::endl;
    }
    return 0;
}