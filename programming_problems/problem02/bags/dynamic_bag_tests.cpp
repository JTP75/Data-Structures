#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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

  delete &c;
}
/*
TEST_CASE("Test add", "[DynamicBag]"){
  DynamicBag<int> a;

  a.add(0);
  REQUIRE(a.getCurrentSize() == 1);
  REQUIRE_FALSE(a.isEmpty());

  a.add(29);
  a.add(14);
  REQUIRE(a.getCurrentSize() == 3);

  //delete &a;
}

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("Bag of bags test", "[DynamicBag]"){
  DynamicBag<int> b;
}*/
