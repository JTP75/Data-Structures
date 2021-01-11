
#ifndef _ABSTRACT_SORTED_LIST_H_
#define _ABSTRACT_SORTED_LIST_H_

#include <cstdlib>

template <typename T>
class AbstractSortedList
{
  // determine if a list is empty
  virtual bool isEmpty() = 0;

  // return current lenght of the list
  virtual std::size_t getLength() = 0;

  // insert item at ordered position in the list
  virtual void insert(const T& item) = 0;

  // remove first occurance of item from the list
  virtual void remove(const T& item) = 0;

  // remove item at position in the list using 0-based indexing
  virtual void removeAt(std::size_t position) = 0;

  // remove all items from the list
  virtual void clear() = 0;

  // get a copy of the item at position using 0-based indexing
  virtual T getEntry(std::size_t position) = 0;

  // get the position of the first occurance of item or negated position
  // where it would be inserted.
  virtual long int getPosition(const T& newValue) = 0;

};

#endif // _ABSTRACT_SORTED_LIST_H_
