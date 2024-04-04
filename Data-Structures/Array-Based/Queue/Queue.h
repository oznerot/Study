#ifndef QUEUE_H
#define QUEUE_H

#include <algorithm>
#include <stdexcept>

template <typename T>
class Queue{
    private:
        T* _arr;
        size_t _size;
        size_t _capacity;
        size_t _head;   //head index must be a signed integer for the modulo operation
        size_t _tail;

        void increase_capacity()
        {
            _capacity *= 2;
            _tail = _size;
            T* temp = new T[_capacity];
            for(size_t i = 0; i < _size; i++){
                temp[i] = _arr[(_head + i) % _size];
            }
            _head = 0;
            delete[] _arr;
            _arr = temp;
        }

        void initialize()
        {
            _size = 0;
            _capacity = 1;
            _arr = new T[_capacity];
        }


    public:
        Queue() : _arr(nullptr), _size(0), _capacity(0), _head(0), _tail(0) {}
        Queue(const size_t size) : _size(size), _capacity(size), _head(0), _tail(size)
        {
            size == 0 ? _arr = nullptr : _arr = new T[size];
            std::fill(_arr, _arr + _size, T());
        }

        Queue(const size_t size, const T value) : _arr(new T[size]), _size(size), _capacity(size){
            std::fill(_arr, _arr + _size, value);
        }
        //Queue(const std::initializer_list<T> initList);
        //Queue(const Queue& Queue);
        bool empty() {return _size == 0 ? true : false;}
        size_t size() {return _size;}
        size_t capacity() {return _capacity;}

        void enqueue(const T value)
        {
            if(_arr == nullptr)
                initialize();

            if(_size == _capacity)
                increase_capacity();
            

            _size++;
            _arr[_tail] = value;
            _tail = (_tail + 1) % _capacity;
        }

        T dequeue()
        {
            if(empty())
                throw  std::out_of_range("Index out of range");

            size_t prev = _head;
            _head = (_head + 1) % _capacity;
            _size--;

            return _arr[prev];
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