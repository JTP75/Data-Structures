
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "abstract_queue.h"
#include "abstract_list.h"

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
  bool isEmpty();

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


template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  internal_list.insert(internal_list.getLength(), item);
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  internal_list.remove(0);
}

template <typename T, typename L>
T Queue<T,L>::peekFront()
{
  return internal_list.getEntry(0);
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty()
{
  return internal_list.isEmpty();
}

#endif // _QUEUE_H_
