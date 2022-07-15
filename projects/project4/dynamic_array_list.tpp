#include "dynamic_array_list.hpp"

#define INIT_CAP 1000
#define RESIZE_FACTOR 100

using std::size_t;
using std::string;


template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  capacity = INIT_CAP;
  size = 0;
  data = new T[capacity];
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  capacity = x.capacity;
  size = x.size;
  data = new T[capacity];
  for(size_t i = 0; i<size; i++)
    data[i] = x.data[i];
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  delete [] data;
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(const DynamicArrayList<T> x)
{
  capacity = x.capacity;
  size = x.size;
  data = new T[capacity];
  for(size_t i=0; i < size; i++)
    data[i] = x.data[i];
  return *this;
}

template <typename T>
bool DynamicArrayList<T>::isEmpty() const noexcept
{
  return size==0;
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength() const noexcept
{
  return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  // check if position is valid
  if(position < 0 || position > size){
    string desc = "DynamicArrayList<T>::insert() position argument must be between 0 and " + std::to_string(size);
    throw std::range_error(desc);
  }
  // resize if necessary
  if(size == capacity){
    T *newarr = new T[RESIZE_FACTOR*capacity];  // create new array w/ extra capacity
    for(size_t i=0; i < capacity; i++)          // copy items
      newarr[i] = data[i];
    delete [] data;                             // delete old array
    data = newarr;                              // set arr to newarr
    capacity *= RESIZE_FACTOR;                  // double capacity
  }
  // pull back values
  for(size_t i=size++; i > position; i--){
    data[i] = data[i-1];
  }
  data[position] = item;
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  if(position < 0 || position >= size){
    string desc = "DynamicArrayList<T>::remove() position argument must be between 0 and " + std::to_string(size-1);
    throw std::range_error(desc);
  }
  for(size_t i=position; i < size; i++)
    data[i] = data[i+1];
  size--;
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  size = 0;
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position) const
{
  if(position < 0 || position >= size){
    string desc = "DynamicArrayList<T>::getEntry() position argument must be between 0 and " + std::to_string(size-1);
    throw std::range_error(desc);
  }
  return data[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position < 0 || position >= size){
    string desc = "DynamicArrayList<T>::getEntry() position argument must be between 0 and " + std::to_string(size-1);
    throw std::range_error(desc);
  }
  data[position] = newValue;
}
