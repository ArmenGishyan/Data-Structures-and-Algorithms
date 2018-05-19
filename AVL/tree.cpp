
template<class T>
Node<T>* Tree<T>::leftRotation(Node<T>  *node) 
{
    Node<T>* temp=nullptr;
    temp=node->m_right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}

template<class T>
Node<T>* Tree<T>::rightRotation(Node<T> *node)
{
    Node<T>* temp=nullptr;
    temp=node->m_left;
    node->left = temp->right;
    temp->right = node;
    return temp;  
}
template<class T>
Node<T>* Tree<T>::leftRightRotation(Node<T> *node)
{
    Node<T>* temp = nullptr;
    temp = node->m_left;
    node->m_left = LeftRotation(temp);
    return RightRotation(node);
}

template<class T>
Node<T>* Tree<T>::rightLeftRotation(Node<T> *node)
{
    Node<T> *temp = nullptr;
    temp = node->m_right;
    node->right = RightRotation(temp);
    return LeftRotation(node);
}
template<class T>
int Tree<T>::height(Node<T> *node) const
{
    if(node==nullptr) return 0; 
    return (1 + std::max(height(m_root->m_left,height(m_root->m_right))));
}
template<class T>
int Tree<T>::height() const
{
    return height(m_root);
} 
template<class T>
int Tree<T>::balance_factor(Node<T>* node) const
{
    return height(node->m_left)-height(node->m_right);
}
template<class T>
Node<T>* Tree<T>::insert(T const &obj)
{
    int count = 0;
    Node<T>* temp = m_root;
    while(temp != nullptr)
    {
        if(obj > temp->getValue())
        {
            temp = temp->m_right;
        }
        else
        {
            temp = temp->m_left;
        }
    }

    temp = new Node<T>(obj);
    return static_cast<Node<T>* >(temp);
}
template<class T>
void Tree<T>::balancing(Node<T> *node)
{/*
    int bal_factor = 0;
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
    */
}
