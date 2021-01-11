#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bag.hpp"

// force template expansion
template class Bag<int>;

TEST_CASE("Empty Test", "[Bag]"){
  REQUIRE(true);
}
