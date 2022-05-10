
#ifndef _PRIORITY_QUEUE_HPP_
#define _PRIORITY_QUEUE_HPP_

#include "abstract_priority_queue.hpp"

// Type T must be orderable
// Type L must conform to AbstractSortedList<T>
template <typename T, typename L >
class PriorityQueue: AbstractPriorityQueue<T>
{
public:

  // return true if the priority queue is empty
  bool isEmpty() const {
    return slist.isEmpty();
  }

  // insert item into the queue
  void add(const T& item){
    slist.insert(item);
  }

  // remove highest priority item from the queue
  void remove(){
    slist.removeAt(slist.getLength()-1);
  }

  // get the item with the highest priority from the queue
  T peek(){
    return slist.getEntry(slist.getLength()-1);
  }

private:

  L slist; // internal sorted list
};

  
#endif // _PRIORITY_QUEUE_H_
