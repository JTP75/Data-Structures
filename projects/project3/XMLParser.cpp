// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// useful macros
#define tg_open 	'<'
#define tg_close	'>'


// use directives
using std::string;

// helper fcns prototypes
static string deleteAttributes(string);
bool isValidName(string);
int checkAttributes(string);


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
	string tg, tgE, name, attrs;
	for(std::size_t i = 0; i < str_in.size(); i++)
	{
		if(str_in[i] == tg_open){
			std::size_t pos = str_in.find(tg_close), attrs_last_idx;
			attrs = "";

			if(pos == string::npos) return false;			// check for ">" to close tag
			tg = str_in.substr(i + 1, pos - 1);				// tg is substr contained by <>'s

			pos = tg.find(" ");
			if(pos != string::npos){						// if a space is found, check for attributes
				attrs = tg.substr(pos, tg.size());
				attrs_last_idx = checkAttributes(attrs);
				name = tg.substr(0, pos);
			}else{
				name = tg;
			}
			
			if(!isValidName(name)) return false;
		}else{

		}
	}
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

// helper fcns
// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static string deleteAttributes(string str_in){
	return str_in;
}

// checks if string (not including <>'s) is a valid name
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

/** recursively checks for attributes: 
 * @param	attr_list	list of attrs of the form:  [attribute]="[value]" [attribute]="[value]" ... (first character is a space)
 * @returns index of end of attribute list (string::npos if there are none) */
std::size_t checkAttributes(string attr_list){
	if(attr_list.size() == 0){
		return 0;
	}else if(attr_list.size() > 0 && attr_list.size() < ){
		return string::npos;
	}else{
		std::size_t retval, close_quote_idx, eq_idx = attr_list.find("=");
		if(eq_idx == string::npos || eq_idx >= attr_list.size()-3 || attr_list[eq_idx+1] != '"') 	// check eq exists, isnt at end, and next char is a "
			return string::npos;																	// return npos: attr list is invalid
		close_quote_idx = attr_list.find('"', eq_idx+2);				// start search at idx after opening quote (idx will always be within string)
		if(close_quote_idx == string::npos)	return string::npos;		// return npos if closing quote is not found
		retval = checkAttributes(attr_list.substr(close_quote_idx+1, attr_list.size()-1-close_quote_idx));
	}
}