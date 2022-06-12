#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "Test Constructor and Insert", "[LinkedList]" ) {
    LinkedList<int> list;

    REQUIRE_FALSE(list.insert(1,1));

    for(int i=0; i<3; i++)
        REQUIRE(list.insert(i,i));

    REQUIRE_FALSE(list.insert(-1,13));
    REQUIRE_FALSE(list.insert(4,22));

    for(int i=0; i<3; i++)
        REQUIRE(list.insert(0,i));
}

TEST_CASE( "Test isEmpty and getLength", "[LinkedList]" ) {
    LinkedList<int> list;

    REQUIRE(list.isEmpty());
    REQUIRE(list.getLength() == 0);

    for(int i=0; i<100; i++)
        list.insert(0,i);

    REQUIRE_FALSE(list.isEmpty());
    REQUIRE(list.getLength() == 100);
}

TEST_CASE( "Test remove", "[LinkedList]" ) {
    LinkedList<int> list;
    for(int i=0; i<100; i++)
        list.insert(0,i);

    REQUIRE_FALSE(list.remove(-1));
    REQUIRE_FALSE(list.remove(100));

    REQUIRE(list.remove(99));
    REQUIRE(list.remove(0));
    REQUIRE(list.remove(45));

    REQUIRE(list.getLength() == 97);
}

TEST_CASE( "Test clear", "[LinkedList]" ) {
    LinkedList<int> list;
    for(int i=99; i>=0; i--)
        list.insert(0,i);

    list.clear();
    REQUIRE(list.isEmpty());
}

TEST_CASE( "Test getEntry", "[LinkedList]" ) {
    LinkedList<int> list;
    for(int i=0; i<7; i++)
        list.insert(0,i);

    REQUIRE(list.getEntry(-1) == 0);
    REQUIRE(list.getEntry(7) == 0);

    for(int i=0; i<7; i++){
        REQUIRE(list.getEntry(i) == 6-i);
    }
}

TEST_CASE( "Test setEntry", "[LinkedList]" ) {
    LinkedList<int> list;
    for(int i=0; i<10; i++)
        list.insert(0,i);

    list.setEntry(0,129);
    list.setEntry(7,97);
    list.setEntry(10,120);

    REQUIRE(list.getEntry(10) == 0);
    REQUIRE(list.getEntry(7) == 97);
    REQUIRE(list.getEntry(0) == 129);
}

TEST_CASE( "Test copy ctor", "[LinkedList]" ) {
  LinkedList<int> list1;
  for(int i=0; i<100; i++)
    list1.insert(i,100-i);

  LinkedList<int> list2 = list1;        // copy ctor

  bool sameContents = true;
  for(int i=0; i<100; i++)
    sameContents &= ( list1.getEntry(i)==list2.getEntry(i) );

  REQUIRE(sameContents);
}

TEST_CASE( "Test copy assignment operator", "[LinkedList]" ) {
  LinkedList<int> list1, list2;
  for(int i=0; i<100; i++)
    list1.insert(i,100-i);

  list2 = list1;                        // copy assignment

  bool sameContents = true;
  for(int i=0; i<100; i++)
    sameContents &= ( list1.getEntry(i)==list2.getEntry(i) );

  REQUIRE(sameContents);
}