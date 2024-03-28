#include <vector>
#include "MergeSort.h"

void merge(std::vector<int>& A, int p, int q, int r)
{
    int size_l = q - p + 1;     //length of A[p:q]
    int size_r = r - q;         //length of A[q + 1:r]

    int i, j;

    std::vector<int> L, R;

    for(i = 0; i < size_l; i++)
        L.push_back(A[p + i]);

    for(j = 0; j < size_r; j++)
        R.push_back(A[q + j + 1]);

    i = 0;      //i indexes smallest remaining element in L
    j = 0;      //j indexes smallest remaining element in R
    int k = p;  //k indexes the location in A to fill


    // as long as each of the arrays L and R contains an unmerged element,
    // copy the smallest unmerged element back into A[p:r].
    while((i < size_l) && (j < size_r)){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        
        k++;
    }

    // having gone through one of L and R entirely, copy the
    // remainder of the other to the end of A[p:r]
    while(i < size_l){
        A[k] = L[i];
        i++; k++;
    }

    while(j < size_r){
        A[k] = R[j];
        j++; k++;
    }

}

void merge_sort(std::vector<int>& A, int p, int r)
{
    if(p >= r)
        return;

    int q = p + (r - p)/2;      //Here i'm using this instead of q = (p + r)/2 because,
                                //if we're working with large arrays in the order of billions,
                                //we could overflow q when working with the rightest portion
    
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);

    merge(A, p, q, r);
}