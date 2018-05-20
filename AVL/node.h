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

    private:
        T m_value;
};

#include "node.cpp"
