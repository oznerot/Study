#include "SinglyLinked.h"
#include <iostream>
#include <stdexcept>

using key = int;

List::List() : _size(0), _head(nullptr), _tail(nullptr){}

void List::print()
{
    struct node* index = _head;

    while(index != nullptr){
        std::cout << index->_key << " ";
        index = index->_next;
    }
    std::cout << std::endl;

}

bool List::search(key k)
{
    struct node* x = _head;
    while((x != nullptr) && (x->_key != k))
        x = x->_next;

    return x == nullptr ? false : true;
}

void List::append(key x)
{
    struct node* new_node = new struct node();
    new_node->_key = x;

    new_node->_next = nullptr;

    if(_head == nullptr)
        _head = new_node;
    
    _tail->_next = new_node;
    _tail = new_node;
    _size++;  
}

void List::prepend(key x)
{

    struct node* new_node = new struct node();
    new_node->_key = x;

    new_node->_next = _head;

    if(_head == nullptr)
        _tail = new_node;

    _head = new_node;
    _size++;

}

void List::insert(key x, size_t pos)
{
    if(pos >= _size)
        throw std::out_of_range("Dumb fucker");

    struct node* new_node = new struct node();
    struct node* prev_node = nullptr;

    new_node->_key = x;
    new_node->_next = _head;

    while(pos > 0){
        prev_node = new_node->_next;
        new_node->_next = new_node->_next->_next;
        pos--;
    }

    if(prev_node != nullptr)
        prev_node->_next = new_node;

    if(new_node->_next == nullptr)
        _tail = new_node;
    
    if(new_node->_next == _head)
        _head = new_node;

    _size++;
}

void List::remove(key k)
{
    struct node* x = _head;
    struct node* prev = _head;

    while((x != nullptr) && (x->_key != k)){
        prev = x;
        x = x->_next;
    }

    if(x == nullptr)
        return;
    
    prev->_next = x->_next;
    delete[] x;
}