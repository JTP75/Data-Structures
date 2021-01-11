#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "abstract_list.hpp"

template<typename T>
class ArrayList: public AbstractList<T>
{
public:

  // default constructor
  ArrayList();

  // destructor
  ~ArrayList();

  // copy constructor
  ArrayList(const ArrayList & rhs);

  // copy assignment
  ArrayList & operator=(const ArrayList & rhs);
  
  // determine if a list is empty
  bool isEmpty() const;

  // return current length of the list
  std::size_t getLength() const;
  
  // insert item at position in the list using 1-based indexing
  bool insert(std::size_t position, const T& item);

  // remove item at position in the list using 1-based indexing
  bool remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 1-based indexing
  T getEntry(std::size_t position) const;

  // set the value of the item at position using 1-based indexing
  void setEntry(std::size_t position, const T& newValue);

private:

  // TODO
  
};

#include "array_list.tpp"

#endif
