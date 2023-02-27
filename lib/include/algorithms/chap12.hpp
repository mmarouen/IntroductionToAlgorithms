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
    Node()
    {
        value = -1000;
    }
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

class BinarySearchTree
{
    public:
    /**
     * @brief Construct a new Binary Search Tree object
     * 
     */
    BinarySearchTree();

    /**
     * @brief Destroy the Binary Search Tree object
     * 
     */
    ~BinarySearchTree();

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
    void Display(Node* node_ptr, std::string& msg, int depth);

    /**
     * @brief finds a node with the node containing the searched value
     * 
     * @param returned_node node containing the searched value if any
     * @param to_find value to search for
     * @return true
     * @return false 
     */
    bool Search(Node* returned_node, int to_find);

    /**
     * @brief retrieves the node with minimum value
     * 
     * @return Node* 
     */
    Node* Minimum();

    /**
     * @brief retrieves the node with minimum value
     * 
     * @return Node* 
     */
    Node* Maximum();

    Node* root=nullptr; /// root node

    private:
    /**
     * @brief walks through the tree recursively to find the queried value
     * 
     * @param current current parent node
     * @param to_find value to look for
     * @return None 
     */
    void SearchTree(Node* current, Node* result_node, int to_find);

    /**
     * @brief utility to find the minimum node on the tree given
     * 
     * @param current 
     * @param minimum_value 
     * @return Node* 
     */
    void FindMinimum(Node* current, Node* min_node, int minimum_value);

    /**
     * @brief utility to find the maximum node on the tree given
     * 
     * @param current 
     * @param min_node 
     * @param minimum_value 
     */
    void FindMaximum(Node* current, Node* min_node, int minimum_value);
    Node* empty_node_ = new Node(-1000);
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

}

#endif