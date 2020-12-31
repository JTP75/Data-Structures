
#ifndef _SORTED_LINKED_LIST_H_
#define _SORTED_LINKED_LIST_H_

#include "abstract_sorted_list.hpp"
#include "linked_list.hpp"

template <typename T>
class SortedLinkedList: public AbstractSortedList<T>, private LinkedList<T>
{
public:

  // constructor
  SortedLinkedList();

  // copy constructor
  SortedLinkedList(const SortedLinkedList & x);

  // copy assignment
  SortedLinkedList& operator=(const SortedLinkedList& x);

  // destructor
  ~SortedLinkedList();

  // determine if a list is empty
  bool isEmpty();

  // return current lenght of the list
  std::size_t getLength();

  // insert item at ordered position in the list
  void insert(const T& item);

  // remove first occurance of item from the list
  void remove(const T& item);

  // remove item at position in the list using 0-based indexing
  void removeAt(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 0-based indexing
  T getEntry(std::size_t position);

  // get the position of the first occurance of item or negated position
  // where it would be inserted.
  long int getPosition(const T& newValue);

private:

  // TODO

};

#include "sorted_linked_list.tpp"

#endif // _SORTED_LINKED_LIST_H_
