#include "../include/algorithms/chap20.hpp"

Graph::Graph(std::vector<Edge> edges_vector, std::vector<int> vertices, bool direction):
    vertices_(vertices), is_directed_(direction)
{
    number_of_nodes_ = vertices_.size();
    for(int i = 0; i < number_of_nodes_; i++)
    {
        node_to_index_[vertices_[i]] = i;
    }
    for(int node : vertices_)
    {
        Vertex* vertex = new Vertex;
        vertex->value = node;
        adjacency_list_.push_back(vertex);
    }
    for(Edge edge : edges_vector)
    {
        setTailNode(edge.first, edge.second);
        if(!is_directed_)
        {
            setTailNode(edge.second, edge.first);
        }
    }
}

Graph::~Graph()
{
    for(Vertex* vertex : adjacency_list_)
    {
        delete vertex;
    }
    adjacency_list_.clear();
}

void Graph::setTailNode(int vertex_value, int tail_value)
{
    Vertex* vertex = adjacency_list_[node_to_index_[vertex_value]];
    while(vertex->next != nullptr)
    {
        vertex = vertex->next;
    }
    Vertex* vertex_ = new Vertex;
    vertex_->value = tail_value;
    vertex->next = vertex_;
}

std::string Graph::PrintGraph()
{
    std::string msg = "printing graph:\n";
    for(const Vertex* vertex: adjacency_list_)
    {
        while(vertex->next)
        {
            msg += vertex->Print() + " -> ";
            vertex = vertex->next;
        }
        msg += vertex->Print() + "/\n";
    }
    return msg;
}

namespace chap20
{

    GraphSearch::GraphSearch(Graph* graph, int root_node, int search_algorithm): root_node_(root_node), search_algorithm_(search_algorithm)
    {
        if(search_algorithm == SearchAlg::BFS)
        {
            BreadthFirstSearch(graph, root_node);
        }
        else if(search_algorithm == SearchAlg::DFS)
        {
            DepthFirstSearch(graph, root_node);
        }
    }

    void GraphSearch::BreadthFirstSearch(Graph* graph, int root_node)
    {
        Vertex* vertex = graph->adjacency_list_[graph->getIndex(root_node)];
        vertex->distance = 0;
        std::vector<int> queue;
        queue.push_back(root_node);
        visited_vertices_.insert(root_node);
        while(visited_vertices_.size() < graph->getSize())
        {
            std::vector<int> queue_tmp;
            for(int parent_index : queue)
            {
                Vertex* parent_vertex = graph->adjacency_list_[graph->getIndex(parent_index)];
                Vertex* current_vertex = parent_vertex->next;
                while(current_vertex)
                {
                    int current_index = current_vertex->value;
                    if(visited_vertices_.find(current_index) == visited_vertices_.end())
                    {
                        Vertex* current_vertex_ = graph->adjacency_list_[graph->getIndex(current_index)];
                        current_vertex_->distance = parent_vertex->distance + 1;
                        current_vertex_->pred = parent_vertex;
                        queue_tmp.push_back(current_index);
                        visited_vertices_.insert(current_index);
                    }
                    current_vertex = current_vertex->next;
                }
                if(visited_vertices_.size() == graph->getSize())
                {
                    break;
                }
            }
            queue = queue_tmp;
        }
        nodes_ = graph->adjacency_list_;
    }

    std::string GraphSearch::PrintPath()
    {
        std::string msg;
        if(search_algorithm_ == SearchAlg::BFS)
        {
            msg += "BFS Algorithm path search results (nodes distance from source):\n";
        }
        else if(search_algorithm_ == SearchAlg::DFS)
        {
            msg += "DFS Algorithm path search results (nodes distance from source):\n";
        }
        for(Vertex* vertex : nodes_)
        {
            if(vertex->value == root_node_)
            {
                msg += "(root node) "; 
            }
            msg += vertex->Print() + "\n";
        }
        return msg;
    }

    void GraphSearch::DepthFirstSearch(Graph* graph, int root_node)
    {
        Vertex* parent_vertex = graph->adjacency_list_[graph->getIndex(root_node)];
        parent_vertex->distance = 0;
        visited_vertices_.insert(root_node);
        // init queue of depths to go through
        std::vector<int> queue;
        Vertex* current_vertex = parent_vertex->next;
        while(current_vertex)
        {
            queue.push_back(current_vertex->value);
            current_vertex = current_vertex->next;
        }
        for(int node : queue)
        {
            current_vertex = graph->adjacency_list_[graph->getIndex(node)];
            parent_vertex = graph->adjacency_list_[graph->getIndex(root_node)];
            while(true)
            {
                int current_index = current_vertex->value;
                if(visited_vertices_.find(current_index) == visited_vertices_.end())
                {
                    current_vertex->distance = parent_vertex->distance + 1;
                    current_vertex->pred = parent_vertex;
                    visited_vertices_.insert(current_index);
                }
                else if(current_vertex->next)
                {
                    current_vertex = current_vertex->next;
                    continue;
                }
                if(!current_vertex->next)
                {
                    break;
                }
                parent_vertex = graph->adjacency_list_[graph->getIndex(current_index)];
                if(!parent_vertex->next)
                {
                    break;
                }
                current_vertex = parent_vertex->next;
                if(visited_vertices_.size() == graph->getSize())
                {
                    break;
                }
            }
            if(visited_vertices_.size() == graph->getSize())
            {
                break;
            }
        }
        nodes_ = graph->adjacency_list_;
    }
}