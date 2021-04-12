#include "list.hpp"

template <typename T>
List<T>::List()
{
  //TODO
}

template <typename T>
List<T>::~List()
{
  //TODO
}

template <typename T>
List<T>::List(const List<T>& x)
{
  //TODO
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& x)
{
  //TODO
  return *this;
}

template <typename T>
bool List<T>::isEmpty() const
{
  //TODO
  return true;
}

template <typename T>
std::size_t List<T>::getLength() const
{
  //TODO
  return 0;
}

template <typename T>
bool List<T>::insert(std::size_t position, const T& item)
{
  //TODO
  return true;
}

template <typename T>
bool List<T>::remove(std::size_t position)
{
  //TODO
  return true;
}

template <typename T>
void List<T>::clear()
{
  //TODO
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  //TODO
  return T();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
