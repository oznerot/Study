#ifndef HEAPCLASS_H
#define HEAPCLASS_H

#include <vector>

class Heap {
        int _length;
        int _heap_size;
        //std::vector<int> &_A;

        void max_heapify(int i);
        void exchange_value(int x, int y);

    public:
        std::vector<int> &_A;

        Heap(int len, std::vector<int> &array);
        
        int length() const;
        int heap_size() const;
        
        void build_max_heap();
        void heap_sort();

        /*
        void max_heap_maximum();
        void max_heap_extract_max();

        void max_heap_increase_key();
        void max_heap_insert();*/
        
};

#endif