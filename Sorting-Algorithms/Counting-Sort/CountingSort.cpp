#include <vector>
#include "CountingSort.h"

std::vector<int> counting_sort(const std::vector<int>& A, int size, int range)
{
    std::vector<int> B(size, 0);
    std::vector<int> C(range + 1, 0);

    for(int i = 0; i < size; i++)
        C[A[i]]++;

    for(int i = 1; i <= range; i++)
        C[i] += C[i - 1];

    for(int i = size - 1; i >= 0; i--){
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    return B;
} 