#include <algorithm>
#include "Stack.h"
template<typename T>
Stack::Stack() : _arr(nullptr), _size(0), _capacity(0) {}

template<typename T>
Stack::Stack(const size_t size) : _arr(new T[size]), _size(size), _capacity(size)
{
    std::fill(_arr, _arr + _size, T());
}

Stack::Stack(const size_t size, const T value) : _arr(new T[size]), _size(size), _capacity(size){
    std::fill(_arr, _arr + _size, value);
}

Stack::Stack()

//Stack::Stack(const std::initializer_list<T> initList)
bool Stack::empty()
{
    return _size ? true : false;
}

void Stack::increase_capacity()
{
    _capacity *= 2;
    T* temp = new T[_capacity];
    std::copy(_arr, _arr + _size, temp);
    delete[] _arr;
    _arr = temp;
}

void Stack::push(const T value)
{
    if (_size == _capacity)
        increase_capacity();

    _size++;
    _arr[_size] = value;
}

T Stack::pop()
{
    if(empty())
        return;

    _size--;
    return _arr[_size + 1];
}

