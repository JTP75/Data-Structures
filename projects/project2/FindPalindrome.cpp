#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void str2lower(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}
static string wordlist2str(WORD_LIST list)
{
	string listStr = "";
	for(string s : list)
		listStr += s;
	return listStr;
}
static int getCharFreq(string str, char c)
{
	int count = 0;
	for(char x : str)
		count += x == c ? 1 : 0;
	return count;
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// =============================================================================
// ===================== MACRO: WORD_LIST = vector<string> =====================
// =============================================================================

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(WORD_LIST candidateStringVector, 
											  WORD_LIST currentStringVector)
{
	// for initial call: candStrVec is empty and currStrVec is full of all words

	// BASE CASE:
	if(currentStringVector.empty()){									// if currentstrvec is empty (base case), check if canditate is pdrome
		string canditateAsString = wordlist2str(candidateStringVector);	// convert wordlist to string
		if(isPalindrome(canditateAsString))								// candidate is pdr:
			palindromes.push_back(candidateStringVector);				// increment count and add pdr to pdrs vector
		return;															// exit
	}

	// RECURSION CASE
	else{																// if currentstrvec is not empty (recursion case)
		int i=0;
		for(string s : currentStringVector){							// loop through each word in currentStrVec
			WORD_LIST nextCandidate = candidateStringVector;			// create temps to pass into recursive fcn call
			WORD_LIST nextCurrent = currentStringVector;				// **
			nextCandidate.push_back(s);									// add string s to candidate temp
			nextCurrent.erase(nextCurrent.begin() + i++);				// remove string s from current temp
			recursiveFindPalindromes(nextCandidate, nextCurrent);		// pass temps into recursive call
		}
		return;															// exit when loop finishes
	}
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)

// string passed as immediate value, no need to preserve case
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	str2lower(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for(int i=1; i<stringLength/2; i++){
		if( currentString[i - 1] != currentString[stringLength - i] )
			return false;
	}
	return true;
}

bool FindPalindrome::runQuickChecks()
{
	return cutTest1(wordList);
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome(){
	// vectors are initialized automatically, nothing to explicitly construct
}

FindPalindrome::~FindPalindrome()
{
	wordList.clear();			// clear vectors
	palindromes.clear();
}

int FindPalindrome::number() const
{
	return palindromes.size();			// returns palindrome count
}

void FindPalindrome::clear()
{
	wordList.clear();			// clear vectors
	palindromes.clear();		// **
}

bool FindPalindrome::cutTest1(const WORD_LIST & stringVector)
{
	string listString = wordlist2str(stringVector);
	str2lower(listString);

	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int freqMod2Sum = 0;	// sum of the freqs of each letter mod 2

	for(int i=0; i<26; i++)
		freqMod2Sum += ( getCharFreq(listString, alphabet[i]) ) % 2;
	
	return freqMod2Sum <= 1;
	// if sum is more than 1, there is more than 1 letter whose freq is odd
}

bool FindPalindrome::cutTest2(const WORD_LIST & stringVector1,
                              const WORD_LIST & stringVector2)
{

	return false;
}

bool FindPalindrome::add(const string & value)
{
	for(char c : value)										// loop through each char
		if( c < 'A' || (c > 'Z' && c < 'a') || c > 'z' )	// check char
			return false;									// return false if invalid char

	wordList.push_back(value);								// append new value

	palindromes.clear();									// clear pdrs
	WORD_LIST cand;											// temp wordlist
	if(runQuickChecks())									// find palindromes if wordlist passes quickchecks
		recursiveFindPalindromes(cand, wordList);			// **

	return true;
}

bool FindPalindrome::add(const WORD_LIST & stringVector)
{
	for(string word : stringVector)										// loop through each word
		for(char c : word)												// loop through each char
			if( c < 'A' || (c > 'Z' && c < 'a') || c > 'z' )			// return false if ANY word is invalid
				return false;
	
	wordList.insert(wordList.end(),stringVector.begin(),stringVector.end());	// append new words

	palindromes.clear();												// clear pdrs
	WORD_LIST cand;														// temp wordlist
	if(runQuickChecks())												// find palindromes if wordlist passes quickchecks
		recursiveFindPalindromes(cand, wordList);						// **

	return true;
}

vector< WORD_LIST > FindPalindrome::toVector() const
{
	return palindromes;
}



