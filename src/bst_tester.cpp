#include <iostream>
#include <algorithms/chap12.hpp>

int main(int argc, char** argv)
{
    BinarySearchTree* bst = new BinarySearchTree;
    std::string bst_string = "";
    std::vector<int> values{5, 7, 1, 15, 9, 2, 14, 8, 7, 3};
    chap12::FillupTree(bst, values, 0);

    bst->Display(bst->root, bst_string, 0);
    std::cout << bst_string << std::endl;
    int value_to_find = 8;
    std::cout << "Search value " << value_to_find << " within the tree" << std::endl;
    Node* node = new Node;
    bool res = bst->Search(node, value_to_find);
    if(res)
    {
        std::cout << "Query found " << node->value << ", node parent " << node->parent->value << std::endl;
    }
    else
    {
        std::cout << "Query not found " << std::endl;
    }
    std::cout << "Tree minimum: " << bst->Minimum()->value << std::endl;
    std::cout << "Tree maximum: " << bst->Maximum()->value << std::endl;
	return 0;
}