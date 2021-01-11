#include "add.hpp"

#include <iostream>

// implementation using fixed automatic storage

template <typename T> Add<T>::Add() {}

template <typename T> Add<T>::~Add() {}

template <typename T> Abstract_Operator<T>::~Abstract_Operator() {}

template <typename T> T Add<T>::call(T arg1, T arg2) const { 
  // TODO
}
