#include "node.h"
#include <bits/stdc++.h>
#include <algorithm>

template <class T>
class Tree {
    public:
        Node<T>* insert(T const &obj);
        void del(Node<T> const &obj);
        void print() const;
        int height() const;
    private:
        Node<T> *m_root;

        Node<T>* leftRotation(Node<T>  *node);
        Node<T>* rightRotation(Node<T> *node);      
        Node<T>* leftRightRotation(Node<T> *node);
        Node<T>* rightLeftRotation(Node<T> *node);
        int height(Node<T> *node) const; 
        int balance_factor(Node<T> *node) const;
        void balancing(Node<T> *node);
};

#include "tree.cpp"
