#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x){}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  
  return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  return false;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  return false;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return false;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return 0;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  return false;
}

template<typename T>
void DynamicBag<T>::clear(){}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  return 0;
};
