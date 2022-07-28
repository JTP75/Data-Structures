#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "abstract_list.hpp"
#include <stack>


/** 
 * double-stack list implementation (for fun)
 */
template <typename T>
class List: public AbstractList<T>
{
public:
  
  // default constructor
  List();
  
  // copy constructor
  List(const List& x);
    
  // destructor
  ~List();
  
  // copy assignment
  List& operator=(const List& x);
  
  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  std::size_t getLength() const noexcept;

  // insert item at position in the list 
  bool insert(std::size_t position, const T& item);

  // remove item at position in the list 
  bool remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position 
  T getEntry(std::size_t position);

  // set the value of the item at position 
  void setEntry(std::size_t position, const T& newValue);

private:

  std::stack<T> Lstack;     // left stack
  std::stack<T> Rstack;     // right stack
  size_t size;              // list size

  void DSNav(std::size_t position);
  
};

#include "list.tpp"

#endif
