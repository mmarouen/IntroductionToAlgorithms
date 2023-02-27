#include "../include/algorithms/chap12.hpp"
#include <stdexcept>

BinarySearchTree::BinarySearchTree()
{}

BinarySearchTree::~BinarySearchTree()
{
    std::cout << "destructor" << std::endl;
    delete root;
}

void BinarySearchTree::InsertLeaf(Node* node_ptr, int value)
{
    Node* node = new Node(value);
    while(!node->has_parent())
    {
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

void BinarySearchTree::Display(Node* node_ptr, std::string& msg, int depth)
{
    msg += std::to_string(node_ptr->value);
    int spacing = (depth + 1) * 3;
    int space = depth * 4;
    std::string child = "---";
    if(node_ptr->has_right())
    {
        msg += child;
        Display(node_ptr->right, msg, depth + 1);
    }
    if(node_ptr->has_left())
    {
        //msg += "\n|" + std::string(spacing, '-');
        msg += "\n" + std::string(space, ' ') + "|" + child;
        Display(node_ptr->left, msg, depth + 1);
    }
}

void BinarySearchTree::SearchTree(Node* current_node, Node* returned_node, int to_find)
{
    if(current_node == nullptr)
    {
        *returned_node = *empty_node_;
        return;
    }
    if(current_node->value == to_find)
    {
        *returned_node = *current_node;
        return;
    }
    if(to_find <= current_node->value)
    {
        SearchTree(current_node->left, returned_node, to_find);
    }
    else
    {
        SearchTree(current_node->right, returned_node, to_find);
    }
}

bool BinarySearchTree::Search(Node* returned_node, int to_find)
{
    SearchTree(root, returned_node, to_find);
    return returned_node->value != empty_node_->value;
}

void BinarySearchTree::FindMinimum(Node* current_node, Node* min_node, int min_val)
{
    if(current_node->left == nullptr)
    {
        *min_node = *current_node;
        return;
    }
    if(min_val > current_node->value)
    {
        FindMinimum(current_node->left, min_node, current_node->value);
    }
}

void BinarySearchTree::FindMaximum(Node* current_node, Node* max_node, int max_val)
{
    if(current_node->right == nullptr)
    {
        *max_node = *current_node;
        return;
    }
    if(max_val <= current_node->value)
    {
        FindMaximum(current_node->right, max_node, current_node->value);
    }
}

Node* BinarySearchTree::Maximum()
{
    Node* node = new Node;
    FindMaximum(root, node, root->value - 1);
    return node;
}

Node* BinarySearchTree::Minimum()
{
    Node* node = new Node;
    FindMinimum(root, node, root->value + 1);
    return node;
}

namespace chap12
{


    void FillupTree(BinarySearchTree* bst_ptr, std::vector<int> values, int depth)
    {
        if(bst_ptr->root == nullptr)
        {
            Node* node = new Node(values[0]);
            bst_ptr->root = node;
        }
        for(int i = 1; i < values.size(); i++)
        {
            bst_ptr->InsertLeaf(bst_ptr->root, values[i]);
        }
    }
}
