#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bag_simple.hpp"

// force template expansion
template class Bag<int>;

TEST_CASE("Test Construction/Destruction", "[Bag]"){

  Bag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("Test add", "[Bag]"){

  Bag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for(int i = 0; i < Bag<int>::MAXSIZE; ++i){
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i+1);
    REQUIRE(!b.isEmpty());
  }
  REQUIRE(!b.add(0));
}

TEST_CASE("Test remove", "[Bag]"){

  Bag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for(int i = 0; i < Bag<int>::MAXSIZE; ++i){
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i+1);
    REQUIRE(!b.isEmpty());
  }

  REQUIRE(!b.remove(-1));
  
  for(int i = 0; i <  Bag<int>::MAXSIZE; ++i){
    REQUIRE(b.remove(i));
  }
  REQUIRE(!b.remove(0));
}

TEST_CASE("Test clear", "[Bag]"){

  Bag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for(int i = 0; i < Bag<int>::MAXSIZE; ++i){
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i+1);
    REQUIRE(!b.isEmpty());
  }

  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
  
}

TEST_CASE("Test frequency", "[Bag]"){

  {
    Bag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(b.getFrequencyOf(0) == 0);
    
    for(int i = 0; i < Bag<int>::MAXSIZE; ++i){
      REQUIRE(b.add(i));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }
    
    for(int i = 0; i < Bag<int>::MAXSIZE; ++i){
      REQUIRE(b.getFrequencyOf(i) == 1);
    }
  }
  
  {
    Bag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    
    for(int i = 0; i < Bag<int>::MAXSIZE; ++i){
      REQUIRE(b.add(-1));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }

    std::size_t EXPECTED = Bag<int>::MAXSIZE;
    REQUIRE(b.getFrequencyOf(-1) == EXPECTED);
    REQUIRE(b.getFrequencyOf(0) == 0);
  }
}


TEST_CASE("Test contains", "[Bag]"){

  {
    Bag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(!b.contains(0));
	
    for(int i = 0; i < Bag<int>::MAXSIZE; ++i){
      REQUIRE(b.add(i));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }
    
    for(int i = 0; i < Bag<int>::MAXSIZE; ++i){
      REQUIRE(b.contains(i));
    }
    REQUIRE(!b.contains(-1));
  }
  
  {
    Bag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(!b.contains(0));
    
    for(int i = 0; i < Bag<int>::MAXSIZE; ++i){
      REQUIRE(b.add(-1));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }

    REQUIRE(b.contains(-1));
    REQUIRE(!b.contains(0));
  }
}
