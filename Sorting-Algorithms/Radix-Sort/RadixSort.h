#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <vector>

std::vector<int> radix_counting_sort(const std::vector<int>& A, int range, int exp);

void radix_sort(std::vector<int>& A, int range);


#endif