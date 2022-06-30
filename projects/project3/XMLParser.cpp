// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"


// use directives
using std::string;

// helper fcns prototypes
static string deleteAttributes(string);
bool isValidName(string);
bool parseAttributes(string, Bag<Attribute> &);
bool parseTag(size_t open_idx, string str_in, TokenStruct &tkn);
int charfreq(string,char);


// TODO: Implement the constructor here
XMLParser::XMLParser() : tkn_vec() {
	name_bag = new STR_BAG;
	tag_stack = new STR_STACK;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser(){
	// call destructors (vector is not dynamic, dtor called automatically)
	name_bag->~Bag();
	tag_stack->~Stack();
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const string &str_in){
	std::size_t idx = 0;
	while(idx < str_in.size())
	{
		// if string begins with '<', read and parse the tag
		if(str_in[idx] == '<')
		{
			TokenStruct tag;
			if(!parseTag(idx, str_in, tag))
				return false;
		}

		// otherwise, treat as content
		else
		{

		}

	}
	return true;
}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput(){
	return false;
}

// TODO: Implement the clear method here
void XMLParser::clear(){
	// clear data members
	name_bag->clear();
	tag_stack->clear();
	tkn_vec.clear();
}

TKN_VECTOR XMLParser::returnTokenizedInput() const{
	return tkn_vec;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const string &str_in) const{
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const string &str_in) const{
	return -1;
}

/** checks if string (not including <>'s) is a valid name */
bool isValidName(string s){
	if
	(
		// check if string is empty
		s.size() == 0	 ||	
		// check for invalid characters
		s.find("!") != string::npos  || s.find("\"") != string::npos || s.find("#") != string::npos ||  s.find("$") != string::npos ||  
		s.find("%") != string::npos  || s.find("&") != string::npos  || s.find("'") != string::npos ||  s.find("(") != string::npos ||  
		s.find(")") != string::npos  || s.find("*") != string::npos  || s.find("+") != string::npos ||  s.find(",") != string::npos ||  
		s.find("/") != string::npos  || s.find(";") != string::npos  || s.find("<") != string::npos ||  s.find("=") != string::npos ||  
		s.find(">") != string::npos  || s.find("?") != string::npos  || s.find("@") != string::npos ||  s.find("[") != string::npos ||  
		s.find("\\") != string::npos || s.find("]") != string::npos  || s.find("^") != string::npos ||  s.find("`") != string::npos ||  
		s.find("{") != string::npos  || s.find("|") != string::npos  || s.find("}") != string::npos ||  s.find("~") != string::npos ||
		s.find(" ")	!= string::npos  ||
		// check for invalid first characters
		s[0] == '-'		 || s[0] == '.' 	 || s[0] == '0'		||  s[0] == '1'		||
		s[0] == '2'		 || s[0] == '3'		 || s[0] == '4'		||  s[0] == '5'		||
		s[0] == '6'		 || s[0] == '7'		 || s[0] == '8'		||  s[0] == '9'
	) return false;
	return true;
}

/** parse attributes (instead of deleteAttributes): 
 * @param	tag_str		tag string of the form: <[tag name] [attribute 1]="[value 1]" ...>	
 * @returns validity of attrs */
bool parseAttributes(string tag_str, Bag<Attribute> &attr_bag){
	// 3 is minimum size for a valid tag
	if(tag_str.size() < 3)
		return 0;
	
	// frequencies must be: 	1 space : 1 equals sign : 2 quotation marks		for each attribute	(assuming no other spaces)
	int space_count = charfreq(tag_str, ' ');
	int eq_count = charfreq(tag_str, '=');
	int quote_count = charfreq(tag_str, '"');
	if(space_count != eq_count || space_count != 2*quote_count)
		return false;

	// assuming attribute naming conventions are the same as tag names
	size_t idx = 0;
	while(idx < tag_str.length() && tag_str[idx] != '>' && tag_str[idx] != '?'){
		Attribute a;

		size_t space_idx = tag_str.find(' ', idx);
		size_t eq_idx = tag_str.find('=', idx);

		if(tag_str[eq_idx+1] != '"')	// equals must be followed immediately by quote
			return false;

		a.name = tag_str.substr( (space_idx+1), (eq_idx) - (space_idx+1) );		// extract attr name

		idx = tag_str.find('"', eq_idx+2) + 1;		// idx is now index after closing quotation mark
		a.val = tag_str.substr( (eq_idx+2), (idx-1) - (eq_idx+2) );		// extract attr val

		attr_bag.add(a);
	}
	return true;
}

/** general tag parser: parses tag for name and checks that attributes are valid ()
 * @param str 	full string passed in
 * @param tkn	struct for token (reference)
 * @returns bool indicating validity */
bool parseTag(size_t open_idx, string str_in, TokenStruct &tkn){
	// check tag is valid
	if(str_in[open_idx] != '<')			// make sure '<' is at open_idx
		return false;

	// get tag string
	size_t end_idx = str_in.find('>', open_idx);							// find closing bracket
	if(end_idx == string::npos)												// if no closing bracket, invalid tag
		return false;
	string tag_str = str_in.substr( (open_idx), (end_idx) - (open_idx) );	// generate tag string

	// get type, return false if invalid
	bool
		startIsQM = tag_str[1] == '?',
		endIsQM = tag_str[tag_str.length()-2] == '?',
		startIsSL = tag_str[1] == '/',
		endIsSL = tag_str[tag_str.length()-2] == '/';						// bool vars to determine type (content won't be passed in to this  fcn)

	if			(!startIsQM && !endIsQM && !startIsSL && !endIsSL)		tkn.tokenType = START_TAG;		// no /'s or ?'s at beginning or end
	else if		(!startIsQM && !endIsQM && startIsSL && !endIsSL)		tkn.tokenType = END_TAG;		// one / at beginning
	else if		(!startIsQM && !endIsQM && !startIsSL && endIsSL)		tkn.tokenType = EMPTY_TAG;		// one / at end
	else if		(startIsQM && endIsQM && !startIsSL && !endIsSL)		tkn.tokenType = DECLARATION;	// ?'s at beginning and end
	else																return false;					// otherwise: invalid tag

	// check and parse attributes
	if(!parseAttributes())
		return false;
}

/** gets frequency of char c in string str */
int charfreq(string str, char c){
	int count = 0;
	for(char x : str)
		if(x == c)
			count++;
	return count;
}