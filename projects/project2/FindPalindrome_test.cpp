#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test All", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("kayak"));
	REQUIRE_FALSE(b.add("kayak1"));

	vector<string> validList = {"this","is","a","valid","word","list"};
	vector<string> invalidList = {"this","is","an","invalid","word","list."};
	REQUIRE(b.add(validList));
	REQUIRE_FALSE(b.add(invalidList));
} 
/* for some reason my code terminates when it gets to the end of a test case, so i can only use one test case
 - error message:
	"
		  {Unknown expression after the reported line}
		due to a fatal error condition:
		  SIGABRT - Abort (abnormal termination) signal
	"
 - also, the terminal reports an extra assertion that is not in this file
*/