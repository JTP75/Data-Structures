// ********************************************************
// Template implementation file BinaryTree.tpp for the
//  ADT binary tree.
// ********************************************************
template <class TreeItemType, class FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree()
    : root(0){};

template <class TreeItemType, class FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(const TreeItemType& rootItem)
{
    root = new NodeType(rootItem, 0, 0);
    assert(root != 0);
};

template <class TreeItemType, class FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(
    const TreeItemType& rootItem, BinaryTree& leftTree, BinaryTree& rightTree)
{
    root = new NodeType(rootItem, 0, 0);
    assert(root != 0);

    attachLeftSubtree(leftTree);
    attachRightSubtree(rightTree);
};

template <class TreeItemType, class FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(const BinaryTree& tree)
{
    copyTree(tree.root, root);
};

template <class TreeItemType, class FunctionType>
BinaryTree<TreeItemType, FunctionType>::BinaryTree(NodeType* nodePtr)
    : root(nodePtr){};

template <class TreeItemType, class FunctionType>
BinaryTree<TreeItemType, FunctionType>::~BinaryTree()
{
    destroyTree(root);
};

template <class TreeItemType, class FunctionType>
bool BinaryTree<TreeItemType, FunctionType>::isEmpty() const
{
    return (root == 0);
};

template <class TreeItemType, class FunctionType>
TreeItemType BinaryTree<TreeItemType, FunctionType>::rootData() const
{
    if (isEmpty())
        throw TreeException("TreeException: Empty tree");
    return root->item;
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::setRootData(
    const TreeItemType& newItem)
{
    if (!isEmpty())
        root->item = newItem;
    else {
        root = new NodeType(newItem, 0, 0);
        if (root == 0)
            throw TreeException("TreeException: Cannot allocate memory");
    }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachLeft(
    const TreeItemType& newItem)
{
    if (isEmpty())
        throw TreeException("TreeException: Empty tree");
    else if (root->leftChildPtr != 0)
        throw TreeException("TreeException: Cannot overwrite left subtree");
    else // Assertion: nonempty tree; no left child
    {
        root->leftChildPtr = new NodeType(newItem, 0, 0);
        if (root->leftChildPtr == 0)
            throw TreeException("TreeException: Cannot allocate memory");
    }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachRight(
    const TreeItemType& newItem)
{
    if (isEmpty())
        throw TreeException("TreeException: Empty tree");
    else if (root->rightChildPtr != 0)
        throw TreeException("TreeException: Cannot overwrite right subtree");
    else // Assertion: nonempty tree; no right child
    {
        root->rightChildPtr = new NodeType(newItem, 0, 0);

        if (root->rightChildPtr == 0)
            throw TreeException("TreeException: Cannot allocate memory");
    }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachLeftSubtree(
    BinaryTree& leftTree)
{
    if (isEmpty())
        throw TreeException("TreeException: Empty tree");
    else if (root->leftChildPtr != 0)
        throw TreeException("TreeException: Cannot overwrite left subtree");
    else // Assertion: nonempty tree; no left child
    {
        root->leftChildPtr = leftTree.root;
        leftTree.root = 0;
    }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::attachRightSubtree(
    BinaryTree& rightTree)
{
    if (isEmpty())
        throw TreeException("TreeException: Empty tree");
    else if (root->rightChildPtr != 0)
        throw TreeException("TreeException: Cannot overwrite right subtree");
    else // Assertion: nonempty tree; no right child
    {
        root->rightChildPtr = rightTree.root;
        rightTree.root = 0;
    }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::detachLeftSubtree(
    BinaryTree& leftTree)
{
    if (isEmpty())
        throw TreeException("TreeException: Empty tree");
    else {
        leftTree = BinaryTree(root->leftChildPtr);
        root->leftChildPtr = 0;
    }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::detachRightSubtree(
    BinaryTree& rightTree)
{
    if (isEmpty())
        throw TreeException("TreeException: Empty tree");
    else {
        rightTree = BinaryTree(root->rightChildPtr);
        root->rightChildPtr = 0;
    }
};

template <class TreeItemType, class FunctionType>
BinaryTree<TreeItemType, FunctionType>
BinaryTree<TreeItemType, FunctionType>::leftSubtree() const
{
    NodeType* subTreePtr;
    if (isEmpty())
        return BinaryTree();
    else {
        copyTree(root->leftChildPtr, subTreePtr);
        return BinaryTree(subTreePtr);
    }
};

template <class TreeItemType, class FunctionType>
BinaryTree<TreeItemType, FunctionType>
BinaryTree<TreeItemType, FunctionType>::rightSubtree() const
{
    NodeType* subTreePtr;
    if (isEmpty())
        return BinaryTree();
    else {
        copyTree(root->rightChildPtr, subTreePtr);
        return BinaryTree(subTreePtr);
    }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::preorderTraverse(
    FunctionType visit)
{
    preorder(root, visit);
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::inorderTraverse(FunctionType visit)
{
    inorder(root, visit);
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::postorderTraverse(
    FunctionType visit)
{
    postorder(root, visit);
};

template <class TreeItemType, class FunctionType>
BinaryTree<TreeItemType, FunctionType>& BinaryTree<TreeItemType, FunctionType>::
operator=(const BinaryTree& rhs)
{
    if (this != &rhs) {
        destroyTree(root); // deallocate left-hand side
        copyTree(rhs.root, root); // copy right-hand side
    }
    return *this;
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::copyTree(
    NodeType* treePtr, NodeType*& newTreePtr) const
{
    // preorder traversal
    if (treePtr != 0) { // copy node
        newTreePtr = new NodeType(treePtr->item, 0, 0);
        if (newTreePtr == 0)
            throw TreeException("TreeException: Cannot allocate memory");

        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    } else
        newTreePtr = 0; // copy empty tree
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::destroyTree(NodeType*& treePtr)
{
    // postorder traversal
    if (treePtr != 0) {
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = 0;
    }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::setRootPtr(NodeType* newRoot)
{
    root = newRoot;
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::getChildPtrs(
    NodeType* nodePtr, NodeType*& leftPtr, NodeType*& rightPtr) const
{
    leftPtr = nodePtr->leftChildPtr;
    rightPtr = nodePtr->rightChildPtr;
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::setChildPtrs(
    NodeType* nodePtr, NodeType* leftPtr, NodeType* rightPtr)
{
    nodePtr->leftChildPtr = leftPtr;
    nodePtr->rightChildPtr = rightPtr;
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::preorder(
    NodeType* treePtr, FunctionType visit)
{
   if (treePtr != 0) {
        // TODO
   }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::inorder(
    NodeType* treePtr, FunctionType visit)
{
    if (treePtr != 0) {
        // TODO
    }
};

template <class TreeItemType, class FunctionType>
void BinaryTree<TreeItemType, FunctionType>::postorder(
    NodeType* treePtr, FunctionType visit)
{
    if (treePtr != 0) {
        // TODO
    }
};
