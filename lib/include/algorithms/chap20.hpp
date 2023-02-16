#ifndef CHAP_20_H
#define CHAP_20_H
#include <cmath>
#include <vector> // for std::copy
#include <string>
#include <iostream>

/**
 * @brief color of the vertices throughout the BFS algorithm
 * 
 */
enum Color {
    kWhite=0,
    kGray=1,
    kBlack=2
};

/**
 * @brief vertex definition
 * 
 */
struct Vertex{
    int value;
    Color color=kBlack;
    float distance=1000;
    Vertex* next=nullptr;
};

/**
 * @brief edge definition
 * 
 */
typedef std::pair<int, int> Edge;

class Graph
{
    public:
    int root_node_;
    std::vector<Vertex*> adjacency_list_;
    int graph_size_;
    Graph(std::vector<Edge> edges_vector, int number_of_nodes);
    ~Graph();
    private:
    void setTailNode(int vertex_id, int tail_value);
};

/*
struct Graph{
    int root;
    std::vector<Vertex> adjancency_list;
};
*/
namespace chap20
{
    std::string PrintGraph(Graph graph);
    std::string PrintVertex(Vertex* vertex);
}
#endif