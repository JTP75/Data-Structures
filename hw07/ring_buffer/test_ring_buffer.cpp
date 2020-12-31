#include "ring_buffer.h"

#include <cassert>

int main()
{
  RingBuffer<int> buff(3);
    
  buff.enqueue(89);
  buff.enqueue(4);
  buff.enqueue(45);
  buff.enqueue(12);
  buff.enqueue(455);
  buff.enqueue(1);

  //RingBuffer<int> buff2 = buff;
    
  assert(buff.getCount() == 6);
  assert(buff.dequeue() == 89);
  assert(buff.dequeue() == 4);
  assert(buff.dequeue() == 45);
  assert(buff.dequeue() == 12);
  assert(buff.dequeue() == 455);
  assert(buff.dequeue() == 1);
  assert(buff.getCount() == 0);

  
  return 0;
}
