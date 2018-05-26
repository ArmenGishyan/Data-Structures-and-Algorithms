template<class T>
Tree<T>::Tree():m_root(nullptr)
{}
template<class T>
Tree<T>::~Tree()
{
    deleteTree(m_root);
}
template<class T>
void Tree<T>::deleteTree(Node<T> *node)
{
    if(node == nullptr) return;
    deleteTree(node->m_left);
    deleteTree(node->m_right);
    
    delete node;
    node = nullptr;
}
template<class T>
Node<T>* Tree<T>::leftRotation(Node<T>  *node) 
{
    Node<T>* temp = node->m_right;
    node->m_right = temp->m_left;
    temp->m_left = node;
    return temp;
}

template<class T>
Node<T>* Tree<T>::rightRotation(Node<T> *node)
{
    Node<T>* temp = node->m_left;
    node->m_left = temp->m_right;
    temp->m_right = node;
    return temp;  
}
template<class T>
Node<T>* Tree<T>::leftRightRotation(Node<T> *node)
{
    Node<T>* temp = nullptr;
    temp = node->m_left;
    node->m_left = leftRotation(temp);
    return rightRotation(node);
}

template<class T>
Node<T>* Tree<T>::rightLeftRotation(Node<T> *node)
{
    Node<T> *temp = nullptr;
    temp = node->m_right;
    node->m_right = rightRotation(temp);
    return leftRotation(node);
}
template<class T>
int Tree<T>::height(Node<T> *node) const
{
    if(node == nullptr) return 0 ;
    return 1 + std::max(height(node->m_left),height(node->m_right));
}
template<class T>
int Tree<T>::height() const
{
    return height(m_root);
} 
template<class T>
int Tree<T>::balance_factor(Node<T>* node) const
{
    return (height(node->m_left)-height(node->m_right));
}
template<class T>
void Tree<T>::insert(T const &value)
{
    insert(m_root,value);
}
template<class T>
Node<T>* Tree<T>::insert(Node<T>* &node,T const &value)
{
    if (node == nullptr)
    {
        node = new Node<T>(value);
        return node;
    }
    if (value < node->getValue())
    {
        insert(node->m_left, value);
        node = balancing(node);
    }
    else 
    {
        insert(node->m_right, value);
        node =  balancing(node);
    }
}
template<class T>
Node<T>* Tree<T>::balancing(Node<T> *node)
{
    int bal_factor = balance_factor(node);
    Node<T>* temp = node;
    if (bal_factor > 1)
    {
        if (balance_factor(temp->m_left) > 0)
            temp =  rightRotation(temp);
        else
            temp = leftRightRotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (balance_factor(temp->m_right) > 0)
            temp = rightLeftRotation(temp);
        else
            temp = leftRotation(temp);
    }
    return temp;
}

template<class T>
void Tree<T>::preorder()
{
    std::cout<<"preorder:"<<std::endl;
    preorder(m_root);
    std::cout<<"\n";
}
template<class T>
void Tree<T>::inorder()
{
    std::cout<<"inorder:"<<std::endl;
    inorder(m_root);
    std::cout<<"\n";
}
template<class T>
void Tree<T>::postorder()
{
    std::cout<<"postorder:"<<std::endl;
    postorder(m_root);
    std::cout<<"\n";
}

template<class T>
void Tree<T>::preorder(Node<T> *node)
{
    if(node == nullptr) return ; 
    std::cout<<node->getValue()<<",\t";
    preorder(node->m_left);
    preorder(node->m_right);
}
template<class T>
void Tree<T>::inorder(Node<T> *node)
{
    if(node == nullptr) return ; 
    inorder(node->m_left);
    std::cout<<node->getValue()<<",\t";
    inorder(node->m_right);
}
template<class T>
void Tree<T>::postorder(Node<T> *node)
{
    if(node == nullptr) return ; 
    postorder(node->m_left);
    postorder(node->m_right);
    std::cout<<node->getValue()<<",\t";
}
template<class T>
Node<T>* Tree<T>::find(T const& value) const
{
    Node<T> *temp = m_root;
    T nodeValue = 0;
    while(temp != nullptr)
    {
        nodeValue = temp->getValue();
        if(nodeValue == value) return temp;
        if(value >nodeValue)
        {
            temp = temp->m_right;
        }
        else
        {
            temp = temp->m_left;
        }
    }
    return nullptr;
}