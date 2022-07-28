#include "list.hpp"
using std::stack;

template <typename T>
List<T>::List()
{
  size = 0;
}

template <typename T>
List<T>::~List()
{
}

template <typename T>
List<T>::List(const List<T>& x)
{
  Lstack = x.Lstack;
  Rstack = x.Rstack;
  size = x.size;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& x)
{
  Lstack = x.Lstack;
  Rstack = x.Rstack;
  size = x.size;
  return *this;
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  return size==0;
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return size;
}

template <typename T>
bool List<T>::insert(std::size_t position, const T& item)
{
  if(position < 0 || position > size)
    return false;
  DSNav(position);
  Rstack.push(item);
  size++;
  return true;
}

template <typename T>
bool List<T>::remove(std::size_t position)
{
  if(position < 0 || position >= size)
    return false;
  DSNav(position);
  Rstack.pop();
  size--;
  return true;
}

template <typename T>
void List<T>::clear()
{
  while(!Lstack.empty())
    Lstack.pop();
  while(!Rstack.empty())
    Rstack.pop();
  size = 0;
}

template <typename T>
T List<T>::getEntry(std::size_t position)
{
  if(position < 0 || position >= size)
    return T();
  this->DSNav(position);
  return Rstack.top();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position < 0 || position >= size)
    return;
  DSNav(position);
  Rstack.pop();
  Rstack.push(newValue);
}

/** 
 * @n double-stack navigator
 * @brief reallocates values between the stacks such that the 
 *        left stack's size is equal to position
 * @param position index to navigate to
 */
template <typename T>
void List<T>::DSNav(std::size_t position)
{
  if(size == 0)
    return;

  while(Lstack.size() < position && !Rstack.empty()){
    Lstack.push(Rstack.top());
    Rstack.pop();
  }
  while(Lstack.size() > position && !Lstack.empty()){
    Rstack.push(Lstack.top());
    Lstack.pop();
  }
  
}