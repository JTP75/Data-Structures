
#ifndef _PRIORITY_QUEUE_HPP_
#define _PRIORITY_QUEUE_HPP_

#include "abstract_priority_queue.hpp"

// Type T must be orderable
// Type L must conform to AbstractSortedList<T>
template <typename T, typename L >
class PriorityQueue: public AbstractPriorityQueue<T>
{
public:

  // return true if the priority queue is empty
  bool isEmpty() const;

  // insert item into the queue
  void add(const T& item);

  // remove highest priority item from the queue
  void remove();

  // get the item with the highest priority from the queue
  T peek();

private:

  L slist; // internal sorted list
};

#include "priority_queue.tpp"
  
#endif 
