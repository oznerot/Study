#include <algorithm>
#include "Stack.h"
template<typename T>
Stack<T>::Stack() : _arr(nullptr), _size(0), _capacity(0) {}

template<typename T>
Stack<T>::Stack(const size_t size) : _arr(new T[size]), _size(size), _capacity(size)
{
    std::fill(_arr, _arr + _size, T());
}

template<typename T>
Stack<T>::Stack(const size_t size, const T value) : _arr(new T[size]), _size(size), _capacity(size){
    std::fill(_arr, _arr + _size, value);
}

//Stack::Stack()

//Stack::Stack(const std::initializer_list<T> initList)
template<typename T>
bool Stack<T>::empty()
{
    return _size ? true : false;
}

template<typename T>
void Stack<T>::increase_capacity()
{
    _capacity *= 2;
    T* temp = new T[_capacity];
    std::copy(_arr, _arr + _size, temp);
    delete[] _arr;
    _arr = temp;
}

template<typename T>
void Stack<T>::push_back(const T value)
{
    if (_size == _capacity)
        increase_capacity();

    _size++;
    _arr[_size] = value;
}

template<typename T>
T Stack<T>::pop_back()
{
    if(empty())
        return;

    _size--;
    return _arr[_size + 1];
}

template<typename T>
T& Stack<T>::operator[](size_t index)
{
    if(index < _size)
        return _arr[index];

    throw std::out_of_range("Index out of range");
}

template<typename T>
const T& Stack<T>::operator[](size_t index) const
{
    if(index < _size)
        return _arr[index];

    throw std::out_of_range("Index out of range");
}

