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


