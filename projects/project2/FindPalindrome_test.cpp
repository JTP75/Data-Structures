#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"
#include <time.h>

// There should be at least one test per FindPalindrome method
// NOTE: I define a macro called WORD_LIST that is equivalent to vector<string>

// helper function
static int factorial(int n)
{
	if(n==1) return 1;
	else return n*factorial(n-1);
}

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

TEST_CASE( "test recursive find for 1 word", "[FindPalindrome]" )
{
	FindPalindrome obj;
	
	string s = "aibohphobia";		// aibohphobia is the fear of palindromes
	REQUIRE(obj.add(s));
	REQUIRE(obj.number() == 1);
};

TEST_CASE( "test cutTest1 on very large", "[FindPalindrome]" )
{
	FindPalindrome obj;
	
	// palindrome
	WORD_LIST lngList = {"Dennis","Nell","Edna","Leon","Nedra","Otto","Arden","Noel","and","Ellen","sinned"};
	// any longer than this would take hours to run
	/*obj.add(lngList); 
	REQUIRE(obj.number() > 0);
	obj.clear();*/

	// no longer any possible palindromes, given cuttest1
	lngList.push_back("alot");		// there is now an odd number of r's, a's, and e's
	obj.add(lngList);				// despite the long list, this should be quick, since it fails cutTest1
	REQUIRE(obj.number() == 0);
};

TEST_CASE( "test cutTest2 by checking timings", "[FindPalindrome]" )
{
	FindPalindrome obj;
	clock_t t, tP, tU;
	
	WORD_LIST palindrList = {"Dennis","Nell","Edna","Leon","Otto","Noel","and","Ellen","sinned"};
	WORD_LIST uniformList = {"Nnnnnn","Nnnn","Nnnn","Nnnn","Nnnn","Nnnn","nnn","Nnnnn","nnnnnn"};
	// lists have same number of words with same lengths and same capitalizations, for control
	/*
		IDEA:
		the uniform word list will always pass cutTest2. therefore, it should take longer to
		process than the palindrlist, since it wont skip any recursion layers
	*/
	t = clock();				// measure start time
	obj.add(uniformList);		// run add function
	tU = clock()-t;				// measure time differnce

	REQUIRE(obj.number()==factorial(9));		// check num of pdrs (should be 9!.)
	obj.clear();

	t = clock();				// measure start time
	obj.add(palindrList);		// run add function
	tP = clock()-t;				// measure time difference

	REQUIRE(obj.number()>=1);	// should be one

	REQUIRE(tP < tU);			// check to make sure timing for uniform is longer
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





















