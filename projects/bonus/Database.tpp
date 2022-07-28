#include "Database.hpp"
using std::string;
using std::size_t;

template <typename T>
Database<T>::Database()
{
}

template <typename T>
bool Database<T>::isEmpty()
{
    return data.isEmpty();
}

template <typename T>
size_t Database<T>::getNumberOfEntries()
{
    return data.getLength();
}

template <typename T>
bool Database<T>::add(string key1, string key2, const T& item)
{
    size_t new_index;
    if(data.isEmpty())
        new_index = 0;
    else
        data.getLength()-1;

    if(BST1.insert(key1,new_index) && BST2.insert(key2,new_index)){
        DatabaseEntry<T> entry = {item,key1,key2};
        data.insert(new_index,entry);
        return true;
    }
    BST1.remove(key1);
    return false;
}

template <typename T>
bool Database<T>::remove(std::string key)
{
    size_t remove_index;
    string key1, key2;

    if(BST1.retrieve(key,remove_index)){
        key1 = key;
        key2 = data.getEntry(remove_index).key2;
    }else if(BST2.retrieve(key,remove_index)){
        key1 = data.getEntry(remove_index).key1;
        key2 = key;
    }else{
        return false;
    }
    
    data.remove(remove_index);
    BST1.remove(key1);
    BST2.remove(key2);
    return true;
}

template <typename T>
void Database<T>::clear()
{
    data.clear();
    BST1.~BinarySearchTree();
    BST2.~BinarySearchTree();
}

template <typename T>
T Database<T>::getValue(string key)
{
    size_t index;
    if(BST1.retrieve(key,index) || BST2.retrieve(key,index))
        return data.getEntry(index).item;
    return T();
}

template <typename T>
bool Database<T>::contains(string key)
{
    size_t index;
    return BST1.retrieve(key,index) || BST2.retrieve(key,index);
}

template <typename T>
std::vector<T> Database<T>::getAllEntries(int keyIndex) {
    // TODO    
    return std::vector<T>();
}