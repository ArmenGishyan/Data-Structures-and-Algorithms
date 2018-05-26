#include "tree.h"


int main()
{
    Tree<int> tree;
    tree.insert(5);
    tree.insert(12);
    tree.insert(7);
    tree.insert(6);
    tree.insert(22);
    tree.insert(30);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
  
    std::cout<<"h = "<<tree.height()<<"\n";
    std::cout<<"value="<<tree.find(4)->getValue()<<"\n";
    
    tree.inorder();
    tree.postorder();
    tree.preorder();
    return 0;
}