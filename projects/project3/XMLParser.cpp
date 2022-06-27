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
std::size_t checkAttributes(string);


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
	std::size_t i = 0;
	while(i < str_in.size()){
		if(str_in[i] == '<')		// if string begins with '<', treat as tag
		{
			std::size_t tagstart_close, pos, attrs_last_idx;
			string tagstart, tagstart_raw, tagend, name, attrs = "", content;

			tagstart_close = str_in.find('>', i);			// find ">"
			if(tagstart_close == string::npos)				// check for ">" to close tag
				return false;

			tagstart_raw = str_in.substr(i, tagstart_close + 1);
			tagstart = str_in.substr(i + 1, tagstart_close - 1);	// tagstart is substr contained by <>'s
			pos = tagstart.find(" ");
			if(pos != string::npos){						// if a space is found, check for attributes
				attrs = tagstart.substr(pos, tagstart.size());
				attrs_last_idx = checkAttributes(attrs);	// find attrs last index 
				if(attrs_last_idx == string::npos)			// check if attributes are valid
					return false;
				name = tagstart.substr(0, pos);
			}else{
				name = tagstart;
			}
			if(!isValidName(name)) return false;				// check if name is valid

			if(tagstart[tagstart.size()-1] == '/'){				// if last value of tag is '/' (empty)
				i += tagstart.size();							// incr size and continue
			}else{
				tagend = "</" + name + ">";						// tagend is same as tagstart, with '/' inserted at beginning
				std::size_t repeated_nested_count = 0;			// count for number of repeated, nested tags (including first)
				while()

				if(tagend_open == string::npos)								// check that tagend exists
					return false;
				content = str_in.substr(tagstart_close+1, tagend_open-tagstart_close-1);		// content: string between tagstart and tagend
				i += tagstart_raw.size() + content.size() + tagend.size();						// increment index by sum of lengths of tags and content
			}

			name_bag->add(name);			// add name to bag

			tag_stack->push(name);			// push END name to stack
			tokenizeInputString(content);	// recursive call (will push 'content' to stack)
			tag_stack->push(name);			// push START name to stack
		}
		else					// otherwise, treat as content
		{
			nexttag_pos = str_in.find()
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
	if(attr_list.size() == 0)
		return 0;
	
	if(attr_list.size() > 0 && attr_list.size() < 7)
		return string::npos;
	
	std::size_t retval, close_quote_idx, eq_idx = attr_list.find("=");
	if(eq_idx == string::npos || eq_idx >= attr_list.size()-3 || attr_list[eq_idx+1] != '"') 	// check eq exists, isnt at end, and next char is a "
		return string::npos;																	// return npos: attr list is invalid
	
	close_quote_idx = attr_list.find('"', eq_idx+2);				// start search at idx after opening quote (idx will always be within string)
	if(close_quote_idx == string::npos)						// return npos if closing quote is not found
		return string::npos;

	retval = checkAttributes(attr_list.substr(close_quote_idx+1));
	if(retval == string::npos)
		return string::npos;
	
	return retval + close_quote_idx;
}