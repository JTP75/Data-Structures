#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"

int main()
{
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  
  return 0;
}
