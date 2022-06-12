#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  size = 0;
  capacity = 10;
  array = unique_ptr<T[]>(new T[capacity]);
}

template <typename T>
ArrayList<T>::~ArrayList() {}     // no need to implement: unique_ptrs are automatically destructed

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){
  size = rhs.size;
  capacity = rhs.capacity;
  array = unique_ptr<T[]>(new T[capacity]);

  for(size_t i=0; i < rhs.size; i++)
    array[i] = rhs.array[i];
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  size = rhs.size;
  capacity = rhs.capacity;
  array = unique_ptr<T[]>(new T[capacity]);

  for(size_t i=0; i < rhs.size; i++)
    array[i] = rhs.array[i];
  
  return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
  return size == 0;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  return size;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  if(position < 0 || position > size)
    return false;

  // we can increase efficiency by inserting new element and reallocating at the same time
  if(size >= capacity){

    capacity = static_cast<size_t>(capacity * RESIZE_FACTOR);             // set new capacity, recast back to size_t
    size++;                                                               // increment size

    unique_ptr<T[]> newArr = unique_ptr<T[]>(new T[capacity]);            // allocate new mem location

    size_t oldIndex = 0;                                                  // copies array, but inserts item at index:
    for(size_t newIndex = 0; newIndex < size; newIndex++){                // loop through new array
      if(newIndex == position)                    // if loop index is equal to position, set newArr to item and DONT increment oldIndex
        newArr[newIndex] = item;
      else                                        // otherwise, copy value and increment oldIndex
        newArr[newIndex] = array[oldIndex++];
    }

    // reset function: deletes memory managed by 'array' ptr, then 'array' ptr takes ownership of newArr's memory
    array.swap(newArr);     // swap newArr and array pointers

    return true;        // exit function, newArr ptr is deleted
  }

  // if no resizing is needed, we can just push back
  for(size_t i = size++; i > position; i--)           // reverse loop starts at i = old size, terminates when i = position (also increment size)
    array[i] = array[i-1];                            // set value at i to value at i-1
  
  array[position] = item;            // set array at position to item

  return true;                // exit function

}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  if(position < 0 || position >= size)
    return false;
  
  size--;
  for(int i = position; i<size; i++)
    array[i] = array[i+1];

  return true;
}

template <typename T>
void ArrayList<T>::clear(){
  size = 0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const{
  if(position < 0 || position >= size)
    return T();
  return array[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue){
  if(position < 0 || position >= size)
    return;
  array[position] = newValue;
}
