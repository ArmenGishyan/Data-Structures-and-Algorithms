#include <iostream>

template<class T>
class Node 
{
    public:
        Node(T val = T(),Node<T> *left = nullptr,Node<T> *right = nullptr);
        void setValue(T val);
        T getValue() const;
        Node<T> *m_left;
        Node<T> *m_right;
        bool isLeaf() const;
        //check is node have one chalid and return pointer on it
        Node<T>* isHaveOneChild() const;
        Node<T>* predecessor() const;

    private:
        T m_value;
};

#include "node.cpp"
