#include <algorithm>
#include <vector>

std::vector<int> radix_counting_sort(const std::vector<int>& A, int range, int exp)
{
    std::vector<int> B(A.size(), 0);
    std::vector<int> C(range + 1, 0);

    int size = static_cast<int>(A.size());

    for(int i = 0; i < size; i++)
        C[(A[i]/exp) % 10]++;

    for(int i = 1; i <= range; i++)
        C[i] += C[i - 1];

    for(int i = size - 1; i >= 0; i--){
        B[C[(A[i]/exp) % 10] - 1] = A[i];
        C[(A[i]/exp) % 10]--;
    }

    return B;
}

void radix_sort(std::vector<int>& A, int range)
{
    int max = *std::max_element(A.begin(), A.end());

    for(int exp = 1; max/exp > 0; exp *= 10)
        A = radix_counting_sort(A, range, exp);
}