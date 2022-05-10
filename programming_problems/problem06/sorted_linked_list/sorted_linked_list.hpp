
#ifndef _SORTED_LINKED_LIST_HPP_
#define _SORTED_LINKED_LIST_HPP_

#include "abstract_sorted_list.hpp"
#include "linked_list.hpp"

template <typename T>
class SortedLinkedList: public AbstractSortedList<T>, private LinkedList<T>
{
public:

  // constructor
  SortedLinkedList();

  // constructor from list (should sort the input list)
  SortedLinkedList(LinkedList<T> unsorted_list);

  // copy constructor
  SortedLinkedList(const SortedLinkedList & x);

  // copy assignment
  SortedLinkedList& operator=(const SortedLinkedList& x);

  // destructor
  ~SortedLinkedList();

  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  std::size_t getLength() const noexcept;

  // insert item at sorted position in the list
  void insert(const T& item);

  // remove first occurrence of item from the list
  void remove(const T& item);

  // remove item at position in the list 
  void removeAt(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position 
  T getEntry(std::size_t position) const;

  // get the position of the first occurrence of item
  // return -1 if not in list
  long int getPosition(const T& item);

private:

  // TODO

};

#include "sorted_linked_list.tpp"

#endif // _SORTED_LINKED_LIST_HPP_
