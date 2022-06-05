#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag()   // def constr
{
  bagSize = 0;
  itemPtr = new T[bagSize];
}

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x)    // copy constr
{
  bagSize = x.bagSize;
  itemPtr = new T[x.bagSize];
  for(size_t i=0; i<bagSize; i++)
    *(itemPtr+i) = *(x.itemPtr+i);
}
    
template<typename T>
DynamicBag<T>::~DynamicBag()    // deconstr
{
  delete [] itemPtr;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)   // copy assignment operator
{  
  bagSize = x.bagSize;
  itemPtr = new T[x.bagSize];
  for(size_t i=0; i<bagSize; i++)
    *(itemPtr+i) = *(x.itemPtr+i);
  return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  if(typeid(T) != typeid(*itemPtr))                             // return false if typeids dont match
    return false;
  
  itemPtr = (T*) realloc(itemPtr, ++bagSize * sizeof(T));     // increment size and reallocate memory
  *(itemPtr+bagSize-1) = item;                          // add item at last index

  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)   // removes top-most element that matches item passed in
{
  if(typeid(T) != typeid(*itemPtr))   // return false if typeids dont match (datatype mismatch)
    return false;

  for(int i=bagSize-1; i>=0; i--){
    if(itemPtr[i] == item){
      T *tempPtr = new T[bagSize-1];
      std::copy(itemPtr, itemPtr+i, tempPtr);
      std::copy(itemPtr+i+1, itemPtr+bagSize--, tempPtr+i);
      delete [] itemPtr;
      itemPtr = tempPtr;
      return true;
    }
  }
  return false;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return bagSize==0;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return bagSize;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  for(int i=0; i<bagSize; i++)
    if(itemPtr[i]==item)
      return true;
  return false;
}

template<typename T>
void DynamicBag<T>::clear()
{
  this->~DynamicBag();
  DynamicBag<T> newbag;
  *this = newbag;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  int freq = 0;
  for(int i=0; i<bagSize; i++)
    freq += itemPtr[i]==item ? 1 : 0;
  return freq;
};
