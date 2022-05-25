
#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "abstract_queue.hpp"

template <typename T, typename L>
class Queue: public AbstractQueue<T>
{
public:

  // default constructor
  // not needed, default is ok
  
  // copy constructor
  // not needed, default is ok
  
  // destructor
  // not needed, default is ok
  
  // copy assignment
  // not needed, default is ok

  // return true is the queue is empty
  bool isEmpty() const;

  // enqueue (add) newEntry into the queue back
  // throw exception if not possible
  void enqueue(const T& item);

  // dequeue (remove) newEntry from the queue front
  // throw exception if not possible
  void dequeue();

  // return a copy of the item at the front of the queue
  // throw exception if not possible
  T peekFront();

private:

  // L must conform to AbstractList interface
  L internal_list;
};

#include "queue.tpp"

#endif 
