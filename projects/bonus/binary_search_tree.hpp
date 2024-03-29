
#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <stack>
#include <vector>

template <typename KeyType, typename ItemType>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& rhs);
    BinarySearchTree<KeyType, ItemType>& operator=(
        const BinarySearchTree<KeyType, ItemType>& rhs);
    ~BinarySearchTree();

    bool insert(const KeyType& key, const ItemType& item);
    bool isEmpty();
    bool retrieve(const KeyType& key, ItemType& item);
    bool remove(KeyType key);
    void treeSort(ItemType arr[], int size);

private:
    template <typename K, typename I>
    struct Node {
        I data;
        K key;
        Node<K, I>* left = 0x0;
        Node<K, I>* right = 0x0;
    };

    template <typename K, typename I>
    struct stackvar {
        Node<K, I>* rhs;
        Node<K, I>** lhs;
    };

    Node<KeyType, ItemType>* root;

    void clone(Node<KeyType, ItemType>* rhs);
    void destroy();

    void inorder(Node<KeyType, ItemType>* curr, Node<KeyType, ItemType>*& in,
        Node<KeyType, ItemType>*& parent);

    void search(KeyType key, Node<KeyType, ItemType>*& curr,
        Node<KeyType, ItemType>*& parent);

    std::vector<ItemType> tree2vect(Node<KeyType, ItemType> *nd) const;
};

#include "binary_search_tree.tpp"

#endif // _BINARY_SEARCH_TREE_H_
