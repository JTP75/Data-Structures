#include <cassert>

#include "dynamic_array_list.h"
#include "heap_priority_queue.h"

int main()
{
  HeapPriorityQueue<int>  pq;
  assert(pq.isEmpty());
  
  pq.add(25);
  assert(!pq.isEmpty());
  assert(pq.peek() == 25);

  pq.add(1);
  assert(pq.peek() == 25);

  pq.add(78);
  assert(pq.peek() == 78);

  pq.remove();
  pq.remove();
  pq.remove();
  assert(pq.isEmpty());

  return 0;
}
