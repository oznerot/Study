#include "BinaryTree.h"

BTree::BTree() : _root(nullptr){}

void BTree::_insert(struct node* cur, struct node* ptr)
{
    
}

void BTree::insert(int key)
{
    struct node* x = new struct node();
    x._key = key;

    if(_root == nullptr){
        _root = x;
        return;
    }

    _insert(_root, x);

}