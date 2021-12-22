#include "bag_simple.hpp"

#include <iostream>

// implementation using fixed automatic storage

template <typename T> Bag<T>::Bag(): size(0) {}

template <typename T> Bag<T>::~Bag() {}

template <typename T> std::size_t Bag<T>::getCurrentSize() const { return size; }

template <typename T> bool Bag<T>::isEmpty() const { return (size == 0); }

template <typename T> bool Bag<T>::add(const T& entry) {

  if(size >= MAXSIZE){
    return false;
  }

  data[size] = entry;
  ++size;
  
  return true;
}

template <typename T> bool Bag<T>::remove(const T& entry) {

  if(size == 0) return false;

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == entry) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;
  for(std::size_t i = idx; i < size; ++i){
    data[i] = data[i+1];
  }

  return true;
}


template <typename T> void Bag<T>::clear() { size = 0; }

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const {

  std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == entry) ++freq;
  }
  
  return freq;
}

template <typename T> bool Bag<T>::contains(const T& entry) const {

  return (getFrequencyOf(entry) != 0);
}

