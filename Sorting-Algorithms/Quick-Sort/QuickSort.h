#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
void exchange_values(std::vector<int>& A, int x, int y);
int random_pivot(int a, int b);

int partition(std::vector<int>& A, int beg, int end);
void quick_sort(std::vector<int>& A, int beg, int end);
void TRE_quick_sort(std::vector<int>& A, int beg, int end);

int randomized_partition(std::vector<int>& A, int beg, int end);
void randomized_quick_sort(std::vector<int>& A, int beg, int end);

#endif