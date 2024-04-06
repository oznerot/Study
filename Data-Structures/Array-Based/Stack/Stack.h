#ifndef STACK_H
#define STACK_H

#include <algorithm>

template <typename T>
class Stack{
    private:
        T* _arr;
        size_t _size;
        size_t _capacity;

        void increase_capacity()
        {
            _capacity *= 2;
            T* temp = new T[_capacity];
            std::copy(_arr, _arr + _size, temp);
            delete[] _arr;
            _arr = temp;
        }

        void initialize()
        {
            _size = 0;
            _capacity = 1;
            _arr = new T[1];
        }

    public:
        Stack() : _arr(nullptr), _size(0), _capacity(0), _head(0), _tail(0){}
        Stack(const size_t size) : _size(size), _capacity(size)
        {
            size == 0 ? _arr = nullptr : _arr = new T[size];
            std::fill(_arr, _arr + _size, T());
        }

        Stack(const size_t size, const T value) : _arr(new T[size]), _size(size), _capacity(size){
            std::fill(_arr, _arr + _size, value);
        }
        //Stack(const std::initializer_list<T> initList);
        //Stack(const Stack& stack);
        bool empty() {return !_size ? true : false;}
        size_t size() {return _size;}
        size_t capacity() {return _capacity;}

        void push_back(const T value)
        {
            if(_arr == nullptr)
                initialize();
                
            if(_size == _capacity)
                increase_capacity();

            _size++;
            _arr[_size - 1] = value;
        }

        T pop_back()
        {
            if(empty())
                throw  std::out_of_range("Index out of range");

            _size--;
            return _arr[_size + 1];
        }

        T& operator[](size_t index)
        {
            if(index < _size)
                return _arr[index];

            throw std::out_of_range("Index out of range");
        }
        const T& operator[](size_t index) const
        {
            if(index < _size)
                return _arr[index];

            throw std::out_of_range("Index out of range");
        }


};

#endif