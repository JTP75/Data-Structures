#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "ring_buffer.h"

TEST_CASE("Test 1", "[ring_buffer]") {
  RingBuffer<int> buff(3);

  REQUIRE(buff.enqueue_back(1));
  REQUIRE(buff.enqueue_back(2));
  REQUIRE(buff.enqueue_back(3));
  REQUIRE_FALSE(buff.enqueue_back(4));
  REQUIRE_FALSE(buff.enqueue_back(5));
  REQUIRE_FALSE(buff.enqueue_back(6));

  REQUIRE(buff.getCount() == 3);
  REQUIRE(buff.dequeue_front() == 1);
  REQUIRE(buff.dequeue_front() == 2);
  REQUIRE(buff.dequeue_front() == 3);
  REQUIRE(buff.getCount() == 0);

}
