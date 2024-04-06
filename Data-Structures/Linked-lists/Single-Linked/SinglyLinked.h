#ifndef SINGLY_H
#define SINGLY_H

#include <cstddef>

using key = int;

class List{
    private:
        struct node{
            int _key;
            struct node* _next;

            node() : _key(0), _next(nullptr){}
        };

        std::size_t _size;
        struct node* _head;
        struct node* _tail;

    public:
        List();

        void print();
        bool search(key x);
        void append(key x);
        void prepend(key x);
        void insert(key x, size_t pos);
        void remove(key x);



};


#endif