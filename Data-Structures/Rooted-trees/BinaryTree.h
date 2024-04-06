#ifndef BTREE_H
#define BTREE_H

class BTree{
    private:
        struct node{
            int _key;
            struct node* _p;
            struct node* _left;
            struct node* _right;

            node() : _key(0), _p(nullptr), _left(nullptr), _right(nullptr){}
        };

        struct node* _root;

        void _insert(struct node* cur, struct node* ptr);

    public:
        Btree();
        
        void insert(int key);
}

#endif