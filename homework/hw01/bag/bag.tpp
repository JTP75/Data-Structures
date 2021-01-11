#include "bag.hpp"

// empty implementation                                                                                                     

template <typename T> Bag<T>::Bag() {}

template <typename T> Bag<T>::~Bag() {}

template <typename T> std::size_t Bag<T>::getCurrentSize() const { return 0; }

template <typename T> bool Bag<T>::isEmpty() const { return false; }

template <typename T> bool Bag<T>::add(const T& entry) { return false; }

template <typename T> bool Bag<T>::remove(const T& entry) { return false; }

template <typename T> void Bag<T>::clear() {}

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const { return 0; }

template <typename T> bool Bag<T>::contains(const T& entry) const { return false; }

