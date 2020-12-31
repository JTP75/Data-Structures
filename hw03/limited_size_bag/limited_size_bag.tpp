#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {}
  

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag& x){}
    
template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag(){}
  
template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T>& x)
{  
  return *this;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return false;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return 0;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear(){}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  return 0;
};
