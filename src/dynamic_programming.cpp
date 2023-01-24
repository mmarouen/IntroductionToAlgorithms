#include <iostream>
#include <algorithms/chap14.hpp>

int main(int argc, char** argv)
{
    std::vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    clock_t begin_time = clock();
    int revenue = chap14::CutRod(prices, 10);
    std::cout << "max revenue (recursive) " << revenue << " runtime " << float(clock() - begin_time) / CLOCKS_PER_SEC << "s" << std::endl;
    begin_time = clock();
    int revenue_ = chap14::MemoizedCutRod(prices, 10);
    std::cout << "max revenue (memoized) " << revenue_ << " runtime " << float(clock() - begin_time) / CLOCKS_PER_SEC << "s" << std::endl;
	return 0;
}