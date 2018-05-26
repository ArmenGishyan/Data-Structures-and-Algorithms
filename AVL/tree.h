#include "node.h"
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

template <class T>
class Tree {
    public:
        Tree();
        ~Tree();
        void insert(T const &obj);
        void preorder();
        void inorder();
        void postorder();
        void _delete(Node<T> const &obj);
        int height() const;
        Node<T>* find(T const &value) const;
    private:
        Node<T> *m_root;
        //-----------------------------------------------Traversal--------------------------
        void preorder(Node<T> *node);
        void inorder(Node<T> *node);
        void postorder(Node<T> *node);
        //------------------------------------------------Rotations--------------------------
        Node<T>* leftRotation(Node<T>  *node);
        Node<T>* rightRotation(Node<T> *node);      
        Node<T>* leftRightRotation(Node<T> *node);
        Node<T>* rightLeftRotation(Node<T> *node);
        //-------------------------------------------Other helper functions-------------------
        int height(Node<T> *node) const; 
        int balance_factor(Node<T> *node) const;
        Node<T>* balancing(Node<T> *node);
        Node<T>* insert(Node<T>* &node,T const &value);
        void deleteTree(Node<T> *node);
};

#include "tree.cpp"
