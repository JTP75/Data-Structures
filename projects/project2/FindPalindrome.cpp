#include <string>
#include <vector>
#include <iostream>
#include <locale> 
//#include <bits/stdc++.h>
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

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string> candidateStringVector, 
											  vector<string> currentStringVector)
{
	// for initial call: candStrVec is empty and currStrVec is full of all words

	// BASE CASE:
	if(currentStringVector.empty()){									// if currentstrvec is empty (base case), check if canditate is pdrome
		string canditateAsString = "";									// put candidate vector in string form
		for(string s : candidateStringVector)							// **
			canditateAsString += s;										// **
		if(isPalindrome(canditateAsString))								// candidate is pdr:
			palindromes[pdrCount++] = candidateStringVector;			// increment count and add pdr to pdrs vector
		return;															// exit
	}

	// RECURSION CASE
	else{																// if currentstrvec is not empty (recursion case)
		int i=0;
		for(string s : currentStringVector){							// loop through each word in currentStrVec
			vector<string> nextCandidate = candidateStringVector;		// create temps to pass into recursive fcn call
			vector<string> nextCurrent = currentStringVector;			// **
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
	return true;
	}
}

bool FindPalindrome::runQuickChecks(vector<string> currentStringVector)
{
	// idea: if this function returns false, recursiveFindPalindromes() will not be called at all

	// WIP...

	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	charCount = 0;		// vector ctor is called automatically
	pdrCount = 0;
}

FindPalindrome::~FindPalindrome()
{
	delete &wordList;
}

int FindPalindrome::number() const
{
	// TODO need to implement this...
	return 10;
}

void FindPalindrome::clear()
{
	wordList.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{
	size_t tmpCharCounter = 0;
	for(char c : value){									// loop through each char
		tmpCharCounter++;									// update temp counter
		if( c < 'A' || (c > 'Z' && c < 'a') || c > 'z' )	// check char
			return false;									// return false if invalid char 
	}
	wordList.push_back(value);								// append new value
	charCount += tmpCharCounter;							// add temp counter to class counter
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	size_t tmpCharCounter = 0;
	for(string word : stringVector){									// loop through each word
		for(char c : word){												// loop through each char
			tmpCharCounter++;											// update temp char counter
			if( c < 'A' || (c > 'Z' && c < 'a') || c > 'z' )			// return false if ANY word is invalid
				return false;
		}
	}
	wordList.insert(wordList.end(),stringVector.begin(),stringVector.end());	// append new words
	charCount += tmpCharCounter;												// add temp counter to class counter
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	vector<vector<string>> returnThingie;
	return returnThingie;
}







// NOTES
/*
	- if the number of words is odd, the middle word MUST be a palindrome
		- i.e. if numwords is odd and none of them are palindromes, it is impossible for there to be any palindrome sentences.

	- if numwords is even, numchars must also be even
*/