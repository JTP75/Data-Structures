#ifndef _DYNAMIC_ARRAY_LIST_HPP_
#define _DYNAMIC_ARRAY_LIST_HPP_

#include "abstract_list.hpp"

template <typename T>
class DynamicArrayList: public AbstractList<T>
{
public:

  // default constructor
  DynamicArrayList();
  
  // copy constructor
  DynamicArrayList(const DynamicArrayList& x);
    
  // destructor
  ~DynamicArrayList();
  
  // copy assignment
  DynamicArrayList& operator=(const DynamicArrayList x);

  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current lenght of the list
  std::size_t getLength() const noexcept;

  // insert item at position in the list using 0-based indexing
  void insert(std::size_t position, const T& item);

  // remove item at position in the list using 0-based indexing
  void remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 0-based indexing
  T getEntry(std::size_t position) const;

  // set the value of the item at position using 0-based indexing
  void setEntry(std::size_t position, const T& newValue);

private:

  T * data;
  // number of elements that can be added before reallocation (space remaining)
  std::size_t capacity;
  // current allocated memory
  std::size_t size;
  
};

#include "dynamic_array_list.tpp"

#endif // _DYNAMIC_ARRAY_LIST_H_
