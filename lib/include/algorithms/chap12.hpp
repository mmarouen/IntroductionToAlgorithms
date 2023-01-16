#ifndef CHAP_12_H
#define CHAP_12_H
#include <cmath>
#include "chap2.hpp"

struct Node{
    int value;
    Node* left=nullptr;
    Node* right=nullptr;
    Node* parent=nullptr;
    Node(int value_) : value(value_)
    {}
    bool has_left(){return left != nullptr;};
    bool has_right(){return right != nullptr;};
    bool has_parent(){return parent != nullptr;};
    std::string state()
    {
        std::string msg = "value " + std::to_string(value) + " left leaf: ";
        if(has_left())
        {
            msg += std::to_string(left->value);
        }
        else
        {
            msg += "None";
        }
        msg += " right leaf: ";
        if(has_right())
        {
            msg += std::to_string(right->value);
        }
        else
        {
            msg += "None";
        }
        return msg;
    }
};

struct BinarySearchTree
{
    Node* root=nullptr;
};

namespace chap12
{

    /**
     * @brief creates a binary tree given a vector of ints and depth
     * 
     * @param bst_ptr pointer binary search tree to be filled
     * @param values input values vector
     * @param depth depth of the tree
     */
    void FillupTree(BinarySearchTree* bst_ptr, std::vector<int> values, int depth);

    /**
     * @brief recursively inserts a leaf into the tree starting from root position by respecting the 
     * binary search tree property
     * 
     * @param node_ptr a node belonging to the tree
     * @param value node value to be inserted
     */
    void InsertLeaf(Node* node_ptr, int value);

    /**
     * @brief prints the content of a binary tree in a tring 
     * 
     * @param node_ptr node to print belonging to the tree
     * @param msg tree structure to fillup
     * @param depth representation of the current tree depth to compute spacing
     */
    void DisplayTree(Node* node_ptr, std::string& msg, int depth);
}

#endif