#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"
#include <type_traits>

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test Insert", "[ArrayList]" ) {
  ArrayList<int> list;

  REQUIRE(list.insert(0,-7));           // valid index test
  REQUIRE_FALSE(list.insert(-1,293));   // lower OOB test
  REQUIRE_FALSE(list.insert(2,921));    // upper OOB test

  for(int i=1; i<5; i++)                // test many inserts
    REQUIRE(list.insert(i,-i));
}

TEST_CASE( "Test isEmpty & getLength", "[ArrayList]" ) {
  ArrayList<int> list;

  REQUIRE(list.isEmpty());
  REQUIRE(list.getLength() == 0);

  for(int i=0; i<100; i++)
    list.insert(i,i+1);

  REQUIRE_FALSE(list.isEmpty());
  REQUIRE(list.getLength() == 100);
}

TEST_CASE( "Test Remove", "[ArrayList]" ) {
  ArrayList<int> list;
  for(int i=0; i<100; i++)
    list.insert(i,i+1);

  REQUIRE_FALSE(list.remove(100));    // OOB tests
  REQUIRE_FALSE(list.remove(-1));
  REQUIRE(list.remove(99));       // remove last elem
  REQUIRE(list.remove(0));        // remove first 
  
  REQUIRE(list.getLength() == 98);  // check for correct size
}

TEST_CASE( "Test Clear", "[ArrayList]" ) {
  ArrayList<std::string> list;
  for(int i=0; i<100; i++)
    list.insert(i,"This is an arraylist element");

  list.clear();

  REQUIRE(list.isEmpty());  // check that list is empty after clearing
}

TEST_CASE( "Test getEntry", "[ArrayList]" ) {
  ArrayList<int> list;
  for(int i=0; i<10; i++)
    list.insert(i,i);

  for(int i=0; i<10; i++){
    REQUIRE(list.getEntry(i) == i);
  }

  REQUIRE( list.getEntry(-1) == 0 );
  REQUIRE( list.getEntry(10) == 0 );
}

TEST_CASE( "Test setEntry", "[ArrayList]" ) {
  ArrayList<int> list;
  for(int i=0; i<10; i++)
    list.insert(i,i);

  list.setEntry(4,299);
  REQUIRE(list.getEntry(4) == 299);

  list.setEntry(10,-5);
  REQUIRE_FALSE(list.getEntry(4) == -5);
}

TEST_CASE( "Test copy ctor", "[ArrayList]" ) {
  ArrayList<int> list1;
  for(int i=0; i<100; i++)
    list1.insert(i,100-i);

  ArrayList<int> list2 = list1;

  bool sameContents = true;
  for(int i=0; i<100; i++)
    sameContents &= ( list1.getEntry(i)==list2.getEntry(i) );

  REQUIRE(sameContents);
}

TEST_CASE( "Test copy assignment operator", "[ArrayList]" ) {
  ArrayList<int> list1, list2;
  for(int i=0; i<100; i++)
    list1.insert(i,100-i);

  list2 = list1;

  bool sameContents = true;
  for(int i=0; i<100; i++)
    sameContents &= ( list1.getEntry(i)==list2.getEntry(i) );

  REQUIRE(sameContents);
}
