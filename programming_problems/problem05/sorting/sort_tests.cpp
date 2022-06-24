#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"
#include "sort.hpp"

#include <time.h>

// write your test cases here
TEST_CASE("basic sort", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 4);
  REQUIRE(sorted.getEntry(1) == 10);
  REQUIRE(sorted.getEntry(2) == 11);
  REQUIRE(sorted.getEntry(3) == 25);
  REQUIRE(sorted.getEntry(4) == 100);
  
}

TEST_CASE("timed test", "sorting"){

  srand(time(NULL));

  clock_t t, dt_sort, dt_n2;
  size_t sz = 10000;
  LinkedList<std::uint8_t> big_lst, sorted;

  for(size_t i = 0; i < sz; i++)
    big_lst.insert(0, rand() % 256);

  t = clock();
  sorted = sort(big_lst);
  dt_sort = clock() - t;

  t = clock();
  for(std::size_t i = 0; i < sz*sz; i++)
  dt_n2 = clock() - t;

  REQUIRE(dt_n2 > dt_sort);
}
















