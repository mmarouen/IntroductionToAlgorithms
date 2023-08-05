#ifndef CHAP_20_H
#define CHAP_20_H
#include <cmath>
#include <vector> // for std::copy
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>

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
 * @brief vertex definition.
 * Below definition doesnt make use of the color attributes.
 * The implementation of BFS doesnt as well making it a lighter version of
 * the BFS algorithm.
 * 
 */
struct Vertex{
    int value;
    float distance=1000;
    float edge_value=-1;
    Vertex* next=nullptr;
    Vertex* pred=nullptr;
    std::string Print() const
    {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2)
               << "(value: " << value << ", dist: " << distance << ", edge: " << edge_value << ")";
        return stream.str();
    }
};

/**
 * @brief edge definition
 * 
 */
struct Edge{
    int first;
    int second;
    float weight=10;
};

class Graph
{
    public:
    bool is_directed_;
    std::vector<Vertex*> adjacency_list_;
    std::vector<int> vertices_;
    Graph(std::vector<Edge> edges_vector, std::vector<int> vertices, bool direction=false);
    inline int getIndex(int node_id) {return node_to_index_[node_id];};
    inline int getSize() const {return number_of_nodes_;};
    ~Graph();
    std::string PrintGraph();
    Vertex* getVertex(int node_id) const;
    private:
    int number_of_nodes_;
    std::map<int, int> node_to_index_;
    void setTailNode(int vertex_id, int tail_value, float weight);
};

namespace chap20
{
    

    /**
     * @brief color of the vertices throughout the BFS algorithm
     * 
     */
    enum SearchAlg {
        BFS=0,
        DFS=1
    };

    /**
     * @brief BFS implementation not using the color attribute and breaking as soon as all nodes are visited
     * 
     */
    class GraphSearch
    {
        public:
        GraphSearch(Graph* graph, int source_node, int search_alg=SearchAlg::BFS);
        void BreadthFirstSearch(Graph* graph, int source_node);
        void DepthFirstSearch(Graph* graph, int source_node);
        std::string PrintPath();
        private:
        std::vector<Vertex*> nodes_;
        int root_node_;
        std::set<int> visited_vertices_;
        int search_algorithm_;
    };

}
#endif