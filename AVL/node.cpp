template<class T>
Node<T>::Node(T val,Node<T> *left,Node<T> *right):m_value(val),m_left(left),m_right(right)
{}
template<class T>
T Node<T>::getValue() const
{
    return m_value;
}
template<class T>
void Node<T>::setValue(T obj)
{
    m_value = obj;
}
template<class T>
bool Node<T>::isLeaf() const
{
    return (m_left == nullptr && m_right == nullptr);
}
template <class T>
Node<T>* Node<T>::isHaveOneChild() const
{
    if(m_left != nullptr && m_right == nullptr)
        return m_left;
    if(m_left == nullptr && m_right != nullptr)
        return m_right;
    return nullptr;
}
template<class T>
Node<T>* Node<T>::predecessor() const
{
    Node<T>* temp = m_left;
    while(temp->m_right != nullptr)
    {
        temp = temp->m_right;
    }
    return temp;
}


