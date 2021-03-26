#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList(): data(nullptr), capacity(0), size(0)
{}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  capacity = x.capacity;
  size = x.size;
  data = capacity ? new T[capacity] : nullptr;
  std::copy(x.data, x.data + x.capacity, data);
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  delete [] data;
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
  std::swap(data, y.data);
  std::swap(capacity, y.capacity);
  std::swap(size, y.size);
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  return (size == 0);
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  //std::clog << "Insert at " << position << " with size " << size << std::endl;
  
  if(position > size) throw std::range_error("position out of range in insert");

  if(size == capacity){ // need to realloc
    std::size_t newcapacity = capacity ? 2*capacity: 1;
    T* newdata = new T[newcapacity];
    std::copy(data, data+capacity, newdata);
    delete [] data;
    capacity = newcapacity;
    data = newdata;
  }

  for(long i = size-1; i >= static_cast<long>(position); --i){
    data[i+1] = data[i];
    //std::clog << "Shifting " << i << " > " << position << std::endl;
  }
  //std::clog << std::endl;
  data[position] = item;
  ++size;
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  if(position >= size) throw std::range_error("position out of range in remove");
  
  for(long i = position; i < size-1; ++i){
    data[i] = data[i+1];
  }
  --size;
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  size = 0;
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  if(position >= size) throw std::range_error("position out of range in getEntry");

  return data[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position >= size) throw std::range_error("position out of range in setEntry");

  data[position] = newValue;
}
