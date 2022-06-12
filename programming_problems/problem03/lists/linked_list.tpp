#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  size = 0;       // initialize to empty, head is set to NULL 
  head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  Node<T> *ptr = head, *tmp;    // deconstructor traverses list, deleting the nodes one by one
  while(ptr != nullptr){
    tmp = ptr->getNext();
    delete ptr;
    ptr = tmp;
  }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  size = x.size;
  Node<T> *ptr = x.head;
  while(ptr != nullptr){

  }

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  //TODO
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  //TODO
  return true;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  //TODO
  return 0;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if(position < 0 || position > size)     // check that position is valid
    return false;

  Node<T> *prev = head;             // this node comes before the new node
  for(int i=0; i<position-1; i++)   // traverse list until we arrive at prev (position-1)
    prev = prev->getNext();

  Node<T> newNode(item,prev->getNext());    // create new node with item, pointing to next node (currently pointed to by prev)
  prev->setNext(&newNode);                  // set next pointer for previous node to point to newNode

  return true;      // exit
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  //TODO
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //TODO
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
