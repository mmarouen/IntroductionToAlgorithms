#include <iostream>
#include <algorithms/chap12.hpp>

int main(int argc, char** argv)
{
    BinarySearchTree bst;
    std::string bst_string = "";
    std::vector<int> values{5, 7, 1, 15, 9, 2, 14, 8, 7, 3};
    chap12::FillupTree(&bst, values, 0);

    chap12::DisplayTree(bst.root, bst_string, 0);
    std::cout << bst_string << std::endl;
	return 0;
}