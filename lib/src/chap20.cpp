#include "../include/algorithms/chap20.hpp"

Graph::Graph(std::vector<Edge> edges_vector, int number_of_nodes): graph_size_(number_of_nodes)
{
    for(int i = 0; i < number_of_nodes; i++)
    {
        Vertex* vertex = new Vertex;
        vertex->value = i + 1;
        adjacency_list_.push_back(vertex);
    }
    for(Edge edge : edges_vector)
    {
        setTailNode(edge.first, edge.second);
        setTailNode(edge.second, edge.first);
    }
}

Graph::~Graph()
{
    for(int i = 0; i < graph_size_; i++)
    {
        delete adjacency_list_[i];
    }
}

void Graph::setTailNode(int vertex_value, int tail_value)
{
    Vertex* vertex = adjacency_list_[vertex_value - 1];
    while(vertex->next != nullptr)
    {
        vertex = vertex->next;
    }
    Vertex* vertex_ = new Vertex;
    vertex_->value = tail_value;
    vertex->next = vertex_;
}

namespace chap20
{
    std::string PrintVertex(Vertex* vertex)
    {
        std::string msg;
        while(vertex->next)
        {
            msg += std::to_string(vertex->value) +" -> ";
            vertex = vertex->next;
        }
        msg += std::to_string(vertex->value);
        return msg;
    }
}