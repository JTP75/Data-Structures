#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.hpp"
#include "queue.hpp"

TEST_CASE("test arraylist", "[array list]") {
  DynamicArrayList<int> alst;
  REQUIRE(alst.isEmpty());

  alst.insert(0, 100);
  alst.insert(0,99);
  REQUIRE_FALSE(alst.isEmpty());
  REQUIRE(alst.getLength()==2);

  alst.insert(2,102);
  alst.insert(3,103);
  alst.insert(2,101);
  REQUIRE(alst.getLength()==5);
  REQUIRE(alst.getEntry(0)==99);
  REQUIRE(alst.getEntry(1)==100);
  REQUIRE(alst.getEntry(2)==101);
  REQUIRE(alst.getEntry(3)==102);
  REQUIRE(alst.getEntry(4)==103);

  alst.remove(0);
  alst.remove(3);
  alst.remove(1);
  REQUIRE(alst.getLength()==2);
  REQUIRE(alst.getEntry(0)==100);
  REQUIRE(alst.getEntry(1)==102);

  alst.clear();
  REQUIRE(alst.isEmpty());
}

TEST_CASE("testing all", "[queue]") {
  Queue<int, DynamicArrayList<int>> queue;

  queue.enqueue(12);
  REQUIRE(!queue.isEmpty());
  REQUIRE(queue.peekFront() == 12);

  queue.enqueue(-4);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 12);

  queue.dequeue();
  queue.dequeue();
  REQUIRE(queue.isEmpty());

  queue.enqueue(241);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(45);
  REQUIRE(!queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(62);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  Queue<int, DynamicArrayList<int>> another_queue;
  another_queue = queue;

  REQUIRE_FALSE(another_queue.isEmpty());
  REQUIRE(another_queue.peekFront() == 241);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 45);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 62);
}