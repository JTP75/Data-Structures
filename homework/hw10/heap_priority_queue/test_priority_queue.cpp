#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "heap_priority_queue.h"

TEST_CASE("Test Construction", "[construction]") {
  HeapPriorityQueue<int>  pq;
  assert(pq.isEmpty());
}

TEST_CASE("Test add", "[add]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);

  assert(!pq.isEmpty());
  assert(pq.peek() == 25);

  pq.add(1);
  assert(pq.peek() == 25);

  pq.add(78);
  assert(pq.peek() == 78);
}

TEST_CASE("Test remove", "[remove]") {
  HeapPriorityQueue<int>  pq;
  pq.add(25);
  pq.add(1);
  pq.add(78);

  pq.remove();
  assert(pq.peek() == 25);
  pq.remove();
  assert(pq.peek() == 1);
  pq.remove();
  assert(pq.isEmpty());
}
