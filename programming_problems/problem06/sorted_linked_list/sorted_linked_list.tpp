#include "sorted_linked_list.hpp"
#include <stdexcept>

#define max(a,b) a > b ? a : b;

template <typename T>
SortedLinkedList<T>::SortedLinkedList() : LinkedList<T>() {}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) : LinkedList<T>(unsorted_list)
{
  // bubble
  std::size_t numswaps;
  do{
    numswaps = 0;
    Node<T> *ptr = head;
    for(std::size_t i=0; i<size; i++){
      if(ptr->getItem() > ptr->getNext()->getItem()){
        swapNodes(ptr, ptr->getNext());
        numswaps++;
      }
      ptr = ptr->getNext();
    }
  } while(numswaps > 0);
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x) : LinkedList<T>(x) {}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  LinkedList<T>::insert(0, item);
  Node<T> *ptr = head;
  while(ptr->getNext() != nullptr && ptr->getItem() > ptr->getNext()->getItem()){
    swapNodes(ptr, ptr->getNext());
    ptr = ptr->getNext();
  }
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  Node<T> *ptr = head;
  while(ptr != nullptr){
    if(ptr->getNext()->getItem() == item){

    }
  }
  // todo
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  // todo
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position+1);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
  // todo
  return 0;
}

template <typename T>
void swapNodes(Node<T> *ptr1, Node<T> *ptr2)
{
  T tmp = ptr1->getItem();
  ptr1->setItem(ptr2->getItem());
  ptr2->setItem(tmp);
}