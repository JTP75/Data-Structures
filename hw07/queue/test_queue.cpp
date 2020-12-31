#include "queue.h"
#include "dynamic_array_list.h"

#include <cassert>

int main()
{
  // a queue, holding ints, using a DynamicArrayList as the container
  Queue<int,DynamicArrayList<int> > queue;
  assert(queue.isEmpty());
  
  queue.enqueue(12);
  assert(!queue.isEmpty());
  assert(queue.peekFront() == 12);

  queue.enqueue(-4);
  assert(!queue.isEmpty());
  assert(queue.peekFront() == 12);

  queue.dequeue();
  queue.dequeue();
  assert(queue.isEmpty());

  queue.enqueue(241);
  assert(!queue.isEmpty());
  assert(queue.peekFront() == 241);

  queue.enqueue(45);
  assert(!queue.isEmpty());
  assert(queue.peekFront() == 241);

  queue.enqueue(62);
  assert(!queue.isEmpty());
  assert(queue.peekFront() == 241);
  
  Queue<int,DynamicArrayList<int> > another_queue;
  another_queue = queue;

  assert(!another_queue.isEmpty());
  assert(another_queue.peekFront() == 241);
  another_queue.dequeue();
  assert(another_queue.peekFront() == 45);
  another_queue.dequeue();
  assert(another_queue.peekFront() == 62);
    
  return 0;
}
