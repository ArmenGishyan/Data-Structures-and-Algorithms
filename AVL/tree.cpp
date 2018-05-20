template<class T>
Tree<T>::Tree():m_root(nullptr)
{}
template<class T>
Tree<T>::~Tree()
{
    deleteTree(m_root);
    std::cout<<"destructor"<<std::endl;
}
template<class T>
Node<T>* Tree<T>::deleteTree(Node<T> *node)
{
    while(node != nullptr)
    {
        deleteTree(node->m_left);
        deleteTree(node->m_right);
    }
    delete node;
    return (node=nullptr);
}
template<class T>
Node<T>* Tree<T>::leftRotation(Node<T>  *node) 
{
    Node<T>* temp=nullptr;
    temp=node->m_right;
    node->m_right = temp->m_left;
    temp->m_left = node;
    return temp;
}

template<class T>
Node<T>* Tree<T>::rightRotation(Node<T> *node)
{
    Node<T>* temp=nullptr;
    temp=node->m_left;
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
    if(node==nullptr) return 0; 
    return (1 + std::max(height(m_root->m_left),height(m_root->m_right)));
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
void Tree<T>::insert(T const &value)
{
    insert(m_root,value);
}
template<class T>
Node<T>* Tree<T>::insert(Node<T>* node,T const &value)
{
    if (node == nullptr)
    {
        node = new Node<T>(value);
        return node;
    }
    else if (value < node->getValue())
    {
        node->m_left = insert(node->m_left, value);
        node = balancing(node);
    }
    else if (value >= node->getValue())
    {
        node->m_right = insert(node->m_right, value);
        node = balancing(node);
    }
    return node;
}
template<class T>
Node<T>* Tree<T>::balancing(Node<T> *node)
{
    int bal_factor = balance_factor(node);
    Node<T>* temp = nullptr;
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
void Tree<T>::LevelOrder(Node<T>* node) const
{
    int h = height(node);
    int i;
    for (i=1; i<=h; i++)
    {
       GivenLevel(node, i);
    }
}

template<class T> 
void Tree<T>::GivenLevel(Node<T>* node, int level) const
{
    if (node == nullptr)
        return;
    if (level == 1)
        std::cout<<(node->getValue());
    else if (level > 1)
    {
        GivenLevel(node->m_left, level-1);
        GivenLevel(node->m_right, level-1);
    }
}
template<class T>
void Tree<T>::print() const
{
    LevelOrder(m_root);
    std::cout<<"print\n";
}

template<class T>
void Tree<T>::preorder()
{
    std::cout<<"preorder:"<<std::endl;
    preorder(m_root);
}
template<class T>
void Tree<T>::inorder()
{
    std::cout<<"inorder:"<<std::endl;
    inorder(m_root);
}
template<class T>
void Tree<T>::postorder()
{
    std::cout<<"postorder:"<<std::endl;
    postorder(m_root);
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