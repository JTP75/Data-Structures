#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int bagset[20] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10};

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Test copy constructor, copy assigment, and destructor", "[DynamicBag]"){
  DynamicBag<double> a;
  for(size_t i = 1; i<=100; i++)
    a.add(100.0 / i);
  REQUIRE(a.getCurrentSize()==100);

  DynamicBag<double> b = a;
  REQUIRE(a.getCurrentSize()==b.getCurrentSize());

  DynamicBag<double> c;
  REQUIRE(c.isEmpty());
  c = a;
  REQUIRE(a.getCurrentSize()==c.getCurrentSize());
}

TEST_CASE("Test add/remove/clear", "[DynamicBag]"){
  DynamicBag<int> a;

  a.add(-35);
  REQUIRE_FALSE(a.isEmpty());
  bool didRemoveItem = a.remove(-34);
  REQUIRE_FALSE(a.isEmpty());
  REQUIRE_FALSE(didRemoveItem);
  a.remove(-35);
  REQUIRE(a.isEmpty());

  for(int i : bagset) a.add(i);
  REQUIRE(a.getCurrentSize()==20);

  a.remove(8);
  REQUIRE(a.getCurrentSize()==19);

  a.clear();
  REQUIRE(a.isEmpty());
}

TEST_CASE("Test contains/frequency", "[DynamicBag]"){
  DynamicBag<int> a;
  for(int i : bagset) a.add(i);

  REQUIRE(a.contains(6));
  REQUIRE_FALSE(a.contains(-6));

  REQUIRE(a.getFrequencyOf(6)==2);
  REQUIRE(a.getFrequencyOf(-6)==0);
}
