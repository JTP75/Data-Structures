// ********************************************************
// Header file BinaryTree.h for the ADT binary tree.
// ********************************************************
#ifndef _BinaryTree_h
#define _BinaryTree_h

#include <cassert>

#include "TreeException.h"

// Binary Tree Type
// templated over the item type and the visit function
template <class TreeItemType, class FunctionType>
class BinaryTree
{
public:
    // constructors and destructor
    BinaryTree();
    
    BinaryTree(const TreeItemType& rootItem);

    BinaryTree(const TreeItemType& rootItem, BinaryTree& leftTree,
        BinaryTree& rightTree);

    BinaryTree(const BinaryTree& tree);

    ~BinaryTree();

    // copy-assignment
    BinaryTree& operator=(const BinaryTree& rhs);

    // binary tree operations:
    bool isEmpty() const;
    TreeItemType rootData() const;
    void setRootData(const TreeItemType& newItem);
    void attachLeft(const TreeItemType& newItem);
    void attachRight(const TreeItemType& newItem);
    void attachLeftSubtree(BinaryTree& leftTree);
    void attachRightSubtree(BinaryTree& rightTree);
    void detachLeftSubtree(BinaryTree& leftTree);
    void detachRightSubtree(BinaryTree& rightTree);
    BinaryTree leftSubtree() const;
    BinaryTree rightSubtree() const;
    void preorderTraverse(FunctionType visit);
    void inorderTraverse(FunctionType visit);
    void postorderTraverse(FunctionType visit);

protected:

    // Define Internal Tree Node
    class NodeType
    {
    public:
        NodeType(){};
        NodeType(const TreeItemType& nodeItem, NodeType* left = 0,
            NodeType* right = 0)
            : item(nodeItem)
            , leftChildPtr(left)
            , rightChildPtr(right)
        {
        }

        TreeItemType item; // data
        NodeType* leftChildPtr; // pointer to left child
        NodeType* rightChildPtr; // pointer to right child
    };

    NodeType* root; // root of tree

    
    // internal constructor
    BinaryTree(NodeType* nodePtr);

    // Copies the tree rooted at treePtr into a tree rooted
    // at newTreePtr. Throws TreeException if a copy of the
    // tree cannot be allocated.
    void copyTree(NodeType* treePtr, NodeType*& newTreePtr) const;

    // delete the tree rooted at treePtr.
    // Throws TreeException if tree doesn't exist
    void destroyTree(NodeType*& treePtr);

    NodeType* rootPtr() const { return root; };

    void setRootPtr(NodeType* newRoot);

    // The next two functions retrieve and set the values
    // of the left and right child pointers of a tree node.
    void getChildPtrs(NodeType* nodePtr, NodeType*& leftChildPtr,
        NodeType*& rightChildPtr) const;
    void setChildPtrs(
        NodeType* nodePtr, NodeType* leftChildPtr, NodeType* rightChildPtr);

    void preorder(NodeType* treePtr, FunctionType visit);
    void inorder(NodeType* treePtr, FunctionType visit);
    void postorder(NodeType* treePtr, FunctionType visit);
};

// include template implementation
#include "BinaryTree.tpp"

#endif
