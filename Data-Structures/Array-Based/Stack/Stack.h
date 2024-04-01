#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack{

        T* _arr;
        size_t _size;
        size_t _capacity;

    public:
        Stack();
        Stack(const size_t size);
        Stack(const size_t size, const T value);
        //Stack(const std::initializer_list<T> initList);
        //Stack(const Stack& stack);
        //Stack()

        push(const T value);


};

#include "Stack.tpp"

#endif