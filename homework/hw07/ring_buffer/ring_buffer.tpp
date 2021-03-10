#include "ring_buffer.h"

#include <cassert>

template <typename T>
RingBuffer<T>::RingBuffer(std::size_t size)
{
  queueLength = size;
  data.reset(new T[queueLength]);
  front = 0;
  back = queueLength-1;
  count = 0;
}

/**
template <typename T>
bool RingBuffer<T>::enqueue_back(const T& item)
{
  // TODO
}
*/

template <typename T>
bool RingBuffer<T>::enqueue_back(const T& item)
{
  if(count != queueLength){
    back = (back + 1) % queueLength;
    data[back] = item;
    ++count;
    return true;
  }
  
  return false;
}

template <typename T>
T RingBuffer<T>::dequeue_front()
{
  assert(count > 0);
  
  T value;
  
  value = data[front];
  front = (front +1) % queueLength;
  --count;
  
  return value;
}

/**
template <typename T>
T RingBuffer<T>::dequeue_front()
{
  // TODO
}
*/

template <typename T>
long int RingBuffer<T>::getCount()
{
  return count;
}
