#include "HeapClass.h"
#include <vector>
#include <iostream>

void initialize_array(std::vector<int>& array, const int SIZE)
{
    for(int i = 0; i < SIZE; i++){
        array.push_back(i);
    }
}

void print_array(std::vector<int>& array, const int SIZE)
{
    for(int i = 0; i < SIZE; i++){
        std::cout << array[i] << " ";

        if(!((i+1)%10))
            std::cout << std::endl;
    }
}

int main(int argc, char **argv)
{
    int size = std::stoi(argv[1]);

    std::vector<int> array_of_integers;

    initialize_array(array_of_integers, size);

    Heap heap(size, array_of_integers);

    std::cout << "Tamanho do vetor: " << heap.length() << std::endl;
    std::cout << "Tamanho do heap: " << heap.heap_size() << std::endl;

    heap.build_max_heap();

    std::cout << "Tamanho do vetor: " << heap.length() << std::endl;
    std::cout << "Tamanho do heap: " << heap.heap_size() << std::endl;    

    print_array(array_of_integers, size);

    heap.heap_sort();

    print_array(heap._A, size);

    return 0;
}