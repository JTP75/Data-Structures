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
int charfreq(string,char);


// TODO: Implement the constructor here
XMLParser::XMLParser() : tkn_vec() {
	TIScalled = false;
	PTIcalled = false;
	name_bag = new STR_BAG;
	tag_stack = new TAG_STACK;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser(){
	// call destructors (vector is not dynamic, dtor called automatically)
	name_bag->~Bag();
	tag_stack->~Stack();
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const string &str_in){
	size_t idx = 0;
	while(idx < str_in.length()){

		// if space is encountered, increment index and continue
		if(str_in[idx] == ' '){
			idx++;
		}

		// handles tags
		else if(str_in[idx] == '<'){
			TokenStruct ts;

			size_t closing_delimiter = str_in.find('>', idx), L;
			if(closing_delimiter == string::npos)
				return false;
			string tag = str_in.substr( (idx), (closing_delimiter+1) - (idx) );
			L = tag.length();

			ts.tagStruct.full_str = tag;

			bool
				QMS = tag[1] == '?',
				QME = tag[L-2] == '?',
				SLS = tag[1] == '/',
				SLE = tag[L-2] == '/';

			if		(!QMS && !QME && !SLS && !SLE){																		// start tag
				ts.tokenType = START_TAG;
				ts.tagStruct.name_str = deleteAttributes(tag);
				ts.tagStruct.name = ts.tagStruct.name_str.substr( (1), (ts.tagStruct.name_str.length()-1) - (1) );
				ts.tokenString = ts.tagStruct.name;
			}else if(!QMS && !QME &&  SLS && !SLE){																		// end tag
				ts.tokenType = END_TAG;
				ts.tagStruct.name_str = tag;
				ts.tagStruct.name = ts.tagStruct.name_str.substr( (2), (ts.tagStruct.name_str.length()-1) - (2) );
				ts.tokenString = ts.tagStruct.name;
			}else if(!QMS && !QME && !SLS &&  SLE){																		// mt tag
				ts.tokenType = EMPTY_TAG;
				ts.tagStruct.name_str = tag;
				ts.tagStruct.name = ts.tagStruct.name_str.substr( (1), (ts.tagStruct.name_str.length()-2) - (1) );
				ts.tokenString = ts.tagStruct.name;
			}else if( QMS &&  QME && !SLS && !SLE){																		// dec tag
				ts.tokenType = DECLARATION;
				ts.tagStruct.name_str = deleteAttributes(tag);
				ts.tagStruct.name = ts.tagStruct.name_str.substr( (2), (ts.tagStruct.name_str.length()-2) - (2) );
				ts.tokenString = tag.substr( 2, tag.length()-2 - 2 );		// keep attributes for declarations (?)
			}else{
				return false;
			}
			
			if(!isValidName(ts.tagStruct.name))
				return false;
			
			idx += L; 
			tkn_vec.push_back(ts);
		}

		// handle content
		else{
			TokenStruct ts;

			ts.tokenType = CONTENT;
			size_t next_idx = str_in.find('<', idx);
			if(next_idx == string::npos)
				next_idx = str_in.length()-1;
			size_t i = next_idx;
			while(str_in[--i] == ' ');						// decrement index until it is not a space
			ts.tokenString = str_in.substr(idx, 1+i-idx);

			idx = next_idx;
			tkn_vec.push_back(ts);
		}

	}

	TIScalled = true;
	return true;
}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput(){
	// if TIC was not called successfully, return false
	if(!TIScalled)
		return false;

	for(int i=0; i<tkn_vec.size(); i++)
	{TokenStruct T = tkn_vec[i];

		// if this token is content and tag_stack is empty, content has no container
		if(T.tokenType == CONTENT && tag_stack->isEmpty()){
			return false;
		}

		// if this token is a start tag, push it to the stack and add it to the bag
		else if(T.tokenType == START_TAG){
			tag_stack->push(T.tagStruct);
			name_bag->add(T.tagStruct.name);
		}

		// if this token is an empty tag, add it to the bag
		else if(T.tokenType == EMPTY_TAG){
			name_bag->add(T.tagStruct.name);
		}

		// if this token is an end tag, check that it matches top of stack and pop the stack
		else if(T.tokenType == END_TAG){
			if(tag_stack->peek().name != T.tokenString)
				return false;
			tag_stack->pop();
		}

	}
	// if stack is not empty, return false
	PTIcalled = tag_stack->isEmpty();
	return PTIcalled;
}

// TODO: Implement the clear method here
void XMLParser::clear(){
	// clear data members
	TIScalled = false;
	PTIcalled = false;
	name_bag->clear();
	tag_stack->clear();
	tkn_vec.clear();
}

// TODO: Implement the returnTokenizedInput method here
TOKEN_VECTOR XMLParser::returnTokenizedInput() const{
	return tkn_vec;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const string &str_in) const{
	if(TIScalled && PTIcalled)
		return name_bag->contains(str_in);
	throw std::logic_error("tokenizedInputString and parseTokenizedInputs weren't called");
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const string &str_in) const{
	if(TIScalled && PTIcalled)
		return name_bag->getFrequencyOf(str_in);
	throw std::logic_error("tokenizedInputString and parseTokenizedInputs weren't called");
}

/** deletes attrs from tag
 * @param tag 	string of form "<[?/][tag name] [attribute list][?/]>" 
 * @return 		string of form "<[?/][tag name][?/]>" as a new string (to preserve orginal with attributes)	*/
static string deleteAttributes(string tag){
	size_t L = tag.length();
	if(tag[0] != '<' || tag[L-1]!= '>')
		return "";
	
	size_t space_idx = tag.find(' ');
	if(space_idx == string::npos)
		return tag;
	string back;
	if(tag[L-2] == '/' || tag[L-2] == '?')
		back = tag.substr(L-2,1) + ">";
	else
		back = ">";

	return tag.substr(0,space_idx) + back;
}

/** checks if name is valid 
 * @param s		string of the form "[name]"
 * @return 		validity of name */
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

/** gets frequency of char c in string str */
int charfreq(string str, char c){
	int count = 0;
	for(char x : str)
		if(x == c)
			count++;
	return count;
}