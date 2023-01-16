#include "../include/algorithms/chap12.hpp"
#include <stdexcept>

namespace chap12
{

    void InsertLeaf(Node* node_ptr, int value)
    {
        Node* node = new Node(value);
        while(!node->has_parent())
        {
            //std::string msg = "value " + std::to_string(value) + " current node " + node_ptr->state();
            //std::cout << msg << std::endl;
            if(node_ptr->value > value && node_ptr->has_left())
            {
                InsertLeaf(node_ptr->left, value);
            }
            else if(node_ptr->value > value && !node_ptr->has_left())
            {
                node->parent = node_ptr;
                node_ptr->left = node;
            }
            else if(node_ptr->value <= value && node_ptr->has_right())
            {
                InsertLeaf(node_ptr->right, value);
            }
            else
            {
                node->parent = node_ptr;
                node_ptr->right = node;
            }
            return;
        }
    }

    void FillupTree(BinarySearchTree* bst_ptr, std::vector<int> values, int depth)
    {
        if(bst_ptr->root == nullptr)
        {
            Node* node = new Node(values[0]);
            bst_ptr->root = node;
        }
        for(int i = 1; i < values.size(); i++)
        {
            InsertLeaf(bst_ptr->root, values[i]);
        }
    }

    void DisplayTree(Node* node_ptr, std::string& msg, int depth)
    {
        msg += std::to_string(node_ptr->value);
        int spacing = (depth + 1) * 3;
        int space = depth * 4;
        std::string child = "---";
        if(node_ptr->has_right())
        {
            msg += child;
            DisplayTree(node_ptr->right, msg, depth + 1);
        }
        if(node_ptr->has_left())
        {
            //msg += "\n|" + std::string(spacing, '-');
            msg += "\n" + std::string(space, ' ') + "|" + child;
            DisplayTree(node_ptr->left, msg, depth + 1);
        }
    }
}
