
#ifndef _ABSTRACT_SORTED_LIST_HPP_
#define _ABSTRACT_SORTED_LIST_HPP_

#include <cstdlib>

template <typename T>
class AbstractSortedList
{
  // determine if a list is empty
  virtual bool isEmpty() const noexcept = 0;

  // return current length of the list
  virtual std::size_t getLength() const noexcept = 0;

  // insert item at sorted position in the list
  virtual void insert(const T& item) = 0;

  // remove first occurrence of item from the list
  virtual void remove(const T& item) = 0;

  // remove item at position in the list 
  virtual void removeAt(std::size_t position) = 0;

  // remove all items from the list
  virtual void clear() = 0;

  // get a copy of the item at position
  virtual T getEntry(std::size_t position) const = 0;

  // get the position of the first occurrence of item
  // return -1 if not in list
  virtual long int getPosition(const T& newValue) = 0;

};

#endif // _ABSTRACT_SORTED_LIST_HPP_
