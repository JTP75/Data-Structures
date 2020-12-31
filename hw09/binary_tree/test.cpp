#include <iostream>
using std::cout;
using std::endl;

#include "BinaryTree.h"

typedef std::string ItemType;
typedef void (*FunctionType)(ItemType& anItem);

void PrintNode(ItemType& i) { cout << i << endl; };

int main(int argc, char** argv)
{
    BinaryTree<ItemType, FunctionType> T1("B");
    BinaryTree<ItemType, FunctionType> T2("C");

    BinaryTree<ItemType, FunctionType> T3("A");
    T3.attachLeftSubtree(T1);
    T3.attachRightSubtree(T2);
    T3.postorderTraverse(&PrintNode);
    T3.preorderTraverse(&PrintNode);
    T3.inorderTraverse(&PrintNode);

    // now T1 and T2 are no longer trees, but empty objects

    return 0;
};
