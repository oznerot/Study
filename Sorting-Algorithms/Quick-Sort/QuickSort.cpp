#include <vector>
#include <random>
#include "QuickSort.h"

//Utility functions

void exchange_values(std::vector<int>& A, int x, int y)
{
    int tmp = A[x];
    A[x] = A[y];
    A[y] = tmp;
}

//Quick Sort with Lomuto algorithm variation

int partition(std::vector<int>& A, int beg, int end)
{
    int pivot = A[end];
    int i = beg - 1;

    for(int j = beg; j < end; j++)
        if(A[j] <= pivot){
            i++;
            exchange_values(A, i, j);
        }
    exchange_values(A, i+1, end);

    return i+1;
}


void quick_sort(std::vector<int>& A, int beg, int end)
{
    if(beg < end){
        int mid = partition(A, beg, end);
        quick_sort(A, beg, mid-1);
        quick_sort(A, mid+1, end);
    }
}

void TRE_quick_sort(std::vector<int>& A, int beg, int end)
[
    while(beg < end){
        int mid = partition(A, beg, end);
        TRE_quick_sort(A, beg, end);
        beg = mid + 1
    }
]

//Random pivoting variant

int random_pivot(int a, int b)
{
    std::random_device rand;
    std::mt19937 mt(rand());
    std::uniform_int_distribution<int> dist(a, b);

    return dist(mt);
}

int randomized_partition(std::vector<int>& A, int beg, int end)
{
    int pivot = random_pivot(beg, end);
    exchange_values(A, pivot, end);

    return partition(A, beg, end);

}

void randomized_quick_sort(std::vector<int>& A, int beg, int end)
{
    if(beg < end){
        int mid = randomized_partition(A, beg, end);
        randomized_quick_sort(A, beg, mid-1);
        randomized_quick_sort(A, mid+1, end);
    }
}
