#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  //TODO
  
  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost

  // needs return statement

}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //TODO
  
  //implement this the same way we implemented push in the heap lecture.

}

template <typename T>
bool frontier_queue<T>::empty() {

  //TODO

  return true;
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  //TODO

  return false;

}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO

}


