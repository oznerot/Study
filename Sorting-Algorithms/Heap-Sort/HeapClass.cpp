
#include "HeapClass.h"
#include <stdexcept>
#include <limits>
#include <vector>

#define PARENT(i)   ((i-1)/2)
#define LEFT(i)     (2*i + 1)
#define RIGHT(i)    (2*i + 2)


Heap::Heap(int len, std::vector<int> &array) : _length(len), _heap_size(0), _A(array){}

int Heap::length() const
{
    return _length;
}

int Heap::heap_size() const
{
    return _heap_size;
}

void Heap::exchange_value(int x, int y)
{
    int tmp = _A[x];
    _A[x] = _A[y];
    _A[y] = tmp;
}

void Heap::max_heapify(int i)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = 0;

    if((l < _heap_size) && (_A[l] > _A[i]))
        largest = l;
    else
        largest = i;

    if((r < _heap_size) && (_A[r] > _A[largest]))
        largest = r;

    if(largest != i){
        exchange_value(i, largest);
        max_heapify(largest);
    }
}

void Heap::build_max_heap()
{
    _heap_size = _length;
    for(int i = (_length/2)-1; i >= 0; i--)
        max_heapify(i);
}

void Heap::heap_sort()
{
    build_max_heap();
    for(int i = _length-1; i > 0; i--){
        exchange_value(0, i);
        _heap_size--;
        max_heapify(0);
    }
}
/*
int Heap::max_heap_maximum()
{
    if _heap_size < 1
        throw std::out_of_range("heap underflow");
    
    return A[0];
}
void Heap::max_heap_extract_max()
{
    int max = max_heap_maximum();
    A[0] = A[heap.size-1]
    heap.size -= 1
    max_heapify_wrapped(0)

    return max;
}
void Heap::max_heap_increase_key(int i, int new_key)
{
    if (new_key < A[i])
        throw std::invalid_argument("new key is smaller than current key");
    
    A[i] = new_key;

    while(i > 0 && A[PARENT(i)] < A[i]){
        exchange_value(i, PARENT(i));
        i = PARENT(i);
    }
}
void max_heap_insert(int new_key)
{
    if (_heap_size == length)
        throw std::out_of_range("heap overflow");

    _heap_size++;
    A[_heap_size-1] = std::numeric_limits<int>::min();

    max_heap_increase_key(_heap_size-1, new_key);
}
*/
