#include <vector>
#include <iostream>
#include <random>
#include "MergeSort.h"

int range_a = 0;
int range_b = 10;
int SIZE = 100;

int random_number(int a, int b)
{
    std::random_device rand;
    std::mt19937 mt(rand());
    std::uniform_int_distribution<int> dist(a, b);

    return dist(mt);
}

void initialize_array(std::vector<int>& array, const int size)
{
    for(int i = 0; i < size; i++)
        array.push_back(random_number(range_a, range_b));
}

void print_array(std::vector<int>& array, const int size)
{
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";

        if(!((i+1)%10))
            std::cout << std::endl;
    }
}

int main(int argc, char** argv)
{
    if(argc > 1)
        SIZE = std::stoi(argv[1]);

    if(argc == 4){
        range_a = std::stoi(argv[2]);
        range_b =  std::stoi (argv[3]);
    }

    std::vector<int> array_of_integers;

    initialize_array(array_of_integers, SIZE);

    std::cout << "Unordered Array: " << std::endl;
    print_array(array_of_integers, SIZE);

    std::cout << "Standard Quick Sort: " << std::endl;
    merge_sort(array_of_integers, 0, SIZE-1);
    print_array(array_of_integers, SIZE);

    return 0;
}