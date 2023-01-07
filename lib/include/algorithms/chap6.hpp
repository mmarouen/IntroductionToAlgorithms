#ifndef CHAP_6_H
#define CHAP_6_H
#include <cmath>
#include "chap2.hpp"

struct Heap {
    int heap_size=0;
    std::vector<float> vals;
};

namespace chap6
{
    /**
     * @brief gets the index of the left child node in the heap
     * 
     * @param index node index
     * @return int 
     */
    int inline Left(int index){return 2 * index + 1;};

    /**
     * @brief gets the index of the right child node in the heap
     * 
     * @param index node index
     * @return int 
     */
    int inline Right(int index){return 2 * (index + 1);};

    /**
     * @brief gets the index of the parent node in the heap
     * 
     * @param index node index
     * @return int 
     */
    int inline Parent(int index){return index / 2;};

    /**
     * @brief Enforces the heap property as defined by the chapter
     * 
     * @param A heap input
     * @param i index of the node to heapify
     */
    void MaxHeapify(Heap& A, int i);

    /**
     * @brief Building a max heap starting from a randomly sorted array
     * 
     * @param A heap input
     */
    void BuildMaxHeap(Heap& A);
}

#endif