
#ifndef _ABSTRACT_QUEUE_H_
#define _ABSTRACT_QUEUE_H_

template <typename T>
class AbstractQueue
{
public:

  // return true is the queue is empty
  virtual bool isEmpty() = 0;

  // enqueue (add) newEntry into the queue back
  // throw exception if not possible
  virtual void enqueue(const T& item) = 0;

  // dequeue (remove) newEntry from the queue front
  // throw exception if not possible
  virtual void dequeue() = 0;

  // return a copy of the item at the front of the queue
  // throw exception if not possible
  virtual T peekFront() = 0;
};

#endif // _ABSTRACT_QUEUE_H_
