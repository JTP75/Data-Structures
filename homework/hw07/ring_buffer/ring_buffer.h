// implement a deque as a ring buffer
#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include <cstdlib>
#include <memory>

template <typename T> class RingBuffer {
public:
  RingBuffer(std::size_t size);

  // bool enqueue(const T &item);
  // T dequeue();
  bool enqueue_front(const T& item);
  bool enqueue_back(const T& item);
  T dequeue_front();
  T dequeue_back();
  long int getCount();

private:
  std::size_t queueLength;
  long int front;
  long int back;
  long int count;

  std::unique_ptr<T[]> data;
};

#include "ring_buffer.tpp"

#endif // _RING_BUFFER_H_
