#include <iostream>
#include <algorithms/chap10.hpp>

int main(int argc, char** argv)
{
    std::vector<float> values{10.0, 11, 23, 9};
    LinkedList list = chap10::FillupList(values);
    std::cout << chap10::DisplayLists(list) << std::endl;
	return 0;
}