#include "binary_search_tree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree
(
    const BinarySearchTree<KeyType, ItemType>& rhs
)
{
    root = 0;
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType>* rhs)
{
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType>& rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert
(
    const KeyType& key, const ItemType& item
)
{
    // empty list cond handle
    if(isEmpty()){
        root = new Node<KeyType,ItemType>;
        root->data = item;
        root->key = key;
        return true;
    }
    // search tree for key
    Node<KeyType,ItemType> *insert_after, *insert_afters_parent;
    search(key, insert_after, insert_afters_parent);
    if(insert_after->key == key)        // no duplicate keys allowed
        return false;

    // create new node
    Node<KeyType,ItemType> *newPtr = new Node<KeyType,ItemType>;
    newPtr->data = item;
    newPtr->key = key;

    // place new node on lhs or rhs according to key
    if(key < insert_after->key)
        insert_after->left = newPtr;
    else
        insert_after->right = newPtr;
    return true;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve
(
    const KeyType& key, ItemType& item
)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    // check for tree of size 0 or 1
    if (isEmpty())                                              // empty tree
        return false;
    else if(root->left == 0 && root->right == 0){               // only one node
        if(root->key == key){   
            delete root;    
            root = 0;
            return true;
        }else{
            return false;
        }
    }

    // find node to remove
    Node<KeyType,ItemType> *to_remove, *parent;
    search(key,to_remove,parent);       // parent ptr will not be 0
    if(to_remove->key != key)                                   // key not found, return false
        return false;  

    // bool handle for removing root
    bool isRoot = parent == 0, isLeft;
    if(!isRoot)
        isLeft = parent->left == to_remove;    // <-- bool handle to determine which child to_remove is of parent 

    if     (to_remove->left == 0 && to_remove->right == 0){     // no children
        delete to_remove;
        if(isRoot)
            root = 0;
        else{
            if(isLeft)
                parent->left = 0;
            else
                parent->right = 0;
        }
        return true;
    }
    else if(to_remove->left != 0 && to_remove->right == 0){     // only left child
        Node<KeyType,ItemType> *tmp = new Node<KeyType,ItemType>;
        tmp->data = to_remove->left->data;
        tmp->key = to_remove->left->key;
        tmp->left = to_remove->left->left;
        tmp->right = to_remove->left->right;
        delete to_remove;
        if(isRoot)
            root = tmp;
        else{
            if(isLeft)
                parent->left = tmp;
            else
                parent->right = tmp;
        }
        return true;
    }
    else if(to_remove->left == 0 && to_remove->right != 0){     // only right child
        Node<KeyType,ItemType> *tmp = new Node<KeyType,ItemType>;
        tmp->data = to_remove->right->data;
        tmp->key = to_remove->right->key;
        tmp->left = to_remove->right->left;
        tmp->right = to_remove->right->right;
        delete to_remove;
        if(isRoot)
            root = tmp;
        else{
            if(isLeft)
                parent->left = tmp;
            else
                parent->right = tmp;
        }
        return true;
    }
    else if(to_remove->left != 0 && to_remove->right != 0){     // both children
        Node<KeyType,ItemType> *insucc, *p;
        inorder(to_remove,insucc,p);
        to_remove->data = insucc->data; // move inorder successor key and item to removed node
        to_remove->key = insucc->key;   
        if(p->left == insucc){      // remove inorder successor
            delete insucc;
            p->left = 0;
        }else if(p->right == insucc){
            delete insucc;
            p->right = 0;
        }
        return true;
    }

    return false; // default should never get here
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder
(
    Node<KeyType, ItemType>* curr, Node<KeyType, ItemType>*& successor, Node<KeyType, ItemType>*& parent
)
{
    // clone the righthand subtree
    BinarySearchTree<KeyType, ItemType> RHsubtree;
    RHsubtree.clone(curr->right);

    // search for key
    RHsubtree.search(curr->key,successor,parent);
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search
(
    KeyType key, Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent
)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(ItemType arr[], int size) {
    // TODO: check for duplicate items in the input array

    // TODO: use the tree to sort the array items

    // TODO: overwrite input array values with sorted values
}
