#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test add for single word", "[FindPalindrome]" )
{
	FindPalindrome b;

	REQUIRE(b.add("kayak"));
	REQUIRE_FALSE(b.add("kayak1"));
};

TEST_CASE( "Test add for word list", "[FindPalindrome]" )
{
	FindPalindrome b;
	
	WORD_LIST validList = {"this","is","a","valid","word","list"};
	WORD_LIST invalidList = {"this","is","an","invalid","word","list."};
	REQUIRE(b.add(validList));
	REQUIRE_FALSE(b.add(invalidList));
};

TEST_CASE( "test recursive find and clear", "[FindPalindrome]" )
{
	FindPalindrome obj;
	
	WORD_LIST a = {"a","AA","AaA"};
	REQUIRE(obj.add(a));
	REQUIRE(obj.number() == 6);
	obj.clear();
	REQUIRE(obj.number() == 0);
};

TEST_CASE( "test toVector", "[FindPalindrome]" )
{
	FindPalindrome obj;

	WORD_LIST racecar = {"racE","car"};

	obj.add(racecar[0]);
	REQUIRE(obj.number() == 0);
	obj.add(racecar[1]);
	REQUIRE(obj.number() == 1);

	vector<WORD_LIST> pdrs = obj.toVector();
	REQUIRE(racecar == pdrs[0]);
};




















