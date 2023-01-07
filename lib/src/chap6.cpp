#include "../include/algorithms/chap6.hpp"
#include <stdexcept>

namespace chap6
{
    void MaxHeapify(Heap& A, int index)
    {
        int left = Left(index);
        int right = Right(index);
        int heap_size = A.heap_size - 1;
        if(left > heap_size && right > heap_size)
        {
            return;
        }
        if(A.vals[index] >= A.vals[left] && A.vals[index] >= A.vals[right])
        {
            return;
        }
        float tmp = A.vals[index];
        int l_max = -1;
        if(A.vals[index] < A.vals[left] && left <= heap_size)
        {
            l_max = left;
        }
        if(A.vals[left] < A.vals[right] && right <= heap_size)
        {
            l_max = right;
        }
        if(l_max > -1)
        {
            A.vals[index] = A.vals[l_max];
            A.vals[l_max] = tmp;
            MaxHeapify(A, l_max);
        }
    }

    void BuildMaxHeap(Heap& A)
    {
        int n = A.heap_size - 1;
        for(int i = ceil(n / 2); i >= 0; i--)
        {
            MaxHeapify(A, i);
        }
    }
}