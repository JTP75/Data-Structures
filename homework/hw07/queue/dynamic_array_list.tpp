#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  //TODO
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
    //TODO
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  //TODO
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  //TODO
  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
  //TODO
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  //TODO
  return false;
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  //TODO
  return 0;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  //TODO
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  //TODO
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  //TODO
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  //TODO
  return T();
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
