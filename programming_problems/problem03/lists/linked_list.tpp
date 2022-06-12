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
  Node<T> *xptr = x.head;

  int i=0;
  while(xptr != nullptr){
    insert(i++,xptr->getItem());
    xptr = xptr->getNext();
  }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  Node<T> *xptr = x.head;

  int i=0;
  while(xptr != nullptr){
    insert(i++,xptr->getItem());
    xptr = xptr->getNext();
  }

  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return size==0;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return size;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if(position < 0 || position > size)     // check that position is valid
    return false;

  Node<T> *newPtr = new Node<T>(item);    // create new node

  if(head==nullptr){      // if theres no head, set it to new node, increment size, and exit
    head = newPtr;
    size++;
    return true;
  }
  
  Node<T> *ptr = head;                  // traverse list to find pointer to previous node (set to head it pos = 0)
  for(size_t i=1; i<position; i++)
    ptr = ptr->getNext();

  if(position == 0){          // if position is zero, we must replace the head
    newPtr->setNext(ptr);     // (since pos = 0, ptr points to head)
    head = newPtr;            // reassign head to newPtr
    size++;                   // incr size
    return true;              // exit
  }

  newPtr->setNext(ptr->getNext());   // set newPtr to point to next node
  ptr->setNext(newPtr);              // set previous node to point to new node

  size++;           // increment size
  return true;      // exit
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  if(position < 0 || position >= size)    // check that pos is valid
    return false;

  Node<T> *ptr = head;              // traverse list to find node to remove (ptr corresponds to previous node)
  for(size_t i=1; i<position; i++)
    ptr = ptr->getNext();

  if(position == 0){            // if position is 0, we need to remove (and replace) the head
    head = ptr->getNext();      // set head to next node
    delete ptr;                 // delete old head
    size--;                     // decr size
    return true;                // exit
  }

  Node<T> *removeMe = ptr->getNext();   // node to be removed
  ptr->setNext(removeMe->getNext());    // set

  delete removeMe;

  size--;       // decrement size
  return true;  // exit
}

template <typename T>
void LinkedList<T>::clear()
{
  Node<T> *ptr = head, *tmp;    // traverse list, delete the nodes one by one
  while(ptr != nullptr){
    tmp = ptr->getNext();
    delete ptr;
    ptr = tmp;
  }
  head = nullptr;   // set head to nullptr
  size = 0;         // reset size
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if(position < 0 || position >= size)
    return T();
  
  Node<T> *ptr = head;
  for(size_t i=0; i<position; i++)
    ptr = ptr->getNext();
  
  return ptr->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position < 0 || position >= size)
    return;
  
  Node<T> *ptr = head;
  for(size_t i=0; i<position; i++)
    ptr = ptr->getNext();
  
  ptr->setItem(newValue);
}
